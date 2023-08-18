/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
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

    module: wifi_common_hal.h

    ---------------------------------------------------------------

    description:

        This header file gives the function call prototypes and
        structure definitions used for the RDK-Video
        Wifi radio hardware abstraction layer

    ---------------------------------------------------------------

    environment:

        This HAL layer is intended to support Wifi drivers
        through an open API.

    ---------------------------------------------------------------

    HAL version:

        The version of the Wifi HAL is specified in #defines below.

**********************************************************************/

#ifndef __WIFI_COMMON_HAL_H__
#define __WIFI_COMMON_HAL_H__

/**
 * @addtogroup HPK HPK
 *
 * @section WIFI_GLOSSARY Glossary of terms
 *
 * Abbreviations | Description
 * -----|------------
 * Access Popint | A device that acts as the bridge between wireless clients and the wired network. Often abbreviated as AP.
 * AES | The Advanced Encryption Standard is a symmetric block encryption protocol used in WPA2.
 * BSSID | BSSID stands for Basic Service Set Identifier and is the MAC address of the AP.
 * EAP | The Extensible Authentication Protocol (EAP) can be used to provide authentication to the wireless network when employing WPA-Enterprise and WPA2-Enterprise.
 * SSID | The Service Set Identifier (SSID) is the name of the wireless network. It can be contained in the beacons sent out by APs.
 * ESSID | The Extended Service Set Identifier is the name of the wireless network, and is used by all APs that provide access to the same infrastructure in an ESS.
 * ESS | An extended service set (ESS) refers to a network with two or more APs working cooperatively.
 * QoS | Quality of Service enables networks to prioritize certain traffic types.
 * CCMP | Cipher Block Chaining Message Authentication Code Protocol (CCMP) is an encryption protocol that forms part of the wireless standard local area networks.
 * STA | Wireless Station.
 *
 * @section WIFI_STANDARD Wi-Fi Standards
 * IEEE Standards for Wireless, 802.11 is the set of standards maintained by the IEEE for wireless networking.
 *
 * Abbreviations | Description
 * -----|------------
 * 802.11a |  In the 5 GHz range. 802.11a networks can support up to 54 Mbps throughput and operate in the UNII bands
 * 802.11ac |  In the 5 GHz range. 802.11ac networks can support up to 1 Gbps throughput using multiple channels.
 * 802.11b |  In the 2.4 GHz range. 802.11b networks support up to 11 Mbps throughput and operate in the ISM band.
 * 802.11d |  Addresses the Media Access Control (MAC) layer to comply with rules in each country.
 * 802.11g |  In the 2.4 GHz range. 802.11g networks support up to 54 Mbps throughput and operate in the ISM band.
 * 802.11h |  Sets the requirements for Dynamic Frequency Selection (DFS) and Transmit Power Control (TPC).
 * 802.11n |  Can use both the 2.4 GHz and 5 GHz ranges.
 *
 *
 * @section WIFI_SECURITY Wireless Security
 *
 * Abbreviations | Description
 * -----|------------
 * Ad Hoc Mode | A peer to peer mode of networking using Wi-Fi networking but no access point. Ad Hoc networks can include more than two devices.
 * WAP | WAP can refer to the Wireless Application Protocol, or can be used to mean Wireless Access Point.
 * WEP | Wired Equivalent Privacy is the original encryption scheme implemented in wireless networks
 * WPA | Wi-Fi Protected Access is a security protocol for wireless networks that was designed to replace WEP. It uses TKIP to encrypt data.
 * WPA2 | Wi-Fi Protected Access v2 is currently the strongest encryption protocol available to wireless networks. It uses AES encryption algorithm.
 * WPS | Wi-Fi Protected Setup makes it easier for users to add Wi-Fi clients to WPA and WPA2 protected wireless networks.
 * TKIP | The Temporal Key Integrity Protocol was developed as a replacement for WEP but is no longer considered secure and has been removed from 802.11 standards.
 * TLS | Transport Layer Security is a protocol designed to encrypt and authenticate all kinds of network traffic at the trans port layer, and is the successor to SSL.
 *
 * @defgroup WIFI_HAL Wi-Fi HAL
 *
 * @ingroup HPK
 *
 * @defgroup WIFI_HAL_COMMON_API Wi-Fi Common HAL API List
 * @ingroup WIFI_HAL
 *
 * @defgroup WIFI_HAL_TYPES Wi-Fi HAL Data Structure
 * @ingroup WIFI_HAL
 */


/**
 * @addtogroup WIFI_HAL_TYPES
 * @{
 */

/**
 * @brief Defines for the basic data types.
 */
#ifndef ULONG
#define ULONG unsigned long
#endif

#ifndef BOOL
#define BOOL  unsigned char //!< unsigned char bool
#endif

#ifndef CHAR
#define CHAR  char //!< char
#endif

#ifndef UCHAR
#define UCHAR unsigned char //!< unsigned char
#endif

#ifndef INT
#define INT   int //!< int
#endif

#ifndef UINT
#define UINT  unsigned int //!<insigned int
#endif

#ifndef FLOAT
#define FLOAT  float //!< float
#endif

/**
 * @brief Defines for TRUE/FALSE/ENABLE flags
 */
#ifndef TRUE
#define TRUE     1 //!< true 1
#endif

#ifndef FALSE
#define FALSE    0 //!< false 0
#endif

#ifndef ENABLE
#define ENABLE   1 //!< enable 1
#endif

/**
 * @brief Defines for function returns
 *
 * RETURN_OK Return value for the success case
 * RETURN_ERR Return value for the failure case
 *
 */
#ifndef RETURN_OK
#define RETURN_OK   0 //!< return ok
#endif

#ifndef RETURN_ERR
#define RETURN_ERR   -1 //!< return err
#endif


#ifndef RADIO_INDEX_1
#define RADIO_INDEX_1 1 //!< radio index 1
#define RADIO_INDEX_2 2 //!< radio index 2
#define AP_INDEX_1 1 //!< AP index 1
#define AP_INDEX_2 2 //!< AP index 2
#define AP_INDEX_3 3 //!< AP index 3
#define AP_INDEX_4 4 //!< AP index 4
#define AP_INDEX_5 5 //!< AP index 5
#define AP_INDEX_6 6 //!< AP index 6
#define AP_INDEX_7 7 //!< AP index 7
#define AP_INDEX_8 8 //!< AP index 8
#define AP_INDEX_9 9 //!< AP index 9
#define AP_INDEX_10 10 //!< AP index 10
#define AP_INDEX_11 11 //!< AP index 11
#define AP_INDEX_12 12 //!< AP index 12
#define AP_INDEX_13 13 //!< AP index 13
#define AP_INDEX_14 14 //!< AP index 14
#define AP_INDEX_15 15 //!< AP index 15
#define AP_INDEX_16 16  //!< AP index 16
#endif

