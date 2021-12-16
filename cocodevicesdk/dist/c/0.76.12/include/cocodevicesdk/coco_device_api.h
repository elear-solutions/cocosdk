/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_device_api.h
 * @brief     COCO Device SDK public API
 * @details   The COCO Device SDK public API allows for rapid development of applications
 *            to make IoT enabled resources.
 * @see
 * @author    Prajeesh Prakash, prajeeshprakash@elear.solutions
 * @author    Varun Kumar, varun.k@healthasyst.com
 * @copyright Copyright (c) 2018-2019 Elear Solutions Tech Private Limited. All rights
 *            reserved.
 * @license   To any person (the "Recipient") obtaining a copy of this software and
 *            associated documentation files (the "Software"):\n
 *            All information contained in or disclosed by this software is
 *            confidential and proprietary information of Elear Solutions Tech
 *            Private Limited and all rights therein are expressly reserved.
 *            By accepting this material the recipient agrees that this material and
 *            the information contained therein is held in confidence and in trust
 *            and will NOT be used, copied, modified, merged, published, distributed,
 *            sublicensed, reproduced in whole or in part, nor its contents revealed
 *            in any manner to others without the express written permission of
 *            Elear Solutions Tech Private Limited.
 */
/*************************************************************************************/
/*===================================================================================*/
#ifndef COCO_DEVICE_API_H_INCLUDED
#define COCO_DEVICE_API_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include "cocostandard/coco_std_api.h"
#include "cocostandard/coco_std_data_storage_control_types.h"

/*************************************************************************************
 *                          GLOBAL MACROS                                            *
 *************************************************************************************/
#ifndef threadLocal
# if __STDC_VERSION__ >= 201112 && !defined __STDC_NO_THREADS__
#  define threadLocal _Thread_local
# elif defined _WIN32 && ( \
       defined _MSC_VER || \
       defined __ICL || \
       defined __DMC__ || \
       defined __BORLANDC__ )
#  define threadLocal __declspec(thread)
/* note that ICC (linux) and Clang are covered by __GNUC__ */
# elif defined __GNUC__ || \
       defined __SUNPRO_C || \
       defined __xlC__
#  define threadLocal __thread
# else
#  error "Cannot define thread_local"
# endif
#endif

/* Default connectivity timer values */
#define COCO_DEVICE_DEFAULT_FAST_RETRY_DURATION             20      // fast Retry Duration of SDK Nodes in seconds to connect with other nodes
#define COCO_DEVICE_DEFAULT_BACKGROUND_MAX_RETRY_PERIOD     30      // background Maximum Retry Period of SDK Nodes in seconds to connect with other nodes
#define COCO_DEVICE_DEFAULT_FOREGROUND_MAX_RETRY_PERIOD     30      // Foreground Maximum Retry Period of SDK Nodes in seconds to connect with other nodes
#define COCO_DEVICE_DEFAULT_KEEP_ALIVE_TIMEOUT              5       // Time in seconds for which Node will wait for the response of keep alive packet
#define COCO_DEVICE_DEFAULT_KEEP_ALIVE_INTERVAL             10      // SDK nodes will send a keep alive packet to other connected nodes in this interval
#define COCO_DEVICE_DEFAULT_DEVICE_BUSY_ST_TIMEOUT          60000   // SDK nodes default maximum time to be in a busy state to perform an operation

/*************************************************************************************
 *                          GLOBAL TYPEDEFS                                          *
 *************************************************************************************/
/* Device firmware update details */
typedef struct {
  char *version;      // Current firmware version
  char *filePath;     // Path of firmware file
} coco_device_fw_update_details_t;

typedef struct {
  uint32_t nodeId;
} coco_device_tunnel_handle_t;

/* Callback to free deviceTunnelParams structure */
typedef void (* coco_device_free_tunnel_params_cb_t)(void *deviceTunnelParams);

/*Device Tunnel parameter details*/
typedef struct {
  char *hostname;
  uint16_t port;
  int32_t ipVersion;
  coco_device_free_tunnel_params_cb_t freeTunnelParamsCb;
} coco_device_tunnel_params_t;

typedef struct {
  void  *context;
  uint16_t channelPort;
} coco_device_channel_handle_t;

typedef  struct {
  uint32_t cmdSenderNodeId;                       // Sender node Id of command
  char *resourceEui;                              // Unique Id of resource
  uint32_t streamId;
  int32_t streamSessionId;                        // SessionId per stream
  int32_t streamSessionType;                      // stream session type, defined in coco_std_media_session_type_t
  uint32_t channelHandleCount;
  coco_device_channel_handle_t **channelHandleArr;
  char *streamDescription;
  void *streamContext;
} coco_device_media_stream_handle_t;

typedef  struct {
  int32_t contentType;                  // Stream/File/Attribute
  int32_t uploadTriggerType;            // user or attribute
  coco_std_source_uri_t sourceUri;      // Structure of coco_std_source_uri_t
  coco_std_upload_triggered_uri_t uploadTriggeredUri;
  uint16_t channelHandleCount;
  coco_device_channel_handle_t **channelHandleArr;
  void *uploadContext;
} coco_device_storage_upload_handle_t;

typedef  struct {
  int32_t contentType;                  // stream/File
  int32_t uploadTriggerType;            // user or attribute
  coco_std_source_uri_t sourceUri;      // Structure of coco_std_source_uri_t
  coco_std_upload_triggered_uri_t uploadTriggeredUri;
  uint32_t storageNodeId;
  char *resourceEui;                    // Unique Id of resource, Destination storage resource EUI
  bool appendFlag;                      // <overwrite / append>
  uint32_t offset;                      // ignored for streams
  uint32_t size;                        // ignored for streams
  time_t createdTimestamp;
  uint16_t channelCount;
  uint16_t *channelPortArr;
  char **channelDescriptionArr;
  uint32_t *channelRxBuffSizeArr;       // Array of channel receiver buffer size
  uint32_t timeoutMs;                   // Timeout in ms after which SDK will invoke the storage
                                        // upload status callback with status as
                                        // COCO_DEVICE_STORAGE_UPLOAD_FAILED
                                        // timeoutMs = 0 means infinity
} coco_device_storage_upload_params_t;

/// A callback that provides the status of #coco_device_capture_snapshot_request API.
/** @param filePath     : Snapshot download file path that was passed from
 *                        coco_device_capture_snapshot_request API.
 *  @param status       : snapshot request status, one of the values from coco_device_snapshot_status_t
 *  @param context      : Context pointer that is set in coco_device_capture_snapshot_request() API
 */
typedef void (*coco_device_capture_snapshot_request_status_cb_t)(const char *filePath, int status,
                                                                 void *context);

typedef  struct {
  uint32_t nodeId;
  char *resourceEui;            // Unique Id of resource
  uint16_t pixelHeight;
  uint16_t pixelWidth;
  coco_device_capture_snapshot_request_status_cb_t snapshotReqestStatusCb;
  const char *downloadPath;
  uint32_t timeoutMs;           // Timeout in ms after which deviceSdk will invoke the respective status
                                // callback with status as COCO_STD_STATUS_TIMEOUT and ignore status
                                // received for that particular command. timeoutMs = 0 means infinity.
} coco_device_capture_snapshot_request_params_t;

/* Callback to receive resource command */
/// A callback that provides the resource command to the application
/** @param streamHandle    resource command pointer
 */
typedef void (* coco_device_resource_cmd_cb_t)(coco_std_resource_cmd_t *resourceCmd);

