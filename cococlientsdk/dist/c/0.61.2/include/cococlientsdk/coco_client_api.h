/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_client_api.h
 * @brief     COCO App SDK public API
 * @details   The COCO App SDK public API allows for rapid development of
 *            IoT enabled applications in a P2P network. This library is POSIX compliant
 *            and portable to multiple platforms and operating systems.
 * @author    Virajitha Palepu, Virajitha.Palepu@healthasyst.com
 * @author    Bala Krishna Kurmapu, balakrishna.kurmapu@healthasyst.com
 * @author    Prajeesh Prakash, prajeeshprakash@elear.solutions
 * @author    Varun Kumar, varun.k@healthasyst.com
 * @copyright Copyright (c) 2018-2020 Elear Solutions Tech Private Limited. All rights
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
#ifndef COCO_CLIENT_API_H_INCLUDED
#define COCO_CLIENT_API_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/
#include "cocostandard/coco_std_api.h"
#include "cocostandard/coco_std_data_tunnel_types.h"
#include "cocostandard/coco_std_data_media_stream_types.h"
#include <stdbool.h>

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
#define COCO_CLIENT_DEFAULT_FAST_RETRY_DURATION             20
#define COCO_CLIENT_DEFAULT_BACKGROUND_MAX_RETRY_PERIOD     600
#define COCO_CLIENT_DEFAULT_FOREGROUND_MAX_RETRY_PERIOD     30
#define COCO_CLIENT_DEFAULT_KEEP_ALIVE_TIMEOUT              5
#define COCO_CLIENT_DEFAULT_KEEP_ALIVE_INTERVAL             10

/*************************************************************************************
 *                          GLOBAL TYPEDEFS                                          *
 *************************************************************************************/
/**
 * An enum for status of the cocoNet
 */
typedef enum {
  COCO_CLIENT_COCONET_STATE_MIN = -1,
  COCO_CLIENT_CONNECTED,               // Connected to at least one other node in the COCONet
  COCO_CLIENT_CONNECTING,              // Trying to establish connection with the nodes in the COCONet
  COCO_CLIENT_CONNECT_ERROR,           // Failed to join the COCONet
  COCO_CLIENT_COCONET_RESET,           // User is no longer part of the COCONet
  COCO_CLIENT_DISCONNECTED,            // Disconnected from the COCONet
  COCO_CLIENT_COCONET_STATE_MAX,
  COCO_CLIENT_COCONET_STATE_UBOUND = 0x7FFFFFFF
} coco_client_coconet_state_t;

/**
 * An enum for status of the tunnel
 */
typedef enum {
  COCO_TUNNEL_STATUS_MIN = -1,
  COCO_TUNNEL_OPENING,
  COCO_TUNNEL_OPENED,
  COCO_TUNNEL_REOPENED,
  COCO_TUNNEL_OPEN_FAILED,
  COCO_TUNNEL_CLOSED,
  COCO_TUNNEL_CLOSE_FAILED,
  COCO_TUNNEL_TIMEOUT,
  COCO_TUNNEL_MAX_CLIENT_REACHED,
  COCO_TUNNEL_STATUS_MAX,
  COCO_TUNNEL_STATUS_UBOUND = 0x7FFF
} coco_tunnel_status_t;

/**
 * An enum of all cocoClientErrno values
 */
typedef enum {
  COCO_CLIENT_ERROR_MIN = -1,
  COCO_CLIENT_API_SUCCESS,          // No Error
  COCO_CLIENT_API_FAILURE,          // General failure
  COCO_CLIENT_API_EINVAL,           // Invalid input arguments to function
  COCO_CLIENT_API_EPERM,            // Not permitted (perhaps wrong sequence)
  COCO_CLIENT_API_ETIME,            // Timed out
  COCO_CLIENT_API_TOKEN_NOT_SET,    // Access Token is not set
  COCO_CLIENT_API_NOT_SUPPORTED,    // Not supported for the coconetType
  COCO_CLIENT_ERROR_MAX,
  COCO_CLIENT_ERROR_UBOUND = 0x7FFFFFFF
} coco_client_errno_t;

/**
 * An enum for coco client tunnel protocol type
 */
typedef enum{
  COCO_CLIENT_TUNNEL_PROTOCOL_MIN,
  COCO_CLIENT_TUNNEL_PROTOCOL_TCP,
  COCO_CLIENT_TUNNEL_PROTOCOL_UDP,
  COCO_CLIENT_TUNNEL_PROTOCOL_MAX,
  COCO_CLIENT_TUNNEL_PROTOCOL_UBOUND = 0x7FFF
} coco_tunnel_protocol_type_t;

/**
 * An enum for different types of COCO Network
 */
typedef enum {
  COCO_CLIENT_COCONET_TYPE_MIN = -1,
  COCO_CLIENT_COCONET_TYPE_IOT,
  COCO_CLIENT_COCONET_TYPE_CALL_NET,
  COCO_CLIENT_COCONET_TYPE_MAX,
  COCO_CLIENT_COCONET_TYPE_UBOUND = 0x7FFF
} coco_client_coconet_type_t;

/* Coco client sdk coconet structure  */
typedef struct {
  char *networkId;
  char *networkName;
  uint16_t clusterPort;   /* Physical port to be used for cluster communication.
                             Application is reposible for providing an available port.
                             Each COCONet requires a unique node. Set this to 0 for
                             the SDK to choose a port on its own. This is not set
                             by the SDK when the list of COCONets is fetched.*/
  int32_t userRole;       // It takes values from coco_std_user_role_type_t enum
  int32_t accessType;     // It takes values from coco_std_access_type_t enum
  void *coconetContext;
  int32_t coconetType;    // It will take values from enum coco_client_coconet_type_t
} coco_client_coconet_t;

typedef enum {
  COCO_CLIENT_MEDIA_STREAM_MIN = 0,
  COCO_CLIENT_MEDIA_STREAM_OPENED,
  COCO_CLIENT_MEDIA_STREAM_FAILED,
  COCO_CLIENT_MEDIA_STREAM_CLOSED,
  COCO_CLIENT_MEDIA_STREAM_TIMEOUT,
  COCO_CLIENT_MEDIA_MAX_CLIENT_REACHED,
  COCO_CLIENT_MEDIA_STREAM_MAX,
  COCO_CLIENT_MEDIA_STREAM_INVALID = 0xFFFF
} coco_client_data_stream_status_t;