/**
 * @brief Defines for HAL version 2.0.0
 * @todo Anjali will check on HAL version really needed or not
 */
#define WIFI_HAL_MAJOR_VERSION 2         //!<  This is the major version of this HAL.
#define WIFI_HAL_MINOR_VERSION 0         //!<  This is the minor version of the HAL.
#define WIFI_HAL_MAINTENANCE_VERSION 0   //!<  This is the maintenance version of the HAL.

/**
 * @brief Defines for iface name size
 */
#define WLAN_IFNAMSIZ 32

/**
 * @brief Enumerators for Wifi RSSI Levels
 */
typedef enum {
    WIFI_RSSI_NONE = 0,      //!< No signal (0 bar)
    WIFI_RSSI_POOR,          //!< Poor (1 bar)
    WIFI_RSSI_FAIR,          //!< Fair (2 bars)
    WIFI_RSSI_GOOD,          //!< Good (3 bars)
    WIFI_RSSI_EXCELLENT,     //!< Excellent (4 bars)
    WIFI_RSSI_MAX
} wifiRSSILevel_t;

/**
 * @brief wifi wpa supplicant status codes
 * @todo TO BE CHECKED NOW Devika will check this enum is needed or not
 */
typedef enum _WiFiHalStatus_t {
    WIFISTATUS_HAL_DISCONNECTED,          //!< Disconnected to the AP
    WIFISTATUS_HAL_INTERFACE_DISABLED,    //!< Interface disabled
    WIFISTATUS_HAL_INACTIVE,              //!< Inactive
    WIFISTATUS_HAL_SCANNING,              //!< Scanning for list of available SSID's
    WIFISTATUS_HAL_AUTHENTICATING,        //!< Authenticating 
    WIFISTATUS_HAL_ASSOCIATING,           //!< Associating to the AP
    WIFISTATUS_HAL_ASSOCIATED,            //!< Associated
    WIFISTATUS_HAL_4WAY_HANDSHAKE,        //!< 4 way handshake
    WIFISTATUS_HAL_GROUP_HANDSHAKE,       //!< Group hand shake
    WIFISTATUS_HAL_COMPLETED              //!< Completed and connected to AP
} WiFiHalStatus_t;

/**
 * @brief WiFi Bands
 */
typedef enum {
    WIFI_HAL_FREQ_BAND_ERROR,     //!< No frequency band 
    WIFI_HAL_FREQ_BAND_24GHZ,     //!< 2.4Ghz frequency band
    WIFI_HAL_FREQ_BAND_5GHZ,      //!< 5Ghz frequency band
} WIFI_HAL_FREQ_BAND;


/**
 * @brief Enumerators for Wi-Fi connection status.
 */
typedef enum {
    WIFI_HAL_SUCCESS = 0,                    /**< Successful connect/disconnect */
    WIFI_HAL_CONNECTING,                     /**< Attempting to connect to a Network/AP using wps or SSID selection*/
    WIFI_HAL_DISCONNECTING = 10,             /**< Attempting to disconnect to a Network/AP */

    /* Failure/Error Codes*/
    WIFI_HAL_ERROR_NOT_FOUND = 20,           /**< Device/AP not found*/
    WIFI_HAL_ERROR_TIMEOUT_EXPIRED,          /**< Timeout expired */
    WIFI_HAL_ERROR_DEV_DISCONNECT,           /**< Failed/Error in Device/AP Disconnect */
    WIFI_HAL_ERROR_SSID_CHANGED,             /**< the SSID of the network changed */
    WIFI_HAL_ERROR_CONNECTION_LOST,          /**< the connection to the network was lost */
    WIFI_HAL_ERROR_CONNECTION_FAILED,        /**< the connection failed for an unknown reason */
    WIFI_HAL_ERROR_CONNECTION_INTERRUPTED,   /**< the connection was interrupted */
    WIFI_HAL_ERROR_INVALID_CREDENTIALS,      /**< the connection failed due to invalid credentials */
    WIFI_HAL_UNRECOVERABLE_ERROR,            /**< The device has encountered an unrecoverable (driver or hardware failures) errors */
    WIFI_HAL_ERROR_AUTH_FAILED,              /**< the connection failed due to authentication failure */
    WIFI_HAL_ERROR_UNKNOWN = 40,             /**< Unknown/unspecified error */
} wifiStatusCode_t;

/**
 * @brief Wifi Security modes
 *
 * Security modes are used to prevent the unauthorized access or damage to computers using wireless networks.
 * Wired Equivalent Privacy (WEP), Wi-Fi Protected Access (WPA), and Wi-Fi Protected Access II (WPA2) are the
 * primary security algorithms.
 * WEP is the oldest and has proven to be vulnerable as more and more security flaws have been discovered.
 * WPA improved security, but is now also considered vulnerable to intrusion.
 *
 */
typedef enum
{
    WIFI_SECURITY_NONE = 0,               //!< No Security
    WIFI_SECURITY_WEP_64,                 //!< WEP with 64 bit encryption
    WIFI_SECURITY_WEP_128,                //!< WEP with 128 bit encryption
    WIFI_SECURITY_WPA_PSK_TKIP,           //!< WPA(Pre-Shared Key) with TKIP (Temporal Key Integrity Protocol) encryption
    WIFI_SECURITY_WPA_PSK_AES,            //!< WPA(Pre-Shared Key) with AES (Advanced Encryption Standard) encryption
    WIFI_SECURITY_WPA2_PSK_TKIP,          //!< WPA2(Pre-Shared Key) with TKIP (Temporal Key Integrity Protocol) encryption
    WIFI_SECURITY_WPA2_PSK_AES,           //!< WPA2(Pre-Shared Key) with AES (Advanced Encryption Standard) encryption
    WIFI_SECURITY_WPA_ENTERPRISE_TKIP,    //!< WPA Enterprise  with  TKIP (Temporal Key Integrity Protocol) encryption
    WIFI_SECURITY_WPA_ENTERPRISE_AES,     //!< WPA Enterprise with AES (Advanced Encryption Standard) encryption
    WIFI_SECURITY_WPA2_ENTERPRISE_TKIP,   //!< WPA2 Enterprise with TKIP (Temporal Key Integrity Protocol) encryption
    WIFI_SECURITY_WPA2_ENTERPRISE_AES,    //!< WPA2 Enterprise with AES (Advanced Encryption Standard) encryption
    WIFI_SECURITY_WPA_WPA2_PSK,           //!< WPA2(Pre-Shared Key) with TKIP AES encryption
    WIFI_SECURITY_WPA_WPA2_ENTERPRISE,    //!< WPA,WPA2 Enterprise with TKIP AES encryption
    WIFI_SECURITY_WPA3_PSK_AES,           //!< WPA3(Pre-Shared Key) with AES encryption
    WIFI_SECURITY_WPA3_SAE,               //!< WPA3 with SAE encryption

    WIFI_SECURITY_NOT_SUPPORTED = 99,     //!< Security mode not supported
} wifiSecurityMode_t;