/* Callback to receive device command */
/// A callback that provides the device command to the application
/** @param streamHandle    Device command pointer
 */
typedef void (* coco_device_mgmt_cmd_cb_t)(coco_std_device_cmd_t *deviceCmd);

/* Callback to receive add resource execution status */
/// A callback that provides the add resource status to the application
/** @param status   status of add resource. status takes values from the enum
 *                  coco_std_status_code_t. Possible status are
 *                  COCO_STD_STATUS_SUCCESS
 *                  COCO_STD_STATUS_FAILURE
 *  @param context  Context passed in the dd resource
 */
typedef void (* coco_device_add_resource_status_cb_t)(int32_t status, void *context);

/* Callback to receive remove resource execution status */
/// A callback that provides the remove resource status to the application
/** @param status   status of remove resource. status takes values from the enum
 *                  coco_std_status_code_t. Possible status are
 *                  COCO_STD_STATUS_SUCCESS
 *                  COCO_STD_STATUS_FAILURE
 *  @param context  Context passed in the remove resource
 */
typedef void (* coco_device_remove_resource_status_cb_t)(int32_t status, void *context);

/* Callback to receive send device management command status execution status */
/// A callback that provides the device command status to the application
/** @param status   status of device command. status takes values from the enum
 *                  coco_std_status_code_t. Possible status are
 *                  COCO_STD_STATUS_SUCCESS
 *                  COCO_STD_STATUS_FAILURE
 *  @param context  Context passed to the device command
 */
typedef void (* coco_device_mgmt_cmd_status_update_cb_t)(int32_t status, void *context);

/* Callback to receive transmission status of resource command status */
/// A callback that provides the resource command status to the application
/** @param status   status of resource command. status takes values from the enum
 *                  coco_std_status_code_t. Possible status are
 *                  COCO_STD_STATUS_SUCCESS
 *                  COCO_STD_STATUS_FAILURE
 *  @param context  Context passed in the resource command
 */
typedef void (* coco_device_resource_cmd_status_update_cb_t)(int32_t status, void *context);

/* Callback to receive send info request execution status */
/// A callback that provides the Info request status to the application
/** @param status   status of Info request. status takes values from the enum
 *                  coco_std_status_code_t. Possible status are
 *                  COCO_STD_STATUS_SUCCESS
 *                  COCO_STD_STATUS_FAILURE
 *  @param context  Context passed in the info request
 */
typedef void (* coco_device_info_request_status_cb_t)(int32_t status, void *context);

/* Callback to receive info response */
/// A callback that provides the Info response to the application
/** @param infoResponse   pointer to the info response
 *  @param context        Context passed in the info response
 */
typedef void (* coco_device_info_response_cb_t)(coco_std_info_response_t *infoResponse, void *context);

/* Callback to receive send info response execution status */
/// A callback that provides the Info response status to the application
/** @param status   status of Info response. status takes values from the enum
 *                  coco_std_status_code_t. Possible status are
 *                  COCO_STD_STATUS_SUCCESS
 *                  COCO_STD_STATUS_FAILURE
 *  @param context  Context passed in the info response
 */
typedef void (* coco_device_info_response_status_cb_t)(int32_t status, void *context);

/* Callback to receive info request */
/// A callback that provides the Info request to the application
/** @param infoRequest    pointer to the info request
 *  @param context        Context passed in the info request
 */
typedef void (* coco_device_info_request_cb_t)(coco_std_info_request_t *infoRequest);

/* Callback to receive send advertise resource execution status */
/// A callback that provides the status of advertise resource api to the application
/** @param status   status of advertise resource. status takes values from the enum
 *                  coco_std_status_code_t. Possible status are
 *                  COCO_STD_STATUS_SUCCESS
 *                  COCO_STD_STATUS_FAILURE
 *  @param context  Context passed in the advertise resource
 */
typedef void (* coco_device_advertise_resource_status_cb_t)(int32_t status, void *context);

/* Callback to receive send show message execution status */
/// A callback that provides the show message status to the application
/** @param status   status of show message. status takes values from the enum
 *                  coco_std_status_code_t. Possible status are
 *                  COCO_STD_STATUS_SUCCESS
 *                  COCO_STD_STATUS_FAILURE
 *  @param context  Context passed in the show message
 */
typedef void (* coco_device_show_message_status_cb_t)(int32_t status, void *context);

/* Callback to receive attribute update status */
/// A callback that provides the attribute update status to the application
/** @param status   status of attribute update. status takes values from the enum
 *                  coco_std_status_code_t. Possible status are
 *                  COCO_STD_STATUS_SUCCESS
 *                  COCO_STD_STATUS_FAILURE
 *  @param context  Context passed in the attribute update
 */
typedef void (* coco_device_attribute_update_status_cb_t)(int32_t status, void *context);

/* Callback to receive cocoNet connection status. Status will takes values from the enum
   coco_device_connect_status_ */
/// A callback that provides the device connection status to the application
/** @param status   status of device connection. status takes values from the enum
 *                  coco_device_connect_status_t. Possible status are
 *                  COCO_DEVICE_CONNECTING,
 *                  COCO_DEVICE_CONNECTED,
 *                  COCO_DEVICE_CONNECTED,
 *                  COCO_DEVICE_NETWORK_BLOCKED
 */
typedef void (*coco_device_connect_status_cb_t)(int32_t status);

/* Callbacks to receive tunnel status */
/// A callback that provides the tunnel status to the application
/** @param tunnelHandle   tunnel handle
 *  @param sessionId      session Id
 *  @param tunnelStatus   Status of tunnel. Status takes values from the enum cp_tunnel_status_t.
 *  @param listeningPort  Listening port to the tunnel
 */
typedef void (*coco_device_tunnel_status_cb_t)(coco_device_tunnel_handle_t *tunnelHandle,
                                               uint32_t sessionId, int32_t tunnelStatus,
                                               uint16_t listeningPort);

/* Callback to receive firmware update details */
/// A callback that provides the firmware update to the application
/** @param fwUpdateDetails    Firmware update detail pointer
 */
typedef void (* coco_device_firmware_update_cb_t)(coco_device_fw_update_details_t *fwUpdateDetails);

/* Callback to receive capability update status */
/// A callback that provides the capability update status to the application
/** @param status   status of capability update. status takes values from the enum
 *                  coco_std_status_code_t. Possible status are
 *                  COCO_STD_STATUS_SUCCESS
 *                  COCO_STD_STATUS_FAILURE
 *  @param context  Context passed in the capability update
 */
typedef void (* coco_device_capability_update_status_cb_t)(int32_t status, void *context);

/* Callback to receive scene execute command */
/// A callback that provides the scene execution commands to the application
/** @param resourceCmdArr     Resource command array pointer
 *  @param resourceCmdArrCnt  Resource command array count
 */
typedef void (* coco_device_scene_execute_cb_t)(coco_std_resource_cmd_t *resourceCmdArr,
                                                int resourceCmdArrCnt);

/* Callback to receive tunnel parameters */
/// A callback that provides the tunnel parameters to the application
/** @param resourceCmdInfo   Resource command info pointer
 *  @param status            status of tunnel operation. status takes values from the enum
 *                           coco_std_status_code_t. Possible status are
 *                           COCO_STD_STATUS_SUCCESS
 *                           COCO_STD_STATUS_FAILURE
 *  @return coco_device_tunnel_params_t  tunnel parameter pointer
 */
