/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2016 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

/**********************************************************************

    module: wifi_client_hal.h

    ---------------------------------------------------------------

    description:

        This header file gives the function call prototypes and
        structure definitions used for the RDK-Video
        WiFi client hardware abstraction layer

    ---------------------------------------------------------------

    environment:

        This HAL layer is intended to support WiFi drivers
        through an open API.


**********************************************************************/
#ifndef __WIFI_CLIENT_HAL_H__
#define __WIFI_CLIENT_HAL_H__

/**
 * @addtogroup WIFI_HAL WiFi HAL
 * @{
 * @defgroup WIFI_CLIENT_HAL WiFi Client HAL
 * @{
 * WiFi Client HAL provides an interface (data structures and API) to interact with underlying WiFi driver and
 * enabling the client to be connected with an access point.
 */

#include <wifi_common_hal.h>

/**
 * @note ssidIndex across APIs is not being used it will be revisited in next phase 
 * @todo ssidIndex across APIs is not being used it will be revisited in next phase
*/

/**
 * @struct _wifi_pairedSSIDInfo
 * @brief Structure for SSID information
 *
 * This structure stores the paired SSID information
 */
typedef struct _wifi_pairedSSIDInfo
{
  CHAR  ap_ssid[64];          //!< The current service set identifier in use by the neighboring WiFi SSID. The value MAY be empty for hidden SSIDs.
  CHAR  ap_bssid[64];         //!< [MACAddress] The BSSID (Basic Service Set ID) used for the neighboring WiFi SSID.
  CHAR  ap_security[64];      //!< Security mode of AP
  CHAR  ap_passphrase[128];   //!< Passphrase of AP
  CHAR  ap_wep_key[128];      //!< wep_key of AP incase of WEP security
}wifi_pairedSSIDInfo_t;

/**
 * @struct _wifi_roamingCtrl_t
 * @brief Structure for roaming control information
 * @note postAssnSelfSteerBeaconsMissedTime will be removed
 * @todo Need to add comments for each variables including the ranges
 */
typedef struct _wifi_roamingCtrl_t
{
  BOOL roamingEnable;                          //!< Enables or disbles the roaming
  BOOL selfSteerOverride;                      //!< Starts self steer roaming if roam80211kvrEnable is FALSE
  BOOL roam80211kvrEnable;                     //!< Sets roaming mode to AP steer if roam80211kvrEnable is TRUE and selfSteerOverride is FALSE
  INT preassnBestThreshold;                    //!< Default value -67
  INT preassnBestDelta;                        //!< Default value 3
  INT postAssnLevelDeltaConnected;             //!< Delta level if WiFi connected. Default value 12
  INT postAssnLevelDeltaDisconnected;          //!< Delta level if WiFi disconnected. Default value 8
  INT postAssnSelfSteerThreshold;              //!< Self steer threshold. Default value -75
  INT postAssnSelfSteerTimeframe;              //!< Self sterr timeframe range 0 to 36000 secs
  INT postAssnBackOffTime;                     //!< BackOff time for incrementing post association time-frame during failure roaming attempts. Range 0 to 3600 secs
  //INT postAssnSelfSteerBeaconsMissedTime;    //!< postAssnSelfSteerBeaconsMissedTime will be removed
  INT postAssnAPctrlThreshold;                 //!< AP steer threshold
  INT postAssnAPctrlTimeframe;                 //!< AP steer time frame. Range 0 to 60 secs

}wifi_roamingCtrl_t;

/**
 * @struct _wifi_telemetry_ops_t 
 * 
 * @brief Structure for telemetry callback functions
 * @todo revisit telemetry requirement to move out of WiFi-HAL in next phase
 */
typedef struct _wifi_telemetry_ops_t
{
    void (*init)(char* name);                   //!< init telemetry callback function
    void (*event_s)(char* marker, char* value); //!< callback funtion to event a string telemetry marker
    void (*event_d)(char* marker, int value);   //!< callback funtion to event an integer telemetry marker
} wifi_telemetry_ops_t;