/**********************************************************************
                STRUCTURE DEFINITIONS
**********************************************************************/

/**
 * @struct _wifi_radioTrafficStats wifi_common_hal.h "include/wifi_common_hal.h"
 * @brief structure for radioTrafficStats
 */

typedef struct _wifi_radioTrafficStats
{
    ULONG radio_BytesSent;	                     //!< The total number of bytes transmitted out of the interface, including framing characters.
    ULONG radio_BytesReceived;	                 //!< The total number of bytes received on the interface, including framing characters.
    ULONG radio_PacketsSent;	                 //!< The total number of packets transmitted out of the interface.
    ULONG radio_PacketsReceived;                 //!< The total number of packets received on the interface.
    
    ULONG radio_ErrorsSent;	                     //!< The total number of outbound packets that could not be transmitted because of errors.
    ULONG radio_ErrorsReceived;                  //!< The total number of inbound packets that contained errors preventing them from being delivered to a higher-layer protocol.
    ULONG radio_DiscardPacketsSent;              //!< The total number of outbound packets which were chosen to be discarded even though no errors had been detected to prevent their being transmitted. One possible reason for discarding such a packet could be to free up buffer space.
    ULONG radio_DiscardPacketsReceived;          //!< The total number of inbound packets which were chosen to be discarded even though no errors had been detected to prevent their being delivered. One possible reason for discarding such a packet could be to free up buffer space.
    ULONG radio_PLCPErrorCount;	                 //!< The number of packets that were received with a detected Physical Layer Convergence Protocol (PLCP) header error.
    ULONG radio_FCSErrorCount;	                 //!< The number of packets that were received with a detected FCS error. This parameter is based on dot11FCSErrorCount from [Annex C/802.11-2012].
    ULONG radio_InvalidMACCount;	             //!< The number of packets that were received with a detected invalid MAC header error.
    ULONG radio_PacketsOtherReceived;	         //!< The number of packets that were received, but which were destined for a MAC address that is not associated with this interface.
    INT   radio_NoiseFloor; 	                 //!< The noise floor for this radio channel where a recoverable signal can be obtained. Expressed as a signed integer in the range (-110:0).  Measurement should capture all energy (in dBm) from sources other than Wi-Fi devices as well as interference from Wi-Fi devices too weak to be decoded. Measured in dBm
    ULONG radio_ChannelUtilization;              //!< Percentage of time the channel was occupied by the radio’s own activity (Activity Factor) or the activity of other radios.  Channel utilization MUST cover all user traffic, management traffic, and time the radio was unavailable for CSMA activities, including DIFS intervals, etc.  The metric is calculated and updated in this parameter at the end of the interval defined by "Radio Statistics Measuring Interval".  The calculation of this metric MUST only use the data collected from the just completed interval.  If this metric is queried before it has been updated with an initial calculation, it MUST return -1.  Units in Percentage
    INT   radio_ActivityFactor;                  //!< Percentage of time that the radio was transmitting or receiving Wi-Fi packets to/from associated clients. Activity factor MUST include all traffic that deals with communication between the radio and clients associated to the radio as well as management overhead for the radio, including NAV timers, beacons, probe responses,time for receiving devices to send an ACK, SIFC intervals, etc.  The metric is calculated and updated in this parameter at the end of the interval defined by "Radio Statistics Measuring Interval".  The calculation of this metric MUST only use the data collected from the just completed interval.   If this metric is queried before it has been updated with an initial calculation, it MUST return -1. Units in Percentage
    INT   radio_CarrierSenseThreshold_Exceeded;  //!< Percentage of time that the radio was unable to transmit or receive Wi-Fi packets to/from associated clients due to energy detection (ED) on the channel or clear channel assessment (CCA). The metric is calculated and updated in this Parameter at the end of the interval defined by "Radio Statistics Measuring Interval".  The calculation of this metric MUST only use the data collected from the just completed interval.  If this metric is queried before it has been updated with an initial calculation, it MUST return -1. Units in Percentage
    INT   radio_RetransmissionMetirc;            //!< Percentage of packets that had to be re-transmitted. Multiple re-transmissions of the same packet count as one.  The metric is calculated and updated in this parameter at the end of the interval defined by "Radio Statistics Measuring Interval".   The calculation of this metric MUST only use the data collected from the just completed interval.  If this metric is queried before it has been updated with an initial calculation, it MUST return -1. Units  in percentage
    INT   radio_MaximumNoiseFloorOnChannel;      //!< Maximum Noise on the channel during the measuring interval.  The metric is updated in this parameter at the end of the interval defined by "Radio Statistics Measuring Interval".  The calculation of this metric MUST only use the data collected in the just completed interval.  If this metric is queried before it has been updated with an initial calculation, it MUST return -1.  Units in dBm
    INT   radio_MinimumNoiseFloorOnChannel;      //!< Minimum Noise on the channel. The metric is updated in this Parameter at the end of the interval defined by "Radio Statistics Measuring Interval".  The calculation of this metric MUST only use the data collected in the just completed interval.  If this metric is queried before it has been updated with an initial calculation, it MUST return -1. Units in dBm
    INT   radio_MedianNoiseFloorOnChannel;       //!< Median Noise on the channel during the measuring interval.   The metric is updated in this parameter at the end of the interval defined by "Radio Statistics Measuring Interval".  The calculation of this metric MUST only use the data collected in the just completed interval.  If this metric is queried before it has been updated with an initial calculation, it MUST return -1. Units in dBm
    ULONG radio_StatisticsStartTime; 	         //!< The date and time at which the collection of the current set of statistics started.  This time must be updated whenever the radio statistics are reset.

} wifi_radioTrafficStats_t;	//for radio only

