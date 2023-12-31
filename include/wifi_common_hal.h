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

/*********************************************************************

    module: wifi_common_hal.h

    ---------------------------------------------------------------

    description:

        This header file gives the function call prototypes and
        structure definitions used for the RDK-Video
        WiFi radio hardware abstraction layer

    ---------------------------------------------------------------

    environment:

        This HAL layer is intended to support WiFi drivers
        through an open API.

    ---------------------------------------------------------------

    HAL version:

        The version of the WiFi HAL is specified in #defines below

**********************************************************************/

#ifndef __WIFI_COMMON_HAL_H__
#define __WIFI_COMMON_HAL_H__

/**
 * @addtogroup HPK Hardware Porting Kit
 * @{
 *
 * @defgroup RDKV_WIFI RDK-V WiFi
 * @{
 * @defgroup RDKV_WIFI_HAL WiFi HAL
 * @{
 * @section WIFI_GLOSSARY Glossary of terms
 *
 * Abbreviations | Description
 * -----|------------
 * Access Popint | A device that acts as the bridge between wireless clients and the wired network. Often abbreviated as AP
 * AES | The Advanced Encryption Standard is a symmetric block encryption protocol used in WPA2
 * BSSID | BSSID stands for Basic Service Set Identifier and is the MAC address of the AP
 * EAP | The Extensible Authentication Protocol (EAP) can be used to provide authentication to the wireless network when employing WPA-Enterprise and WPA2-Enterprise
 * SSID | The Service Set Identifier (SSID) is the name of the wireless network. It can be contained in the beacons sent out by APs
 * ESSID | The Extended Service Set Identifier is the name of the wireless network, and is used by all APs that provide access to the same infrastructure in an ESS
 * ESS | An extended service set (ESS) refers to a network with two or more APs working cooperatively
 * QoS | Quality of Service enables networks to prioritize certain traffic types
 * CCMP | Cipher Block Chaining Message Authentication Code Protocol (CCMP) is an encryption protocol that forms part of the wireless standard local area networks
 * STA | Wireless Station
 *
 * @section WIFI_STANDARD Wi-Fi Standards
 * IEEE Standards for Wireless, 802.11 is the set of standards maintained by the IEEE for wireless networking
 *
 * Abbreviations | Description
 * -----|------------
 * 802.11a |  In the 5 GHz range. 802.11a networks can support up to 54 Mbps throughput and operate in the UNII bands
 * 802.11ac |  In the 5 GHz range. 802.11ac networks can support up to 1 Gbps throughput using multiple channels
 * 802.11b |  In the 2.4 GHz range. 802.11b networks support up to 11 Mbps throughput and operate in the ISM band
 * 802.11d |  Addresses the Media Access Control (MAC) layer to comply with rules in each country
 * 802.11g |  In the 2.4 GHz range. 802.11g networks support up to 54 Mbps throughput and operate in the ISM band
 * 802.11h |  Sets the requirements for Dynamic Frequency Selection (DFS) and Transmit Power Control (TPC)
 * 802.11n |  Can use both the 2.4 GHz and 5 GHz ranges
 *
 *
 * @section WIFI_SECURITY Wireless Security
 *
 * Abbreviations | Description
 * -----|------------
 * Ad Hoc Mode | A peer to peer mode of networking using Wi-Fi networking but no access point. Ad Hoc networks can include more than two devices
 * WAP | WAP refers to the Wireless Application Protocol, or can be used to mean Wireless Access Point
 * WEP | Wired Equivalent Privacy is the original encryption scheme implemented in wireless networks
 * WPA | Wi-Fi Protected Access is a security protocol for wireless networks that was designed to replace WEP. It uses TKIP to encrypt data
 * WPA2 | Wi-Fi Protected Access v2 is currently the strongest encryption protocol available to wireless networks. It uses AES encryption algorithm
 * WPS | Wi-Fi Protected Setup makes it easier for users to add Wi-Fi clients to WPA and WPA2 protected wireless networks
 * TKIP | The Temporal Key Integrity Protocol was developed as a replacement for WEP but is no longer considered secure and has been removed from 802.11 standards
 * TLS | Transport Layer Security is a protocol designed to encrypt and authenticate all kinds of network traffic at the trans port layer, and is the successor to SSL
 * @defgroup WIFI_COMMON_HAL WiFi Common HAL
 * @{
 * @section Data-Model
 * [Data-Model Definition](https://cwmp-data-models.broadband-forum.org/tr-181-2-11-0.html)  (licensed under a BSD-style license)
 * @note ssidIndex across APIs is not being used it will be revisited in next phase
 */

/**
 * @file  wifi_common_hal.h
 */

/**
 * @brief Defines for the basic data types
 */

#ifndef ULONG
#define ULONG unsigned long
#endif

#ifndef BOOL
#define BOOL  unsigned char /**< unsigned char bool */
#endif

#ifndef CHAR
#define CHAR  char /**< char */
#endif

#ifndef UCHAR
#define UCHAR unsigned char /**< unsigned char */
#endif

#ifndef INT
#define INT   int /**< int */
#endif

#ifndef UINT
#define UINT  unsigned int /**< insigned int */
#endif

#ifndef FLOAT
#define FLOAT  float /**< float */
#endif

/**
 * @brief Defines for TRUE/FALSE/ENABLE flags
 */

#ifndef TRUE
#define TRUE     1 /**< true 1 */
#endif

#ifndef FALSE
#define FALSE    0 /**< false 0 */
#endif

#ifndef ENABLE
#define ENABLE   1 /**< enable 1 */
#endif

/**
 * @brief Defines for function returns
 *
 * RETURN_OK          - Return value for the success case
 * RETURN_ERR         - Return value for the failure case
 * RETURN_UNSUPPORTED - Return value for the unsupported API
 * RETURN_INVALID_PARAM, RETURN_UNINITIALISED in next phase
 */

#ifndef RETURN_OK
#define RETURN_OK   0 /**< return ok */
#endif

#ifndef RETURN_ERR
#define RETURN_ERR   -1 /**< return error */
#endif

#ifndef RETURN_UNSUPPORTED
#define RETURN_UNSUPPORTED   1 /**< return unsupported */
#endif 

/**
 * @brief Defines for HAL version 2.0.0
 */