typedef coco_device_tunnel_params_t *(* coco_device_get_tunnel_params_cb_t)(coco_std_resource_cmd_t *resourceCmdInfo,
                                                                            coco_std_status_code_t *status);

/* Callback to receive media stream accept */
/// A callback invoked to the application when stream is accepted.
/** @param resourceUri              Unique resource Id
 *  @param channelCount             count of channels
 *  @param portArray                Array of ports
 *  @param streamTransportTypeArr   Array of stream transport type
 *  @param streamSessionType        stream session type, defined in coco_std_media_session_type_t
 *  @param streamDescription        stream description
 *  @param streamContext            Context passed for stream handle in the accept callback
 *  @param status                   status of media stream accept operation. status takes values from the enum
 *                                  coco_std_status_code_t. Possible status are
 *                                  COCO_STD_STATUS_SUCCESS
 *                                  COCO_STD_STATUS_FAILURE
 *  @return bool
 */
typedef bool (*coco_device_media_stream_accept_cb_t)(char *resourceUri, uint16_t channelCount, uint16_t *portArray,
                                                     int32_t *streamTransportTypeArr, int32_t streamSessionType,
                                                     char *streamDescription, void **streamContext,
                                                     coco_std_status_code_t *status);

/* Callback to receive media stream status */
/// A callback that provides the media stream status to the application
/** @param handle          Stream handle pointer
 *  @param channelHandle   Stream channel handle pointer
 *  @param status          Stream channel connection status
 *  @param streamContext   Context passed for stream handle in the stream open API or accept callback
 *  @param channelContext  Context passed for stream channel in set channel receive callback API
 */
typedef void (*coco_device_media_stream_status_cb_t)(coco_device_media_stream_handle_t *handle,
                                                     coco_device_channel_handle_t *channelHandle,
                                                     int32_t status, void *streamContext,
                                                     void *channelContext);

/* Callback to receive media stream receive */
/// A callback invoked to the application when stream is received.
/** @param handle          Stream handle pointer
 *  @param channelHandle   Stream channel handle pointer
 *  @param data            Pointer to the received data from the stream channel to the app
 *  @param len             Length of the received data
 *  @param streamContext   Context passed for stream handle in the stream open API or accept callback
 *  @param channelContext  Context passed for stream channel in set channel receive callback API
 */
typedef void (*coco_device_media_stream_receive_cb_t)(coco_device_media_stream_handle_t *handle,
                                                      coco_device_channel_handle_t *channelHandle,
                                                      const void *data, size_t len,
                                                      void *streamContext, void *channelContext);

/* Callback to receive active tunnel clients */
/// A callback that provides the active tunnel clients to the application
/** @param activeTunnelClientArr    pointer to the array of active tunnel clients
 *  @param activeTunnelClientCount  count of active tunnel clients
 *  @param requestContext           User defined context pointer
 */
typedef void (*coco_device_active_tunnel_clients_cb_t)(uint32_t *activeTunnelClientArr,
                                                       uint16_t activeTunnelClientCount,
                                                       void *requestContext);

/// A callback that provides the status of #coco_device_ap_listen API.
/** @param status: Take the values from coco_std_status_t enum.
 *  @param context  User's context passed into #coco_device_ap_listen() API call.
 */
typedef void (*coco_device_ap_listen_status_cb_t)(int32_t status, void *context);

/// A callback that provides the status of #coco_device_ap_disconnect API.
/** @param status: Take the values from coco_std_status_t enum.
 *  @param context  User's context passed into #coco_device_ap_disconnect() API call.
 */
typedef void (*coco_device_ap_disconnect_status_cb_t)(int32_t status, void *context);

/* Callback to receive remove device status */
/// A callback that provides the remove device status to the application
/** @param status   status of remove status. status takes values from the enum
 *                  coco_std_status_code_t. Possible status are
 *                  COCO_STD_STATUS_SUCCESS
 *                  COCO_STD_STATUS_FAILURE
 */
typedef void (*coco_device_remove_status_cb_t)(int32_t status);

/* Callback to send remove device request */
/// A callback that provides the remove device request to the application
/** @param  factoryResetFlag   Flag to indicate whether the device needs to Factory reset or not.
 *  @return int32_t            success return 0
 *                             failure return -1
 */
typedef int32_t (*coco_device_remove_request_cb_t)(int32_t factoryResetFlag);

/* Callback to receive storage upload accept*/
/// A callback invoked to an application when uploaded data is accepted by storage node
/** @param storageUploadData    Storage upload data pointer
 *  @param resourceEui          Unique Id of resource
 *  @param uploadContext        Context passed for storage upload accept
 */
typedef bool (*coco_device_storage_upload_accept_cb_t)(coco_std_cmd_storage_upload_t *storageUploadData,
                                                       char *resourceEui, void **uploadContext);

/* Callback to receive storage upload status*/
/// A callback that provides the storage upload status to the application
/** @param uploadHandle    Storage Upload handle
 *  @param channelHandle   channel handle
 *  @param status          Status of storage upload. Status takes values from the enum coco_device_storage_upload_status_t.
 *  @param uploadContext   Context passed for storage upload handle
 *  @param channelContext  Context passed for channel
 */
typedef void (*coco_device_storage_upload_status_cb_t)(coco_device_storage_upload_handle_t *uploadHandle,
                                                       coco_device_channel_handle_t *channelHandle,
                                                       int32_t status, void *uploadContext,
                                                       void *channelContext);

/* Callback to receive storage upload receive */
/// A callback that provides uploaded storage data to application
/** @param uploadHandle    Storage upload handle pointer
 *  @param channelHandle   Storage upload channel handle pointer
 *  @param data            Pointer to the received data from the stream channel to the app
 *  @param len             Length of the received data
 *  @param uploadContext   Context passed for storage upload handle
 *  @param channelContext  Context passed for storage upload channel
 */
typedef void (*coco_device_storage_upload_receive_cb_t)(coco_device_storage_upload_handle_t *uploadHandle,
                                                        coco_device_channel_handle_t *channelHandle,
                                                        const void *data, size_t len,
                                                        void *uploadContext, void *channelContext);

/// This callback is invoked when client requests to scan available SSIDs
typedef void (*coco_device_ap_scan_ssid_cb_t)();

/// A callback that provides the status of #coco_device_ap_send_ssid API.
/** @param status : Take the values from coco_std_status_t enum.
 *  @param context: User's context passed into #coco_device_ap_send_ssid() API call.
 */
typedef void (*coco_device_ap_send_ssid_status_cb_t)(int32_t status, void *context);

/// A callback that provides the WiFi network's credentials received from the client.
/** @param ssid    : SSID
 *  @param password: Password
 */
typedef void (*coco_device_ap_wifi_cred_cb_t)(char *ssid, char*password);

/// A callback that provides the status of #coco_device_check_internet API.
/** @param status : Take the values from coco_std_status_t enum.
 *  @param context: User's context passed into #coco_device_check_internet() API call.
 */
typedef void (*coco_device_internet_status_cb_t)(int32_t status, void *context);

/// A callback that requests the snapshot received from client.
/** @param snapshotId     : Snapshot ID.
 *  @param resourceEui    : Resource EUI which received the snapshot request.
 *  @param pixelHeight    : Pixel height of the snapshot image
 *  @param pixelWidth     : Pixel width of the snapshot image
 *  @return bool          : true to accept the request else false to reject the snapshot request.
 */
typedef bool (*coco_device_capture_snapshot_request_cb_t)(uint32_t snapshotId, char *resourceEui,
                                                          uint16_t pixelHeight, uint16_t pixelWidth);