/**
 * @struct _wifi_ssidTrafficStats wifi_common_hal.h "include/wifi_common_hal.h"
 * @brief structure for ssidTrafficStats
 */

typedef struct _wifi_ssidTrafficStats
{
    ULONG ssid_BytesSent;	               //!< The total number of bytes transmitted out of the interface, including framing characters.
    ULONG ssid_BytesReceived;	           //!< The total number of bytes received on the interface, including framing characters.
    ULONG ssid_PacketsSent;	               //!< The total number of packets transmitted out of the interface.
    ULONG ssid_PacketsReceived;            //!< The total number of packets received on the interface.

    ULONG ssid_RetransCount;	           //!< The total number of transmitted packets which were retransmissions. Two retransmissions of the same packet results in this counter incrementing by two.
    ULONG ssid_FailedRetransCount;         //!< The number of packets that were not transmitted successfully due to the number of retransmission attempts exceeding an 802.11 retry limit. This parameter is based on dot11FailedCount from [802.11-2012].
    ULONG ssid_RetryCount;                 //!< The number of packets that were successfully transmitted after one or more retransmissions. This parameter is based on dot11RetryCount from [802.11-2012].
    ULONG ssid_MultipleRetryCount;         //!< The number of packets that were successfully transmitted after more than one retransmission. This parameter is based on dot11MultipleRetryCount from [802.11-2012].
    ULONG ssid_ACKFailureCount;            //!< The number of expected ACKs that were never received. This parameter is based on dot11ACKFailureCount from [802.11-2012].
    ULONG ssid_AggregatedPacketCount;      //!< The number of aggregated packets that were transmitted. This applies only to 802.11n and 802.11ac.

    ULONG ssid_ErrorsSent;	               //!< The total number of outbound packets that could not be transmitted because of errors.
    ULONG ssid_ErrorsReceived;             //!< The total number of inbound packets that contained errors preventing them from being delivered to a higher-layer protocol.
    ULONG ssid_UnicastPacketsSent;	       //!< The total number of inbound packets that contained errors preventing them from being delivered to a higher-layer protocol.
    ULONG ssid_UnicastPacketsReceived;     //!< The total number of received packets, delivered by this layer to a higher layer, which were not addressed to a multicast or broadcast address at this layer.
    ULONG ssid_DiscardedPacketsSent;       //!< The total number of outbound packets which were chosen to be discarded even though no errors had been detected to prevent their being transmitted. One possible reason for discarding such a packet could be to free up buffer space.
    ULONG ssid_DiscardedPacketsReceived;   //!< The total number of inbound packets which were chosen to be discarded even though no errors had been detected to prevent their being delivered. One possible reason for discarding such a packet could be to free up buffer space.
    ULONG ssid_MulticastPacketsSent;       //!< The total number of packets that higher-level protocols requested for transmission and which were addressed to a multicast address at this layer, including those that were discarded or not sent.
    ULONG ssid_MulticastPacketsReceived;   //!< The total number of received packets, delivered by this layer to a higher layer, which were addressed to a multicast address at this layer.
    ULONG ssid_BroadcastPacketsSent;       //!< The total number of packets that higher-level protocols requested for transmission and which were addressed to a broadcast address at this layer, including those that were discarded or not sent.
    ULONG ssid_BroadcastPacketsRecevied;   //!< The total number of packets that higher-level protocols requested for transmission and which were addressed to a broadcast address at this layer, including those that were discarded or not sent.
    ULONG ssid_UnknownPacketsReceived;     //!< The total number of packets received via the interface which were discarded because of an unknown or unsupported protocol.

} wifi_ssidTrafficStats_t;  //for ssid only

/**
 * @struct _wifi_ssidTrafficStats wifi_common_hal.h "include/wifi_common_hal.h"
 * @brief structure for neighbor_ap
 *
 * @note Please do not edit the elements for this data structure
 */

typedef struct _wifi_neighbor_ap
{
    CHAR  ap_SSID[64];	                        //!< The current service set identifier in use by the neighboring WiFi SSID. The value MAY be empty for hidden SSIDs.
    CHAR  ap_BSSID[64];	                        //!< [MACAddress] The BSSID used for the neighboring WiFi SSID.
    CHAR  ap_Mode[64];	                        //!< The mode the neighboring WiFi radio is operating in. Enumeration of: AdHoc, Infrastructure
    UINT  ap_Channel;	                        //!< The current radio channel used by the neighboring WiFi radio.
    INT   ap_SignalStrength;	                //!< An indicator of radio signal strength (RSSI) of the neighboring WiFi radio measured in dBm, as an average of the last 100 packets received.
    CHAR  ap_SecurityModeEnabled[64];	        //!< The type of encryption the neighboring WiFi SSID advertises. Enumeration of:None, WPA-WPA2 etc.
    CHAR  ap_EncryptionMode[64];	            //!< Comma-separated list of strings. The type of encryption the neighboring WiFi SSID advertises. Each list item is an enumeration of: TKIP, AES
    CHAR  ap_OperatingFrequencyBand[16];	    //!< Indicates the frequency band at which the radio this SSID instance is operating. Enumeration of:2.4GHz, 5GHz
    CHAR  ap_SupportedStandards[64];	        //!< Comma-separated list of strings. List items indicate which IEEE 802.11 standards this Result instance can support simultaneously, in the frequency band specified by OperatingFrequencyBand. Each list item is an enumeration of:
    CHAR  ap_OperatingStandards[16];	        //!< Comma-separated list of strings. Each list item MUST be a member of the list reported by theSupportedStandards parameter. List items indicate which IEEE 802.11 standard that is detected for thisResult.
    CHAR  ap_OperatingChannelBandwidth[16];	    //!< Indicates the bandwidth at which the channel is operating. Enumeration of:
    UINT  ap_BeaconPeriod;	                    //!< Time interval (in ms) between transmitting beacons.
    INT   ap_Noise;	                            //!< Indicator of average noise strength (in dBm) received from the neighboring WiFi radio.
    CHAR  ap_BasicDataTransferRates[256];	    //!< Comma-separated list (maximum list length 256) of strings. Basic data transmit rates (in Mbps) for the SSID. For example, if BasicDataTransferRates is "1,2", this indicates that the SSID is operating with basic rates of 1 Mbps and 2 Mbps.
    CHAR  ap_SupportedDataTransferRates[256];	//!< Comma-separated list (maximum list length 256) of strings. Data transmit rates (in Mbps) for unicast frames at which the SSID will permit a station to connect. For example, if SupportedDataTransferRates is "1,2,5.5", this indicates that the SSID will only permit connections at 1 Mbps, 2 Mbps and 5.5 Mbps.
    UINT  ap_DTIMPeriod;	                    //!< The number of beacon intervals that elapse between transmission of Beacon frames containing a TIM element whose DTIM count field is 0. This value is transmitted in the DTIM Period field of beacon frames. [802.11-2012]
    UINT  ap_ChannelUtilization[64];	        //!< Indicates the fraction of the time AP senses that the channel is in use by the neighboring AP for transmissions.

} wifi_neighbor_ap_t;	//COSA_DML_NEIGHTBOURING_WIFI_RESULT