#define WIFI_HAL_MAJOR_VERSION 2         /**<  This is the major version of this HAL */
#define WIFI_HAL_MINOR_VERSION 0         /**<  This is the minor version of the HAL */
#define WIFI_HAL_MAINTENANCE_VERSION 0   /**<  This is the maintenance version of the HAL */

/**
 * @brief Defines for iface name size
 */
#define WLAN_IFNAMSIZ 32

/**
 * @brief Enumerators for WiFi RSSI levels
 */
typedef enum {
    WIFI_RSSI_NONE = 0,      /**< No signal (0 bar) */
    WIFI_RSSI_POOR,          /**< Poor (1 bar) */
    WIFI_RSSI_FAIR,          /**< Fair (2 bars) */
    WIFI_RSSI_GOOD,          /**< Good (3 bars) */
    WIFI_RSSI_EXCELLENT,     /**< Excellent (4 bars) */
    WIFI_RSSI_MAX
} wifiRSSILevel_t;

/**
 * @brief WiFi Bands
 */
typedef enum {
    WIFI_HAL_FREQ_BAND_NONE,      /**< No frequency band */
    WIFI_HAL_FREQ_BAND_24GHZ,     /**< 2.4Ghz frequency band */
    WIFI_HAL_FREQ_BAND_5GHZ,      /**< 5Ghz frequency band */
} WIFI_HAL_FREQ_BAND;


/**
 * @brief Enumerators for Wi-Fi connection status.
 */
typedef enum {
    WIFI_HAL_SUCCESS = 0,                    /**< Successful connect/disconnect */
    WIFI_HAL_CONNECTING,                     /**< Attempting to connect to a Network/AP using wps or SSID selection */
    WIFI_HAL_DISCONNECTING = 10,             /**< Attempting to disconnect to a Network/AP */

    /* Failure/Error Codes */
    WIFI_HAL_ERROR_NOT_FOUND = 20,           /**< Device/AP not found */
    WIFI_HAL_ERROR_TIMEOUT_EXPIRED,          /**< Timeout expired */
    WIFI_HAL_ERROR_DEV_DISCONNECT,           /**< Failed/Error in Device/AP disconnect */
    WIFI_HAL_ERROR_SSID_CHANGED,             /**< The SSID of the network changed */
    WIFI_HAL_ERROR_CONNECTION_LOST,          /**< The connection to the network was lost */
    WIFI_HAL_ERROR_CONNECTION_FAILED,        /**< The connection failed for an unknown reason */
    WIFI_HAL_ERROR_CONNECTION_INTERRUPTED,   /**< The connection was interrupted */
    WIFI_HAL_ERROR_INVALID_CREDENTIALS,      /**< The connection failed due to invalid credentials */
    WIFI_HAL_UNRECOVERABLE_ERROR,            /**< The device has encountered an unrecoverable (driver or hardware failures) errors */
    WIFI_HAL_ERROR_AUTH_FAILED,              /**< The connection failed due to authentication failure */
    WIFI_HAL_ERROR_UNKNOWN = 40              /**< Unknown/unspecified error */
} wifiStatusCode_t;

/**
 * @brief WiFi Security modes
 *
 * Security modes are used to prevent the unauthorized access or damage to computers using wireless networks.
 * Wired Equivalent Privacy (WEP), Wi-Fi Protected Access (WPA), and Wi-Fi Protected Access II (WPA2) are the
 * primary security algorithms.
 * WEP is the oldest and has proven to be vulnerable as more and more security flaws have been discovered.
 * WPA improved security, but is now also considered vulnerable to intrusion.
 */
typedef enum
{
    WIFI_SECURITY_NONE = 0,               /**< No Security */
    WIFI_SECURITY_WEP_64,                 /**< WEP with 64 bit encryption */
    WIFI_SECURITY_WEP_128,                /**< WEP with 128 bit encryption */
    WIFI_SECURITY_WPA_PSK_TKIP,           /**< WPA(Pre-Shared Key) with TKIP (Temporal Key Integrity Protocol) encryption */
    WIFI_SECURITY_WPA_PSK_AES,            /**< WPA(Pre-Shared Key) with AES (Advanced Encryption Standard) encryption */
    WIFI_SECURITY_WPA2_PSK_TKIP,          /**< WPA2(Pre-Shared Key) with TKIP (Temporal Key Integrity Protocol) encryption */
    WIFI_SECURITY_WPA2_PSK_AES,           /**< WPA2(Pre-Shared Key) with AES (Advanced Encryption Standard) encryption */
    WIFI_SECURITY_WPA_ENTERPRISE_TKIP,    /**< WPA Enterprise with TKIP (Temporal Key Integrity Protocol) encryption */
    WIFI_SECURITY_WPA_ENTERPRISE_AES,     /**< WPA Enterprise with AES (Advanced Encryption Standard) encryption */
    WIFI_SECURITY_WPA2_ENTERPRISE_TKIP,   /**< WPA2 Enterprise with TKIP (Temporal Key Integrity Protocol) encryption */
    WIFI_SECURITY_WPA2_ENTERPRISE_AES,    /**< WPA2 Enterprise with AES (Advanced Encryption Standard) encryption */
    WIFI_SECURITY_WPA_WPA2_PSK,           /**< WPA2(Pre-Shared Key) with TKIP AES encryption */
    WIFI_SECURITY_WPA_WPA2_ENTERPRISE,    /**< WPA,WPA2 Enterprise with TKIP AES encryption */
    WIFI_SECURITY_WPA3_PSK_AES,           /**< WPA3(Pre-Shared Key) with AES encryption */
    WIFI_SECURITY_WPA3_SAE,               /**< WPA3 with SAE encryption */
    WIFI_SECURITY_NOT_SUPPORTED = 99      /**< Security mode not supported */
} wifiSecurityMode_t;

/**
 * @struct _wifi_radioTrafficStats
 * @brief structure for radioTrafficStats
 */