/**
 * @brief Gets WPS configuration methods supported by the device
 *
 * This function provides the comma-separated list of strings. For example:
 * - "USBFlashDrive" - User uses a USB flash drive to transfer data between the new client device and
 * the network's access point.
 * - "Ethernet" - If there is no WPS button, user can configure the wireless settings using ethernet on a wifi-extender
 * - "ExternalNFCToken" - NFC Tag contains a password token to authenticate WiFi connection.
 * Uses external program to write  * NDEF encapsulation data to the NFC tag using an external program.
 * - "IntegratedNFCToken" - The NFC Tag is integrated in the device.
 * - "NFCInterface" - User has to bring the client close to AP allowing a near field communication between the devices.
 * - "PushButton" - User has to push a button, either an actual or virtual one,
 * on both the access point and the new wireless * client device.
 * - "PIN" - User has to be read the PIN from either a sticker or display on the new wireless device.
 *
 * @param[in]  ssidIndex The index of SSID array
 * @param[out] methods   The WPS supported methods as a comma-separated string. Refer data-model parameter for the complete set of supported methods {Ex: "PushButton,PIN"}
 *
 * @return INT - The status of the operation
 * @retval RETURN_OK if successful
 * @retval RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter Device.WiFi.EndPoint.{i}.WPS.ConfigMethodsSupported
 * @todo Need more review on the ConfigMethodsSupported for this module in next phase
 */
INT wifi_getCliWpsConfigMethodsSupported(INT ssidIndex, CHAR *methods);

/**
 * @brief Gets WPS configuration methods enabled on the device
 *
 * The API provides the comma-separated list of strings.
 * Each list item MUST be a member of the list reported by the ConfigMethodsSupported parameter.
 *
 * @param[in]  ssidIndex      The index of SSID array
 * @param[out] output_string  The current WPS methods as a comma-separated string {Ex: "PushButton,PIN"}
 *
 * @return INT - The status of the operation
 * @retval RETURN_OK if successful
 * @retval RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_getCliWpsConfigMethodsSupported(), wifi_setCliWpsConfigMethodsEnabled()
 * @see @ref Data-Model Parameter Device.WiFi.EndPoint.{i}.WPS.ConfigMethodsEnabled
 */
INT wifi_getCliWpsConfigMethodsEnabled(INT ssidIndex, CHAR *output_string);

/**
 * @brief Sets the active WPS methods
 *
 * @param[in] ssidIndex    The index of SSID array
 * @param[in] methodString The methods to enable as a comma-separated string {Ex: "PushButton,PIN"}
 *
 * @return INT - The status of the operation
 * @retval RETURN_OK if successful
 * @retval RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_getCliWpsConfigMethodsSupported(), wifi_getCliWpsConfigMethodsEnabled()
 * @see @ref Data-Model Parameter Device.WiFi.EndPoint.{i}.WPS.ConfigMethodsEnabled
 */
INT wifi_setCliWpsConfigMethodsEnabled(INT ssidIndex, CHAR *methodString);

/**
 * @brief Sets the WPS PIN and uses it to pair with access point
 *
 * @param[in] ssidIndex   The index of SSID array
 * @param[in] EnrolleePin PIN code to connect to the access point. This PIN is either a four digit number or an eight digit number
 *
 * @return INT - The status of the operation
 * @retval RETURN_OK if successful
 * @retval RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @pre wifi_connectEndpoint_callback_register() should be called before calling this API
 * @see wifi_connectEndpoint_callback(), wifi_cancelWpsPairing()
 * @see @ref Data-Model Parameter Device.WiFi.EndPoint.{i}.WPS.PIN
 * @todo EnrolleePin will be revisited in next phase
 */
INT wifi_setCliWpsEnrolleePin(INT ssidIndex, CHAR *EnrolleePin);

/**
 * @brief Starts the WPS Push button pairing with access point
 *
 * @param[in] ssidIndex The index of SSID array variable is unused
 *
 * @return INT - The status of the operation
 * @retval RETURN_OK if successful
 * @retval RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @pre wifi_connectEndpoint_callback_register() should be called before calling this API
 * @see wifi_connectEndpoint_callback(), wifi_cancelWpsPairing()
 */
INT wifi_setCliWpsButtonPush(INT ssidIndex);

/**
 * @brief Starts the process of connection between the client and an access point
 *
 * @param[in] ssidIndex                 The index of SSID array
 * @param[in] AP_SSID                   The ssid to connect
 * @param[in] AP_security_mode          The security mode to use
 * @param[in] AP_security_WEPKey        The wep key
 * @param[in] AP_security_PreSharedKey  The pre shared key
 * @param[in] AP_security_KeyPassphrase The key passphrase
 * @param[in] saveSSID                  Specifies whether or not to save the WiFi configuration on a successfull connect {0-false,1-true}
 * @param[in] eapIdentity               EAP identity
 * @param[in] carootcert                CA root cert
 * @param[in] clientcert                client cert
 * @param[in] privatekey                private key
 *
 * @return INT - The status of the operation
 * @retval RETURN_OK if successful
 * @retval RETURN_ERR if any error is detected
 *  
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @pre wifi_connectEndpoint_callback_register() should be called before calling this API
 * @see wifiSecurityMode_t, wifi_disconnectEndpoint(), wifi_connectEndpoint_callback()
 * @note On successfull connect, wifi_connectEndpoint_callback() will be called
 * @todo Consider to define and use a data structure for input parameter in next phase
 */