typedef enum {
  COCO_CLIENT_SNAPSHOT_MIN = 0,
  COCO_CLIENT_SNAPSHOT_SUCCESS,
  COCO_CLIENT_SNAPSHOT_FAILURE,
  COCO_CLIENT_SNAPSHOT_TIMEOUT,
  COCO_CLIENT_SNAPSHOT_MAX,
  COCO_CLIENT_SNAPSHOT_INVALID = 0xFFFF
} coco_client_snapshot_status_t;

typedef struct {
  void *context;
  uint16_t channelPort;
} coco_client_channel_handle_t;

typedef  struct {
  uint32_t deviceNodeId;
  char *networkId;
  char *resourceEui;
  uint32_t streamId;
  int32_t streamSessionId;
  uint32_t channelHandleCount;
  coco_client_channel_handle_t **channelHandleArr;
  coco_std_stream_buffer_sizes_t streamBufferSizes;
  void *streamContext;
} coco_client_media_stream_handle_t;

/* Coco client sdk network data structure  */
typedef struct {
  uint32_t deviceNodeId;
  char *deviceName;
} coco_client_device_t;

typedef struct {
  char *networkId;
  uint32_t deviceArrCnt;
  coco_client_device_t *deviceArr;
  uint32_t zoneArrCnt;
  coco_std_zone_entity_t *zoneArr;
  uint32_t sceneArrCnt;
  coco_std_scene_entity_t *sceneArr;
  uint32_t ruleArrCnt;
  coco_std_rule_entity_t *ruleArr;
} coco_client_network_data_t;

/// A callback to save the key chain on application
/** @param key    Key that refers the value
 *  @param value  Value that associated with key
 */
typedef void (*coco_client_save_to_keychain_fn_t)(char *key, char *value);

/// A callback provide the saved value based on the key
/** @param  key    Key that refers the value
 *  @return value  Value that associated with key
 */
typedef char *(*coco_client_retrieve_from_keychain_fn_t)(char *key);

/// A callback to initiate an OAuth 2.0 authorization flow to get an access token
/// and optionally a refresh token
/** @param authorizationEndpoint  Authorization endpoint for coco authorization server; hard coded in SDK
 *  @param tokenEndpoint          Token endpoint for coco authorization server; hard coded in SDK
 */
typedef void (*coco_client_start_auth_fn_t)(const char *authorizationEndpoint, const char *tokenEndpoint);

/// A callback that provides the information about connection status of a CocoNet
/** @param networkId            NetworkId of the CocoNet
 *  @param coconetStatus        Connection status of the CocoNet. It takes values from
 *                              coco_client_coconet_state_t enum.
 *  @param coconetContext       context of the CocoNet
 */
typedef void (*coco_client_connect_status_cb_t)(char *networkId, int32_t coconetStatus,
                                                void *coconetContext);

/// A callback that provides the list of COCO Network(s) that the user is part of.
/** @param coconetArr      List of COCO Network(s) that the user is part of. Developer
 *                         should free it using #coco_client_free_coconets() API.
 *  @param coconetArrCnt   Number of COCO Network(s) that the user is part of.
 *                         0 if user is not part of any COCO Network
 *                         -1 in case of error
 *  @param requestContext  User's context passed into coco_client_get_all_coconets() API call.
 */
typedef void (*coco_client_get_coconets_cb_t)(coco_client_coconet_t *coconetArr, int32_t coconetArrCnt,
                                              void *requestContext);

/// A callback that provides the resource details coming from a device.
/** @param resource            Allocated resource structure, user needs to free.
 *  @param coconetContext      Context of the cocoNet
 */
typedef void (*coco_client_resource_cb_t)(coco_std_resource_t *resource, void *coconetContext);

/// A callback that provides the resource capability info from device.
/** @param resourceCapability  Allocated resource capability info structure, user needs to free.
 *  @param coconetContext      Context of the cocoNet
 */
typedef void (*coco_client_resource_capability_cb_t)(coco_std_resource_capability_info_t *resourceCapability,
                                                     void *coconetContext);

/// A callback that provides the resource attribute info from device.
/** @param resourceAttribute  Allocated resource attribute info structure, user needs to free.
 *  @param coconetContext     Context of the cocoNet
 */
typedef void (*coco_client_resource_attribute_cb_t)(coco_std_resource_attribute_info_t *resourceAttribute,
                                                    void *coconetContext);

/// A callback that provides the resource command status from device.
/** @param resourceCmdStatus  Allocated resource command status structure, user needs to free.
 *  @param cmdContext         Command context of the command
 *  @param coconetContext     Context of the cocoNet
 */
typedef void (*coco_client_resource_cmd_status_cb_t)(coco_std_resource_cmd_status_t *resourceCmdStatus,
                                                     void *cmdContext, void *coconetContext);

/// A callback that provides the device management command status from device.
/** @param deviceCmdStatus  Allocated device management command status structure, user needs to free.
 *  @param cmdContext       Command context of the command
 *  @param coconetContext   Context of the cocoNet
 */
typedef void (*coco_client_device_mgmt_cmd_status_cb_t)(coco_std_device_cmd_status_t *deviceCmdStatus,
                                                        void *cmdContext, void *coconetContext);

/// A callback that provides the resource advertise from device.
/** @param resourceAd      Allocated resource advertise structure, user needs to free.
 *  @param coconetContext  Context of the cocoNet
 */
typedef void (*coco_client_advertise_resource_cb_t)(coco_std_resource_advertise_t *resourceAd,
                                                    void *coconetContext);

/// A callback that provides the message from device.
/** @param resourceAd      Allocated message structure, user needs to free.
 *  @param cmdContext      Command context of the command
 *  @param coconetContext  Context of the cocoNet
 */
typedef void (*coco_client_message_cb_t)(coco_std_message_t *message, void *cmdContext,
                                         void *coconetContext);

/// A callback that provides the message from device.
/** @param resourceAd      Allocated message structure, user needs to free.
 *  @param cmdContext      Command context of the command
 *  @param coconetContext  Context of the cocoNet
 */
typedef void (*coco_client_info_request_cb_t)(coco_std_info_request_t* infoRequest, void *cmdContext,
                                              void *coconetContext);