typedef struct _wifi_radioTrafficStats
{
    ULONG radio_BytesSent;                       /**< The total number of bytes transmitted out of the interface, including framing characters. Range is [0, 2^64 - 1] */
    ULONG radio_BytesReceived;                   /**< The total number of bytes received on the interface, including framing characters. Range is [0, 2^64 - 1] */
    ULONG radio_PacketsSent;                     /**< The total number of packets transmitted out of the interface. Range is [0, 2^64 - 1] */
    ULONG radio_PacketsReceived;                 /**< The total number of packets received on the interface. Range is [0, 2^64 - 1] */
    
    ULONG radio_ErrorsSent;                      /**< The total number of outbound packets that could not be transmitted because of errors. Range is [0, 2^32 - 1] */
    ULONG radio_ErrorsReceived;                  /**< The total number of inbound packets that contained errors preventing them from being delivered to a higher-layer protocol. Range is [0, 2^32 - 1] */
    ULONG radio_DiscardPacketsSent;              /**< The total number of outbound packets which were chosen to be discarded even though no errors had been detected to prevent their being transmitted. One possible reason for discarding such a packet could be to free up buffer space. Range is [0, 2^32 - 1] */
    ULONG radio_DiscardPacketsReceived;          /**< The total number of inbound packets which were chosen to be discarded even though no errors had been detected to prevent their being delivered. One possible reason for discarding such a packet could be to free up buffer space. Range is [0, 2^32 - 1] */
    ULONG radio_PLCPErrorCount;                  /**< The number of packets that were received with a detected Physical Layer Convergence Protocol (PLCP) header error. Range is [0, 2^32 - 1] */
    ULONG radio_FCSErrorCount;                   /**< The number of packets that were received with a detected FCS error. This parameter is based on dot11FCSErrorCount from [Annex C/802.11-2012]. Range is [0, 2^32 - 1] */
    ULONG radio_InvalidMACCount;                 /**< The number of packets that were received with a detected invalid MAC header error. Range is [0, 2^32 - 1]*/
    ULONG radio_PacketsOtherReceived;            /**< The number of packets that were received, but which were destined for a MAC address that is not associated with this interface. Range is [0, 2^32 - 1] */
    INT   radio_NoiseFloor;                      /**< The noise floor for this radio channel where a recoverable signal can be obtained. Measurement should capture all energy (in dBm) from sources other than Wi-Fi devices as well as interference from Wi-Fi devices too weak to be decoded. Measured in dBm. Range is [-110, 0] */
    ULONG radio_ChannelUtilization;              /**< Percentage of time the channel was occupied by the radio’s own activity (Activity Factor) or the activity of other radios. Channel utilization MUST cover all user traffic, management traffic, and time the radio was unavailable for CSMA activities, including DIFS intervals, etc. The metric is calculated and updated in this parameter at the end of the interval defined by "Radio Statistics Measuring Interval". The calculation of this metric MUST only use the data collected from the just completed interval. If this metric is queried before it has been updated with an initial calculation, it MUST return -1. Units in Percentage. Range is [0, 100] */
    INT   radio_ActivityFactor;                  /**< Percentage of time that the radio was transmitting or receiving Wi-Fi packets to/from associated clients. Activity factor MUST include all traffic that deals with communication between the radio and clients associated to the radio as well as management overhead for the radio, including NAV timers, beacons, probe responses,time for receiving devices to send an ACK, SIFC intervals, etc. The metric is calculated and updated in this parameter at the end of the interval defined by "Radio Statistics Measuring Interval". The calculation of this metric MUST only use the data collected from the just completed interval. If this metric is queried before it has been updated with an initial calculation, it MUST return -1. Units in Percentage. Range is [0, 100] */
    INT   radio_CarrierSenseThreshold_Exceeded;  /**< Percentage of time that the radio was unable to transmit or receive Wi-Fi packets to/from associated clients due to energy detection (ED) on the channel or clear channel assessment (CCA). The metric is calculated and updated in this Parameter at the end of the interval defined by "Radio Statistics Measuring Interval". The calculation of this metric MUST only use the data collected from the just completed interval. If this metric is queried before it has been updated with an initial calculation, it MUST return -1. Units in Percentage. Range is [0, 100] */
    INT   radio_RetransmissionMetirc;            /**< Percentage of packets that had to be re-transmitted. Multiple re-transmissions of the same packet count as one. The metric is calculated and updated in this parameter at the end of the interval defined by "Radio Statistics Measuring Interval". The calculation of this metric MUST only use the data collected from the just completed interval. If this metric is queried before it has been updated with an initial calculation, it MUST return -1. Units in percentage. Range is [0, 100] */
    INT   radio_MaximumNoiseFloorOnChannel;      /**< Maximum Noise on the channel during the measuring interval. The metric is updated in this parameter at the end of the interval defined by "Radio Statistics Measuring Interval". The calculation of this metric MUST only use the data collected in the just completed interval. If this metric is queried before it has been updated with an initial calculation, it MUST return -1. Units in dBm. Range is [-200, 0] */
    INT   radio_MinimumNoiseFloorOnChannel;      /**< Minimum Noise on the channel. The metric is updated in this Parameter at the end of the interval defined by "Radio Statistics Measuring Interval". The calculation of this metric MUST only use the data collected in the just completed interval. If this metric is queried before it has been updated with an initial calculation, it MUST return -1. Units in dBm. Range is [-200, 0] */
    INT   radio_MedianNoiseFloorOnChannel;       /**< Median Noise on the channel during the measuring interval. The metric is updated in this parameter at the end of the interval defined by "Radio Statistics Measuring Interval". The calculation of this metric MUST only use the data collected in the just completed interval. If this metric is queried before it has been updated with an initial calculation, it MUST return -1. Units in dBm. Range is [-200, 0] */
    ULONG radio_StatisticsStartTime;             /**< The date and time at which the collection of the current set of statistics started. This time must be updated whenever the radio statistics are reset. Range is [0, 2^64 - 1] */

} wifi_radioTrafficStats_t;

/**
 * @struct _wifi_ssidTrafficStats
 * @brief structure for ssidTrafficStats
 */