/// A callback that provides the status of #coco_device_capture_snapshot API.
/** @param snapshotId     : Snapshot ID.
 *  @param status         : snapshot status, one of the values from coco_device_snapshot_status_t
 *  @param filePath       : File path of the snapshot that is being sent.
 *  @param context        : Context pointer that is set in coco_device_capture_snapshot() API
 */
typedef void (*coco_device_capture_snapshot_status_cb_t)(uint32_t snapshotId, int status,
                                                         char *filePath, void *context);

/// This callback is invoked when a device having node ID as deviceNodeId is removed from the network
/** @param deviceNodeId : device node ID.
 */
typedef void (*coco_device_removed_device_cb_t)(uint32_t deviceNodeId);

/// This callback is invoked when the data maintained by cocodevicesdk library gets corrupted.
/// The application should perform any required cleanup in this callback. cocodevicesdk library
/// will cleanup all the the corrupted data and terminate the process after the execution returns
/// from this callback. After this, when the application restarts, device will have to be added
/// to a COCONet again.
typedef void (*coco_device_data_corruption_cb_t)();

/* Structure used to initialize connectivity timers */
typedef struct {
  uint32_t fastRetryDuration;          // SDK will try to connect to other nodes at an interval
                                       // of 1 second for this duration in seconds. It must be a non-negative
                                       // integer. Set it to COCO_DEVICE_DEFAULT_FAST_RETRY_DURATION for using the
                                       // default value.
  uint32_t backgroundMaxRetryPeriod;   // After fastRetryDuration, SDK will try to connect to
                                       // other nodes at intervals which will keep on increasing with each
                                       // retry. backgroundMaxRetryPeriod in seconds is the maximum value of
                                       // this interval when the app is in background connectivity mode.
                                       // It must be a positive integer. Set it to
                                       // COCO_DEVICE_DEFAULT_BACKGROUND_MAX_RETRY_PERIOD for using the default value.
  uint32_t foregroundMaxRetryPeriod;   // After fastRetryDuration, SDK will try to connect to
                                       // other nodes at intervals which will keep on increasing with each
                                       // retry. foregroundMaxRetryPeriod in seconds is the maximum value of
                                       // this interval when the app is in foreground connectivity mode.
                                       // It must be a positive integer. Set it to
                                       // COCO_DEVICE_DEFAULT_FOREGROUND_MAX_RETRY_PERIOD for using the default value.
  uint32_t keepAliveInterval;          // SDK nodes will send a keep alive packet to other
                                       // connected nodes at an internal of keepAliveInterval seconds.
                                       // It must be a positive integer. Set it to
                                       // COCO_DEVICE_DEFAULT_KEEP_ALIVE_INTERVAL for using the default value.
  uint32_t keepAliveTimeout;           // This the timeout in seconds for which SDK will wait
                                       // for the response of the keep alive packet. It must be a positive
                                       // integer. Set it to COCO_DEVICE_DEFAULT_KEEP_ALIVE_TIMEOUT for using the
                                       // default value.
} coco_device_connectivity_timers_t;

/* cocoDeviceSdk init data structure */
typedef struct {
  char *cwdPath;                               // current working directory path, Mandatory
  void *encryptionKey;                         // To be used for Internal purpose
  uint32_t encryptionKeyLen;                   // To be used for Internal purpose
  char *configFilePath;                        // configuration file path, Mandatory
  char *downloadPath;                          // Path where all the device files will be downloaded, Mandatory
  char *tempPath;                              // Temporary folder path
  char *firmwareVersion;                       // Current firmware version of device, Mandatory
  int32_t *protocolIdArr;                      // Supported protocols by the device, will take value from coco_std_protocol_id_t
  uint32_t protocolIdArrCnt;                   // Count of Supported protocols
  int32_t isExtendable;                        /* Flag to indicate whether the device is able to connect with other devices (resources).
                                                  If True, other resources can be added else resources can't be added*/
  int32_t powerSource;                         // Type of power source of a device will have values from coco_std_power_source_t
  int32_t receiverType;                        // Type of receiver of a device will have values from coco_std_receiver_type_t
  int32_t skipSSLVerification;                 /* Flag to indicate SSL Verification.
                                                  if skipSSLVerification is false, device needs to do SSL verification, else not required */
  char *canonicalHostNameList;                 // Set canonical host name(s); its optional to use
  uint16_t clusterPort;                        /* Physical port to be used for cluster communication.
                                                  Application should provide an available port.
                                                  Set this to 0 for the SDK to choose a port on its own. */
  int32_t ssidScanAvailable;
  int32_t dontPersistData;                     /* Set this flag to true only to reduce the amount of disk space being used and
                                                  to reduce the number of disk writes, for example in case of
                                                  wearable flash memory. Also, setting this flag will be
                                                  suitable only for devices which set isExtendable = false
                                                  because updating COCO backend with the list of added and
                                                  removed resources will not be consistent. Apps which once
                                                  set this flag should stick to it; unsetting it will result
                                                  in undefined behaviour.
                                                  Setting this flag has the following limitations:
                                                  1. In the current version, rules will not be supported.
                                                     In a future release, rules won't work after boot up
                                                     until rules and scenes are delivered to the device by
                                                     the COCO backend.
                                                  2. Re-delivery guarantee won't persist packets.
                                                  3. Packet ID will start from 1 after every boot up.
                                                     This can mismatch info response to info request and
                                                     resource command status to resource command.
                                                  4. Resource metadata(or icons) won't be persisted.
                                                  5. All client app nodes will have access to all resources,
                                                     capabilities and device commands.
                                                  6. Resources won't be persisted, so OEM app will have to
                                                     call add resource API on every boot up.
                                                  7. Firmware version will not be persisted by the SDK - this
                                                     means that firmware update success status will not be
                                                     sent to clients. */
  char *tmpCwdPath;                            /* Mandatory if dontPersistData is true. This must be a RAM based
                                                  memory location, for example a path in /tmp mounted on /tmpfs.
                                                  If this is not done, it can cause critical performance issues. */
  int32_t doNotUseHttpClient;                  // Flag to indicate HTTP client intialisation is needed or not.
  int32_t doNotInitLogger;                     // Flag to indicate logger need to be initialised or not.
  int32_t deviceBusyStTimeoutMs;               /* OEM will specify the timeout for the device busy state.
                                                  If not specified then set the 60 sec of default timeout for
                                                  device busy state */
  int32_t loggerOutput;                        // Variable to set the log output.
  char *resInfoPath;                           // Optional path to read resource info template, if provided resource
                                               // will be added on successful gateway addition
  coco_device_resource_cmd_cb_t resourceCmdCb; // Callbacks are optional
  coco_device_mgmt_cmd_cb_t devMgmtCmdCb;
  coco_device_add_resource_status_cb_t addResStatusCb;
  coco_device_remove_resource_status_cb_t remResStatusCb;
  coco_device_mgmt_cmd_status_update_cb_t devMgmtCmdStatusCb;
  coco_device_resource_cmd_status_update_cb_t resourceCmdStatusCb;
  coco_device_advertise_resource_status_cb_t advResStatusCb;
  coco_device_show_message_status_cb_t showMsgStatusCb;
  coco_device_info_request_status_cb_t infoReqStatusCb;
  coco_device_info_response_cb_t infoResponseCb;
  coco_device_info_response_status_cb_t infoRespStatusCb;
  coco_device_info_request_cb_t infoRequestCb;
  coco_device_connect_status_cb_t coconetConnStatusCb;
  coco_device_attribute_update_status_cb_t attributeUpdateCb;
  coco_device_tunnel_status_cb_t tunnelStatusCb;
  coco_device_firmware_update_cb_t firmwareUpdateCb;
  coco_device_capability_update_status_cb_t capabilityUpdateCb;
  coco_device_get_tunnel_params_cb_t getTunnelParamsCb;
  coco_device_media_stream_accept_cb_t mediaStreamAcceptCb;
  coco_device_media_stream_status_cb_t mediaStreamStatusCb;
  coco_device_storage_upload_accept_cb_t storageUploadAcceptCb;
  coco_device_storage_upload_status_cb_t storageUploadStatusCb;
  coco_device_active_tunnel_clients_cb_t activeTunnelClientsCb;
  coco_device_remove_status_cb_t removeDeviceStatusCb;
  coco_device_remove_request_cb_t removeDeviceRequestCb;
  coco_device_ap_listen_status_cb_t apListenStatusCb;
  coco_device_ap_disconnect_status_cb_t apDisconnectStatusCb;
  coco_device_connectivity_timers_t *connectivityTimers;  // Optional. If it is set to NULL, then the
                                                          // SDK will use the default values.
  coco_device_ap_scan_ssid_cb_t scanSsidCb;
  coco_device_ap_send_ssid_status_cb_t sendSsidStatusCb;
  coco_device_ap_wifi_cred_cb_t wifiCredCb;
  coco_device_internet_status_cb_t internetCb;
  coco_device_capture_snapshot_request_cb_t captureSnapshotRequestCb;
  coco_device_capture_snapshot_status_cb_t captureSnapshotStatusCb;
  coco_device_removed_device_cb_t removedDeviceCb;
  coco_device_data_corruption_cb_t dataCorruptionCb;
  coco_device_scene_execute_cb_t sceneExecuteCb;
} coco_device_init_params_t;