/// A callback that provides the response to device on particular request.
/** @param infoResponse      Allocated response structure, user needs to free.
 *  @param cmdContext        Command context of the command
 *  @param coconetContext    Context of the cocoNet
 */
typedef void (*coco_client_info_response_cb_t)(coco_std_info_response_t* infoResponse, void *cmdContext,
                                               void *coconetContext);

/// A callback that provides the COCONet management command status
/** @param coconetCmdStatus  coconet command status structure, User needs to free this pointer.
 *  @param cmdContext        Command context of the command
 *  @param coconetContext    Context of the cocoNet
 */
typedef void (*coco_client_coconet_mgmt_cmd_status_cb_t)(
               coco_std_coconet_mgmt_cmd_status_t *coconetCmdStatus, void *cmdContext,
               void *coconetContext);

/// A callback that provides the device information from device.
/** @param resourceAd      Allocated message structure, user needs to free.
 *  @param cmdContext      Command context of the command
 *  @param coconetContext  Context of the cocoNet
 */
typedef void (*coco_client_device_info_cb_t)(coco_std_device_info_t *deviceInfo, void *coconetContext);

/// A callback that provides the info response transmission status.
/** @param status   Status of the info response transmission. It takes values from
 *                  coco_std_status_code_t enum.
 *  @param context  User's context.
 */
typedef void (*coco_client_info_response_status_cb_t)(int32_t status, void *context);

/// A callback that provides the info request transmission status.
/** @param status   Status of the info request transmission. It takes values from
 *                  coco_std_status_code_t enum.
 *  @param context  User's context.
 */
typedef void (*coco_client_info_request_status_cb_t)(int32_t status, void *context);

/// A callback that provides the added resource notification .
/** @param resourceAddNotf   Allocated resource added structure, user needs to free.
 *  @param coconetContext    Context of the cocoNet
 */
typedef void (*coco_client_resource_added_cb_t)(coco_std_added_resource_t *resourceAddNotf,
                                                void *coconetContext);

/// A callback that provides the removed resource notification.
/** @param resourceRemoveNotf   Allocated resource removed structure, user needs to free.
 *  @param coconetContext       Context of the cocoNet
 */
typedef void (*coco_client_resource_removed_cb_t)(coco_std_removed_resource_t *resourceRemoveNotf,
                                                  void *coconetContext);

/// A callback that provides the added zone notification.
/** @param zoneInfo        Allocated zone entity structure, user needs to free.
 *  @param coconetContext  Context of the cocoNet
 */
typedef void (*coco_client_zone_info_cb_t)(coco_std_zone_entity_t *zoneInfo, void *coconetContext);

/// A callback that provides the added scene info notification.
/** @param sceneInfo       Allocated scene entity structure, user needs to free.
 *  @param coconetContext  Context of the cocoNet
 */
typedef void (*coco_client_scene_info_cb_t)(coco_std_scene_entity_t *sceneInfo, void *coconetContext);

/// A callback that provides the added rule info notification.
/** @param ruleInfo        Allocated rule entity structure, user needs to free.
 *  @param coconetContext  Context of the cocoNet
 */
typedef void (*coco_client_rule_info_cb_t)(coco_std_rule_entity_t *ruleInfo, void *coconetContext);

/// A callback that provides the deleted zone info notification.
/** @param zoneInfo        Allocated zone deleted structure, user needs to free.
 *  @param coconetContext  Context of the cocoNet
 */
typedef void (*coco_client_zone_deleted_cb_t)(coco_std_zone_deleted_t *zoneDeleted, void *coconetContext);

/// A callback that provides the deleted scene info notification.
/** @param sceneInfo       Allocated scene deleted structure, user needs to free.
 *  @param coconetContext  Context of the cocoNet
 */
typedef void (*coco_client_scene_deleted_cb_t)(coco_std_scene_deleted_t *sceneDeleted,
                                               void *coconetContext);

/// A callback that provides the deleted rule info notification.
/** @param ruleInfo         Allocated rule deleted structure, user needs to free.
 *  @param coconetContext   Context of the cocoNet
 */
typedef void (*coco_client_rule_deleted_cb_t)(coco_std_rule_deleted_t *ruleDeleted, void *coconetContext);

/// This callback provides the composite network data consisting of device, zone, scene and rule list.
/// This callbacks can only be provided if node of type COCO_STD_NODE_TYPE_NETWORK is online.
/** @param networkData      Allocated network data structure, user needs to free.
 *  @param coconetContext   Context of the cocoNet
 */
typedef void (*coco_client_network_data_cb_t)(coco_client_network_data_t *networkData, void *coconetContext);

/* Tunnel callbacks */
typedef struct cp_tunnel_handle_t coco_client_tunnel_handle_t;

/// A callback that provides tunnel operation status.
/** @param tunnelHandle     Tunnel handle
 *  @param status           Tunnel operation status. It takes values from coco_std_tunnel_status_t
 *                          enum.
 *  @param port             Listening port
 *  @param coconetContext   Context of the cocoNet
 *  @param tunnelContext    User's context.
 */
typedef void (*coco_client_tunnel_status_cb_t)(coco_client_tunnel_handle_t *tunnelHandle,
                                               int32_t status, uint16_t port, void *coconetContext,
                                               void *tunnelContext);

/// A callback that provides firmware update notification.
/** @param tunnelHandle     Tunnel handle
 *  @param status           Tunnel operation status
 *  @param port             Listening port
 *  @param coconetContext   Context of the cocoNet
 *  @param tunnelContext    User's context.
 */
typedef void (*coco_client_fw_update_notif_cb_t)(coco_std_fw_update_notif_t *fwUpdateNotif,
                                                 void *coconetContext);

/// A callback that provides the access token to the application
/** @param accessToken  Pointer to access token JSON string in case of success
 *                      NULL in case access token fetch fails
 *  @param status       Status of coco_client_get_access_token API call. It takes values from the enum
 *                      coco_std_status_code_t. Possible values of status here are:
 *                      COCO_STD_STATUS_SUCCESS,             // Success
 *                      COCO_STD_STATUS_TOKEN_NOT_SET,       // Access token not set
 *                      COCO_STD_STATUS_CONNECTIVITY_ERROR,  // Failed to refresh the token due to
 *                                                           // connectivity error
 *                      COCO_STD_STATUS_TOKEN_REFRESH_FAILED // Refresh token is no longer valid and
 *                                                           // coco_client_set_tokens should be called
 *  @param context      User defined context pointer
 */