typedef struct _wifi_ssidTrafficStats
{
    ULONG ssid_BytesSent;                  /**< The total number of bytes transmitted out of the interface, including framing characters. Range is [0, 2^64 - 1] */
    ULONG ssid_BytesReceived;              /**< The total number of bytes received on the interface, including framing characters. Range is [0, 2^64 - 1] */
    ULONG ssid_PacketsSent;                /**< The total number of packets transmitted out of the interface. Range is [0, 2^64 - 1] */
    ULONG ssid_PacketsReceived;            /**< The total number of packets received on the interface. Range is [0, 2^64 - 1] */

    ULONG ssid_RetransCount;               /**< The total number of transmitted packets which were retransmissions. Two retransmissions of the same packet results in this counter incrementing by two. Range is [0, 2^32 - 1] */
    ULONG ssid_FailedRetransCount;         /**< The number of packets that were not transmitted successfully due to the number of retransmission attempts exceeding an 802.11 retry limit. This parameter is based on dot11FailedCount from [802.11-2012]. Range is [0, 2^32 - 1] */
    ULONG ssid_RetryCount;                 /**< The number of packets that were successfully transmitted after one or more retransmissions. This parameter is based on dot11RetryCount from [802.11-2012]. Range is [0, 2^32 - 1] */
    ULONG ssid_MultipleRetryCount;         /**< The number of packets that were successfully transmitted after more than one retransmission. This parameter is based on dot11MultipleRetryCount from [802.11-2012]. Range is [0, 2^32 - 1] */
    ULONG ssid_ACKFailureCount;            /**< The number of expected ACKs that were never received. This parameter is based on dot11ACKFailureCount from [802.11-2012]. Range is [0, 2^32 - 1] */
    ULONG ssid_AggregatedPacketCount;      /**< The number of aggregated packets that were transmitted. This applies only to 802.11n and 802.11ac. Range is [0, 2^32 - 1] */

    ULONG ssid_ErrorsSent;                 /**< The total number of outbound packets that could not be transmitted because of errors. Range is [0, 2^32 - 1] */
    ULONG ssid_ErrorsReceived;             /**< The total number of inbound packets that contained errors preventing them from being delivered to a higher-layer protocol. Range is [0, 2^32 - 1] */
    ULONG ssid_UnicastPacketsSent;         /**< The total number of inbound packets that contained errors preventing them from being delivered to a higher-layer protocol. Range is [0, 2^64 - 1] */
    ULONG ssid_UnicastPacketsReceived;     /**< The total number of received packets, delivered by this layer to a higher layer, which were not addressed to a multicast or broadcast address at this layerm. Range is [0, 2^64 - 1] */
    ULONG ssid_DiscardedPacketsSent;       /**< The total number of outbound packets which were chosen to be discarded even though no errors had been detected to prevent their being transmitted. One possible reason for discarding such a packet could be to free up buffer space. Range is [0, 2^32 - 1] */
    ULONG ssid_DiscardedPacketsReceived;   /**< The total number of inbound packets which were chosen to be discarded even though no errors had been detected to prevent their being delivered. One possible reason for discarding such a packet could be to free up buffer space. Range is [0, 2^32 - 1] */
    ULONG ssid_MulticastPacketsSent;       /**< The total number of packets that higher-level protocols requested for transmission and which were addressed to a multicast address at this layer, including those that were discarded or not sent. Range is [0, 2^64 - 1] */
    ULONG ssid_MulticastPacketsReceived;   /**< The total number of received packets, delivered by this layer to a higher layer, which were addressed to a multicast address at this layer. Range is [0, 2^64 - 1] */
    ULONG ssid_BroadcastPacketsSent;       /**< The total number of packets that higher-level protocols requested for transmission and which were addressed to a broadcast address at this layer, including those that were discarded or not sent. Range is [0, 2^64 - 1] */
    ULONG ssid_BroadcastPacketsRecevied;   /**< The total number of packets that higher-level protocols requested for transmission and which were addressed to a broadcast address at this layer, including those that were discarded or not sent. Range is [0, 2^64 - 1] */
    ULONG ssid_UnknownPacketsReceived;     /**< The total number of packets received via the interface which were discarded because of an unknown or unsupported protocol. Range is [0, 2^32 - 1] */

} wifi_ssidTrafficStats_t;

/**
 * @struct _wifi_ssidTrafficStats
 * @brief structure for neighbor_ap
 *
 * @note Do not edit the fields of this data structure
 */
typedef struct _wifi_neighbor_ap
{
    CHAR  ap_SSID[64];                          /**< The current service set identifier in use by the neighboring WiFi SSID. The value MAY be empty for hidden SSIDs. SSID can be any string up to 32 characters in length, including 0 length */
    CHAR  ap_BSSID[64];                         /**< [MACAddress] The BSSID used for the neighboring WiFi SSID. MAC will be of "AA:BB:CC:DD:EE:FF" format */
    CHAR  ap_Mode[64];                          /**< The mode the neighboring WiFi radio is operating in. Possible values {"AdHoc", "Infrastructure"} */
    UINT  ap_Channel;                           /**< The current radio channel used by the neighboring WiFi radio. Possible values {1-13, 36-64,100-165} */
    INT   ap_SignalStrength;                    /**< An indicator of radio signal strength (RSSI) of the neighboring WiFi radio measured in dBm, as an average of the last 100 packets received. Range is [-200, 0] */
    CHAR  ap_SecurityModeEnabled[64];           /**< The type of encryption the neighboring WiFi SSID advertises. Possible values {"None", "WEP", "WPA", "WPA2", "WPA3", "WPA-WPA2", "WPA2-WPA3", "WPA-Enterprise", "WPA2-Enterprise", "WPA-WPA2-Enterprise"} */
    CHAR  ap_EncryptionMode[64];                /**< Comma-separated list of strings. The type of encryption the neighboring WiFi SSID advertises. Possible values {"TKIP", "AES"} */
    CHAR  ap_OperatingFrequencyBand[16];        /**< Indicates the frequency band at which the radio this SSID instance is operating. Possible values {"2.4GHz", "5GHz"} */
    CHAR  ap_SupportedStandards[64];            /**< Comma-separated list of strings. List items indicate which IEEE 802.11 standards this Result instance can support simultaneously, in the frequency band specified by OperatingFrequencyBand. Possible values {"a", "b", "g", "n", "ac"} */
    CHAR  ap_OperatingStandards[16];            /**< Comma-separated list of strings. Each list item MUST be a member of the list reported by theSupportedStandards parameter. List items indicate which IEEE 802.11 standard that is detected for thisResult. Possible values {"a", "b", "g", "n", "ac"} */
    CHAR  ap_OperatingChannelBandwidth[16];     /**< Indicates the bandwidth at which the channel is operating. Possible values {"20MHz", "40MHz", "80MHz", "160MHz", "Auto"} */
    UINT  ap_BeaconPeriod;                      /**< Time interval (in ms) between transmitting beacons. Range is [0, 2^32 - 1] */
    INT   ap_Noise;                             /**< Indicator of average noise strength (in dBm) received from the neighboring WiFi radio. Range is [-200, 0] */
    CHAR  ap_BasicDataTransferRates[256];       /**< Comma-separated list (maximum list length 256) of strings each of which represents a number in the range [1-9608]. Basic data transmit rates (in Mbps) for the SSID. For example, if BasicDataTransferRates is "1,2", this indicates that the SSID is operating with basic rates of 1 Mbps and 2 Mbps */
    CHAR  ap_SupportedDataTransferRates[256];   /**< Comma-separated list (maximum list length 256) of strings each of which represents a number in the range [1-9608]. Data transmit rates (in Mbps) for unicast frames at which the SSID will permit a station to connect. For example, if SupportedDataTransferRates is "1,2,5.5", this indicates that the SSID will only permit connections at 1 Mbps, 2 Mbps and 5.5 Mbps */
    UINT  ap_DTIMPeriod;                        /**< The number of beacon intervals that elapse between transmission of Beacon frames containing a TIM element whose DTIM count field is 0. This value is transmitted in the DTIM Period field of beacon frames. [802.11-2012]. Range is [0, 2^32 - 1] */
    UINT  ap_ChannelUtilization[64];            /**< Indicates the fraction of the time AP senses that the channel is in use by the neighboring AP for transmissions. Range is [0, 100] */

} wifi_neighbor_ap_t;

