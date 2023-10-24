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

/********************************************************************

    module: wifi_client_hal.h

    ---------------------------------------------------------------
    description:

        This header file gives the function call prototypes and
        structure definitions used for the RDK-Video
        WiFi client hardware abstraction layer

    ---------------------------------------------------------------

    environment:

        This HAL layer is intended to support WiFi drivers
        through an open API

*********************************************************************/
#ifndef __WIFI_CLIENT_HAL_H__
#define __WIFI_CLIENT_HAL_H__

/**
 * @addtogroup HPK Hardware Porting Kit
 * @{
 * @defgroup RDKV_WIFI RDK-V WiFi
 * @{
 * @defgroup RDKV_WIFI_HAL WiFi HAL
 * @{
 * @defgroup WIFI_CLIENT_HAL WiFi Client HAL
 * @{
 * WiFi Client HAL provides an interface (data structures and API) to interact with underlying WiFi driver and
 * enabling the client to be connected with an access point.
 */

/**
 * @file wifi_client_hal.h
 */

#include <wifi_common_hal.h>

/*
 * @note ssidIndex across APIs is not being used it will be revisited in next phase 
 * @todo ssidIndex across APIs is not being used it will be revisited in next phase
 */

/*
 * @struct _wifi_pairedSSIDInfo
 * @brief Structure for SSID information
 *
 * This structure stores the paired SSID information
 */
typedef struct _wifi_pairedSSIDInfo
{
  CHAR  ap_ssid[64];          /**< The current service set identifier in use by the neighboring WiFi SSID. The value MAY be empty for hidden SSID. SSID can be any string up to 32 characters in length, including 0 length */
  CHAR  ap_bssid[64];         /**< [MACAddress] The BSSID (Basic Service Set ID) used for the neighboring WiFi SSID {Valid values: empty string} */
  CHAR  ap_security[64];      /**< Security mode of AP. Possible values {"NONE", "WPA-NONE", "WPA-PSK", "WPA-EAP", "IEEE8021X", "FT-PSK", "FT-EAP", "FT-EAP-SHA384", "WPA-PSK-SHA256", "WPA-EAP-SHA256", "SAE", "FT-SAE", "WPA-EAP-SUITE-B", "WPA-EAP-SUITE-B-192", "OSEN", "FILS-SHA256", "FILS-SHA384", "FT-FILS-SHA256", "FT-FILS-SHA384", "OWE", "DPP"} */
  CHAR  ap_passphrase[128];   /**< Passphrase of AP, if applicable for the security mode. ASCII passphrase will be minimum 8 characters long and maximum 63 characters long. */
  CHAR  ap_wep_key[128];      /**< wep_key of AP incase of WEP security. An ASCII string enclosed in quotation marks to encode the WEP key. Without quotes this is a hex string of the actual key. */
}wifi_pairedSSIDInfo_t;

/**
 * @struct _wifi_roamingCtrl_t
 * @brief Structure for roaming control information
 * @todo The 802.11 kvr feature has to be supported and enabled by default. This data structure will be removed in next phase.
 * @note The 802.11 kvr feature has to be supported and enabled by default. This data structure will be removed in next phase.
 */
typedef struct _wifi_roamingCtrl_t
{
  BOOL roamingEnable;                          /**< Enables or disables the roaming control {0-disable, 1-enable} */
  BOOL selfSteerOverride;                      /**< Starts self steer roaming if selfSteerOverride is enabled {0-disable, 1-enable} */
  BOOL roam80211kvrEnable;                     /**< Sets roaming mode to AP steer if roam80211kvrEnable is enabled and selfSteerOverride is disabled {0-disable, 1-enable} */
  INT preassnBestThreshold;                    /**< Pre-association best RSSI threshold. Default value -67. Range is [-100, 0] */
  INT preassnBestDelta;                        /**< Pre-association best RSSI delta between 2.4GHz and 5GHz. Default value 3. Range is [0, 100] */
  INT postAssnLevelDeltaConnected;             /**< Post-association delta level if WiFi connected. Default value 12. Range is [0, 100] */
  INT postAssnLevelDeltaDisconnected;          /**< Post-association delta level if WiFi disconnected. Default value 8. Range is [0, 100] */
  INT postAssnSelfSteerThreshold;              /**< Post-association self steer threshold. Default value -75. Range is [-100, 0] */
  INT postAssnSelfSteerTimeframe;              /**< Post-association self steer timeframe. Default value 60. Range is [0, 36000] seconds */
  INT postAssnBackOffTime;                     /**< Post-association backoff time for incrementing self steer time-frame during failure of roaming attempts. Default value 2 seconds. Range is [0, 3600] seconds */
  INT postAssnAPctrlThreshold;                 /**< Post-association AP steer control threshold. Default value -75. Range is [-100, 0] */
  INT postAssnAPctrlTimeframe;                 /**< Post-association AP steer control time frame. Default value 60. Range is [0, 60] seconds */

}wifi_roamingCtrl_t;