/* Consisting of all cocoDeviceErrno values */
typedef enum {
  COCO_DEVICE_ERROR_MIN = -1,
  COCO_DEVICE_API_SUCCESS,         // No Error
  COCO_DEVICE_API_FAILURE,         // General failure
  COCO_DEVICE_API_EINVAL,          // Invalid input arguments to function
  COCO_DEVICE_API_EPERM,           // Not permitted (perhaps wrong sequence)
  COCO_DEVICE_API_ETIME,           // Timed out
  COCO_DEVICE_ALREADY_PROVISIONED, // Device is already provisioned
  COCO_DEVICE_REMOVE_FAILED,       // Device remove failed
  COCO_DEVICE_ERROR_MAX,
  COCO_DEVICE_ERROR_UBOUND = 0x7FFFFFFF
} coco_device_errno_t;

/* Structure used in fetch attribute API */
typedef struct {
  char *resourceEui;              // Unique Id of resource
  int32_t capabilityId;           // It will take values from the enum - coco_std_capability_t
  int32_t attributeId;
} coco_device_fetch_attr_param_t;

// Possible values which matchType parameter in API coco_device_resource_fetch() can accept
typedef enum {
  COCO_DEVICE_MATCH_TYPE_MIN = -1,
  COCO_DEVICE_MATCH_TYPE_EQUALS,      // Matches exact parameters
  COCO_DEVICE_MATCH_TYPE_CONTAINS,    // Contains matched parameters
  COCO_DEVICE_MATCH_TYPE_MAX,
  COCO_DEVICE_MATCH_TYPE_UBOUND = 0x7FFFFFFF
} coco_device_match_type_t;

typedef enum {
  COCO_DEVICE_MEDIA_STREAM_MIN = 0,
  COCO_DEVICE_MEDIA_STREAM_OPENED,
  COCO_DEVICE_MEDIA_STREAM_FAILED,
  COCO_DEVICE_MEDIA_STREAM_CLOSED,
  COCO_DEVICE_MEDIA_STREAM_MAX,
  COCO_DEVICE_MEDIA_STREAM_INVALID = 0xFFFF
} coco_device_media_stream_status_t;

typedef enum {
  COCO_DEVICE_STORAGE_UPLOAD_MIN = 0,
  COCO_DEVICE_STORAGE_UPLOAD_STARTED,
  COCO_DEVICE_STORAGE_UPLOAD_FAILED,
  COCO_DEVICE_STORAGE_UPLOAD_DONE,
  COCO_DEVICE_STORAGE_UPLOAD_MAX,
  COCO_DEVICE_STORAGE_UPLOAD_INVALID = 0xFFFF
} coco_device_storage_upload_status_t;

/* An enum for connection status to the COCO network */
typedef enum {
  COCO_DEVICE_CONNECT_STATUS_MIN = -1,
  COCO_DEVICE_CONNECTING,
  COCO_DEVICE_CONNECTED,
  COCO_DEVICE_NETWORK_BLOCKED,
  COCO_DEVICE_CONNECT_STATUS_MAX,
  COCO_DEVIVE_CONNECT_STATE_UBOUND = 0x7FFFFFFF
} coco_device_connect_status_t;

/* An enum used to set different modes of connectivity */
typedef enum {
  COCO_DEVICE_CONNECTIVITY_MODE_MIN = -1,
  COCO_DEVICE_CONNECTIVITY_MODE_FOREGROUND,
  COCO_DEVICE_CONNECTIVITY_MODE_BACKGROUND,
  COCO_DEVICE_CONNECTIVITY_MODE_MAX,
  COCO_DEVICE_CONNECTIVITY_MODE_UNBOUND = 0x7FFFFFFF
} coco_device_connectivity_mode_t;

typedef enum {
  COCO_DEVICE_SNAPSHOT_MIN = 0,
  COCO_DEVICE_SNAPSHOT_SUCCESS,
  COCO_DEVICE_SNAPSHOT_FAILURE,
  COCO_DEVICE_SNAPSHOT_TIMEOUT,
  COCO_DEVICE_SNAPSHOT_MAX,
  COCO_DEVICE_SNAPSHOT_INVALID = 0xFFFF
} coco_device_snapshot_status_t;

/*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/
/***********************************************************************************//**
 * @brief Most Recent Error Number
 * A variable holding the last encountered error from the COCO Device SDK.
 * This is a thread local variable that contains the error code of the most recent error
 * encountered by a COCO Device API function called in the current thread.
 * The variable is only updated when an error is encountered, and is not reset if a
 * function returned successfully.
 ******************************************************************************************/
extern threadLocal int32_t cocoDeviceErrno;

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/
/********************************************//**
 * @brief   Initialize the COCO device SDK library.
 * @details It is the first API to be called for initializing the COCO device SDK
 *          and it should be called only once.
 * @param   params  : A pointer to a coco_device_init_params_t struct which contains all
 *                    the parameters required for the initialization
 *                    (can be freed after function returns)
 * @return  int32_t : -1 on failure
 *                    0 if device is not provisioned yet
 *                    1 if device already provisioned
 ***********************************************/
int32_t coco_device_init(coco_device_init_params_t *params);

/********************************************//**
 * @brief   Updates resource capability info
 * @details This handler will update resource capability info. Send the updated resource
 *          capability info to the other nodes
 * @param   resourceAttribute: Resource capability info (can be freed after function returns)
 * @param   context          : User defined context pointer. It will be returned in the
 *                             attributeUpdateCb.
 * @return  int32_t          : 0 on success , -1 on failure
 ***********************************************/