/**
 * @struct _wifi_sta_stats
 * @brief structure for Access Point info
 */
typedef struct _wifi_sta_stats
{
    CHAR  sta_SSID[64];                 /**< The current connected SSID name. SSID can be any string up to 32 characters in length, including 0 length. The value MAY be empty for hidden SSIDs */
    CHAR  sta_BSSID[64];                /**< The BSSID used for connected SSID. MAC will be of AA:BB:CC:DD:EE:FF format */
    CHAR  sta_BAND[16];                 /**< The BAND used for connected SSID. Possible values {5GHz, 2.4GHz}*/
    CHAR  sta_SecMode[64];              /**< WiFi Security Mode. Possible values {None, WEP, WPA, WPA2, WPA3, WPA-WPA2, WPA2-WPA3, WPA-Enterprise, WPA2-Enterprise, WPA-WPA2-Enterprise} */
    CHAR  sta_Encryption[64];           /**< WiFi Encryption Type. Possible values {AES, TKIP} */
    FLOAT sta_PhyRate;                  /**< Indicates the Physical rate (Mbps). Range is [1, 2.4 * 1024] */
    FLOAT sta_Noise;                    /**< Indicator of average noise strength (in dBm) received from the connected Wi-Fi radio. Range is [-200, 0]*/
    FLOAT sta_RSSI;                     /**< RSSI value in dBm. Range is [-200, 0]*/
    UINT  sta_Frequency;                /**< Current Operating Frequency. Possible values {2412, 2417, 2422, 2427, 2432, 2437, 2442, 2447, 2452, 2457, 2462, 2467, 2472, 5160, 5180, 5200, 5220, 5240, 5260, 5280, 5300, 5320, 5340, 5480, 5500, 5520, 5540, 5560, 5580, 5600, 5620, 5640, 5660, 5680, 5700, 5720, 5745, 5765, 5785, 5805, 5825, 5845, 5865, 5885} */
    UINT  sta_LastDataDownlinkRate;     /**< The data transmit rate in kbps that was most recently used for transmission from the access point to the end point device. Range is [1000, 600000]*/
    UINT  sta_LastDataUplinkRate;       /**< The data transmit rate in kbps that was most recently used for transmission from the end point to the access point device. Range is [1000, 600000] */
    UINT  sta_Retransmissions;          /**< The number of packets that had to be re-transmitted, from the last 100 packets sent to the access point. Multiple re-transmissions of the same packet count as one. Range is [0, 100] */
} wifi_sta_stats_t;

/**
 * @struct _wifi_halSettings
 * @brief structure for halSettings
 */
typedef struct _wifi_halSettings
{
  char wlan_Interface[WLAN_IFNAMSIZ];  /**< Name of the wireless interface {Ex: "wlan0", "wlan1"} */
} wifi_halConfig_t;

/**
 * @brief Gets the Wi-Fi HAL version in string {Ex: "2.0.0"}
 * - WIFI_HAL_MAJOR_VERSION
 * - WIFI_HAL_MINOR_VERSION
 * - WIFI_HAL_MAINTENANCE_VERSION
 *
 * @param[out] output_string It contains HAL version. Maximum version length is 16 characters.
 * 
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 */
INT wifi_getHalVersion(CHAR *output_string);

/**
 * @brief Initializes the WiFi subsystem for wlan0 WiFi interface
 * 
 * For instance, steps involved in a wifi_init operation for a wpa_supplicant-based WiFi-HAL
 * - Create default configuration file in a first time boot.
 * - Reset the state machine.
 * - Start wpa_supplicant daemon.
 * - Open communication channels for monitoring and control interfaces
 * - Create the wpa_supplicant event monitoring thread.
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 *
 * @see wifi_uninit()
 * @note This function must not invoke any blocking calls.
 */
INT wifi_init(); 

/**
 * @brief Initializes the WiFi subsystem with specified interface configuration
 * 
 * At any given point of time, only one wireless interface will be active {Ex: "wlan0" or "wlan1"}. 
 * To initialize a new interface the current interface has to be uninitialized #wifi_uninit().
 * 
 * @param[in] conf It contains WLAN interface name
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @see wifi_halConfig_t
 */
INT wifi_initWithConfig(wifi_halConfig_t *conf);

/**
 * @brief Disables all WiFi interfaces
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful or if interfaces are already disabled
 * @retval #RETURN_ERR if any error is detected
 *
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @note This function must not invoke any blocking calls.
 */
INT wifi_down(); 