/**
 * @struct _wifi_telemetry_ops_t
 *
 * @brief Structure for telemetry callback functions
 * @todo revisit telemetry requirement to move out of WiFi-HAL in next phase
 */
typedef struct _wifi_telemetry_ops_t
{
    void (*init)(char *name);                   /**< init telemetry callback function */
    void (*event_s)(char *marker, char *value); /**< callback funtion to event a string telemetry marker */
    void (*event_d)(char *marker, int value);   /**< callback funtion to event an integer telemetry marker */
} wifi_telemetry_ops_t;

/**
 * @brief Gets WPS configuration methods supported by the device
 *
 * This function provides the comma-separated list of strings. For example:
 * - "USBFlashDrive"      - User uses a USB flash drive to transfer data between the new client device and
 * the network's access point
 * - "Ethernet"           - If there is no WPS button, user can configure the wireless settings using ethernet on a wifi-extender
 * - "ExternalNFCToken"   - NFC Tag contains a password token to authenticate WiFi connection
 * Uses external program to write  * NDEF encapsulation data to the NFC tag using an external program
 * - "IntegratedNFCToken" - The NFC Tag is integrated in the device
 * - "NFCInterface"       - User has to bring the client close to AP allowing a near field communication between the devices
 * - "PushButton"         - User has to push a button, either an actual or virtual one
 *                          on both the access point and the new wireless * client device
 * - "PIN"                - User has to be read the PIN from either a sticker or display on the new wireless device
 *
 * @param[in]  ssidIndex The index of SSID array {Valid values: 1}
 * @param[out] methods   The WPS supported methods as a comma-separated string.Refer @ref Data-Model parameter for the complete set of supported methods {Ex: "PushButton,PIN"}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 *
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.EndPoint.{i}.WPS.ConfigMethodsSupported
 * @todo Need more review on the ConfigMethodsSupported for this module in next phase
 */
INT wifi_getCliWpsConfigMethodsSupported(INT ssidIndex, CHAR *methods);

/**
 * @brief Gets WPS configuration methods enabled on the device
 *
 * This function provides the comma-separated list of strings.
 * Each list item MUST be a member of the list reported by the ConfigMethodsSupported parameter.
 *
 * @param[in]  ssidIndex      The index of SSID array {Valid values: 1}
 * @param[out] output_string  The current WPS methods as a comma-separated string. 
 * Refer @ref Data-Model parameter for the complete set of supported methods 
 * possible values {"USBFlashDrive", "Ethernet", "ExternalNFCToken", "IntegratedNFCToken", "NFCInterface", "PushButton", "PIN" }
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_getCliWpsConfigMethodsSupported(), wifi_setCliWpsConfigMethodsEnabled()
 * @see @ref Data-Model Parameter: Device.WiFi.EndPoint.{i}.WPS.ConfigMethodsEnabled
 */
INT wifi_getCliWpsConfigMethodsEnabled(INT ssidIndex, CHAR *output_string);

/**
 * @brief Sets the active WPS methods
 *
 * @param[in] ssidIndex    The index of SSID array {Valid values: 1}
 * @param[in] methodString The methods to enable as a comma-separated string.
 * Refer @ref Data-Model parameter for the complete set of supported methods 
 * possible values {"USBFlashDrive", "Ethernet", "ExternalNFCToken", "IntegratedNFCToken", "NFCInterface", "PushButton", "PIN" }
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_getCliWpsConfigMethodsSupported(), wifi_getCliWpsConfigMethodsEnabled()
 * @see @ref Data-Model Parameter: Device.WiFi.EndPoint.{i}.WPS.ConfigMethodsEnabled
 */
INT wifi_setCliWpsConfigMethodsEnabled(INT ssidIndex, CHAR *methodString);