INT wifi_connectEndpoint(INT ssidIndex, CHAR *AP_SSID, wifiSecurityMode_t AP_security_mode, CHAR *AP_security_WEPKey, CHAR *AP_security_PreSharedKey, CHAR *AP_security_KeyPassphrase,INT saveSSID,CHAR * eapIdentity,CHAR * carootcert,CHAR * clientcert,CHAR * privatekey);

/**
 * @brief Starts the process of disconnection between the client and an access point
 *
 * @param[in] ssidIndex The index of SSID array
 * @param[in] AP_SSID   The ssid to disconnect
 *
 * @return INT - The status of the operation
 * @retval RETURN_OK if successful
 * @retval RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @pre wifi_disconnectEndpoint_callback_register() should be called before calling this API
 * @see wifi_connectEndpoint(), wifi_disconnectEndpoint_callback()
 * @note On successfull disconnect, wifi_disconnectEndpoint_callback() will be called
 */
INT wifi_disconnectEndpoint(INT ssidIndex, CHAR *AP_SSID);

/**
 * @brief Clears the SSID information
 * 
 * This function clears the SSID info which was saved as a result of using #wifi_connectEndpoint() 
 * and disconnects from existing WiFi connection.
 * 
 * @param[in] ssidIndex The index of SSID array
 *
 * @return INT - The status of the operation
 * @retval RETURN_OK if successful
 * @retval RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 */
INT wifi_clearSSIDInfo(INT ssidIndex);

/**
 * @brief This call back should be registered by caller to receive status updates from HAL in case of a disconnection event
 *
 * @param[in]  ssidIndex The index of SSID array
 * @param[in]  AP_SSID   The ssid to disconnect
 * @param[out] error     An enum variable that indicates the Wi-Fi connection status
 *
 * possible error values:
 * - WIFI_HAL_ERROR_NOT_FOUND      WPS connection timeout, WPS overlap detects, SSID not found in last scan
 * - WIFI_HAL_SUCCESS              Successfully disconnected from BSSID
 * - WIFI_HAL_ERROR_SSID_CHANGED   SSID change
 * 
 * @return INT - The status of the operation
 * @retval RETURN_OK if successful
 * @retval RETURN_ERR if any error is detected
 * 
 * @pre wifi_disconnectEndpoint_callback_register() should be called before calling this API
 * @see wifiStatusCode_t, wifi_cancelWpsPairing()
 * @todo merge wifi_connectEndpoint_callback() wifi_disconnectEndpoint_callback() into a single wifi_status_callback() in next phase
 */
typedef INT (*wifi_disconnectEndpoint_callback)(INT ssidIndex, CHAR *AP_SSID, wifiStatusCode_t *error);

/**
 * @brief Disconnect Callback registration function
 *
 * @param[in] callback_proc the callback function to disconnect the client
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_connectEndpoint_callback_register()
 * @todo merge wifi_connectEndpoint_callback() wifi_disconnectEndpoint_callback() into a single wifi_status_callback() in next phase
 */
void wifi_disconnectEndpoint_callback_register(wifi_disconnectEndpoint_callback callback_proc);

/**
 * @brief This call back will be invoked when client automatically connect to access point
 *
 * @param[in]  ssidIndex The index of SSID array
 * @param[in]  AP_SSID   The ssid to connect
 * @param[out] error     An enum variable that indicates the Wi-Fi connection status
 * 
 * possible error values:
 * - WIFI_HAL_CONNECTING                  WPS connection in progress, connec to specific SSID
 * - WIFI_HAL_SUCCESS                     Successfully connected to BSSID
 * - WIFI_HAL_ERROR_CONNECTION_FAILED     SSID disabled
 * - WIFI_HAL_ERROR_INVALID_CREDENTIALS   Wrong key, Password may not be falling within spec   
 * - WIFI_HAL_ERROR_AUTH_FAILED           Authentication failed           
 *
 * @return INT - The status of the operation
 * @retval RETURN_OK if successful
 * @retval RETURN_ERR if any error is detected
 * 
 * @pre wifi_connectEndpoint_callback_register() should be called before calling this API
 * @see wifiStatusCode_t, wifi_connectEndpoint(), wifi_setCliWpsEnrolleePin(), wifi_setCliWpsButtonPush()
 * @todo merge wifi_connectEndpoint_callback() wifi_disconnectEndpoint_callback() into a single wifi_status_callback() in next phase
 */