/**
 * @brief Un-initilizes WiFi module
 * 
 * For instance, steps involved in a wifi_uninit operation for a wpa_supplicant-based WiFi-HAL:
 * - Reset the state machine
 * - Stop wpa_supplicant daemon.
 * - Close communication channels for monitoring and control interfaces
 * - Shut down any threads that were created during #wifi_init() #wifi_initWithConfig
 * 
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_init()
 */
INT wifi_uninit();

/**
 * @brief Gets current station connection status bssid,ssid,rssi,phyrate,noise,band
 *
 * @param[in] radioIndex      The index of the radio {Valid values: 1}
 * @param[out] wifi_sta_stats Station status data
 * 
 * @see wifi_sta_stats_t
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @pre Memory for "wifi_sta_stats" must be pre-allocated by the caller
 */
void wifi_getStats(INT radioIndex, wifi_sta_stats_t *wifi_sta_stats);

/**
 * @brief Gets the total number of radios in the WiFi subsystem
 *
 * @param[out] output The number of radios in string {Valid values: 1}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.RadioNumberOfEntries
 */
INT wifi_getRadioNumberOfEntries(ULONG *output);

/**
 * @brief Gets the total number of SSID entries in the WiFi subsystem
 *
 * @param[out] output The number of SSID entries in string {Valid values: 1}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.SSIDNumberOfEntries
 */
INT wifi_getSSIDNumberOfEntries(ULONG *output);

/**
 * @brief Checks whether radio is enabled or not
 *
 * @param[in] radioIndex   The index of radio {Valid values: 1}
 * @param[out] output_bool The radio state {Ex: 0-disabled, 1-enabled}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.Enable
 */
INT wifi_getRadioEnable(INT radioIndex, BOOL *output_bool);

/**
 * @brief Gets the current operational state of the radio
 *
 * @param[in] radioIndex     The index of radio {Valid values: 1}
 * @param[out] output_string The radio status. Refer @ref Data-Model parameter for the complete set of
 * possible values {"Up", "Down", "Unknown", "Dormant", "NotPresent", "LowerLayerDown"}
 * 
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.Status
 */
INT wifi_getRadioStatus(INT radioIndex, CHAR *output_string);

/**
 * @brief Gets the radio interface name from platform
 *
 * @param[in] radioIndex     The index of radio {Valid values: 1}
 * @param[out] output_string The string which stores the radio interface name {Ex: "wlan0", "wlan1"}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API.
 */
INT wifi_getRadioIfName(INT radioIndex, CHAR *output_string);

/**
 * @brief Gets the maximum PHY bit rate supported by the interface
 *
 * @param[in] radioIndex     The index of radio {Valid values: 1}
 * @param[out] output_string The string which stores the maximum bit rate value {Ex: "216.7 Mbps", "1300 Mbps"}. Range is [0, 2.4 * 1024]
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.MaxBitRate
 */
INT wifi_getRadioMaxBitRate(INT radioIndex, CHAR *output_string);

/**
 * @brief Gets the supported frequency bands at which the radio can operate
 * 
 * @param[in] radioIndex     The index of the radio {Valid values: 1}
 * @param[out] output_string The string which stores the comma-separated list of supported frequency bands {Valid values: "2.4Ghz,5Ghz"}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.SupportedFrequencyBands
 */
INT wifi_getRadioSupportedFrequencyBands(INT radioIndex, CHAR *output_string);

/**
 * @brief Gets the frequency band at which the radio is operating
 * 
 * The value MUST be a member of the list reported by the #wifi_getRadioSupportedFrequencyBands()
 *
 * @param[in] radioIndex     The index of the radio {Valid values: 1}
 * @param[out] output_string The string which stores current operating band {Ex: "2.4GHz", "5GHz", NULL if not connected}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_getRadioSupportedFrequencyBands()
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.OperatingFrequencyBand
 */
INT wifi_getRadioOperatingFrequencyBand(INT radioIndex, CHAR *output_string);

/**
 * @brief Gets radio supported standards.
 *
 * @param[in] radioIndex The index of the radio {Valid values: 1}
 * @param[out] output_string The string stores the comma-separated list of radio supported standards {Ex: "b,g,n" or "a,n,ac"}
 * If OperatingFrequencyBand is set to 2.4GHz, only values b, g, n are allowed
 * If OperatingFrequencyBand is set to 5GHz, only values a, n, ac are allowed
 * 
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_getRadioOperatingFrequencyBand()
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.SupportedStandards
 */
INT wifi_getRadioSupportedStandards(INT radioIndex, CHAR *output_string);

/**
 * @brief Gets the radio operating mode and pure mode flag
 * 
 * Mode flags are the IEEE 802.11 standards to indicate the maximum network bandwidth supported. 
 * The value MUST be a member of the list reported by the #wifi_getRadioSupportedStandards()
 *
 * @param[in] radioIndex     The index of the radio {Valid values: 1}
 * @param[out] output_string The string stores the comma-separated list of radio operating mode. If OperatingFrequencyBand is set to 2.4GHz, only values b, g, n are allowed.
 * If OperatingFrequencyBand is set to 5GHz, only values a, n, ac are allowed {Ex: "b,g,n" or "a,n,ac"}.
 * @param[out] gOnly         The g-only mode
 * @param[out] nOnly         The n-only mode
 * @param[out] acOnly        The ac-only mode
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_getRadioSupportedStandards()
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.OperatingStandards
 */
INT wifi_getRadioStandard(INT radioIndex, CHAR *output_string, BOOL *gOnly, BOOL *nOnly, BOOL *acOnly);

/**
 * @brief Gets the supported channel list
 * 
 * List items represent possible radio channels for the wireless standard (a, b, g, n) and the regulatory domain.
 * 
 * @param[in] radioIndex     The index of the radio {Valid values: 1}
 * @param[out] output_string The string stores the comma-separated list of supported channels
 * possible values {"1-13", "36-64,100-165"}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.PossibleChannels
 */
INT wifi_getRadioPossibleChannels(INT radioIndex, CHAR *output_string);

/**
 * @brief Gets the list of channels currently in use
 *
 * @param[in] radioIndex     The index of the radio {Valid values: 1}
 * @param[out] output_string The string stores the comma-separated list of used channels
 * possible values {"1-13", "36-64,100-165"}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called  before calling this API
 * @see wifi_getRadioPossibleChannels()
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.ChannelsInUse
 */