/**
 * @struct _wifi_sta_stats wifi_common_hal.h "include/wifi_common_hal.h"
 * @brief structure for AP info
 */

typedef struct _wifi_sta_stats
{
    CHAR  sta_SSID[64];                 //!< The current connected SSID name.
    CHAR  sta_BSSID[64];                //!< The BSSID used for connected SSID.
    CHAR  sta_BAND[16];                 //!< The BAND used for connected SSID.
    CHAR  sta_SecMode[64];              //!< WiFi Security Mode WPA2-PSK , WPA2-EAP etc..
    CHAR  sta_Encryption[64];           //!< WiFi Encryption Type AES, TKIP, etc.
    FLOAT sta_PhyRate;                  //!< Indicates the Physical rate (Mbps)
    FLOAT sta_Noise;                    //!< Indicator of average noise strength (in dBm) received from the connected WiFi radio.
    FLOAT sta_RSSI;                     //!< RSSI value in dBm
    UINT  sta_Frequency;                //!< Current Operating Frequency.
    UINT  sta_LastDataDownlinkRate;		//!< The data transmit rate in kbps that was most recently used for transmission from the access point to the end point device.
    UINT  sta_LastDataUplinkRate;		//!< The data transmit rate in kbps that was most recently used for transmission from the end point to the access point device.
    UINT  sta_Retransmissions;			//!< The number of packets that had to be re-transmitted, from the last 100 packets sent to the access point. Multiple re-transmissions of the same packet count as one.
} wifi_sta_stats_t;

/**
 * @struct _wifi_halSettings wifi_common_hal.h "include/wifi_common_hal.h"
 * @brief structure for halSettings
 */

typedef struct _wifi_halSettings
{
  char wlan_Interface[WLAN_IFNAMSIZ];  //!< Name of the wireless interface ex: "wlan0", "wlan1" 
} wifi_halConfig_t;

/** @} */ //End of WIFI_HAL_TYPES

/**
 * @brief Get the wifi hal version in string, eg "2.0.0".  WIFI_HAL_MAJOR_VERSION.WIFI_HAL_MINOR_VERSION.WIFI_HAL_MAINTENANCE_VERSION
 *
 * @param[out] output_string it contains HAL version
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected. 
 */
INT wifi_getHalVersion(CHAR *output_string);

//---------------------------------------------------------------------------------------------------
//
// Wifi subsystem level APIs that are common to Client and Access Point devices.
//
//---------------------------------------------------------------------------------------------------
/**
 * @addtogroup WIFI_HAL_COMMON_API
 * @{
 */

/**
 * @brief Initializes the wifi subsystem.
 *
 * Steps involved in a wifi_init operation
 * - Creating default configuration file in a firsttime boot.
 * - Reset the state machine.
 * - Starting of wpa_supplicant daemon.
 * - Opening up communication channels for monitoring and control interfaces
 * - Invoking the event monitoring thread.
 *
 * @todo Change all API's retun tag type(ex: INT)
 * @return INT - The status of the operation. 
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 *
 * @see wifi_uninit()
 * @note This function must not suspend and must not invoke any blocking system
 * calls. It should probably just send a message to a driver event handler task.
 */
INT wifi_init(); 

/**
 * @brief Initializes the wifi subsystem.
 *
 * @param[in] conf conatians wlan interface name.
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 */

INT wifi_initWithConfig(wifi_halConfig_t * conf);

/**
 * @brief Turns off transmit power for the entire Wifi subsystem, for all radios.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 *
 * @pre wifi_init() should be called  before calling this API.
 * @note This function must not suspend and must not invoke any blocking system
 * calls. It should probably just send a message to a driver event handler task.
 */
INT wifi_down(); 

/**
 * @brief Uninitilizes wifi module.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @see wifi_init()
 */
INT wifi_uninit();

// log wifi parameters  format SSID:   BSSID:  ulChan: Noise:  RSSI:

/**
 * @brief Gets current station connection status bssid,ssid,rssi,phyrate,noise,Band.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] wifi_sta_stats Station status data.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @pre "wifi_sta_stats" must be preallocated by the caller.
 * @todo To check if there is any telemetry requirement
 */
void wifi_getStats(INT radioIndex, wifi_sta_stats_t *wifi_sta_stats);

//---------------------------------------------------------------------------------------------------
//Wifi Tr181 API

//Device.WiFi.

//Device.WiFi.RadioNumberOfEntries

/**
 * @brief Get total number of radios in the wifi subsystem.
 *
 * @param[out] output Outputs the number of radios in string.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected. 
 * 
 * @pre wifi_init() should be called  before calling this API.
 */
INT wifi_getRadioNumberOfEntries(ULONG *output); //Tr181


//Device.WiFi.SSIDNumberOfEntries
/**
 * @brief Get the total number of SSID entries in the wifi subsystem.
 *
 * @param[out] output Outputs the number of SSID entries in string.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected. 
 * 
 * @pre wifi_init() should be called  before calling this API.
 */
INT wifi_getSSIDNumberOfEntries(ULONG *output); //Tr181

//---------------------------------------------------------------------------------------------------
//
// Wifi radio level APIs that are common to Client and Access Point devices
//
//---------------------------------------------------------------------------------------------------


//Device.WiFi.Radio.

//Device.WiFi.Radio.{i}.Enable

/**
 * @brief Get the Radio enable config parameter.
 *
 * If the radio is enable, return TRUE, otherwise FALSE.
 *
 * @param[in] radioIndex The index of radio.
 * @param[out] output_bool output of the radio state.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @pre "output_string" buffer must be preallocated by the caller.
 */