int32_t coco_device_resource_capability_update(coco_std_resource_capability_info_t *resourceCapability,
                                               void *context);

/********************************************//**
 * @brief   Updates resource attribute info
 * @details This handler will update resource attribute info. Send the updated resource
 *          attribute info to the other nodes
 * @param   resourceAttribute: Resource attribute info (can be freed after function returns)
 * @param   context          : User defined context pointer. It will be returned in the
 *                             attributeUpdateCb.
 * @return  int32_t          : 0 on success , -1 on failure
 ***********************************************/
int32_t coco_device_resource_attribute_update(coco_std_resource_attribute_info_t *resourceAttribute,
                                              void *context);

/********************************************//**
 * @brief   Updates resource attribute info in an array
 * @details This handler will update resource attribute info in the form of an array.
 *          Send all the updated resource attribute info to the other nodes.
 * @param   resourceAttribute: Resource attribute info (can be freed after function returns)
 * @param   attributeCount   : Number of attributes to update
 * @param   context          : User defined context pointer. It will be returned in the
 *                             attributeUpdateCb.
 * @return  int32_t          : 0 on success , -1 on failure
 ***********************************************/
int32_t coco_device_resource_attribute_update_arr(coco_std_resource_attribute_info_t *resourceAttribute,
                                                  int attributeCount, void *context);

/********************************************//**
 * @brief   update resource command status
 * @details OEM application must use this API to send a status update to notify the client app.
 * @param   resourceCmdStatus: ptr to the response structure (can be freed after function returns)
 * @param   context          : User defined context pointer. It will be returned in the
 *                             resourceCmdStatusCb.
 * @return  int32_t          : 0 on success, -1 on failure
 ***********************************************/
int32_t coco_device_resource_cmd_status_update(coco_std_resource_cmd_status_t *resourceCmdStatus,
                                               void *context);

/********************************************//**
 * @brief   Returns a standard error description for coco device sdk
 * @details This function returns description of valid error for coco device sdk
 *          library. Use cocoDeviceErrno as errNum which is set to appropriate
 *          coco device error upon call to coco device sdk APIs
 * @param   errNum      : Valid error number registered in coco_device_errno_t enum
 * @return  const char *: A string describing the error
 ***********************************************/
const char *coco_device_strerror(int32_t errNum);

/********************************************//**
 * @brief   Prints errors to standard error output stream
 * @details Prints the standard error description from coco_device_strerror to standard error
 *          output stream with user defined error message description.
 * @param   str: User defined error message description
 * @return  void : None
 ***********************************************/
void coco_device_perror(const char *str);

/********************************************//**
 * @brief   Adds given set resources to the device and updates node info
 * @details This handler will add a given set of resources to the device and updates node info.
 *          Send added resource info to the other nodes.
 * @param   resourceArr   : Pointer to array of resource info structure.
 * @param   resourceArrCnt: Count of resource info structure array.
 * @param   cmdSeqNum: Add resource command sequence number.
 * @param   cmdSenderNodeId: Command sender Node Id of the node which issued the add resource command.
 * @param   context       : User defined context pointer.
 * @return  int32_t       : 0 on success , -1 on failure
 ***********************************************/
int32_t coco_device_add_resource(coco_std_resource_t *resourceArr, uint32_t resourceArrCnt,
                                 uint32_t cmdSeqNum, uint32_t cmdSenderNodeId,
                                 void *context);

/********************************************//**
 * @brief   Sends resource advertisement to client apps
 * @details This handler will send resource advertisement to client apps.
 * @param   resourceAd: Pointer to resource advertise structure.
 * @param   context: User defined context pointer.
 * @return  int : 0 on success , -1 on failure
 ***********************************************/
int32_t coco_device_advertise_resource(coco_std_resource_advertise_t *resourceAd, void *context);

/********************************************//**
 * @brief   Sends message to client apps
 * @details This handler will sends message to client apps.
 * @param   message: Pointer to show message structure.
 * @param   context: User defined context pointer.
 * @return  int : 0 on success , -1 on failure
 ***********************************************/
int32_t coco_device_show_message(coco_std_message_t *message, void *context);

/********************************************//**
 * @brief   Sends info request to client apps
 * @details This handler will send info request to client apps.
 * @param   infoRequest   : Pointer to info request structure.
 * @param   context       : User defined context pointer to be returned in infoReqStatusCb and
 *                          infoResponseCb callback.
 * @return  int32_t       : 0 on success, -1 on failure
 ***********************************************/
int32_t coco_device_info_request(coco_std_info_request_t *infoRequest, void *context);

/********************************************//**
 * @brief   Sends info response to client apps
 * @details This handler will send info response to client apps.
 * @param   infoRequest   : Pointer to info response structure.
 * @param   context       : User defined context pointer to be returned in infoRespStatusCb.
 * @return  int           : 0 on success , -1 on failure
 ***********************************************/
int64_t coco_device_info_response(coco_std_info_response_t *infoResponse, void *context);

/********************************************//**
 * @brief   Sends device command status to client apps
 * @details This handler will send device command status to client apps.
 * @param   deviceCmdStatus: Pointer to device command status structure.
 * @param   context: User defined context pointer.
 * @return  int : 0 on success , -1 on failure
 ***********************************************/
int32_t coco_device_send_device_cmd_status(coco_std_device_cmd_status_t *deviceCmdStatus,
                                           void *context);

/********************************************//**
 * @brief   Coco device sdk init auth API
 * @details API for authorizing the device
 * @param   void
 * @return  int32_t : 0 on success
 *                    -1 on failure
 *                    In case of failure, if cocoDeviceErrno = COCO_DEVICE_ALREADY_PROVISIONED,
 *                    it means that the device is already provisioned.
 *          Note: This API call a blocking call
 ***********************************************/
int32_t coco_device_init_auth(void);

/********************************************//**
 * @brief   Fetch resource attribute info
 * @details API for fetching the attribute info record.
 * @param   fetchAttrParam   : Fetch attribute params structure (can be freed after function returns)
 * @param   fetchAttrParamCnt: fetchAttrParam array length
 * @param   attributeArr     : Reference pointer to attribute info struct. User needs to deallocate
 *                             this pointer once the API return success state.
 * @param   attributeCount   : Number of successfully fetched record.
 * @return  int32_t          : 0 on success
                               -1 on failure
 ***********************************************/
int32_t coco_device_resource_attribute_fetch(coco_device_fetch_attr_param_t *fetchAttrParam,
                                             uint32_t fetchAttrParamCnt,
                                             coco_std_resource_attribute_info_t **attributeArr,
                                             uint32_t *attributeCount);

/********************************************//**
 * @brief   Free firmware update details
 * @details API to free the firmware update details structure and its members
 * @param   fwUpdateDetails: Pointer to coco_device_fw_update_details_t structure
 *                           whose memory has to be freed
 * @return   None
 ***********************************************/
void coco_device_free_fw_update_details(coco_device_fw_update_details_t *fwUpdateDetails);

/********************************************//**
* @brief   Fetch resource entity.
* @details This API is to be used for fetching the resource entity. It is to be used for the resources
*          which have been earlier added using the coco_device_add_resource() API call.
* @param   resourceEuiArr      : An array of resourceEui for which the resource entity is to be returned.
*                                This can be deallocated by the API caller after the API returns.
* @param   resourceEuiArrCnt   : Number of elements in resourceEuiArr.
* @param   matchType           : This takes values from the enum coco_device_match_type_t. This
*                                specifies how should the match between the EUI in resourceEuiArr
*                                and the actual EUI should be performed.
* @param   resourceEntityArr   : The API caller should pass a reference pointer. This pointer will
*                                point to an array of fetched resources based after the function
*                                returns.This can be deallocated by the API caller after
*                                the API returns.
* @param   resourceEntityArrCnt: The API caller should pass a reference pointer. This pointer will
*                                point to the number of elements in resourceEntityArr. This can be
*                                deallocated by the API caller after the API returns.
* @return  int32_t             : 0 on success
                                 -1 on failure
 ***********************************************/