typedef void (*coco_client_access_token_cb_t)(char *accessToken, int32_t status, void *context);

/// This callback provides the connection status for each node
/** @param networkId        networkId ID of the network to which the node belongs to.
 *  @param nodeId           nodeId ID of the node which got connected or disconnected.
 *  @param nodeType         nodeType Type of the node which got connected or disconnected.
 *                          It takes values from coco_std_node_type_t enum.
 *  @param isOnline         1 if node got connected and 0 if node got disconnected
 *  @param coconetContext   Context passed for the network in the connect API
 */
typedef void (*coco_client_node_connect_status_cb_t)(char *networkId, uint32_t nodeId,
                                                     int32_t nodeType, int32_t isOnline,
                                                     void *coconetContext);

/// A callback that provides the refresh token status to the application
/** @param status : Refresh token status
 *                  COCO_STD_STATUS_SUCCESS            - On success
 *                  COCO_STD_STATUS_CONNECTIVITY_ERROR - On failure
 */
typedef void (*coco_client_refresh_token_status_cb_t)(int32_t status);

/// A callback that provides the media stream status to the application
/** @param streamHandle    Stream handle pointer
 *  @param channelHandle   Stream channel handle pointer
 *  @param status          Stream channel connection status
 *  @param coconetContext  Context passed for the network in the connect API
 *  @param streamContext   Context passed for stream handle in the stream open API or accept callback
 *  @param channelContext  Context passed for stream channel in set channel receive callback API
 */
typedef void (*coco_client_media_stream_status_cb_t)(coco_client_media_stream_handle_t *streamHandle,
                                                      coco_client_channel_handle_t *channelHandle,
                                                      uint16_t channelPort, int32_t status,
                                                      void *coconetContext, void *streamContext,
                                                      void *channelContext);

/// A callback that provides the media stream receive callback to the application
/** @param streamHandle    Stream handle pointer
 *  @param channelHandle   Stream channel handle pointer
 *  @param data            Pointer to the received data from the stream channel to the app
 *  @param len             Length of the received data
 *  @param coconetContext  Context passed for the network in the connect API
 *  @param streamContext   Context passed for stream handle in the stream open API or accept callback
 *  @param channelContext  Context passed for stream channel in set channel receive callback API
 */
typedef void (*coco_client_media_stream_receive_cb_t)(coco_client_media_stream_handle_t *streamHandle,
                                                       coco_client_channel_handle_t *channelHandle,
                                                       void *data, size_t len, void *coconetContext,
                                                       void *streamContext, void *channelContext);

/// A callback that provides the snapshot capture status to the application
/** @param filePath        File path to the captured snapshot
 *  @param status          Snapshot capture status
 *  @param coconetContext  Context passed for the network in the connect API
 *  @param snapshotContext Context passed in the coco_client_capture_snapshot() API
 */
typedef void (*coco_client_snapshot_status_cb_t)(const char *filePath,
                                                 coco_client_snapshot_status_t status,
                                                 void *coconetContext, void *snapshotContext);

/// A callback that provides the leave from coconet status to the application
/** @param status          Leave from coconet status. status takes values from the enum
 *                          coco_std_status_code_t. Possible status are
 *                          COCO_STD_STATUS_SUCCESS
 *                          COCO_STD_STATUS_FAILURE
 *  @param requestContext  Context passed in the coco_client_leave_coconet() API
 */
typedef void (*coco_client_leave_coconet_status_cb_t)(int32_t status, void *requestContext);

/// A callback that provides the content info received from another application in the network
/** @param metadata       Content metadata set by the application sending the content info.
 *                        It can be used to share information like content URL, etc.
 *  @param contentTime    Content time in milliseconds adjusted for the network latency
 *  @param srcNodeId      Node ID of the application which sent the content info
 *  @param coconetContext Context passed for the network in the connect API
 */
typedef void (*coco_client_content_info_cb_t)(char *metadata, int32_t contentTime,
                                              uint32_t srcNodeId, void *coconetContext);

/// A callback that provides metadata set for the network usually during network creation.
/** @param metadata        Network metadata.
 *  @param coconetContext  Context passed for the network in the connect API
 */
typedef void (*coco_client_network_metadata_cb_t)(char *metadata, void *coconetContext);

/// A callback that provides the data received from another application in the network
/** @param data            Data sent by the application
 *  @param srcNodeId       Node ID of the application which sent the data
 *  @param coconetContext  Context passed for the network in the connect API
 */
typedef void (*coco_client_data_cb_t)(char *data, uint32_t srcNodeId, void *coconetContext);

/* Coco client sdk callback structure */
typedef struct {
  coco_client_connect_status_cb_t appConnectStatusCb;
  coco_client_resource_cb_t appResourceCb;
  coco_client_resource_capability_cb_t appResCapabilityCb;
  coco_client_resource_attribute_cb_t appResAttributeCb;
  coco_client_resource_cmd_status_cb_t appResCmdStatusCb;
  coco_client_get_coconets_cb_t appCoconetListCb;
  coco_client_device_mgmt_cmd_status_cb_t appDeviceMgmtCmdStatusCb;
  coco_client_advertise_resource_cb_t appAdvertiseResCb;
  coco_client_message_cb_t appMessageCb;
  coco_client_info_request_cb_t appInfoRequestCb;
  coco_client_info_response_status_cb_t appInfoResponseStatusCb;
  coco_client_coconet_mgmt_cmd_status_cb_t appCoconetMgmtCmdStatusCb;
  coco_client_resource_added_cb_t appResourceAddedCb;
  coco_client_resource_removed_cb_t appResourceRemovedCb;
  coco_client_device_info_cb_t appDeviceInfoCb;
  coco_client_tunnel_status_cb_t appTunnelStatusCb;
  coco_client_fw_update_notif_cb_t appFwUpdateNotifCb;
  coco_client_zone_info_cb_t appZoneInfoCb;
  coco_client_zone_deleted_cb_t appZoneDeletedCb;
  coco_client_scene_info_cb_t appSceneInfoCb;
  coco_client_scene_deleted_cb_t appSceneDeletedCb;
  coco_client_rule_info_cb_t appRuleInfoCb;
  coco_client_rule_deleted_cb_t appRuleDeletedCb;
  coco_client_node_connect_status_cb_t appNodeConnStatusCb;
  coco_client_info_response_cb_t appInfoResponseCb;
  coco_client_info_request_status_cb_t appInfoRequestStatusCb;
  coco_client_network_data_cb_t networkDataCb;
  coco_client_leave_coconet_status_cb_t appLeaveCoconetStatusCb;
  coco_client_content_info_cb_t appContentInfoCb;
  coco_client_network_metadata_cb_t appNetworkMetadataCb;
  coco_client_data_cb_t appDataCb;
} coco_client_app_callbacks_t;