INT wifi_getRadioEnable(INT radioIndex, BOOL *output_bool);

//Device.WiFi.Radio.{i}.Status

/**
 * @brief Get the Radio enable status.
 *
 * Wi-Fi is up when the driver is loaded, and control/monitoring socket is open between HAL and wpa_supplicant.
 *
 * @param[in] radioIndex The index of radio.
 * @param[out] output_string output of the radio status.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @pre "output_string" buffer must be preallocated by the caller.
 */
INT wifi_getRadioStatus(INT radioIndex, CHAR *output_string);

//Device.WiFi.Radio.{i}.Alias

//Device.WiFi.Radio.{i}.Name

/**
 * @brief Get the Radio Interface name from platform.
 *
 * @param[in] radioIndex The index of radio.
 * @param[out] output_string Output string which stores the radio interface name.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @pre "output_string" buffer must be preallocated by the caller.
 */
INT wifi_getRadioIfName(INT radioIndex, CHAR *output_string); //Tr181

//Device.WiFi.Radio.{i}.LastChange

//Device.WiFi.Radio.{i}.LowerLayers

//Device.WiFi.Radio.{i}.Upstream

//Device.WiFi.Radio.{i}.MaxBitRate

/**
 * @brief Get the maximum PHY bit rate supported by the interface.
 *
 * Can use netlink APIs to retrieve the maximum bit rate value
 * Output is of the format "X.X Mb/s", "X.X Gb/s"
 * Eg. "216.7 Mb/s", "1.3 Gb/s"
 *
 * @param[in] radioIndex The index of radio.
 * @param[out] output_string Output string which stores the maximum bit rate value.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @pre "output_string" buffer must be preallocated by the caller.
 */
INT wifi_getRadioMaxBitRate(INT radioIndex, CHAR *output_string);

//Device.WiFi.Radio.{i}.SupportedFrequencyBands

/**
 * @brief Get Supported frequency bands at which the radio can operate.
 *
 * Output is comma seperated Values. Eg: 2.4Ghz,5Ghz.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] output_string Output string which stores the supported freq band.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @pre "output_string" buffer must be preallocated by the caller.
 */
INT wifi_getRadioSupportedFrequencyBands(INT radioIndex, CHAR *output_string);

//Device.WiFi.Radio.{i}.OperatingFrequencyBand

/**
 * @brief Get the frequency band at which the radio is operating.
 *
 * RKD-V support STATION interface only.
 * Output format: Example: "2.4GHz", NULL if not connected.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] output_string Output string which stores current operating band.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @pre "output_string" buffer must be preallocated by the caller.
 * @see wifi_getRadioSupportedFrequencyBands()
 */
INT wifi_getRadioOperatingFrequencyBand(INT radioIndex, CHAR *output_string); //Tr181

//Device.WiFi.Radio.{i}.SupportedStandards

/**
 * @brief Get radio supported standards.
 *
 * Output is comma seperated Values. Eg: b,g,n or a,n,ac.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] output_string Output string which stores the supported freq band.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @pre "output_string" buffer must be preallocated by the caller.
 */
INT wifi_getRadioSupportedStandards(INT radioIndex, CHAR *output_string); //Tr181

//Device.WiFi.Radio.{i}.OperatingStandards

/**
 * @brief Get the radio operating mode and pure mode flag.
 * Mode flags are the IEEE 802.11 standards to indicate the maximum network  bandwidth supported.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] output_string the output string.
 * @param[in] gOnly   the g-only mode.
 * @param[in] nOnly   the n-only mode.
 * @param[in] acOnly  the ac-only mode.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @see wifi_getRadioSupportedStandards()
 */
INT wifi_getRadioStandard(INT radioIndex, CHAR *output_string, BOOL *gOnly, BOOL *nOnly, BOOL *acOnly);

//Device.WiFi.Radio.{i}.PossibleChannels

/**
 * @brief Gets the supported channel list.
 *
 * Can use netlink APIs to  retrieve the supported channel list.
 * Output Format: Comma seperated range / values
 *
 * Example: 1-11,36-48,149-161

 * @param[in] radioIndex The index of the radio
 * @param[out] output_string Output string which stores the supported channels.
 *
 * @return The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @pre "output_string" buffer must be preallocated by the caller.
 */
INT wifi_getRadioPossibleChannels(INT radioIndex, CHAR *output_string);

//Device.WiFi.Radio.{i}.ChannelsInUse

/**
 * @brief Gets the list of channels currently in use.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] output_string Output string which stores the list of used channels.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @pre "output_string" buffer must be preallocated by the caller.
 * @see wifi_getRadioPossibleChannels()
 */
INT wifi_getRadioChannelsInUse(INT radioIndex, CHAR *output_string);

//Device.WiFi.Radio.{i}.Channel

/**
 * @brief Get the running channel number.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] output_ulong Variable which stores the currently used channel number.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 */
INT wifi_getRadioChannel(INT radioIndex,ULONG *output_ulong);

//Device.WiFi.Radio.{i}.AutoChannelSupported

/**
 * @brief Check if the driver support the Auto Channel Selection / Dynamic channel selection.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] output_bool Stores the Auto Channel Selection / Dynamic channel selection support status.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @pre "output_bool" buffer must be preallocated by the caller.
 */
INT wifi_getRadioAutoChannelSupported(INT radioIndex, BOOL *output_bool); //Tr181

/**
 * @brief Get the Auto Channel Selection / Dynamic channel selection enable status.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] output_bool Stores the Auto Channel Selection / Dynamic channel selection status.
 *
 * @return The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @pre "output_bool" buffer must be preallocated by the caller.
 * @see wifi_getRadioAutoChannelSupported()
 */
INT wifi_getRadioAutoChannelEnable(INT radioIndex, BOOL *output_bool);

//Device.WiFi.Radio.{i}.AutoChannelRefreshPeriod

/**
 * @brief Get the Auto Channel Selection / Dynamic channel selection refresh period in seconds.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] output_ulong Output variable that stores the Auto Channel Selection / Dynamic channel selection refresh period.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @pre "output_ulong" buffer must be preallocated by the caller.
 */

INT wifi_getRadioAutoChannelRefreshPeriod(INT radioIndex, ULONG *output_ulong); //Tr181

//Device.WiFi.Radio.{i}.GuardInterval