int32_t coco_device_resource_fetch(char **resourceEuiArr, uint32_t resourceEuiArrCnt,
                                   int32_t matchType,
                                   coco_std_resource_t **resourceEntityArr,
                                   uint32_t *resourceEntityArrCnt);

/********************************************//**
 * @brief   Remove resource(s).
 * @details This API is to be used to remove one or more resource(s) which have been added using
 *          coco_device_add_resource() API.
 * @param   resourceEuiArr     : Array containing resourceEUI of the resources to be removed.
 *                               This can be deallocated by the API caller after the API returns.
 * @param   resourceEuiArrCount: Number of elements in the array resourceEuiArr
 * @param   context            : Optional context. This context will be returned in the callback
 *                               coco_device_remove_resource_status_cb_t
 * @return  int32_t            : 0 on success, -1 on failure
 ***********************************************/
int32_t coco_device_remove_resource(char **resourceEuiArr, uint32_t resourceEuiArrCount,
                                    void *context);

/********************************************//**
 * @brief    Set data receive callback for stream channel.
 * @details  This function sets the media stream channel receive callback and it's channel context
 *           streamRecieveCb can be NULL if app indents to set channelContext
 * @param    streamChannelHandle : Media stream channel handle
 * @param    streamRecieveCb     : Media stream channel receive callback
 * @param    channelContext      : Media stream channel context
 * @return   int32_t             : 0 on success, -1 on failure
 ***********************************************/
int32_t coco_device_set_channel_receive_cb(coco_device_channel_handle_t *streamChannelHandle,
                                           coco_device_media_stream_receive_cb_t streamRecieveCb,
                                           void *channelContext);

/********************************************//**
 * @brief    Send data over a media stream channel
 * @details  This function sends data on a media stream channel of a media stream session
 * @param    streamChannelHandle : Media stream channel handle
 * @param    data                : Pointer to data buffer that needs to be sent on channel
 * @param    len                 : Length of the data buffer that needs to be sent on channel
 * @return   ssize_t             : The amount of data that was queued in bytes and -1 on failure
 ***********************************************/
ssize_t coco_device_channel_data_send(coco_device_channel_handle_t *channelHandle, const void *data,
                                      size_t len);

/********************************************//**
 * @brief   Stop storage upload session
 * @details This function closes all the upload channels to the storage node and frees the uploadHandle.
 * @param   params              : A pointer to a coco_device_storage_upload_handle_t struct which
 *                                is the obtained in the status callback.
 * @return  int32_t             : 0 on success , -1 on failure
 ***********************************************/
int coco_device_storage_upload_stop(coco_device_storage_upload_handle_t *uploadHandle);

/********************************************//**
 * @brief   Sends upload command request for the upload session.
 * @details This function sends the upload command to the storage node i.e, initiating upload session
 * @param   params              : A pointer to a coco_device_storage_upload_params_t struct which
 *                                contains all the parameters required for the initialization
 * @param   uploadContext       : Context that needs to be set for that upload handle
 * @return  int32_t             : 0 on success , -1 on failure
 ***********************************************/
 int coco_device_storage_upload_start(coco_device_storage_upload_params_t *params,
                                      void *uploadContext);

/********************************************//**
 * @brief   Set receive callback function for the upload data channel
 * @details This function sets the data receive callback for storage upload channel receive callback
 * @param   streamChannelHandle : Data channel handle of the upload handle
 * @param   recieveCb           : Data channel receive callback that needs to set
 * @param   channelContext      : Context that needs to be set for that channel handle
 * @return  int32_t             : 0 on success , -1 on failure
 ***********************************************/
int32_t coco_device_set_upload_channel_receive_cb(coco_device_channel_handle_t *channelHandle,
                                                  coco_device_storage_upload_receive_cb_t recieveCb,
                                                  void *channelContext);

/********************************************//**
 * @brief   Set data stream channel send and receive buffers
 * @details This function sets the data stream channels with the passed explicit buffers which will
 *          be used for networking the send and receive traffic. Existing data will be re-allocated to
 *          the new buffers and while closing the channel those buffers will be remained untouched.
 *          If buffer pointer and buffer size both are set to NULL and 0 respectively
 *          (for either send type or receive type or both) then that buffer type is ignored.
 *          If buffer pointer is set to NULL and size is a non-zero positive integer
 *          (for either send or receive or both) then the channel is set to an internally allocated
 *          heap memory of the mentioned size bytes and will be maintained by internally.
 *          If buffer pointer (either send or receive or both) is non NULL and size is
 *          not a positive integer then it is considered as an error
 * @param   dataStreamHandle   : Data stream handle
 * @param   sendBuf            : Send buffer pointer
 * @param   sendBufSize        : Send buffer size
 * @param   recvBuf            : Receive buffer pointer
 * @param   recvBufSize        : Receive buffer size
 * @return  int                : -1 in case of invalid parameters passed to the API,
 *                               0 in case of success.
 ***********************************************/
int32_t coco_device_set_channel_buffers(coco_device_channel_handle_t *streamChannelHandle,
                                        void *sendBuf, size_t sendBufsize, void *recvBuf,
                                        size_t recvBufsize);

/********************************************//**
 * @brief   Closes media stream
 * @details This function closes all the associated media stream data channels and frees up
 *          the streamHandle.
 * @param   streamHandle        : media stream handle that needs to closed
 * @return  int32_t             : 0 on success, -1 on failure
 ***********************************************/
int32_t coco_device_media_stream_close(coco_device_media_stream_handle_t *streamHandle);

/********************************************//**
 * @brief   Get Active Tunnel Clients
 * @details This API is to be used to get active tunnel clients
 * @param   requestContext  : Request Context
 * @return  int32_t         : 0 on success, -1 on failure
 ***********************************************/
int32_t coco_device_get_active_tunnel_clients(void *requestContext);

/********************************************//**
 * @brief   Free active tunnel clients array
 * @details API to free the active tunnel clients array
 * @param   activeTunnelClientArr  : Active tunnel client array
 * @return  None
 ***********************************************/
void coco_device_free_active_tunnel_clients_array(uint32_t *activeTunnelClientArr);

/********************************************//**
 * @brief   Set Tunnel send buffer size
 * @details API to set the user defined send buffer pointer and send buffer size
 * @param   tunnelHandle  : Tunnel handle pointer
 * @param   buffer        : User defined tunnel send buffer pointer
 * @param   bufferSize    : User defined tunnel send buffer size
 * @return  int32_t       : 0 on success, -1 on failure
 ***********************************************/
int32_t coco_device_tunnel_set_send_buff(coco_device_tunnel_handle_t *tunnelHandle, void *buffer,
                                         size_t bufferSize);

/********************************************//**
 * @brief   Set Tunnel receive buffer size
 * @details API to set the user defined receive buffer pointer and receive buffer size
 * @param   tunnelHandle  : Tunnel handle pointer
 * @param   buffer        : User defined tunnel receive buffer pointer
 * @param   bufferSize    : User defined tunnel receive buffer size
 * @return  int32_t       : 0 on success, -1 on failure
 ***********************************************/