/**
 * @brief Sets the WPS PIN and uses it to pair with access point
 *
 * @param[in] ssidIndex   The index of SSID array {Valid values: 1}
 * @param[in] EnrolleePin PIN code to connect to the access point. This PIN is either a four digit number or an eight digit number
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 *
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @pre wifi_connectEndpoint_callback_register() should be called before calling this API
 * @see wifi_connectEndpoint_callback(), wifi_cancelWpsPairing()
 * @see @ref Data-Model Parameter: Device.WiFi.EndPoint.{i}.WPS.PIN
 * @todo EnrolleePin will be revisited in next phase
 */
INT wifi_setCliWpsEnrolleePin(INT ssidIndex, CHAR *EnrolleePin);

/**
 * @brief Starts the WPS Push button pairing with access point
 *
 * @param[in] ssidIndex The index of SSID array variable is unused {Valid values: 1}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @pre wifi_connectEndpoint_callback_register() should be called before calling this API
 * @see wifi_connectEndpoint_callback(), wifi_cancelWpsPairing()
 */
INT wifi_setCliWpsButtonPush(INT ssidIndex);

/**
 * @brief Starts the process of connection between the client and an access point
 *
 * @param[in] ssidIndex                 The index of SSID array {Valid values: 1}
 * @param[in] AP_SSID                   The ssid to connect. SSID can be any string up to 32 characters in length, including 0 length
 * @param[in] AP_security_mode          The security mode to use
 * @param[in] AP_security_WEPKey        The wep key. An ASCII string enclosed in quotation marks to encode the WEP key. Without quotes this is a hex string of the actual key.
 * @param[in] AP_security_PreSharedKey  The pre shared key. ASCII pre shared key will be minimum 8 characters long and maximum 63 characters long
 * @param[in] AP_security_KeyPassphrase The key passphrase. ASCII passphrase will be minimum 8 characters long and maximum 63 characters long
 * @param[in] saveSSID                  Specifies whether or not to save the WiFi configuration on a successfull connect {0-false,1-true}
 * @param[in] eapIdentity               EAP identity name. Valid characters are {[a-z], [A-Z], [0-9], '-', '_', '.', ',', '@', '\\', '!', '#', '%', '=', ' '}
 * @param[in] carootcert                Absolute file path to CA root certificate
 * @param[in] clientcert                Absolute file path to client certificate
 * @param[in] privatekey                Absolute file path to private key
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 *  
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @pre wifi_connectEndpoint_callback_register() should be called before calling this API
 * @see wifiSecurityMode_t, wifi_disconnectEndpoint(), wifi_connectEndpoint_callback()
 * @note On successfull connect, wifi_connectEndpoint_callback() will be called
 * @todo Consider to define and use a data structure for input parameter in next phase
 */
INT wifi_connectEndpoint(INT ssidIndex, CHAR *AP_SSID, wifiSecurityMode_t AP_security_mode, CHAR *AP_security_WEPKey, CHAR *AP_security_PreSharedKey, CHAR *AP_security_KeyPassphrase,INT saveSSID,CHAR *eapIdentity,CHAR *carootcert,CHAR *clientcert,CHAR *privatekey);

/**
 * @brief Starts the process of disconnection between the client and an access point
 *
 * @param[in] ssidIndex The index of SSID array {Valid values: 1}
 * @param[in] AP_SSID   The ssid to disconnect
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
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
 * @param[in] ssidIndex The index of SSID array {Valid values: 1}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 */
INT wifi_clearSSIDInfo(INT ssidIndex);

/**
 * @brief Receives status updates from HAL in case of a disconnection event
 *
 * This callback should be registered by caller to receive status updates from HAL in case of a disconnection event.
 *
 * @param[in]  ssidIndex The index of SSID array
 * @param[in]  AP_SSID   The ssid to disconnect
 * @param[out] error     An enum variable that indicates the Wi-Fi connection status @n
 *                       Possible error values:
 *                       - WIFI_HAL_ERROR_NOT_FOUND    - WPS connection timeout, WPS overlap detects, SSID not found in last scan
 *                       - WIFI_HAL_SUCCESS            - Successfully disconnected from BSSID
 *                       - WIFI_HAL_ERROR_SSID_CHANGED - SSID changed
 * 
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_disconnectEndpoint_callback_register() should be called before calling this API
 * @see wifiStatusCode_t, wifi_cancelWpsPairing()
 * @todo merge wifi_connectEndpoint_callback() wifi_disconnectEndpoint_callback() into a single wifi_status_callback() in next phase
 */