typedef INT (*wifi_connectEndpoint_callback)(INT ssidIndex, CHAR *AP_SSID, wifiStatusCode_t *error);

/**
 * @brief Connect Callback registration function
 *
 * @param[in] callback_proc The callback function to connect the client to the access point
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_disconnectEndpoint_callback_register()
 * @todo merge wifi_connectEndpoint_callback() wifi_disconnectEndpoint_callback() into a single wifi_status_callback() in next phase
 */
void wifi_connectEndpoint_callback_register(wifi_connectEndpoint_callback callback_proc);

/**
 * @brief Telemetry callbacks registration function
 * 
 * @param[in] telemetry_ops Telemetry callback functions
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_telemetry_ops_t, wifi_telemetry_ops_t.init(), wifi_telemetry_ops_t.event_s(), wifi_telemetry_ops_t.event_d()
 * @todo revisit telemetry requirement to move out of WiFi-HAL in next phase
 * @note telemetry requirement to be moved out of WiFi-HAL in next phase
 */
void wifi_telemetry_callback_register(wifi_telemetry_ops_t *telemetry_ops);

/**
 * @brief Provides the last connected SSID information
 *
 * @param[out] pairedSSIDInfo Structure which holds the last connected SSID information
 *
 * @return INT - The status of the operation
 * @retval RETURN_OK   - if successful
 * @retval RETURN_ERR  - if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_pairedSSIDInfo_t, wifi_connectEndpoint()
 */
INT wifi_lastConnected_Endpoint(wifi_pairedSSIDInfo_t *pairedSSIDInfo);

/**
 * @brief Sets the roaming control parameters
 *
 * @param[in] ssidIndex         The index of the SSID
 * @param[in] pRoamingCtrl_data Structure with roaming control parameters
 *
 * @returns INT - The status of the operation
 * @retval RETURN_OK   - if successful
 * @retval RETURN_ERR  - if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_roamingCtrl_t, wifi_getRoamingControl()
 */
INT wifi_setRoamingControl(int ssidIndex, wifi_roamingCtrl_t *pRoamingCtrl_data);

/**
 * @brief Gets the roaming control parameters
 *
 * @param[in] ssidIndex          The index of the SSID
 * @param[out] pRoamingCtrl_data Structure with roaming control parameters 
 *
 * @returns INT - The status of the operation
 * @retval RETURN_OK   - if successful
 * @retval RETURN_ERR  - if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_roamingCtrl_t, wifi_setRoamingControl()
 */
INT wifi_getRoamingControl(int ssidIndex, wifi_roamingCtrl_t *pRoamingCtrl_data);

/**
 * @brief Gets the current wifi status
 *
 * @returns WiFiHalStatus_t - wifi status code
 * @retval WIFISTATUS_HAL_DISCONNECTED          - Disconnected from the AP
 * @retval WIFISTATUS_HAL_INTERFACE_DISABLED    - Interface disabled
 * @retval WIFISTATUS_HAL_INACTIVE              - Inactive
 * @retval WIFISTATUS_HAL_SCANNING              - Scanning for list of available SSIDs
 * @retval WIFISTATUS_HAL_AUTHENTICATING        - Authenticating 
 * @retval WIFISTATUS_HAL_ASSOCIATING           - Associating to the AP
 * @retval WIFISTATUS_HAL_ASSOCIATED            - Associated
 * @retval WIFISTATUS_HAL_4WAY_HANDSHAKE        - 4-way handshake
 * @retval WIFISTATUS_HAL_GROUP_HANDSHAKE       - Group handshake
 * @retval WIFISTATUS_HAL_COMPLETED             - Completed and connected to AP
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @todo Need to change the function name to wifi_getwifiStatusCode() from getwifiStatusCode()
 * @todo This is used only by RDKC need to be revisited with RDKC team 
 * @note Implementation of this API is not required as it is currently being used only by end-of-development cameras
 */
WiFiHalStatus_t getwifiStatusCode();

/**
 * @brief This API cancels any in-progress WPS operation
 *
 * @returns INT - The status of the operation
 * @retval RETURN_OK   - if successful
 * @retval RETURN_ERR  - if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_setCliWpsButtonPush(), wifi_setCliWpsEnrolleePin(), wifi_disconnectEndpoint_callback()
 */
INT wifi_cancelWpsPairing();

/** @} */ // End of WIFI_CLIENT_HAL
/** @} */ // End of WIFI_HAL
#else
#error "! __WIFI_CLIENT_HAL_H__"
#endif