int32_t coco_device_tunnel_set_recv_buff(coco_device_tunnel_handle_t *tunnelHandle, void *buffer,
                                         size_t bufferSize);

/********************************************//**
 * @brief   Close all tunnels belonging to a session
 * @details This API closes all the tunnels which are having the given session ID
 *          to the specified node Id.
 * @param   nodeId     : Node ID of the node for which session has to be closed.
 * @param   sessionId  : Id of the session to be closed
 * @return  int32_t    : Count of number of tunnels under the specified session Id
 *                       for the given node Id which are closed
 ***********************************************/
int32_t coco_device_tunnel_close_session(int32_t nodeId, int32_t sessionId);

/********************************************//**
 * @brief   Fetches available ports
 * @details This API gets portCount no. of available ports for nodeId.
 *          Allocated port array can be freed using coco_device_free_port_array() API
 * @param   nodeId     : Node ID of the node for which ports need to fetched.
 * @param   portCount  : Number of ports requested
 * @return  uint16_t * : Array of requested no. of ports on success, NULL on failure
 ***********************************************/
uint16_t *coco_device_get_available_port(uint32_t nodeId, uint16_t portCount);

/********************************************//**
 * @brief   Frees port array
 * @details This API deallocates the port array that was allocated by coco_device_get_available_port()
 * @param   portArray  : Port array
 * @return  None
 ***********************************************/
void coco_device_free_port_array(uint16_t *portArray);

/********************************************//**
 * @brief   Factory reset a device.
 * @details This API should be called in order to factory reset the device. Device SDK will cleanup
 *          its data and invoke coco_device_remove_request_cb_t() with factoryResetFlag as 1 where any
 *          required cleanup in OEM app layer can be done. coco_device_remove_status_cb_t() callback
 *          will give the status of the factory reset process.
 * @param   None
 * @return  int32_t: 0 on success
                    -1 on failure
 ***********************************************/
int32_t coco_device_factory_reset();

/********************************************//**
 * @brief   Getter function to get current node details
 * @details This function returns the nodeId and networkId of the current node.
 *          NetworkId scope will be within the device sdk
 * @param   deviceNodeId : deviceNodeId pointer to be filled
 * @param   networkId: Network id to be filled
 * @param   devicePsn: devicePsn pointer to be filled
 * @return  int32_t: 0 on success
 *                  -1 on failure
 ***********************************************/
int32_t coco_device_get_my_node_details(uint32_t *deviceNodeId, char **networkId, char **devicePsn);

/********************************************//**
 * @brief   API to set connectivity mode
 * @details After fastRetryDuration, SDK will try to connect to other nodes at
 *          intervals which will keep on increasing with each retry. foregroundMaxRetryPeriod or
 *          backgroundMaxRetryPeriod in seconds is the maximum value of this interval depending
 *          upon whether this API is called with foreground or background connectivity mode
 *          respectively. This API is used to set the connectivity mode as foreground or background.
 *          In case it is called to set the state as foreground, the interval after which the
 *          connection to other nodes is retried will be reset.
 * @param   mode      : Connectivity mode specified in coco_device_connectivity_mode_t
 * @return  int32_t   : 0 on success, -1 on failure
 ***********************************************/
int32_t coco_device_set_connectivity_mode(int32_t mode);

/********************************************//**
 * @brief   Call this API in order to start the flow for adding a WiFi device using access point.
 * @details This API will start a listening server to which client will connect to.
 * @param   context: Optional context. This context will be returned in the callback
 *                   coco_device_ap_listen_status_cb_t
 * @return  int32_t: 0 on success
 *                   -1 on failure
 ***********************************************/
int32_t coco_device_ap_listen(void *context);

/********************************************//**
 * @brief    Call this API in order to terminate the flow for adding a WiFi device using access point.
 * @details  This API will stop the listening server to which client can connect to.
 * @param    context: Optional context. This context will be returned in the callback
 *                    coco_device_ap_listen_status_cb_t
 * @return  int32_t: 0 on success, -1 on failure
 ***********************************************/
int32_t coco_device_ap_disconnect(void *context);

/********************************************//**
 * @brief   This API to send list SSIDs
 * @details This API will send the list of SSIDs provided in input to the
 *          client app which had sent a request for scanning SSIDs.
 * @param   ssidArr    : ssid array pointer
 * @param   ssidArrCnt : ssid array count
 * @param   context    : Optional context which will be returned
                         in coco_device_ap_send_ssid_status_cb_t()
 * @return  int32_t    : 0 on success,
 *                       -1 on failure
 ***********************************************/
int32_t coco_device_ap_send_ssid(char **ssidArr, uint32_t ssidArrCnt, void *context);

/********************************************//**
 * @brief    Check Internet connectivity
 * @details  This API checks whether the device is connected to Internet or
 *           not by pinging one of the COCO servers
 * @param    context : Optional context which will be received back in
 *                     callback coco_device_internet_status_cb_t
 * @return   int     : Return 0 on success -1 on failure
 ***********************************************/
int32_t coco_device_check_internet(void *context);

/********************************************//**
 * @brief    Sends snapshot to requested node
 * @details  This API sends the captured snapshot file/image associated with the snapshotId.
 * @param    snapshotId       : Snapshot ID.
 * @param    filePath         : Snapshot file path that needs to be sent.
 * @param    customBuffer     : (Opt.) Custom Tx buffer used for buffering the file,
 *                              ignored if set with NULL.
 * @param    customBufferSize : (Opt.) Custom Tx buffer length in bytes
 * @param    context          : Context pointer, which will be returned in
 *                              coco_device_capture_snapshot_status_cb_t callback.
 * @return   int              : Return 0 on success -1 on failure.
 ***********************************************/
int coco_device_capture_snapshot(uint32_t snapshotId, char *filePath, void *customBuffer,
                                 uint32_t customBufferSize, void *context);

/********************************************//**
 * @brief    Request the destination node to capture a snapshot
 * @details  This API sends the snapshot capture request and fetches the file/image associated
 * @param    params    : A pointer to a coco_device_capture_snapshot_request_params_t struct which
 *                       contains all the parameters required for the initialization
 * @param    context   : Context pointer, which will be returned in
 *                       coco_device_capture_snapshot_request_status_cb_t callback which is set in
 *                       params data structure.
 * @return   int       : Return 0 on success -1 on failure
 ***********************************************/
int coco_device_capture_snapshot_request(coco_device_capture_snapshot_request_params_t *params,
                                         void *context);

/********************************************//**
 * @brief   Publish the attribute update to the network
 * @details This API is to be used only for publishing the attribute update to the other nodes
 *          in the network. Device SDK will not cache the attribute state. It will also not
 *          trigger any rule processing or notifications. If any of this is required,
 *          use coco_device_resource_attribute_update() API.
 * @param   resourceAttribute: Attribute update to be published to the other nodes in the network
 * @return  int              : Return 0 on success -1 on failure
 ***********************************************/
int32_t coco_device_publish_resource_attribute(coco_std_resource_attribute_info_t *resourceAttribute);

/********************************************//**
 * @brief   Publish the logs to remote server
 * @details This API is used to send logs to remote server with EMERGENCY level
 * @param   format: format of logs
 * @return  None
 ***********************************************/
void coco_device_tx_user_log_msg(const char *format, ...);

#endif // COCO_DEVICE_API_H_INCLUDED