INT wifi_getRadioChannelsInUse(INT radioIndex, CHAR *output_string);

/**
 * @brief Gets the current radio channel used by the connection
 *
 * @param[in] radioIndex    The index of the radio {Valid values: 1}
 * @param[out] output_ulong Variable which stores the currently used channel number
 * possible values {"1-13", "36-64,100-165"}
 * 
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.Channel
 */
INT wifi_getRadioChannel(INT radioIndex,ULONG *output_ulong);

/**
 * @brief Checks if the driver supports the auto channel selection / dynamic channel selection
 * 
 * @param[in] radioIndex   The index of the radio {Valid values: 1}
 * @param[out] output_bool Stores the auto channel selection / dynamic channel selection support status {Ex: 0-disabled, 1-enabled}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.AutoChannelSupported
 */
INT wifi_getRadioAutoChannelSupported(INT radioIndex, BOOL *output_bool);

/**
 * @brief Checks whether auto channel selection enabled or not
 *
 * @param[in] radioIndex   The index of the radio {Valid values: 1}
 * @param[out] output_bool Stores the auto channel selection / dynamic channel selection status {Ex: 0-disabled, 1-enabled}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_getRadioAutoChannelSupported()
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.AutoChannelEnable
 */
INT wifi_getRadioAutoChannelEnable(INT radioIndex, BOOL *output_bool);

/**
 * @brief Gets the auto channel selection / dynamic channel selection refresh period in seconds
 * 
 * @param[in] radioIndex    The index of the radio {Valid values: 1}
 * @param[out] output_ulong Stores the auto channel selection / dynamic channel selection refresh period in seconds. 
 * A value of 0 means that the automatic channel selection is done only at boot time. 
 * This parameter is significant only if AutoChannelEnable is set to true. Range is [0, 2^32 - 1].
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_getRadioAutoChannelEnable()
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.AutoChannelRefreshPeriod
 */
INT wifi_getRadioAutoChannelRefreshPeriod(INT radioIndex, ULONG *output_ulong);

/**
 * @brief Gets the guard interval value
 *
 * @param[in] radioIndex     The index of the radio {Valid values: 1}
 * @param[out] output_string Returns the guard interval value {Valid values: "400nsec", "800nsec", "Auto"}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.GuardInterval
 */
INT wifi_getRadioGuardInterval(INT radioIndex, CHAR *output_string);

/**
 * @brief Gets the operating channel bandwidth
 *
 * @param[in] radioIndex     The index of the radio {Valid values: 1}
 * @param[out] output_string The variable stores the bandwidth of the operating channel {Valid values: "20MHz", "40MHz", "80MHz", "160MHz", "Auto" / NULL if not connected}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.OperatingChannelBandwidth
 */
INT wifi_getRadioOperatingChannelBandwidth(INT radioIndex, CHAR *output_string);

/**
 * @brief Gets the secondary extension channel position
 *
 * A secondary channel helps in channel bonding where primary and secondary channels can be
 * combined to create a wide channel which can provide more data rate.
 * Position of secondary channel may be either above or below the primary. Applicable when OperatingChannelBandwidth is set to 40MHz or Auto.
 *
 * @param[in] radioIndex     The index of the radio {Valid values: 1}
 * @param[out] output_string The string which stores the secondary extension channel position {Valid values: "AboveControlChannel", "BelowControlChannel", "Auto"}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called  before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.ExtensionChannel
 * @see wifi_getRadioOperatingChannelBandwidth()
 */
INT wifi_getRadioExtChannel(INT radioIndex, CHAR *output_string);

/**
 * @brief Gets the Modulation Coding Scheme index
 *
 * @param[in] radioIndex   The index of the radio {Valid values: 1}
 * @param[out] output_INT  The mcs index value
 * possible values {802.11n  - "0-31", 802.11ac - "0-9", 802.11ax - "1-11"}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.MCS
 */
INT wifi_getRadioMCS(INT radioIndex, INT *output_INT);

/**
 * @brief Gets the supported transmit power list
 *
 * @param[in] radioIndex    The index of the radio {Valid values: 1}
 * @param[out] output_list  The string stores the comma-separated list of supported transmit power
 * levels as percentage of full power {Ex: “0,25,50,75,100”}. A -1 item indicates auto mode.
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called  before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.TransmitPowerSupported
 */
INT wifi_getRadioTransmitPowerSupported(INT radioIndex, CHAR *output_list);

/**
 * @brief Gets the current transmit Power
 *
 * The transmit power level is in units of full power for this radio. 
 * The value MUST be a member of the list reported by the #wifi_getRadioTransmitPowerSupported()
 *
 * @param[in] radioIndex   The index of the radio {Valid values: 1}
 * @param[out] output_INT  The string stores the current transmit power. A value of -1 indicates auto mode. Range is [-1, 100]
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see wifi_getRadioTransmitPowerSupported()
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.TransmitPower
 */
INT wifi_getRadioTransmitPower(INT radioIndex, INT *output_INT);

/**
 * @brief Checks whether 80211h is supported or not
 *
 * @param[in] radioIndex The index of the radio {Valid values: 1}
 * @param[out] Supported The boolean value, indicates the 80211h support {Ex: 0-Not supported, 1- supported}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.IEEE80211hSupported
 */
INT wifi_getRadioIEEE80211hSupported(INT radioIndex, BOOL *Supported);

/**
 * @brief Checks whether the 80211h feature enabled or not
 * 
 * @param[in] radioIndex The index of the radio {Valid values: 1}
 * @param[out] enable    The 80211h enable status {Ex: 0-disabled, 1-enabled}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected or if #wifi_getRadioIEEE80211hSupported() returns FALSE
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.IEEE80211hEnabled
 */
INT wifi_getRadioIEEE80211hEnabled(INT radioIndex, BOOL *enable);

/**
 * @brief Gets the regulatory domain
 *
 * @param[in] radioIndex    The index of the radio {Valid values: 1}
 * @param[in] output_string Stores the regulatory domain string {Ex: "US", "DE"}.
 *                          First two octets are ISO3166-1 two-character country code.
 *                          The third octet is either “ “ (all environments), “O” (outside) or “I” (inside).
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.RegulatoryDomain
 */
