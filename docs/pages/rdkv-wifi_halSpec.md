
# RDK-V WiFi HAL Documentation

## Version History

| Date (DD/MM/YY) | Comment | Version |
| --- | --- | --- |
| 14/07/23 | Initial Release | 1.0.0 |

## Table of Contents

- [RDK-V WiFi HAL Documentation](#rdk-v-wi-fi-hal-documentation)
  - [Acronyms](#acronyms)
  - [Description](#description)
  - [Component Runtime Execution Requirements](#component-runtime-execution-requirements)
    - [Initialization and Startup](#initialization-and-startup)
    - [Threading Model](#threading-model)
    - [Process Model](#process-model)
    - [Memory Model](#memory-model)
    - [Power Management Requirements](#power-management-requirements)
    - [Asynchronous Notification Model](#asynchronous-notification-model)
    - [Blocking calls](#blocking-calls)
    - [Internal Error Handling](#internal-error-handling)
    - [Persistence Model](#persistence-model)
  - [Non-functional requirements](#non-functional-requirements)
    - [Logging and Debugging requirements](#logging-and-debugging-requirements)
    - [Memory and Performance requirements](#memory-and-performance-requirements)
    - [Quality Control](#quality-control)
    - [Licensing](#licensing)
    - [Build Requirements](#build-requirements)
    - [Variability Management](#variability-management)
    - [Platform or Product Customization](#platform-or-product-customization)
  - [Interface API Documentation](#interface-api-documentation)
    - [Theory of operation](#theory-of-operation)
    - [Diagrams](#diagrams)
      - [Operational call sequences](#operational-call-sequences)
        - [WiFi init](#wi-fi-init)
        - [Get WiFi stats](#get-wi-fi-stats)
        - [Get WiFi scan results](#get-wi-fi-scan-results)
        - [WiFi disconnected event](#wi-fi-disconnected-event)

## Acronyms

- `RDK-V` - Reference Design Kit for Video devices
- `WiFi` - Wireless Fidelity
- `HAL` - Hardware Abstraction Layer
- `API` - Application Programming Interface
- `Caller` - Any user of the interface via the `API`s
- `AP` - Wireless Access Point
- `SSID` - Service Set IDentifier
- `BSSID` - Basic Service Set IDentifier
- `MAC` - Media Access Control
- `WEP` - Wired Equivalent Privacy
- `WPA2` - WiFi Protected Access 2
- `WPA3` - WiFi Protected Access 3
- `PSK` - Pre-Shared Key
- `EAP` - Extensible Authentication Protocol
- `802.11` - Set of standards that define communication for Wireless Local Area Networks
- `AES` - Advanced Encryption Standard
- `TKIP` - Temporal Key Integrity Protocol
- `PHY` - Physical Layer
- `RSSI` - Received Signal Strength Indicator
- `WPS` - WiFi Protected Setup

## Description

This interface is to abstract the `RDK-V` `WiFi` `HAL` requirements at a general level to allow platform independent control.

The picture below shows the interactions between `Caller`, `WiFi` `HAL` and `WiFi` Driver.

```mermaid
%%{ init : { "theme" : "forest", "flowchart" : { "curve" : "linear" }}}%%
graph TD
caller(Caller) <--> hal(WiFi HAL)
hal <--> drv(WiFi Driver)
style caller fill:#ffa,stroke:#333,stroke-width:0.3px
style hal fill:#bbdeb8,stroke:#333,stroke-width:0.3px
style drv fill:#0af,stroke:#333,stroke-width:0.3px
```

## Component Runtime Execution Requirements

These requirements ensure that the `HAL` executes correctly within the run-time environment that it will be used in.

### Initialization and Startup

`Caller` is required to initialize `WiFi` `HAL` by calling `wifi_init()` or `wifi_initWithConfig()` before any other call. The kernel boot sequence is expected to start all dependencies of `WiFi` `HAL`. When `wifi_uninit()` is called, any resources allocated by `wifi_init()` or `wifi_initWithConfig()` must be deallocated, such as termination of any internal `HAL` threads. There must be no resouce leaks if `wifi_init()` or `wifi_initWithConfig()` and `wifi_uninit()` are called alternately for an indeterminate number of times, as might occur where there are requirements to shut down `WiFi` whenever ethernet is plugged in and to start up `WiFi` whenever ethernet is plugged out.

### Threading Model

This interface is required to be thread-safe as it could be invoked from multiple `caller` threads. There is no restriction on thread creation within the `HAL` but calling `wifi_uninit()` must cause all created threads to be terminated.

### Process Model

This interface is expected to support a single instantiation with a single process. Results are undefined if `WiFi` `HAL` is instantiated by more than one process.

### Memory Model

The `WiFi` `HAL` will own any memory that it creates. The `caller` will own any memory that it creates. Exceptions to these rules are `wifi_getNeighboringWiFiDiagnosticResult()` and `wifi_getSpecificSSIDInfo()` that allocate and return memory to the `caller` who must deallocate this memory.

### Power Management Requirements

This interface is not required to be involved in power management.

### Asynchronous Notification Model

The below callback registration functions are defined by the `HAL` interface:

- `wifi_connectEndpoint_callback_register()`
- `wifi_disconnectEndpoint_callback_register()`

The below events are notified via the callback registered using `wifi_connectEndpoint_callback_register()`:
- `WiFi` connection in progress
- `WiFi` connected
- `WiFi` connection failed / invalid credentials / auth failed

The below events are notified via the callback registered using `wifi_disconnectEndpoint_callback_register()`:
- `WiFi` disconnected
- `WiFi` network not found / `SSID` changed

Callback functions must originate in a thread that's separate from `caller` context(s). `Caller` will not make any `HAL` calls in the context of these callbacks.

Note: `wifi_telemetry_callback_register()` will be moved out of WiFi-HAL in next phase.

### Blocking calls

This interface has 3 blocking calls, namely `wifi_getNeighboringWiFiDiagnosticResult()`, `wifi_waitForScanResults()` and `wifi_getSpecificSSIDInfo()`, which will block until scan results are obtained or a timeout occurs, whichever happens earlier.

Note: Timeout for the above `APIs` is defaulted to 4 seconds and it will be passed as an argument in next phase.

### Internal Error Handling

All `APIs` must return errors synchronously as a return argument. This interface is responsible for managing its internal errors.

### Persistence Model

`WiFi` `HAL` is expected to persist the following configurations:
- `WiFi` roaming controls (set using `wifi_setRoamingControl()`)
- `WiFi` configuration parameters (specified as arguments to `wifi_connectEndpoint()`)

<!-- @todo WiFi HAL must not be responsible for persisting WiFi roaming controls. This must be done from outside the WiFi HAL. In next phase -->

These configurations must persist across reboots and device software upgrades/downgrades. A warehouse/factory reset must clear these configurations. Also by calling `wifi_clearSSIDInfo()` the `WiFi` configuration parameters will be cleared.

## Non-functional requirements

The following non-functional requirements must be supported by the component:

### Logging and Debugging requirements

This component is required to log all ERROR, WARNING and INFO messages. DEBUG messages are to be disabled by default and enabled when needed.

### Memory and Performance requirements

This interface is required to not cause excessive memory and CPU utilization.

### Quality Control

* Static analysis is required to be performed. Our preferred tool is Coverity.
* Have a zero-warning policy with regards to compiling. All warnings are required to be treated as errors.
* Copyright validation is required to be performed e.g.: Black duck, FossID.
* Use of memory analysis tools like Valgrind are encouraged to identify leaks/corruptions.
* `HAL` Tests will endeavour to create worst-case scenarios to assist investigations.
* Improvements by any party to the testing suite are required to be fed back.

### Licensing

This interface is required to be released under the Apache License 2.0.

### Build Requirements

This interface is required to build into shared library. The shared library must be named `libwifihal.so`. The building mechanism must be independent of Yocto.

### Variability Management

Any change to the interface must be reviewed and approved by component architects and owners.

### Platform or Product Customization

`WiFi` `HAL` must not have any product-specific dependencies or customizations.

## Interface API Documentation

`API` documentation is generated from doxygen comments in the header files.

### Theory of operation

`Caller` can use the `WiFi` `HAL` to get various `WiFi` settings such as:

- Radio status (on/off)
- `SSID` name
- `BSSID` / `WiFi` Router `MAC` address
- Regulatory domain
- Operating frequency/channel
- Operating channel bandwidth
- Radio standard (`802.11` a / b / g / n / ac / ax / etc.)
- Security mode (Open, `WEP`, `WPA2`-`PSK` / `WPA2`-`EAP` / `WPA3` / etc.)
- Encryption type (`AES` / `TKIP` / etc.)
- `PHY` rate
- `RSSI`
- Noise
- Last data downlink rate
- Last data uplink rate
- Retransmissions
- Packets/Bytes/Errors sent/received
- Supported frequency bands
- Supported radio standards

and to perform actions such as:

- Get `WiFi` scan results (`wifi_getNeighboringWiFiDiagnosticResult()` / `wifi_getSpecificSSIDInfo()`)
- Connect to a `WiFi` network using password (`wifi_connectEndpoint()`)
- Connect to a `WiFi` network using `WPS` Push Button / `WPS` PIN (`wifi_setCliWpsButtonPush()` / `wifi_setCliWpsEnrolleePin()`)
- Disconnect from a `WiFi` network (`wifi_disconnectEndpoint()`)
- Cancel an in-progress `WPS` (`wifi_cancelWpsPairing()`)
- Clear current `WiFi` network configuration (`wifi_clearSSIDInfo()`)
- Get/Set `WiFi` roaming controls (`wifi_getRoamingControl()` / `wifi_setRoamingControl()`)

### Diagrams

#### Operational call sequences

```mermaid
sequenceDiagram
    participant Caller
    participant WiFi_HAL
    participant WiFi_Driver


    Caller->>WiFi_HAL: wifi_init()
    activate WiFi_HAL
    WiFi_HAL->>WiFi_Driver: wifi driver init
    activate WiFi_Driver
    Note right of WiFi_Driver: Init driver interface,<br/>Register driver event handler
    WiFi_Driver-->>WiFi_HAL: 
    deactivate WiFi_Driver
    WiFi_HAL-->>Caller: WiFi init status
    deactivate WiFi_HAL
    Note over WiFi_HAL: System is up and running
    par get WiFi stats
    Caller->>WiFi_HAL: wifi_getStats()
    activate WiFi_HAL
    loop for each WiFi stat
    WiFi_HAL->>WiFi_Driver: get WiFi property
    activate WiFi_Driver
    WiFi_Driver-->>WiFi_HAL: 
    deactivate WiFi_Driver
    end
    WiFi_HAL-->>Caller: WiFi stats
    deactivate WiFi_HAL
    and Get WiFi scan results
    Caller->>WiFi_HAL: wifi_getNeighboringWiFiDiagnosticResult()
    activate WiFi_HAL
    WiFi_HAL->>WiFi_Driver: WiFi scan request
    activate WiFi_Driver
    WiFi_Driver-->>WiFi_HAL: 
    WiFi_Driver->>WiFi_HAL: WiFi scan started event
    WiFi_HAL->>WiFi_HAL: wait for WiFi scan results
    alt WiFi scan timed out
    else
    WiFi_Driver->>WiFi_HAL: WiFi scan results event
    deactivate WiFi_Driver
    end
    WiFi_HAL->>WiFi_Driver: get WiFi scan results
    WiFi_Driver-->>WiFi_HAL: 
    WiFi_HAL-->>Caller: WiFi scan results
    deactivate WiFi_HAL
    end
```

Callback Registrations and Asynchronous Notifications

```mermaid
sequenceDiagram
    participant Caller
    participant WiFi_HAL
    participant WiFi_Driver

    par Callback Registrations
    Caller->>WiFi_HAL: wifi_connectEndpoint_callback_register(connect_callback_function)
    Caller->>WiFi_HAL: wifi_disconnectEndpoint_callback_register(disconnect_callback_function)
    end

    Caller->>WiFi_HAL: wifi_connectEndpoint()
    activate WiFi_HAL
    WiFi_HAL->>WiFi_Driver: WiFi connect request
    activate WiFi_Driver
    WiFi_Driver-->>WiFi_HAL: 
    WiFi_HAL->>Caller: connect_callback_function(WIFI_HAL_CONNECTING)
    WiFi_HAL-->>Caller: 
    deactivate WiFi_HAL
    WiFi_Driver->>WiFi_HAL: WiFi scan started event
    WiFi_Driver->>WiFi_HAL: WiFi scan results event
    alt network not found in scan results
    WiFi_Driver->>WiFi_HAL: WiFi network not found event
    WiFi_HAL->>Caller: disconnect_callback_function(WIFI_HAL_ERROR_NOT_FOUND)
    else connect to network unsuccessful
    WiFi_Driver->>WiFi_HAL: WiFi disconnected event
    WiFi_HAL->>Caller: disconnect_callback_function(WIFI_HAL_SUCCESS)
    else connect to network successful
    WiFi_Driver->>WiFi_HAL: WiFi connected event
    deactivate WiFi_Driver
    WiFi_HAL->>Caller: connect_callback_function(WIFI_HAL_SUCCESS)
    end
```