/**
 * @brief Get the guard interval value. eg "400nsec" or "800nsec".
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] output_string Returns the guard interval value.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 */
INT wifi_getRadioGuardInterval(INT radioIndex, CHAR *output_string);	//Tr181

//Device.WiFi.Radio.{i}.OperatingChannelBandwidth
/**
 * @brief Get the Operating Channel Bandwidth.
 *
 * Can use Netlink APIs to retrieve the operating channel bandwidth.
 * Output format Example: "20MHz", "40MHz", "80MHz", "80+80", "160" / NULL if not connected.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] output_string Output variable stores the bandwidth of the operating channel.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @pre "output_string" buffer must be preallocated by the caller.
 */
INT wifi_getRadioOperatingChannelBandwidth(INT radioIndex, CHAR *output_string); //Tr181

//Device.WiFi.Radio.{i}.ExtensionChannel

/**
 * @brief Get the secondary extension channel position.
 *
 * A secondary channel helps in channel bonding where primary and secondary channels can be
 * combined to create a wide channel which can provide more data rate.
 * Position of secondary channel may be either above or below the primary.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] output_string Output of the secondary extension channel.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @pre "output_string" buffer must be preallocated by the caller.
 */
INT wifi_getRadioExtChannel(INT radioIndex, CHAR *output_string); //Tr181

//Device.WiFi.Radio.{i}.MCS

/**
 * @brief Get the Modulation Coding Scheme index.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] output_INT  The mcs index value.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 */
INT wifi_getRadioMCS(INT radioIndex, INT *output_INT); //Tr181

//Device.WiFi.Radio.{i}.TransmitPowerSupported

/**
 * @brief Get supported Transmit Power list.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] output_list  Output string stores the transmit power list.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @pre "output_list" buffer must be preallocated by the caller.
 * 
 */
INT wifi_getRadioTransmitPowerSupported(INT radioIndex, CHAR *output_list); //Tr181

//Device.WiFi.Radio.{i}.TransmitPower

/**
 * @brief Get the current transmit Power.
 *
 * The transmit power level is in units of full power for this radio.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] output_INT  Output string stores the current transmit power.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @see wifi_getRadioTransmitPowerSupported()
 */
INT wifi_getRadioTransmitPower(INT radioIndex, INT *output_INT);

//Device.WiFi.Radio.{i}.IEEE80211hSupported

/**
 * @brief Function to check 80211h is supported or not.
 *
 * 80211h solves interference with satellites and radar using the same 5 GHz frequency band.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] Supported The Boolean value, indicates the 80211h support.
 *
 * @return int - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @pre "Supported" buffer must be preallocated by the caller.
 */
int wifi_getRadioIEEE80211hSupported(INT radioIndex, BOOL *Supported);  //Tr181

//Device.WiFi.Radio.{i}.IEEE80211hEnabled

/**
 * @brief Get the 80211h feature enable.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] enable The 80211h enable status.
 *
 * @return int - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 */
int wifi_getRadioIEEE80211hEnabled(INT radioIndex, BOOL *enable);  //Tr181

//Device.WiFi.Radio.{i}.RegulatoryDomain

/**
 * @brief Gets the Access Point regulatory domain.
 *
 * Default regulatory domain is set as "Global" by wpa_supplicant.
 * This can be changed to a country specific regulatory.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[in] output_string Stores the regulatory domain string.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 * @pre "output_string" buffer must be preallocated by the caller.
 */
INT wifi_getRegulatoryDomain(INT radioIndex, CHAR* output_string);

//---------------------------------------------------------------------------------------------------
//Device.WiFi.Radio.{i}.Stats.

//Device.WiFi.Radio.{i}.Stats.BytesSent
//Device.WiFi.Radio.{i}.Stats.BytesReceived
//Device.WiFi.Radio.{i}.Stats.PacketsSent
//Device.WiFi.Radio.{i}.Stats.PacketsReceived
//Device.WiFi.Radio.{i}.Stats.ErrorsSent
//Device.WiFi.Radio.{i}.Stats.ErrorsReceived
//Device.WiFi.Radio.{i}.Stats.DiscardPacketsSent
//Device.WiFi.Radio.{i}.Stats.DiscardPacketsReceived
//Device.WiFi.Radio.{i}.Stats.PLCPErrorCount
//Device.WiFi.Radio.{i}.Stats.FCSErrorCount
//Device.WiFi.Radio.{i}.Stats.InvalidMACCount
//Device.WiFi.Radio.{i}.Stats.PacketsOtherReceived
//Device.WiFi.Radio.{i}.Stats.X_COMCAST-COM_NoiseFloor
//Device.WiFi.Radio.{i}.Stats.X_COMCAST-COM_ChannelUtilization
//Device.WiFi.Radio.{i}.Stats.X_COMCAST-COM_ActivityFactor
//Device.WiFi.Radio.{i}.Stats.X_COMCAST-COM_CarrierSenseThreshold_Exceeded
//Device.WiFi.Radio.{i}.Stats.X_COMCAST-COM_RetransmissionMetirc
//Device.WiFi.Radio.{i}.Stats.X_COMCAST-COM_MaximumNoiseFloorOnChannel
//Device.WiFi.Radio.{i}.Stats.X_COMCAST-COM_MinimumNoiseFloorOnChannel
//Device.WiFi.Radio.{i}.Stats.X_COMCAST-COM_MedianNoiseFloorOnChannel
//Device.WiFi.Radio.{i}.Stats.X_COMCAST-COM_StatisticsStartTime

/**
 * @brief Get detail radio traffic statistics information.
 *
 * @param[in] radioIndex The index of the radio.
 * @param[out] output_struct Structure that saves the traffic statistics.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 */
INT wifi_getRadioTrafficStats(INT radioIndex, wifi_radioTrafficStats_t *output_struct); //Tr181

//Device.WiFi.SSID.{i}.Enable

/**
 * @brief Get SSID enable configuration parameters.
 *
 * @param[in] ssidIndex The index of the ssid.
 * @param[out] output_bool The SSID enable status.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 *
 * @pre wifi_init() should be called  before calling this API.
 */
INT wifi_getSSIDEnable(INT ssidIndex, BOOL *output_bool); //Tr181

//Device.WiFi.SSID.{i}.Alias

//Device.WiFi.SSID.{i}.Name

/**
 * @brief Get SSID name.
 *
 * Outputs a 32 byte or less string indicating the SSID name.
 *
 * @param[in] apIndex The index of the access point.
 * @param[out] output_string String which holds the SSID name.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 *
 * @pre wifi_init() should be called  before calling this API.
 * @pre "output_string" buffer must be preallocated by the caller.
 */