INT wifi_getRegulatoryDomain(INT radioIndex, CHAR *output_string);

/**
 * @brief Gets detailed radio traffic statistics information
 *
 * @param[in] radioIndex     The index of the radio {Valid values: 1}
 * @param[out] output_struct Structure of type wifi_radioTrafficStats_t that saves the radio traffic statistics
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @see wifi_radioTrafficStats_t
 * @pre wifi_init() or wifi_initWithConfig() should be called  before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.Radio.{i}.Stats.
 */
INT wifi_getRadioTrafficStats(INT radioIndex, wifi_radioTrafficStats_t *output_struct);

/**
 * @brief Gets the SSID name
 *
 * Outputs a 32 byte or less string indicating the SSID name.
 *
 * @param[in] ssidIndex        The index of the SSID {Valid values: 1}
 * @param[out] output_string   String which holds the SSID name
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 *
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.SSID.{i}.Name
 */
INT wifi_getSSIDName(INT ssidIndex, CHAR *output_string);

/**
 * @brief Gets the BSSID
 * 
 * Basic Service Set Identifier (BSSID) is the mac addresss of the wireless access point.
 *
 * @param[in] ssidIndex      The index of the SSID {Valid values: 1}
 * @param[out] output_string The variable that contains the BSSID
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 *
 * @pre wifi_init() or wifi_initWithConfig() should be called  before calling this API
 */
INT wifi_getBaseBSSID(INT ssidIndex, CHAR *output_string);

/**
 * @brief Gets the MAC address associated with the WiFi SSID
 *
 * @param[in] ssidIndex      The index of the SSID {Valid values: 1}
 * @param[out] output_string The variable that holds the mac address. MAC output will be of "AA:BB:CC:DD:EE:FF" format
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 *
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.SSID.{i}.MACAddress
 */
INT wifi_getSSIDMACAddress(INT ssidIndex, CHAR *output_string);

/**
 * @brief Gets the basic SSID traffic statistics info
 *
 * @param[in] ssidIndex      The index of the SSID {Valid values: 1}
 * @param[out] output_struct Structure of type wifi_ssidTrafficStats_t that holds the ssid traffic status
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 *
 * @see wifi_ssidTrafficStats_t
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.SSID.{i}.Stats
 */
INT wifi_getSSIDTrafficStats(INT ssidIndex, wifi_ssidTrafficStats_t *output_struct);

/**
 * @brief Starts a WiFi scan and gets the scan results
 * 
 * Starts a scan and, after the scan completes or a timeout of 4s occurs, collects scan results.
 *
 * @param[in] radioIndex          The index of the radio {Valid values: 1}
 * @param[out] neighbor_ap_array  Array of neighboring access points found by the WiFi scan. To be allocated by this function and de-allocated by the caller.
 * @param[out] output_array_size  Size of neighbor_ap_array, maximum limit is 512.
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 *
 * @see wifi_neighbor_ap_t
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @see @ref Data-Model Parameter: Device.WiFi.NeighboringWiFiDiagnostic., Device.WiFi.NeighboringWiFiDiagnostic.Result
 * @note This call will block until scan completes or a timeout occurs, whichever is earlier
 */
INT wifi_getNeighboringWiFiDiagnosticResult(INT radioIndex, wifi_neighbor_ap_t **neighbor_ap_array, UINT *output_array_size);

/**
 * @brief Starts a WiFi scan and gets the scan results that match the given SSID name and frequency band
 *
 * Starts a scan and, after the scan completes or a timeout of 4s occurs, collects scan results that match the given SSID name and frequency band.
 * 
 * @param[in] SSID               SSID name
 * @param[in] band               frequency band
 * @param[out] ap_array          Array of neighboring access points with the given SSID name and frequency band that were found by the WiFi scan. To be allocated by this function and de-allocated by the caller.
 * @param[out] output_array_size Size of ap_array
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @see wifi_neighbor_ap_t, WIFI_HAL_FREQ_BAND
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 * @note This call will block until scan completes or a timeout occurs, whichever is earlier
 */
INT wifi_getSpecificSSIDInfo(const char *SSID, WIFI_HAL_FREQ_BAND band, wifi_neighbor_ap_t **ap_array, UINT *output_array_size);

/**
 * @brief Sets the list of frequencies to scan over
 *
 * @param[in] radioIndex  Radio index {Valid values: 1}
 * @param[in] freqList    Space-separated frequency list. An empty list implies that a normal, full scan is performed.
 * Possible values {2412, 2417, 2422, 2427, 2432, 2437, 2442, 2447, 2452, 2457, 2462, 2467, 2472, 5160, 5180, 5200, 5220, 5240, 5260, 5280, 5300, 5320, 5340, 5480, 5500, 5520, 5540, 5560, 5580, 5600, 5620, 5640, 5660, 5680, 5700, 5720, 5745, 5765, 5785, 5805, 5825, 5845, 5865, 5885}
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 */
INT wifi_setRadioScanningFreqList(INT radioIndex, const CHAR *freqList);

/**
 * @brief Checks if dual band is supported
 *
 * @return #INT - The status of the operation
 * @retval 1 if dual band support enabled
 * @retval 0 if dual band support disabled
 * 
 * @pre wifi_init() or wifi_initWithConfig() should be called before calling this API
 */
INT wifi_getDualBandSupport();

/**
 * @brief Wait for scan results.
 *
 * Wait for scan results if scan is in progress,
 * otherwise start a scan and wait for scan results or a timeout of 4s to occur, whichever happens earlier
 *
 * @return #INT - The status of the operation
 * @retval #RETURN_OK  if successful
 * @retval #RETURN_ERR if any error is detected
 *
 * @pre wifi_init() or wifi_initWithConfig() wifi_initWithConfig() should be called  before calling this API.
 * @note This call will block until scan completes or a timeout occurs, whichever is earlier
 */
INT wifi_waitForScanResults(void);
/** @} */ // End of WIFI_COMMON_HAL
/** @} */ // End of RDKV_WIFI_HAL
/** @} */ // End of RDKV_WIFI
/** @} */ // End of HPK
#else
#error "! __WIFI_COMMON_HAL_H__"
#endif