/* Coco client sdk platform function list */
typedef struct {
  coco_client_start_auth_fn_t startOauthFn;
  coco_client_access_token_cb_t getAccessTokenCb;
  coco_client_save_to_keychain_fn_t saveToKeyChainFn;
  coco_client_retrieve_from_keychain_fn_t retrieveFromKeyChainFn;
  coco_client_refresh_token_status_cb_t refreshTokenStatusCb;
} coco_client_platform_fn_list_t;

/* Structure used to initialize connectivity timers */
typedef struct {
  uint32_t fastRetryDuration;          // SDK will try to connect to other nodes at an interval
                                       // of 1 second for this duration in seconds. It must be a non-negative
                                       // integer. Set it to COCO_CLIENT_DEFAULT_FAST_RETRY_DURATION for using the
                                       // default value.
  uint32_t backgroundMaxRetryPeriod;   // After fastRetryDuration, SDK will try to connect to
                                       // other nodes at intervals which will keep on increasing with each
                                       // retry. backgroundMaxRetryPeriod in seconds is the maximum value of
                                       // this interval when the app is in background connectivity mode.
                                       // It must be a positive integer. Set it to
                                       // COCO_CLIENT_DEFAULT_BACKGROUND_MAX_RETRY_PERIOD for using the default value.
  uint32_t foregroundMaxRetryPeriod;   // After fastRetryDuration, SDK will try to connect to
                                       // other nodes at intervals which will keep on increasing with each
                                       // retry. foregroundMaxRetryPeriod in seconds is the maximum value of
                                       // this interval when the app is in foreground connectivity mode.
                                       // It must be a positive integer. Set it to
                                       // COCO_CLIENT_DEFAULT_FOREGROUND_MAX_RETRY_PERIOD for using the default value.
  uint32_t keepAliveInterval;          // SDK nodes will send a keep alive packet to other
                                       // connected nodes at an internal of keepAliveInterval seconds.
                                       // It must be a positive integer. Set it to
                                       // COCO_CLIENT_DEFAULT_KEEP_ALIVE_INTERVAL for using the default value.
  uint32_t keepAliveTimeout;           // This the timeout in seconds for which SDK will wait
                                       // for the response of the keep alive packet. It must be a positive
                                       // integer. Set it to COCO_CLIENT_DEFAULT_KEEP_ALIVE_TIMEOUT for using the
                                       // default value.
} coco_client_connectivity_timers_t;

/* Coco client sdk init data structure  */
typedef struct {
  coco_client_platform_fn_list_t *platformFnList;
  coco_client_app_callbacks_t *appCallbacks;
  char *cwdPath;
  char *appAccessList;
  char *clientId;
  char *downloadPath;
  coco_client_connectivity_timers_t *connectivityTimers; // Optional. If it is set to NULL,
                                                         // then the SDK will use the default values.
} coco_client_init_params_t;

/* Coco client sdk tunnel open data structure  */
typedef struct {
  uint32_t deviceNodeId;
  char *resourceEui;
  char *fwdHostName;          // To be used for COCO_STD_TUNNEL_TYPE_CONNECT
  uint16_t fwdPort;           // To be used for COCO_STD_TUNNEL_TYPE_CONNECT
  char *listeningHostName;    // To be used for COCO_STD_TUNNEL_TYPE_LISTEN
  uint16_t listeningPort;     // To be used for COCO_STD_TUNNEL_TYPE_CONNECT
  int32_t ipVersion;          // To be used for COCO_STD_TUNNEL_TYPE_CONNECT
  int32_t tunnelProtocol;     // Use coco_std_tunnel_protocol_t
  int32_t tunnelType;         // Use coco_std_tunnel_type_t
  int32_t transportType;      // Use coco_std_tunnel_transport_type_t
  void *protocolParams;
} coco_client_tunnel_open_params_t;

/* Coco client sdk capture snapshot data structure  */
typedef struct {
  uint32_t nodeId;
  char *resourceEui;
  uint16_t pixelHeight;
  uint16_t pixelWidth;
  coco_client_snapshot_status_cb_t snapshotCb;
  char *downloadPath;
} coco_client_capture_snapshot_params_t;

typedef struct {
  uint32_t deviceNodeId;
  char *resourceEui;
  coco_std_cmd_media_stream_start_t mediaStreamStartInfo;
  coco_client_media_stream_status_cb_t mediaStreamStatusCb;
  coco_client_media_stream_receive_cb_t mediaStreamReceiveCb;
} coco_client_media_stream_open_params_t;

/* An enum used to set different modes of connectivity */
typedef enum {
  COCO_CLIENT_CONNECTIVITY_MODE_MIN = -1,
  COCO_CLIENT_CONNECTIVITY_MODE_FOREGROUND,
  COCO_CLIENT_CONNECTIVITY_MODE_BACKGROUND,
  COCO_CLIENT_CONNECTIVITY_MODE_MAX,
  COCO_CLIENT_CONNECTIVITY_MODE_UNBOUND = 0x7FFFFFFF
} coco_client_connectivity_mode_t;

/*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/
/// A variable holding the last encountered error from COCO Client App SDK.
/** This is a thread local variable that contains the error code of the most recent error
 *  encountered by a COCO Client API function called in the current thread.
 *  The variable is only updated when an error is encountered, and is not reset to COCO_CLIENT_OK
 *  if a function returned succesfully.
 */