INT wifi_getSSIDName(INT apIndex, CHAR *output_string);

/**
 * @brief Get the BSSID.
 * Basic Service Set Identifier (BSSID) is the mac addresss of the wireless access point.
 *
 * @param[in] ssidIndex  The index of the SSID
 * @param[out] output_string Output variable that contains the BSSID
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 *
 * @pre wifi_init() should be called  before calling this API..
 * @pre "output_string" buffer must be preallocated by the caller.
 */
INT wifi_getBaseBSSID(INT ssidIndex, CHAR *output_string);

//Device.WiFi.SSID.{i}.MACAddress

/**
 * @brief Get the MAC address associated with the Wifi SSID.
 *
 * @param[in] ssidIndex  The index of the SSID.
 * @param[out] output_string Output variable that holds the mac address.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 *
 * @pre wifi_init() should be called  before calling this API..
 */
INT wifi_getSSIDMACAddress(INT ssidIndex, CHAR *output_string); //Tr181

//Device.WiFi.SSID.{i}.SSID

//-----------------------------------------------------------------------------------------------
//Device.WiFi.SSID.{i}.Stats.
//Device.WiFi.SSID.{i}.Stats.BytesSent
//Device.WiFi.SSID.{i}.Stats.BytesReceived
//Device.WiFi.SSID.{i}.Stats.PacketsSent
//Device.WiFi.SSID.{i}.Stats.PacketsReceived

//Device.WiFi.SSID.{i}.Stats.RetransCount
//Device.WiFi.SSID.{i}.Stats.FailedRetransCount
//Device.WiFi.SSID.{i}.Stats.RetryCount
//Device.WiFi.SSID.{i}.Stats.MultipleRetryCount
//Device.WiFi.SSID.{i}.Stats.ACKFailureCount
//Device.WiFi.SSID.{i}.Stats.AggregatedPacketCount

//Device.WiFi.SSID.{i}.Stats.ErrorsSent
//Device.WiFi.SSID.{i}.Stats.ErrorsReceived
//Device.WiFi.SSID.{i}.Stats.UnicastPacketsSent
//Device.WiFi.SSID.{i}.Stats.UnicastPacketsReceived
//Device.WiFi.SSID.{i}.Stats.DiscardPacketsSent
//Device.WiFi.SSID.{i}.Stats.DiscardPacketsReceived
//Device.WiFi.SSID.{i}.Stats.MulticastPacketsSent
//Device.WiFi.SSID.{i}.Stats.MulticastPacketsReceived
//Device.WiFi.SSID.{i}.Stats.BroadcastPacketsSent
//Device.WiFi.SSID.{i}.Stats.BroadcastPacketsReceived
//Device.WiFi.SSID.{i}.Stats.UnknownProtoPacketsReceived

/**
 * @brief Get the basic SSID traffic statistics info.
 *
 * @param[in] ssidIndex  The index of the SSID.
 * @param[out] output_struct Output structure that holds the ssid traffic stats.
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 *
 * @pre wifi_init() should be called  before calling this API.
 */
INT wifi_getSSIDTrafficStats(INT ssidIndex, wifi_ssidTrafficStats_t *output_struct); //Tr181

//-----------------------------------------------------------------------------------------------
//Device.WiFi.NeighboringWiFiDiagnostic.
//Device.WiFi.NeighboringWiFiDiagnostic.DiagnosticsState
//Device.WiFi.NeighboringWiFiDiagnostic.ResultNumberOfEntries

//-----------------------------------------------------------------------------------------------
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.Radio
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.SSID
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.BSSID
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.Mode
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.Channel
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.SignalStrength
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.SecurityModeEnabled
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.EncryptionMode
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.OperatingFrequencyBand
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.SupportedStandards
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.OperatingStandards
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.OperatingChannelBandwidth
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.BeaconPeriod
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.Noise
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.BasicDataTransferRates
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.SupportedDataTransferRates
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.DTIMPeriod
//Device.WiFi.NeighboringWiFiDiagnostic.Result.{i}.X_COMCAST-COM_ChannelUtilization

/**
 * @brief Get neighbor wifi diagnostics.
 *
 * Start the wifi scan and get the result into output buffer for RDKV to parser.
 * The result will be used to manage endpoint list.
 *
 * @param[in] radioIndex  The index of the radio
 * @param[in] neighbor_ap_array The neighbor access point matrix
 * @param[out] output_array_size The size of the access point list
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 *
 * @pre wifi_init() should be called  before calling this API.
 * @note HAL function should allocate an data structure array, and return to caller with "neighbor_ap_array".
 */
INT wifi_getNeighboringWiFiDiagnosticResult(INT radioIndex, wifi_neighbor_ap_t **neighbor_ap_array, UINT *output_array_size); //Tr181

/**
 * @brief Get Specific SSID Info.
 *
 * Start the wifi scan and get the result into output buffer for RDKV to parser.
 * The result will be used to manage endpoint list.
 *
 * @param[in] SSID  SSID name
 * @param[in] band frequency band
 * @param[in] filtered_ap_array The filtered access point list
 * @param[out] output_array_size output array size
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 */
INT wifi_getSpecificSSIDInfo(const char* SSID, WIFI_HAL_FREQ_BAND band, wifi_neighbor_ap_t **filtered_ap_array, UINT *output_array_size);

/**
 * @brief Set radio scanning freq list.
 *
 * @param[in] radioIndex  radio index
 * @param[in] freqList frequency list
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 * 
 * @pre wifi_init() should be called  before calling this API.
 */
INT wifi_setRadioScanningFreqList(INT radioIndex, const CHAR *freqList);

/**
 * @brief Get Dual band support
 *
 * @return INT - The status of the operation.
 * @retval 1 if dual band support enabled.
 * @retval 0 if dual band support disabled.
 * 
 * @pre wifi_init() should be called  before calling this API.
 */
INT wifi_getDualBandSupport();

/**
 * @brief Wait for scan results.
 *
 * Wait for scan results if scan is in progress,
 * otherwise start a scan, complete the scan and wait for scan results
 *
 * @return INT - The status of the operation.
 * @retval RETURN_OK if successful.
 * @retval RETURN_ERR if any error is detected.
 *
 * @pre wifi_init() should be called  before calling this API.
 */
INT wifi_waitForScanResults(void);
/** @} */ // End of WIFI_HAL_COMMON_API
#endif