typedef INT (*wifi_disconnectEndpoint_callback)(INT ssidIndex, CHAR *AP_SSID, wifiStatusCode_t *error);

/**
 * @brief Registers for disconnect callback
 *
 * @param[in] callback_proc the callback function to disconnect the client
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_connectEndpoint_callback_register()
 * @todo merge wifi_connectEndpoint_callback() wifi_disconnectEndpoint_callback() into a single wifi_status_callback() in next phase
 */
void wifi_disconnectEndpoint_callback_register(wifi_disconnectEndpoint_callback callback_proc);

/**
 * @brief Receives status updates from HAL in case of a connection event
 *
 * This callback will be invoked when client automatically connect to access point
 *
 * @param[in]  ssidIndex The index of SSID array
 * @param[in]  AP_SSID   The ssid to connect
 * @param[out] error     An enum variable that indicates the Wi-Fi connection status @n
 *                       Possible error values:
 *                       - WIFI_HAL_CONNECTING                - WPS connection in progress, connect to specific SSID
 *                       - WIFI_HAL_SUCCESS                   - Successfully connected to BSSID
 *                       - WIFI_HAL_ERROR_CONNECTION_FAILED   - SSID disabled
 *                       - WIFI_HAL_ERROR_INVALID_CREDENTIALS - Wrong key, Password may not be falling within spec  
 *                       - WIFI_HAL_ERROR_AUTH_FAILED         - Authentication failed    
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_connectEndpoint_callback_register() should be called before calling this API
 * @see wifiStatusCode_t, wifi_connectEndpoint(), wifi_setCliWpsEnrolleePin(), wifi_setCliWpsButtonPush()
 * @todo merge wifi_connectEndpoint_callback() wifi_disconnectEndpoint_callback() into a single wifi_status_callback() in next phase
 */
typedef INT (*wifi_connectEndpoint_callback)(INT ssidIndex, CHAR *AP_SSID, wifiStatusCode_t *error);

/**
 * @brief Registers for connect callback
 *
 * @param[in] callback_proc The callback function to connect the client to the access point
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_disconnectEndpoint_callback_register()
 * @todo merge wifi_connectEndpoint_callback() wifi_disconnectEndpoint_callback() into a single wifi_status_callback() in next phase
 */
void wifi_connectEndpoint_callback_register(wifi_connectEndpoint_callback callback_proc);

/**
 * @brief Registers for Telemetry callback
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
 * @return #INT - The status of the operation
 * @retval #RETURN_OK   - if successful
 * @retval #RETURN_ERR  - if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_pairedSSIDInfo_t, wifi_connectEndpoint()
 */
INT wifi_lastConnected_Endpoint(wifi_pairedSSIDInfo_t *pairedSSIDInfo);

/**
 * @brief Sets the roaming control parameters
 *
 * @param[in] ssidIndex         The index of the SSID {Valid values: 1}
 * @param[in] pRoamingCtrl_data Structure with roaming control parameters
 *
 * @returns INT - The status of the operation
 * @retval #RETURN_OK   - if successful
 * @retval #RETURN_ERR  - if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_roamingCtrl_t, wifi_getRoamingControl()
 */
INT wifi_setRoamingControl(int ssidIndex, wifi_roamingCtrl_t *pRoamingCtrl_data);

/**
 * @brief Gets the roaming control parameters
 *
 * @param[in] ssidIndex          The index of the SSID {Valid values: 1}
 * @param[out] pRoamingCtrl_data Structure with roaming control parameters 
 *
 * @returns INT - The status of the operation
 * @retval #RETURN_OK   - if successful
 * @retval #RETURN_ERR  - if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_roamingCtrl_t, wifi_setRoamingControl()
 */
INT wifi_getRoamingControl(int ssidIndex, wifi_roamingCtrl_t *pRoamingCtrl_data);

/**
 * @brief Cancels any in-progress WPS operation
 *
 * @returns INT - The status of the operation
 * @retval #RETURN_OK   - if successful
 * @retval #RETURN_ERR  - if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_setCliWpsButtonPush(), wifi_setCliWpsEnrolleePin(), wifi_disconnectEndpoint_callback()
 */
INT wifi_cancelWpsPairing();

/** @} */ // End of WIFI_CLIENT_HAL
/** @} */ // End of RDKV_WIFI_HAL
/** @} */ // End of RDKV_WIFI
/** @} */ // End of HPK
#else
#error "! __WIFI_CLIENT_HAL_H__"
#endif