extern threadLocal int32_t cocoClientErrno;

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/
/********************************************//**
 * @brief   Initialize the COCO SDK
 * @details Initialize the COCO SDK and returns, appCallbacks will be called after
 *          #coco_connect api call.
 *          NOTE: The #coco_init() function *must* be called before trying to call
 *          any other API like #coco_connect()
 * @param   startAuthCb: auth callback, internal to the sdk, used for authorization requests.
 * @param   appCallbacks: application's callbacks, backed up in sdk. User can free it.
 * @param   dataDir: data directory for persistent storage, backed up in sdk. User can free it.
 * @param   appContext: application's context, not backed up. User cannot free it.
 * @return  int:  0 on success, -1 on error.
 *                cocoClientErrno will be set on error.
 *                NOTE: 0 and -1 are returned immediately, this is an async API, so the true result
 *                is only available in the callback.
 ***********************************************/
int32_t coco_client_init(coco_client_init_params_t *params);

/********************************************//**
 * @brief   API to set access token/refresh token
 * @details sets the access token/refresh token
 * @param   token: stringified json response containing access token/refresh token info.
 * @return  int:  0 on success, -1 on error.
 *                cocoClientErrno will be set on error.
 ***********************************************/
int32_t coco_client_set_tokens(char *token);

/********************************************//**
 * @brief   Start connection process into the cocoNet
 * @details This function requests for a secured connection for a cocoNet.
 *          Later, coco_connect_status_cb_t is received with corresponding coconetStatus.
 *          NOTE: API is not MT-SAFE if called for the same networkId from multiple threads.
 *          The #coco_connect() function *must* be called only after a successful return from
 *          #coco_init()
 * @param   coconet: coco_client_coconet_t structure returned by #coco_client_get_all_coconets()
 *                   or #coco_client_get_saved_coconets().
 * @return  int32_t: 0 on success, -1 on error.
 *                   cocoClientErrno will be set on error.
 *                   NOTE: 0 and -1 are returned immediately, this is an async API, so the true result
 *                   of the connection is only available in the callback.
 ***********************************************/
int32_t coco_client_connect(coco_client_coconet_t *coconet);

/********************************************//**
 * @brief   Disconnect from cocoNet
 * @details This function requests for a disconnect from a cocoNet and returns.
 *          Once the cocoNet is disconnected, connect_status_cb is received with status DISCONNECTED
 *          NOTE: API is not MT-SAFE and API cannot be called on a networkId that is pending a
 *          appConnectStatusCb.
 * @param   coconet: coco_client_coconet_t structures returned by #coco_client_get_all_coconets()
 *                   or #coco_client_get_saved_coconets().
 * @return  int32_t: 0 on success, -1 on error.
 *                   cocoClientErrno will be set on error.
 *                   NOTE: 0 and -1 are returned immediately, this is an async API,
 *                   so the true result of the disconnection is only available in the callback.
 ***********************************************/
int32_t coco_client_disconnect(coco_client_coconet_t *coconet);

/********************************************//**
 * @brief   Get the list COCO Network(s) that the user is part of.
 * @details This function makes a request to COCO Cloud to get the list COCO Network(s) that
 *          the user is part of. COCO Network(s) list is asynchronously provided to the user in
 *          #coco_client_get_coconets_cb_t callback.
 * @param   requestContext: User's context pointer to be returned in the callback
 * @return  int:  0 on success, -1 on error.
 *                cocoClientErrno will be set on error.
 ***********************************************/
int32_t coco_client_get_all_coconets(void *requestContext);

/********************************************//**
 * @brief   Get list of all previously connected cocoNets
 * @details This function provides list of all cocoNets user has previously connected to.
 *          Current thread will be blocking until the cocoNetList is received. cocoNetList is
 *          received synchronously with respect to user.
 * @param   coconetArr: Array of networkIds user has previously connected to,
 *                      memory allocated by sdk. User can free it
 *                      using #coco_client_free_coconets api
 * @return  int:  length of previously connected cocoNetList on success, -1 on error.
 *                cocoClientErrno will be set on error.
 ***********************************************/
int32_t coco_client_get_saved_coconets(coco_client_coconet_t **coconetArr);

/********************************************//**
 * @brief   Free coconet list
 * @details This function frees the coconetArr.
 * @param   coconetArr   : coconetArr to be freed
 * @param   coconetArrCnt: num of cocoNets
 * @return  None
 ***********************************************/
void coco_client_free_coconets(coco_client_coconet_t *coconetArr, uint32_t coconetArrCnt);

/********************************************//**
 * @brief   Returns a standard error description for coco client app sdk
 * @details This function returns description of valid error for coco client app sdk
 *          library. Use cocoClientErrno as errNum which is set to appropriate
 *          coco client error upon call to coco client APIs
 * @param   int errNum: Valid error number registered in coco_client_errno_t enum
 * @return  const char *: A string describing the error
 ***********************************************/
const char *coco_client_strerror(int32_t errNum);

/********************************************//**
 * @brief   Prints errors to standard error output stream
 * @details Printfs the standard error description from coco_client_strerror to standard error
 *          output stream with user defined error message description.
 * @param   const char * str: User defined error message description
 * @return  void : None
 ***********************************************/
void coco_client_perror(const char *str);

/********************************************//**
 * @brief   Send resource command
 * @details This API sends resource commands from coco client to coco device
 * @param   resourceCmd : Resource command structure
 * @param   cmdContext  : Command context
 * @return  int32_t     : 0 on success, -1 on error.
 *                        cocoClientErrno will be set on error.
 ***********************************************/
int32_t coco_client_send_resource_cmd(coco_std_resource_cmd_t *resourceCmd, void *cmdContext);

/********************************************//**
 * @brief    coco_client_send_device_mgmt_cmd
 * @details  This function sends device resource management commands
 *           from coco client to coco device
 * @param    deviceCmd : Device management command structure
 *           cmdContext: Command context
 * @return   int32_t   :  0 on success, -1 on error.
 *                        cocoClientErrno will be set on error.
 ***********************************************/
int32_t coco_client_send_device_mgmt_cmd(coco_std_device_cmd_t *deviceCmd, void *cmdContext);

/********************************************//**
 * @brief   Send info response
 * @details This API sends the info response for the info request.
 * @param   infoResponse: Info response structure
 * @param   context     : Info response context
 * @return  int32_t     : 0 on success, -1 on error.
 *                        cocoClientErrno will be set on error.
 ***********************************************/
int32_t coco_client_send_info_response(coco_std_info_response_t *infoResponse, void *context);

/********************************************//**
 * @brief        coco_client_send_info_request
 * @details      This function sends info request from coco client to coco device
 * @param        infoRequest : Pointer to Info request structure
 *               cmdContext: Command context
 * @return  int32_t:  0 on success, -1 on error.
 *                  cocoClientErrno will be set on error.
 ***********************************************/
int32_t coco_client_send_info_request(coco_std_info_request_t *infoRequest, void *cmdContext);

/********************************************//**
 * @brief    API to send COOCNet management commands
 * @details  The API is to be used for sending COCONet management commands
 *           like zone/scene/rule management commands.
 * @param    coconetCmd: Structure containing the parameters for COCONet management command.
 *           cmdContext: Command context
 * @return   int32_t: 0 on success, -1 on error.
 *                    cocoClientErrno will be set on error.
 ***********************************************/
int32_t coco_client_send_coconet_mgmt_cmd(coco_std_coconet_mgmt_cmd_t *coconetCmd, void *cmdContext);

/********************************************//**
 * @brief    coco_client_tunnel_open
 * @details  This function is used to send tunnel open resource command for opening tunnel to device
 * @param    networkId        : networkId
 * @param    params           : Parameters to open Tunnel
 * @param    tunnelContext    : tunnelContext
 * @param    timeoutMs        : Timeout in ms after which SDK will invoke the respective status callback with
 *                              status as COCO_TUNNEL_TIMEOUT. timeoutMs = 0 means infinity.
 * @return   int32_t : 0 on success, -1 on failure
 ***********************************************/
int32_t coco_client_tunnel_open(char *networkId, coco_client_tunnel_open_params_t *params,
                                uint32_t timeoutMs, void *tunnelContext);

/********************************************//**
 * @brief     coco_client_tunnel_close
 * @details   This function sends the resource command to the destination node Id
              to close the tunnel
 * @param     networkId       : networkId
 * @param     tunnelHandle    : tunnelHandle
 * @param     timeoutMs       : Timeout in ms after which SDK will invoke the respective status callback with
 *                              status as COCO_TUNNEL_TIMEOUT. timeoutMs = 0 means infinity.
 * @return    int32_t : 0 on success, -1 on failure
 ***********************************************/
int32_t coco_client_tunnel_close(char *networkId, coco_client_tunnel_handle_t *tunnelHandle,
                                 uint32_t timeoutMs);

/********************************************//**
 * @brief     coco_client_get_access_token
 * @details   This function retrieves the access token for application to
 *            use it with trust center API calls
 * @param     context       : user defined context pointer
 * @return    int32_t : 0 on success, -1 on failure
 ***********************************************/
int32_t coco_client_get_access_token(void *context);

/********************************************//**
 * @brief    Execute a scene
 * @details  This API executes all the commands in a scene
 * @param    sceneInfo: Structure of scene entity for the scene to be executed
 *           context  : Context to be returned in scene execution status callback. The callback will
 *                      will be added in a future release and the parameter is just kept for backward
 *                      compatibility, it has no functionality as of now.
 * @return  int32_t   : 0 on success, -1 on error.
 *                      cocoClientErrno will be set on error.
 ***********************************************/
int32_t coco_client_execute_scene(coco_std_scene_entity_t *sceneInfo, void *context);

/********************************************//**
 * @brief   Start connection process into the COCO Network
 * @details This function requests for a secured connection for a coconet using the networkId, nodeId
 *          and the inviteUrl information.
 *          Later, coco_connect_status_cb_t is received with corresponding coconetStatus.
 * @param   coconet       : Pointer to coco_client_coconet_t structure
 *          nodeId        : ID of the node
 *          inviteUrl     : Invitation URL to join the COCO Network.
 * @return  int32_t       : 0 on success, -1 on error.
 *                          cocoClientErrno will be set on error.
 ***********************************************/
int32_t coco_client_connect_with_invite(coco_client_coconet_t *coconet, uint32_t nodeId,
                                        char *inviteUrl);

/********************************************//**
 * @brief    Open a media stream to a resource in the COCO Network
 * @details  This function opens a media stream session with a device node. This session can contain
 *           multiple channels in which data will be written or read and the stream session is considered
 *           active only after receiving all status callback (OPENED/FAILED) and can call close the session
 *           using coco_client_media_stream_close().
 * @param    networkId        : Network Id of the COCO network
 * @param    params           : Parameters to open media stream
 * @param    timeoutMs        : Timeout in ms after which SDK will invoke the respective status callback with
 *                              status as COCO_CLIENT_MEDIA_STREAM_TIMEOUT. timeoutMs = 0 means infinity.
 * @param    streamContext    : Media stream context
 * @return   int32_t          : 0 on success, -1 on failure
 ***********************************************/
int coco_client_media_stream_open(char *networkId, coco_client_media_stream_open_params_t *params,
                                  uint32_t timeoutMs, void *streamContext);

/********************************************//**
 * @brief    Set a data receive callback for channel in stream
 * @details  This function sets a callback to receive stream data and channel context is optional to set
 * @param    streamChannelHandle : Media stream channel handle
 * @param    streamRecieveCb     : Media stream channel receive callback
 * @param    channelContext      : Media stream channel context
 * @return   int32_t             : 0 on success, -1 on failure
 ***********************************************/
int32_t coco_client_set_channel_receive_cb(coco_client_channel_handle_t *streamChannelHandle,
                                           coco_client_media_stream_receive_cb_t streamRecieveCb,
                                           void *channelContext);

/********************************************//**
 * @brief    Send data over a media stream channel
 * @details  This function sends data on a media stream channel of a media stream session
 * @param    streamChannelHandle : Media stream channel handle
 * @param    data                : Pointer to data buffer that needs to be sent on channel
 * @param    len                 : Length of the data buffer that needs to be sent on channel
 * @return   ssize_t             : 0 on success and -1 on failure
 ***********************************************/
ssize_t coco_client_channel_data_send(coco_client_channel_handle_t *channelHandle, const void *data,
                                      size_t len);

/********************************************//**
 * @brief   Close a media stream in the COCO Network
 * @details This function closes the media stream session and frees up the stream handle.
 *          Afterwards, the streamHandle is invalid and must not be used any more.
 * @param   streamHandle     : Stream handle pointer
 * @return  int32_t          : 0 on success, -1 on failure
 ***********************************************/
int coco_client_media_stream_close(coco_client_media_stream_handle_t *streamHandle);

/********************************************//**
 * @brief   Frees the memory allocated for coco_client_network_data_t pointer.
 * @details This API will be called to free the memory allocated for network data consisting
 *          of device, zone, scene and rule structures.
 * @param   nwDataArr       : Pointer to coco_client_network_data_t structure
 *          nwDataArrCnt    : Network data array count.
 * @return  None.
 ***********************************************/
void coco_client_free_network_data(coco_client_network_data_t *nwDataArr,
                                   uint32_t nwDataArrCnt);

/********************************************//**
 * @brief   Fetches available ports
 * @details This API gets portCount no. of available ports for nodeId.
 *          Allocated port array can be freed using coco_client_free_channel_port_array() API
 * @param   networkId  : Network Id of the COCO network
 * @param   nodeId     : Node ID of the node for which ports need to fetched.
 * @param   portCount  : Number of ports requested
 * @return  uint16_t * : Array of requested no. of ports on success, NULL on failure
 ***********************************************/
uint16_t *coco_client_get_available_channel_port(char *networkId, uint32_t nodeId, uint16_t portCount);

/********************************************//**
 * @brief   Frees port array
 * @details This API deallocates the port array that was allocated by
 *          coco_client_get_available_channel_port()
 * @param   portArray  : Port array
 * @return  None
 ***********************************************/
void coco_client_free_channel_port_array(uint16_t *portArray);

/********************************************//**
 * @brief   API to set connectivity mode
 * @details After fastRetryDuration, SDK will try to connect to other nodes at
 *          intervals which will keep on increasing with each retry. foregroundMaxRetryPeriod or
 *          backgroundMaxRetryPeriod in seconds is the maximum value of this interval depending
 *          upon whether this API is called with foreground or background connectivity mode
 *          respectively. This API is used to set the connectivity mode as foreground or background.
 *          In case it is called to set the state as foreground, the interval after which the
 *          connection to other nodes is retried will be reset.
 * @param   mode      : Connectivity mode specified in coco_client_connectivity_mode_t
 * @return  int32_t   : 0 on success, -1 on failure
 ***********************************************/
int32_t coco_client_set_connectivity_mode(int32_t mode);

/********************************************//**
 * @brief   Captures the snapshot
 * @details This API sends a capture snapshot command to the device node with
 *          snapshot capable resource and downloads the snapshot to the specified downloadFilePath.
 * @param   networkId        : Network Id of the COCO network
 * @param   params           : Capture snapshot parameters data structure pointer
 * @param   timeoutMs        : Timeout in ms after which SDK will invoke the respective status callback with
 *                             status as COCO_CLIENT_SNAPSHOT_TIMEOUT. timeoutMs = 0 means infinity.
 * @param   context          : user defined context pointer
 * @return  int32_t          : 0 on success, -1 on failure.
 ***********************************************/
int32_t coco_client_capture_snapshot(char *networkId, coco_client_capture_snapshot_params_t *params,
                                     uint32_t timeoutMs, void *context);

/********************************************//**
 * @brief     coco_client_invalidate_access_token
 * @details   This API can be called to invalidate the existing tokens. Change in password is one
 *            possible use case when this API can be called. coco_client_start_auth_fn_t() will be
 *            invoked as a result of this API call.
 * @param     void    : None
 * @return    int32_t : 0 on success, -1 on failure
 ***********************************************/
int32_t coco_client_invalidate_access_token(void);

/********************************************//**
 * @brief     API to get the client SDK version details
 * @details   This API will return a JSON having version, environment,
 *            Trust Center base URL, authorization URL and token URL.
 * @param     void  : None
 * @return    char *: JSON string having format:
 *                    {
 *                     "version": <string>,
 *                     "environment": <string>,
 *                     "TCBaseURL": <string>,
 *                     "authorizationURL": <string>,
 *                     "tokenURL": <string>
 *                     }
 ***********************************************/
char *coco_client_get_version(void);

/********************************************//**
 * @brief     API to leave a COCO Network
 * @details   This API can be called to leave from the COCO Network.
 *            Later, coco_client_leave_coconet_status_cb_t is received with corresponding status.
 * @param     coconet       : coco_client_coconet_t structure returned by #coco_client_get_all_coconets()
 *                            or #coco_client_get_saved_coconets().
 * @param     requestContext: User defined context to be returned in leave coconet status callback
 * @return    int32_t       : 0 on success, -1 on failure
 ***********************************************/
int32_t coco_client_leave_coconet(coco_client_coconet_t *coconet, void *requestContext);

/********************************************//**
 * @brief     API to send content info
 * @details   This API can be called to send the content info to the specified nodes or even to all
 *            the nodes in the network.
 * @param     networkId       : Network Id of the COCO network in which the content info is to be sent.
 * @param     metadata        : Content metadata to be sent. It can be used to share information like
 *                              content URL, etc.
 * @param     contentTime     : Content time in milliseconds.
 * @param     destNodeIdArr   : Destination node ID array. Set it to NULL to broadcast the content info
 *                              to all nodes in the network.
 * @param     destNodeIdArrCnt: Number of nodes in destNodeIdArr. Set it to zero to broadcast the
 *                              content info to all nodes in the network.
 * @return    int32_t         : 0 on success, -1 on failure
 ***********************************************/
int32_t coco_client_send_content_info(char *networkId, char *metadata, int32_t contentTime,
                                      uint32_t *destNodeIdArr, uint32_t destNodeIdArrCnt);

/********************************************//**
 * @brief     API to send client app data.
 * @details   This API can be called to send any data to the specified nodes or even to all the
 *            nodes in the network.
 * @param     networkId       : Network Id of the COCO network in which the data is to be sent.
 * @param     data            : Data to be sent.
 * @param     destNodeIdArr   : Destination node ID array. Set it to NULL to broadcast the content info
 *                              to all nodes in the network.
 * @param     destNodeIdArrCnt: Number of nodes in destNodeIdArr. Set it to zero to broadcast the
 *                              content info to all nodes in the network.
 * @return    int32_t         : 0 on success, -1 on failure
 ***********************************************/
int32_t coco_client_send_data(char *networkId, char *data , uint32_t *destNodeIdArr,
                              uint32_t destNodeIdArrCnt);

#endif // COCO_CLIENT_API_H_INCLUDED
