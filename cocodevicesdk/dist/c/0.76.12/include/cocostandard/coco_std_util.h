/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_util.h
 * @brief     COCO Standard common utilities declaration.
 * @details   This file contains the declaration of commonly used COCO Standard utilities.
 * @see
 * @author    Prajeesh Prakasan, prajeeshprakash@elear.solutions
 *            Bala Krishna Kurmapu, balakrishna.kurmapu@healthasyst.com
 * @copyright Copyright (c) 2019 Clear Solutions Tech Private Limited. All rights
 *            reserved.
 * @license   To any person (the "Recipient") obtaining a copy of this software and
 *            associated documentation files (the "Software"):
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
#ifndef COCO_STD_UTIL_H_INCLUDED
#define COCO_STD_UTIL_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/
#include "elearcommon/json_services.h"
#include "coco_std_api.h"

/*************************************************************************************
 *                          GLOBAL MACROS                                            *
 *************************************************************************************/
// Macros for field names in resource command JSON
#define COCO_STD_CMD_JSON_COLOR_RED               "red"
#define COCO_STD_CMD_JSON_COLOR_GREEN             "green"
#define COCO_STD_CMD_JSON_COLOR_BLUE              "blue"
#define COCO_STD_CMD_JSON_COLOR_HUE               "hueDegrees"
#define COCO_STD_CMD_JSON_COLOR_SATURATION        "saturationPct"
#define COCO_STD_CMD_JSON_COLOR_LUMINANCE         "luminancePct"
#define COCO_STD_CMD_JSON_TRANS_TIME_FLAG         "useDefaultTransTimeFlag"
#define COCO_STD_CMD_JSON_TRANS_TIME              "transitionTimeMs"
#define COCO_STD_CMD_JSON_COLOR_TEMP              "colorTemperatureKelvin"
#define COCO_STD_CMD_JSON_COLOR_COMP_ID_ARR       "colorCompIdArr"
#define COCO_STD_CMD_JSON_COLOR_COMP_VALUE_ARR    "colorCompValuesArr"
#define COCO_STD_CMD_JSON_COLOR_COMP              "colorComponent"

#define COCO_STD_CMD_JSON_PIN_RFID                "pinRfidCode"
#define COCO_STD_CMD_JSON_TIME_OUT                "timeoutMs"
#define COCO_STD_CMD_JSON_USER_TYPE               "userType"
#define COCO_STD_CMD_JSON_USER_STATUS             "userStatus"
#define COCO_STD_CMD_JSON_USER_ID                 "userId"

#define COCO_STD_CMD_JSON_LEVEL_PCT               "levelPct"
#define COCO_STD_CMD_JSON_RESTORE_FLAG            "restoreLevelFlag"

#define COCO_STD_CMD_JSON_METER_SCALE             "scale"
#define COCO_STD_CMD_JSON_NOTIFY_TYPE             "notificationType"
#define COCO_STD_CMD_JSON_EVENT_TYPE              "eventType"

// Macros for field names in resource command JSON - for media stream capability Cmd - stream start/stop
#define COCO_STD_CMD_JSON_MEDIA_STREAM_ID                     "streamId"
#define COCO_STD_CMD_JSON_MEDIA_STREAM_SESSIONE_ID            "streamSessionId"
#define COCO_STD_CMD_JSON_MEDIA_STREAM_DESCRIPTION            "streamDescription"
#define COCO_STD_CMD_JSON_MEDIA_STREAM_CHANNEL_PORT_ARR       "channelPortArr"
#define COCO_STD_CMD_JSON_MEDIA_STREAM_TRANSPORT_TYPE_ARR     "streamTransportTypeArr"
#define COCO_STD_CMD_JSON_MEDIA_STREAM_SESSION_TYPE           "streamSessionType"

// Macros for field names in resource command JSON - for media stream capability - Cmd -record start/stop/config
#define COCO_STD_CMD_JSON_MEDIA_STREAM_ID_ARR                 "streamIdArray"
#define COCO_STD_CMD_JSON_MEDIA_STREAM_DESCRIPTION_ARR        "streamDescriptionArray"
#define COCO_STD_CMD_JSON_MEDIA_RECORD_MODE                   "recordMode"
#define COCO_STD_CMD_JSON_MEDIA_RECORD_SIZE                   "size"
#define COCO_STD_CMD_JSON_MEDIA_RECORD_TIME                   "timeMs"
#define COCO_STD_CMD_JSON_MEDIA_RECORD_COOL_OFF_TIME          "recordCoolOffTimeMs"

// MACROS for field names in JSON for warning commands
#define COCO_STD_CMD_JSON_WARNING_TYPE             "warningType"

// Macros for field names in JSON for tunnel commands
#define COCO_STD_CMD_JSON_TUNNEL_CHANNEL_PORT         "channelPort"
#define COCO_STD_CMD_JSON_TUNNEL_PROTOCOL             "tunnelProtocol"
#define COCO_STD_CMD_JSON_TUNNEL_TYPE                 "tunnelType"
#define COCO_STD_CMD_JSON_TUNNEL_TRANSPORT_TYPE       "transportType"
#define COCO_STD_CMD_JSON_TUNNEL_PROTOCOL_PARAMS      "protocolParams"
#define COCO_STD_CMD_JSON_TUNNEL_RTSP_PORT            "port"
#define COCO_STD_CMD_JSON_TUNNEL_SESSION_ID           "sessionId"

// Macros for field names in JSON for keypress sensing
#define COCO_STD_CMD_JSON_COMBO_ID                    "comboId"
#define COCO_STD_CMD_JSON_COMBO_NAME                  "comboName"

// Macros for field names in JSON for window covering
#define COCO_STD_CMD_JSON_SET_OPEN_PCT                "openPct"

// Macros for field names in resource summary JSON
#define   COCO_STD_JSON_RESRC_NAME                "resourceName"
#define   COCO_STD_JSON_RESRC_MODEL               "model"
#define   COCO_STD_JSON_RESRC_MANUFACTURER        "manufacturer"
#define   COCO_STD_JSON_RESRC_FIRMWARE            "firmwareVersion"
#define   COCO_STD_JSON_RESRC_RCVR_TYPE           "receiverType"
#define   COCO_STD_JSON_RESRC_POWER_SRC           "powerSource"
#define   COCO_STD_JSON_METADATA                  "metadata"
#define   COCO_STD_JSON_EXPLORATION_STATUS        "explorationStatus"
#define   COCO_STD_JSON_METADATA_ARR              "metadataArr"

// Macros for field names in capability info JSON
#define COCO_STD_JSON_CAP_NAME                    "capabilityName"
#define COCO_STD_JSON_CAP_STD_CMD_ARR             "stdCmdArr"

// Macros for field names in attribute info JSON
#define   COCO_STD_JSON_ATTR_NAME                   "attribName"
#define   COCO_STD_JSON_ATTR_DESC                   "attribDesc"
#define   COCO_STD_JSON_ATTR_DATA_TYPE              "dataType"
#define   COCO_STD_JSON_ATTR_ARRAY_LEN              "dataArrayLen"
#define   COCO_STD_JSON_ATTR_MIN_VALUE              "minValue"
#define   COCO_STD_JSON_ATTR_MAX_VALUE              "maxValue"
#define   COCO_STD_JSON_ATTR_DEFAULT_VALUE          "defaultValue"
#define   COCO_STD_JSON_ATTR_CURRENT_VALUE          "currentValue"
#define   COCO_STD_JSON_ATTR_RPRT_CHANGE            "reportableChange"
#define   COCO_STD_JSON_ATTR_UPD_TIME_STMP          "lastUpdateTimestamp"
#define   COCO_STD_JSON_ATTR_MIN_RPRT_INTVL         "minReportingIntervalMs"
#define   COCO_STD_JSON_ATTR_MAX_RPRT_INTVL         "maxReportingIntervalMs"
#define   COCO_STD_JSON_ATTR_IS_REAL_TIME_UPDATE    "isRealTimeUpdate"
#define   COCO_STD_JSON_ATTR_PERSIST                "persist"

// Macros for field names in message JSON
#define COCO_STD_JSON_MSG_MESSAGE_TITLE           "messageTitle"
#define COCO_STD_JSON_MSG_MESSAGE_TEXT            "messageText"
#define COCO_STD_JSON_MSG_GW_CMD_SEQ_NUM          "gwCmdSeqNum"
#define COCO_STD_JSON_MSG_MSG_TYPE                "messageType"

// Macros for field names in advertise resource JSON
#define COCO_STD_JSON_ADV_RSRC_NAME               "resourceName"
#define COCO_STD_JSON_ADV_DEV_CMD_SEQ_NUM         "devCmdSeqNum"

// Macros for field names in info request JSON
#define COCO_STD_JSON_INFO_REQST_CMD_SEQ_NUM      "cmdSeqNum"
#define COCO_STD_JSON_INFO_REQST_REQD_ARR         "mandatoryInfoRequestArr"
#define COCO_STD_JSON_INFO_REQST_OPT_ARR          "optionalInfoRequestArr"
#define COCO_STD_JSON_INFO_REQST_MESSAGE_TEXT     "messageText"

// Macros for field names in parameter JSON
#define COCO_STD_JSON_PARAM_KEY                   "key"
#define COCO_STD_JSON_PARAM_VALUE                 "value"

// Macros for field names in Info Response JSON
#define COCO_STD_JSON_INFO_RES_CMD_SEQ_NUM        "cmdSeqNum"
#define COCO_STD_JSON_INFO_RES_RESPONSE_ARR       "infoResponseArr"

// Macros for field names in resource entity JSON
#define COCO_STD_JSON_RESOURCE_ARR               "resourceArr"
#define COCO_STD_JSON_RESOURCE_EUI               "resourceEui"
#define COCO_STD_JSON_CAPABILITY_ARR             "capabilityArr"
#define COCO_STD_JSON_CAPABILITY_ID              "capabilityId"
#define COCO_STD_JSON_ATTRIBUTE_ARR              "attributeArr"
#define COCO_STD_JSON_ATTRIBUTE_ID               "attributeId"

// Macros for field names in Resource command JSON
#define COCO_STD_RESRC_CMD_CAP_ID                "capabilityId"
#define COCO_STD_RESRC_CMD_CMD_SNDR_NODE_ID      "cmdSenderNodeId"
#define COCO_STD_RESRC_CMD_CMD_ID                "cmdId"
#define COCO_STD_RESRC_CMD_CMD_PARAMS            "cmdParams"

// Macros for field names in Resource command status JSON
#define COCO_STD_RESRC_CMD_STATUS_CMD_SNDR_NODE_ID      "cmdSenderNodeId"
#define COCO_STD_RESRC_CMD_STATUS_CMD_COMMAND_ID        "cmdId"
#define COCO_STD_RESRC_CMD_STATUS_CMD_CAPABILITY_ID     "capabilityId"
#define COCO_STD_RESRC_CMD_STATUS_CMD_SNDR_NODE_ID      "cmdSenderNodeId"
#define COCO_STD_RESRC_CMD_STATUS_STATUS                "status"
#define COCO_STD_RESRC_CMD_STATUS_PARAMS_COUNT          "cmdStatusParamsCount"
#define COCO_STD_RESRC_CMD_STATUS_PARAMS                "cmdStatusParams"

// Macros for field names in Gateway command JSON
#define COCO_STD_GW_CMD_CMD_SNDR_NODE_ID         "cmdSenderNodeId"
#define COCO_STD_GW_CMD_CMD_SEQ_NUM              "cmdSeqNum"
#define COCO_STD_GW_CMD_CMD_ID                   "cmdId"
#define COCO_STD_GW_CMD_CMD_PARAMS               "cmdParams"

#define COCO_STD_GW_CMD_RES_EUI                  "resourceEui"
#define COCO_STD_GW_ADD_CMD_PARAMS_ARRAY         "paramArr"
#define COCO_STD_GW_CMD_STATUS                   "status"
#define COCO_STD_GW_CMD_STATUS_IMPACTED_RES_ARR  "impactedResourceArr"
#define COCO_STD_GW_CMD_PROTOCOL_ID              "protocolId"
#define COCO_STD_GW_CMD_WIFI_SSID                "ssid"
#define COCO_STD_GW_CMD_WIFI_PSWD                "password"

// Macros for field names in Gateway command JSON
#define COCO_STD_MEDIA_MGMT_CMD_CMD_SNDR_NODE_ID "cmdSenderNodeId"
#define COCO_STD_MEDIA_MGMT_CMD_CMD_SEQ_NUM      "cmdSeqNum"
#define COCO_STD_MEDIA_MGMT_CMD_CMD_ID           "cmdId"
#define COCO_STD_MEDIA_MGMT_CMD_CMD_PARAMS       "cmdParams"

#define COCO_STD_MEDIA_MGMT_CMD_STATUS           "status"
#define COCO_STD_MEDIA_MGMT_CMD_RES_PARAMS       "cmdRespParams"
#define COCO_STD_MEDIA_MGMT_NETWORK_ID           "networkId"
#define COCO_STD_MEDIA_MGMT_CHANNEL_NAME         "channelName"
#define COCO_STD_MEDIA_MGMT_CHANNEL_METADATA     "metaData"
#define COCO_STD_MEDIA_MGMT_MAX_STREAMS          "maxStreams"
#define COCO_STD_MEDIA_MGMT_CHANNEL_ID           "channelID"
#define COCO_STD_MEDIA_MGMT_CHANNEL_INFO_ARRAY   "channelInfoArray"
#define COCO_STD_MEDIA_MGMT_STREAM_ID            "streamID"
#define COCO_STD_MEDIA_MGMT_SOURCE_NODE_ID       "sourceNodeId"
#define COCO_STD_MEDIA_MGMT_STREAM_SDP           "streamSDP"
#define COCO_STD_MEDIA_MGMT_STREAM_STATUS        "streamStatus"
#define COCO_STD_MEDIA_MGMT_STREAM_COUNT         "numOfStreams"
#define COCO_STD_MEDIA_MGMT_CHANNEL_COUNT        "numOfChannels"
#define COCO_STD_MEDIA_MGMT_STREAM_INFO_ARRAY    "streamInfoArray"
#define COCO_STD_MEDIA_MGMT_CMD_RES_EUI          "resourceEui"

// Macros for field names in zone resource
#define COCO_STD_ZONE_RES_GW_NODE_ID              "gatewayNodeId"
#define COCO_STD_ZONE_RES_RES_EUI                 "resourceEui"
#define COCO_STD_ZONE_RES_RES_NAME                "resourceName"

// Macros for field names in zone entity
#define COCO_STD_JSON_ZONE_ID                     "zoneId"
#define COCO_STD_ZONE_ENTITY_ZONE_NAME            "zoneName"
#define COCO_STD_ZONE_ENTITY_RES_ARR              "resourceArr"

// Macros for field names in scene resource action
#define COCO_STD_RESRC_ACT_GW_NODE_ID             "gatewayNodeId"
#define COCO_STD_RESRC_ACT_RSRC_EUI               "resourceEui"
#define COCO_STD_RESRC_ACT_CAP_ID                 "capabilityId"
#define COCO_STD_RESRC_ACT_CMD_PARAMS             "cmdParams"
#define COCO_STD_RESRC_ACT_ID                     "resrcActionId"
#define COCO_STD_RESRC_ACT_CMD_ID                 "cmdId"

// Macros for field names in scene entity
#define COCO_STD_JSON_SCENE_ID                    "sceneId"
#define COCO_STD_JSON_SCENE_NAME                  "sceneName"

// Macros for field names in rule res cond
#define COCO_STD_RULE_RES_COND_ID                 "ruleResCondId"
#define COCO_STD_RULE_RES_COND_GW_ID              "gatewayNodeId"
#define COCO_STD_RULE_RES_COND_RES_EUI            "resourceEui"
#define COCO_STD_RULE_RES_COND_CAP_ID             "capabilityId"
#define COCO_STD_RULE_RES_COND_DUR_MS             "condDurationMs"
#define COCO_STD_RULE_RES_COND_ATTR_ID            "attributeId"
#define COCO_STD_RULE_RES_COND_OP_ID              "operatorId"
#define COCO_STD_RULE_RES_COND_VAL_DATATYPE_ID    "valueDataTypeId"
#define COCO_STD_RULE_RES_COND_VALUE_ID           "value"

// Macros for field names in rule schedule condition
#define COCO_STD_RULE_SCH_COND_ID                 "ruleSchedCondId"
#define COCO_STD_RULE_SCH_TYPE_ID                 "ruleSchedTypeId"
#define COCO_STD_RULE_SCH_EXP_TIME                "ruleExpiryTime"
#define COCO_STD_RULE_SCH_STRT_TIME               "ruleStartTime"

// Macros for field names in assign to template
#define COCO_STD_NW_CMD_RES_TEMP_ID                 "resTemplateId"
#define COCO_STD_NW_CMD_DEV_NODE_ID                 "deviceNodeId"
#define COCO_STD_NW_CMD_RES_EUI                     "resourceEui"

// Macros for field names in rule Entity
#define COCO_STD_RULE_ENTITY_RES_COND_ARR       "resrcCondnArr"
#define COCO_STD_RULE_ENTITY_SCH_COND_ARR       "schedCondnArr"
#define COCO_STD_RULE_ENTITY_SCENE_ACT_ARR      "sceneActionArr"

// Macros for field names in Device Info JSON
#define COCO_STD_DEV_INFO_DEV_PSN                "devicePsn"
#define COCO_STD_DEV_INFO_DEV_NAME               "deviceName"
#define COCO_STD_DEV_INFO_PRODUCT_NAME           "productName"
#define COCO_STD_DEV_INFO_DEV_MAKE               "make"
#define COCO_STD_DEV_INFO_DEV_MODEL              "model"
#define COCO_STD_DEV_INFO_DEV_FW_VERSION         "firmwareVersion"
#define COCO_STD_DEV_INFO_RSRC_EUI_ARR           "resourceEuiArr"
#define COCO_STD_DEV_INFO_PROTOCOL_ARR           "protocolIdArr"
#define COCO_STD_DEV_INFO_DEV_POW_SRC            "powerSource"
#define COCO_STD_DEV_INFO_DEV_RECVR_TYPE         "receiverType"
#define COCO_STD_DEV_INFO_DEV_IS_EXTNDBL         "isExtendable"

// Macros for field names in firmware update notification sent to client apps
#define COCO_STD_FW_UPDATE_NOTIF_STATUS          "status"
#define COCO_STD_FW_UPDATE_NOTIF_OLD_VERSION     "oldVersion"
#define COCO_STD_FW_UPDATE_NOTIF_NEW_VERSION     "newVersion"
#define COCO_STD_FW_UPDATE_NOTIF_PACKET_ID       "packetId"

// Macros for field names in Network command JSON
#define COCO_STD_COCONET_CMD_CMD_SNDR_NODE_ID                    "cmdSenderNodeId"
#define COCO_STD_COCONET_CMD_CMD_SEQ_NUM                         "cmdSeqNum"
#define COCO_STD_COCONET_CMD_CMD_ID                              "cmdId"
#define COCO_STD_COCONET_CMD_CMD_PARAMS                          "cmdParams"

// Macros for field names in network zone command JSON
#define COCO_STD_COCONET_CMD_ADD_ZONE_ZONE_ID                    "zoneId"
#define COCO_STD_COCONET_CMD_ADD_ZONE_ZONE_NAME                  "zoneName"

// Macros for field names in network zone delete command JSON
#define COCO_STD_JSON_ZONE_ID_ARR                                "zoneIdArr"

// Macros for field names in network zone resource command JSON
#define COCO_STD_COCONET_CMD_ZONE_RES_ZONE_ID                    "zoneId"
#define COCO_STD_COCONET_CMD_ZONE_RES_GW_NODE_ID                 "gatewayNodeId"
#define COCO_STD_COCONET_CMD_ZONE_RES_RES_EUI                    "resourceEui"

// Macros for field names in move zone resource command JSON
#define COCO_STD_COCONET_CMD_ZONE_RES_NEW_ZONE_ID                "newZoneId"
#define COCO_STD_COCONET_CMD_ZONE_RES_OLD_ZONE_ID                "oldZoneId"

// Macros for field names in move zone resource command JSON
#define COCO_STD_NW_CMD_ZONE_RES_NEW_ZONE_ID                    "newZoneId"
#define COCO_STD_NW_CMD_ZONE_RES_OLD_ZONE_ID                    "oldZoneId"

// Macros for field names in network delete scene command JSON
#define COCO_STD_JSON_SCENE_ID_ARR                              "sceneIdArr"

// Macros for field names in network zone resource command JSON
#define COCO_STD_COCONET_CMD_SCENE_RES_ACT_GW_NODE_ID            "gatewayNodeId"
#define COCO_STD_COCONET_CMD_SCENE_RES_ACT_RES_EUI               "resourceEui"
#define COCO_STD_COCONET_CMD_SCENE_RES_ACT_CAP_ID                "capabilityId"
#define COCO_STD_COCONET_CMD_SCENE_RES_ACT_CMD_ID                "cmdId"
#define COCO_STD_COCONET_CMD_SCENE_RES_ACT_CMD_PARAMS            "cmdParams"

// Macros for field names in network command status JSON
#define COCO_STD_COCONET_CMD_STATUS                              "status"

// Macros for field names in network rule command JSON
#define COCO_STD_JSON_RULE_ID                                    "ruleId"
#define COCO_STD_JSON_RULE_NAME                                  "ruleName"

// Macros for field names in network rule resource condition command JSON
#define COCO_STD_COCONET_CMD_DEL_RULE_RULE_RES_COND_ID           "ruleResCondId"

// Macros for field names in network rule schedule condition command JSON
#define COCO_STD_COCONET_CMD_DEL_RULE_RULE_SCH_COND_ID           "ruleSchCondId"

// Macros for field names in network rule resource action command JSON
#define COCO_STD_COCONET_CMD_DEL_RULE_RULE_RES_ACT_ID            "ruleResourceActionId"

// Macros for field names in network command JSON
#define COCO_STD_JSON_RESRC_ACTION_ARR                           "resrcActionArr"

// Macros for field names in network delete rule command JSON
#define COCO_STD_JSON_RULE_ID_ARR                                "ruleIdArr"

// Macros for field names in scene Metadata JSON
#define COCO_STD_JSON_SCENE_METADATA_ARR                         "sceneMetadataArr"
#define COCO_STD_JSON_SCENE_METADATA                             "sceneMetadata"
#define COCO_STD_JSON_SUBCLUSTER_ID                              "subclusterId"

// Macros for field names in info request available listen port params
#define COCO_STD_JSON_REQ_AVAIL_LST_PORT_CNT                    "portCount"
#define COCO_STD_JSON_REQ_AVAIL_LST_PORT_TRANS_TYPE             "transportType"
#define COCO_STD_JSON_REQ_AVAIL_LST_PORT_CONSECUTIVE_PORT       "consecutivePort"

// Macros for the field in mandatory/optional params
#define COCO_STD_JSON_REQ_KEY                                    "keyIndex"
#define COCO_STD_JSON_REQ_PARAMS                                 "params"

// Macros for field names in info response available listen port params
#define COCO_STD_JSON_RES_AVAIL_LST_PORT_ARR                    "portArr"

// Macros for field names in info response pin params
#define COCO_STD_JSON_RES_PIN                                   "pin"

// Macros for field names in info response protocol params
#define COCO_STD_JSON_RES_PROTOCOL                              "protocol"

// Macros for field names in info response DSK params
#define COCO_STD_JSON_RES_DSK                                   "dsk"

// Macros for field names in info response install code params
#define COCO_STD_JSON_RES_INSTALL_CODE                          "installCode"

// Macros for field names in info response of pairing type param
#define COCO_STD_JSON_PAIRING_TYPE                              "pairingType"

// Macros for field names in info response of timezone param
#define COCO_STD_JSON_TIMEZONE                                  "timezone"

// Macros for field names in snapshot capability - snapshot image command
#define COCO_STD_JSON_SNAPSHOT_CHANNEL_PORT                    "channelPort"
#define COCO_STD_JSON_SNAPSHOT_PIXEL_HEIGHT                    "pixelHeight"
#define COCO_STD_JSON_SNAPSHOT_PIXEL_WIDTH                     "pixelWidth"

// Macros for field names in motor control params
#define COCO_STD_JSON_DIRECTION                                 "direction"
#define COCO_STD_JSON_DEGREE                                    "degree"
#define COCO_STD_JSON_SPEED                                     "speed"

// Macros for field names in info request content search params
#define COCO_STD_JSON_RES_SEARCH_OFFSET_INDEX                  "offsetIndex"
#define COCO_STD_JSON_RES_SEARCH_START_EPOCH_TIME              "startEpochTime"
#define COCO_STD_JSON_RES_SEARCH_END_EPOCH_TIME                "endEpochTime"
#define COCO_STD_JSON_RES_SEARCH_CONTENT_TYPE                  "contentType"
#define COCO_STD_JSON_RES_SEARCH_UPLOAD_TRIGGER_TYPE           "uploadTriggerType"
#define COCO_STD_JSON_RES_SEARCH_UPLOAD_TRIGGER_ATTR_REGEX     "uploadTriggeredAttribUriRegEx"
#define COCO_STD_JSON_RES_SEARCH_UPLOAD_TRIGGER_NODE_ID        "uploadTriggeredNodeId"
#define COCO_STD_JSON_RES_SEARCH_SOURCE_URI_REGEX              "sourceUriRegEx"
#define COCO_STD_JSON_REQ_SEARCH_COUNT                         "reqSearchCount"
#define COCO_STD_JSON_REQ_SEARCH_SORT_BY_TYPE                  "sortByType"
#define COCO_STD_JSON_REQ_SEARCH_SORT_BY_ORDER                 "sortByOrder"

// Macros for field names in info response content search params
#define COCO_STD_JSON_RES_SEARCH_CONTENT_ID                  "contentId"
#define COCO_STD_JSON_RES_SEARCH_SOURCE_URI                  "sourceUri"
#define COCO_STD_JSON_RES_SEARCH_UPLOAD_TRIGGER_ATTR_URI     "uploadTriggeredAttribUri"
#define COCO_STD_JSON_RES_SEARCH_SIZE                        "size"
#define COCO_STD_JSON_RES_SEARCH_CONTENT_DURATION            "contentDuration"
#define COCO_STD_JSON_RES_SEARCH_PLAYBACK_URL                "playbackUrl"
#define COCO_STD_JSON_RES_SEARCH_STATIC_LINK                 "staticLink"
#define COCO_STD_JSON_RES_SEARCH_USER_METADATA               "userMetaData"
#define COCO_STD_JSON_RES_SEARCH_CREATED_TIME_STAMP          "createdTimestamp"
#define COCO_STD_JSON_RES_SEARCH_CONTENT_METADATA_ARR        "contentMetaDataArr"
#define COCO_STD_JSON_RES_SEARCH_TOTAL_SEARCH_COUNT          "totalSearchCount"

// Macros for field names in storage config params
#define COCO_STD_JSON_STORAGE_NODE_ID                            "storageNodeId"
#define COCO_STD_JSON_STORAGE_RESOURCE_EUI                       "resourceEui"

// Macros for field names in storage control params
#define COCO_STD_JSON_CONTENT_TYPE                               "contentType"
#define COCO_STD_JSON_UPLOAD_TRIGGER_TYPE                        "uploadTriggerType"
#define COCO_STD_JSON_UPLOAD_TRIGGER_URI                         "uploadTriggeredUri"
#define COCO_STD_JSON_UPLOAD_TRIGGER_NODE_ID                     "uploadTriggeredNodeId"
#define COCO_STD_JSON_CHANNEL_PORT_ARR                           "channelPortArr"
#define COCO_STD_JSON_APPEND_FLAG                                "appendFlag"
#define COCO_STD_JSON_OFFSET                                     "offset"
#define COCO_STD_JSON_SIZE                                       "size"
#define COCO_STD_JSON_CHANNEL_DESCRIPTION                        "channelDescription"
#define COCO_STD_JSON_CHANNEL_RX_BUFF_SIZE_ARRAY                 "channelRxBuffSizeArr"
#define COCO_STD_JSON_CREATED_TIMESTAMP                          "createdTimestamp"
#define COCO_STD_JSON_CONTENT_DURATION                           "contentDuration"
#define COCO_STD_JSON_CONTENT_EXPIRY_TIMESTAMP                   "contentExpiryTimestamp"

// Macros for field names in storage control params
#define COCO_STD_JSON_UPLOAD_NETWORK_ID                          "networkId"
#define COCO_STD_JSON_UPLOAD_NODE_ID                             "nodeId"
#define COCO_STD_JSON_UPLOAD_RESOURCE_EUI                        "resourceEui"
#define COCO_STD_JSON_UPLOAD_CAPABILITY_ID                       "capabilityId"
#define COCO_STD_JSON_UPLOAD_ATTRIBUTE_ID                        "attributeId"
#define COCO_STD_JSON_UPLOAD_SCENE_ID                            "sceneId"
#define COCO_STD_JSON_UPLOAD_RULE_ID                             "ruleId"

// Macros for field names in cmd error
#define COCO_STD_JSON_ERROR                                      "error"
#define COCO_STD_JSON_ERROR_CODE                                 "code"
#define COCO_STD_JSON_ERROR_MESSAGE                              "message"
#define COCO_STD_JSON_ERROR_FIELD_NAME                           "fieldName"

// Macros for field names in image set mirror params
#define COCO_STD_JSON_ON_FLAG                                   "onFlag"

// Macros for field names in motion sensing set sensitivity command JSON
#define COCO_STD_JSON_SENSITIVITY_PCT                            "sensitivityPct"

// Macros for field names in image set text params
#define COCO_STD_JSON_TEXT                                      "text"
#define COCO_STD_JSON_X_POSITION                                "xPosition"
#define COCO_STD_JSON_Y_POSITION                                "yPosition"

// Macros for recording in progress
#define COCO_STD_JSON_SOURCE_URI_STR                      "sourceUri"
#define COCO_STD_JSON_RUNNING_TIME_STR                    "runningTime"

#define COCO_STD_JSON_ACCESS_TOKEN                        "accessToken"

// Macros for field names in info response content playback
#define COCO_STD_JSON_RES_PLAYBACK_STREAM_PROTOCOL_TYPE   "streamProtocolType"
#define COCO_STD_JSON_RES_CONTENT_PLAYBACK_ERROR          "contentPlaybackReqError"
#define COCO_STD_JSON_RES_PLAYBACK_URL                    "playbackUrl"

// Macros for field names in set device loc command params
#define COCO_STD_JSON_LOCATION_ID_STR                     "locationIdStr"
#define COCO_STD_JSON_LOT_ID_STR                          "lotIdStr"
#define COCO_STD_JSON_X_COORDINATE                        "xCoordinate"
#define COCO_STD_JSON_Y_COORDINATE                        "yCoordinate"
#define COCO_STD_JSON_BEACON_ID_STR                       "beaconIdStr"
#define COCO_STD_JSON_AVG_RADIUS_BEACON_OF_BEACON         "avgRadiusOfBeacon"
#define COCO_STD_JSON_AVG_TIME_DUR_OF_BEACON              "avgTimeDurOfBeacon"
#define COCO_STD_JSON_ERROR_PRECISION                     "errorPrecision"
#define COCO_STD_JSON_RADIUS_BEACON_OF_BEACON             "radiusOfBeacon"
#define COCO_STD_JSON_ENVIRONMENTAL_FACTOR                "environmentalFactor"
#define COCO_STD_JSON_RSSI                                "rssi"
#define COCO_STD_JSON_MEASURED_POWER                      "measuredPower"
#define COCO_STD_JSON_DEVICE_RESRC_NAME                   "deviceResourceName"

#define COCO_STD_PARAMS_STREAM_RECEIVE_BUFFER_SIZE        "receiveBufferSize"
#define COCO_STD_PARAMS_STREAM_SEND_BUFFER_SIZE           "sendBufferSize"

#define COCO_STD_JSON_CATEGORY_ID                         "categoryId"
#define COCO_STD_JSON_BRAND_SEARCH_STRING                 "brandSearchString"
#define COCO_STD_JSON_BRAND_ID                            "brandId"
#define COCO_STD_JSON_PAIRING_CODE                        "pairingCode"
#define COCO_STD_JSON_PAIRING_CODES                       "pairingCodes"

#define COCO_STD_JSON_POWER_ON_FLAG                       "powerOnFlag"
#define COCO_STD_JSON_FAN_SPEED                           "fanSpeed"
#define COCO_STD_JSON_MODE                                "mode"
#define COCO_STD_JSON_SWING_ON_FLAG                       "swingOnFlag"
#define COCO_STD_JSON_TEMP_CELSIUS                        "temperatureCelsius"
#define COCO_STD_JSON_COMMAND_ID                          "commandId"
#define COCO_STD_JSON_COMMAND_PARAMS_VALUES_STRUCT        "commandParamValuesStruct"

#define COCO_STD_JSON_APPLIANCE_ID                        "applianceId"
#define COCO_STD_JSON_APPLIANCE_NAME                      "applianceName"
#define COCO_STD_JSON_PROGRAMMING_MODE                    "programmingMode"

#define COCO_STD_JSON_COMMAND_ID_ARR                      "commandIdArray"
#define COCO_STD_JSON_ATTRIBUTE_ID_ARR                    "attributeIdArray"

#define COCO_STD_JSON_OFFSET_INDEX                        "offsetIndex"
#define COCO_STD_JSON_SEARCH_TYPE                         "searchType"
#define COCO_STD_JSON_SORT_BY_ORDER                       "sortByOrder"
#define COCO_STD_JSON_SORT_BY_TYPE                        "sortByType"
#define COCO_STD_JSON_SEARCH_CRITERIA                     "searchCriteria"

#define COCO_STD_JSON_TOTAL_SEARCH_COUNT                  "totalSearchCount"
#define COCO_STD_JSON_BRAND_NAME                          "brandName"
#define COCO_STD_JSON_SEARCH_RESULTS_ARR                  "searchResultsArr"
#define COCO_STD_JSON_COMMAND_RESPONSE                    "commandResponse"

#define COCO_STD_JSON_BUTTON_INFO                         "buttonInfo"
#define COCO_STD_JSON_BUTTON_ID                           "buttonId"
#define COCO_STD_JSON_BUTTON_NAME                         "buttonName"

#define PLATFORM_16_BIT_POINTER_SIZE                       2
#define PLATFORM_32_BIT_POINTER_SIZE                       4
#define PLATFORM_64_BIT_POINTER_SIZE                       8

#define COCO_STD_JSON_CHANNEL_ID                          "channelId"
#define COCO_STD_JSON_CHANNEL_PORT                        "channelPort"
#define COCO_STD_JSON_STREAM_SDP                          "streamSdp"
#define COCO_STD_JSON_STREAM_ID                           "streamId"

/*************************************************************************************
 *                          GLOBAL TYPEDEFS                                          *
 *************************************************************************************/
// LUT for mapping cocostandard dataType to ecJsonType
static const ec_json_data_type_t cocoStdToJsonLUT[] = {
  [COCO_STD_DATA_TYPE_BOOLEAN]         = EC_JSON_TYPE_BOOLEAN,
  [COCO_STD_DATA_TYPE_BOOLEAN_ARR]     = EC_JSON_TYPE_BOOLEAN_ARRAY,
  [COCO_STD_DATA_TYPE_STRING]          = EC_JSON_TYPE_STRING,
  [COCO_STD_DATA_TYPE_STRING_ARR]      = EC_JSON_TYPE_STRING_ARRAY,
  [COCO_STD_DATA_TYPE_UINT8]           = EC_JSON_TYPE_UINT8,
  [COCO_STD_DATA_TYPE_UINT8_ARR]       = EC_JSON_TYPE_UINT8_ARRAY,
  [COCO_STD_DATA_TYPE_UINT16]          = EC_JSON_TYPE_UINT16,
  [COCO_STD_DATA_TYPE_UINT16_ARR]      = EC_JSON_TYPE_UINT16_ARRAY,
  [COCO_STD_DATA_TYPE_UINT32]          = EC_JSON_TYPE_UINT32,
  [COCO_STD_DATA_TYPE_UINT32_ARR]      = EC_JSON_TYPE_UINT32_ARRAY,
  [COCO_STD_DATA_TYPE_UINT64]          = EC_JSON_TYPE_UINT64,
  [COCO_STD_DATA_TYPE_UINT64_ARR]      = EC_JSON_TYPE_UINT64_ARRAY,
  [COCO_STD_DATA_TYPE_INT8]            = EC_JSON_TYPE_INT8,
  [COCO_STD_DATA_TYPE_INT8_ARR]        = EC_JSON_TYPE_INT8_ARRAY,
  [COCO_STD_DATA_TYPE_INT16]           = EC_JSON_TYPE_INT16,
  [COCO_STD_DATA_TYPE_INT16_ARR]       = EC_JSON_TYPE_INT16_ARRAY,
  [COCO_STD_DATA_TYPE_INT32]           = EC_JSON_TYPE_INT32,
  [COCO_STD_DATA_TYPE_INT32_ARR]       = EC_JSON_TYPE_INT32_ARRAY,
  [COCO_STD_DATA_TYPE_INT64]           = EC_JSON_TYPE_INT64,
  [COCO_STD_DATA_TYPE_INT64_ARR]       = EC_JSON_TYPE_INT64_ARRAY,
  [COCO_STD_DATA_TYPE_FLOAT]           = EC_JSON_TYPE_FLOAT,
  [COCO_STD_DATA_TYPE_FLOAT_ARR]       = EC_JSON_TYPE_FLOAT_ARRAY,
  [COCO_STD_DATA_TYPE_DOUBLE]          = EC_JSON_TYPE_DOUBLE,
  [COCO_STD_DATA_TYPE_DOUBLE_ARR]      = EC_JSON_TYPE_DOUBLE_ARRAY,
  [COCO_STD_DATA_TYPE_JSON_STRING]     = EC_JSON_TYPE_STRING,
  [COCO_STD_DATA_TYPE_JSON_STRING_ARR] = EC_JSON_TYPE_STRING_ARRAY,
};

// LUT for mapping array data types to individual data types
static const coco_std_data_type_t arrayToDataLUT[] = {
  [COCO_STD_DATA_TYPE_BOOLEAN]         = COCO_STD_DATA_TYPE_BOOLEAN,
  [COCO_STD_DATA_TYPE_BOOLEAN_ARR]     = COCO_STD_DATA_TYPE_BOOLEAN,
  [COCO_STD_DATA_TYPE_STRING]          = COCO_STD_DATA_TYPE_STRING,
  [COCO_STD_DATA_TYPE_STRING_ARR]      = COCO_STD_DATA_TYPE_STRING,
  [COCO_STD_DATA_TYPE_UINT8]           = COCO_STD_DATA_TYPE_UINT8,
  [COCO_STD_DATA_TYPE_UINT8_ARR]       = COCO_STD_DATA_TYPE_UINT8,
  [COCO_STD_DATA_TYPE_UINT16]          = COCO_STD_DATA_TYPE_UINT16,
  [COCO_STD_DATA_TYPE_UINT16_ARR]      = COCO_STD_DATA_TYPE_UINT16,
  [COCO_STD_DATA_TYPE_UINT32]          = COCO_STD_DATA_TYPE_UINT32,
  [COCO_STD_DATA_TYPE_UINT32_ARR]      = COCO_STD_DATA_TYPE_UINT32,
  [COCO_STD_DATA_TYPE_UINT64]          = COCO_STD_DATA_TYPE_UINT64,
  [COCO_STD_DATA_TYPE_UINT64_ARR]      = COCO_STD_DATA_TYPE_UINT64,
  [COCO_STD_DATA_TYPE_INT8]            = COCO_STD_DATA_TYPE_INT8,
  [COCO_STD_DATA_TYPE_INT8_ARR]        = COCO_STD_DATA_TYPE_INT8,
  [COCO_STD_DATA_TYPE_INT16]           = COCO_STD_DATA_TYPE_INT16,
  [COCO_STD_DATA_TYPE_INT16_ARR]       = COCO_STD_DATA_TYPE_INT16,
  [COCO_STD_DATA_TYPE_INT32]           = COCO_STD_DATA_TYPE_INT32,
  [COCO_STD_DATA_TYPE_INT32_ARR]       = COCO_STD_DATA_TYPE_INT32,
  [COCO_STD_DATA_TYPE_INT64]           = COCO_STD_DATA_TYPE_INT64,
  [COCO_STD_DATA_TYPE_INT64_ARR]       = COCO_STD_DATA_TYPE_INT64,
  [COCO_STD_DATA_TYPE_FLOAT]           = COCO_STD_DATA_TYPE_FLOAT,
  [COCO_STD_DATA_TYPE_FLOAT_ARR]       = COCO_STD_DATA_TYPE_FLOAT,
  [COCO_STD_DATA_TYPE_DOUBLE]          = COCO_STD_DATA_TYPE_DOUBLE,
  [COCO_STD_DATA_TYPE_DOUBLE_ARR]      = COCO_STD_DATA_TYPE_DOUBLE,
  [COCO_STD_DATA_TYPE_JSON_STRING]     = COCO_STD_DATA_TYPE_STRING,
  [COCO_STD_DATA_TYPE_JSON_STRING_ARR] = COCO_STD_DATA_TYPE_STRING
};

/*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/
/********************************************//**
 * @brief   Converts struct to JSON
 * @details This function converts the provided struct to JSON string by calling a
 *          specific handler based upon the type of the struct.
 *          This API is not required by the developers.
 * @param   structType     : Type of structure. It takes values from coco_std_struct_type_t enum.
 * @param   inStruct       : Structure for which the JSON string is
 *                           to be created.
 * @param   ttl            : Time to live in seconds (0 will default to 120)
 *                           EC_TTL_DEFAULT_VALUE - for default (120 seconds).
 *                           EC_TTL_INFINITY      - for infinite time.
 *                           Any other value      - the given no. of seconds.
 * @return  char *         : JSON string created from input structure.
 ***********************************************/
char *coco_std_struct_to_json(int32_t structType, void *inStruct, uint16_t ttl);

/********************************************//**
 * @brief   Converts JSON to struct
 * @details This function converts the provided JSON string to struct by calling a specific
 *          handler based upon the type of the struct.
 *          This API is not required by the developers.
 * @param   structType     : Type of structure. It takes values from coco_std_struct_type_t enum.
 * @param   inJsonStr      : JSON string which is to be converted to
 *                           the corresponding struct.
 * @param   ttl            : Time to live in seconds (0 will default to 120)
 *                           EC_TTL_DEFAULT_VALUE - for default (120 seconds).
 *                           EC_TTL_INFINITY      - for infinite time.
 *                           Any other value      - the given no. of seconds.
 * @return  void *         : Structure created from input JSON string.
 ***********************************************/
void *coco_std_json_to_struct(int32_t structType, char *inJsonStr, uint16_t ttl);

/********************************************//**
 * @brief   Validate the cocostandard structure
 * @details This API validates the members of the structure provided as input.
 *          It can be used for structures that belong to the enum coco_std_struct_type_t.
 * @param   structType     : Type of structure. It takes values from coco_std_struct_type_t enum.
 * @param   structPtr      : Pointer to structure that needs to be validated
 * @return  bool           : true: if the struct is valid
 *                           false: if the struct is invalid or in case of failure
 ***********************************************/
bool coco_std_struct_validate(int32_t structType, void *structPtr);

 /********************************************//**
 * @brief   API to get sizeof different datatype
 * @details This function will return sizeof datatype passed as an input argument
 * @param   dataType     : Data type
 * @return  size_t       : Return sizeof datatype
 *                         0 in case of error
 ***********************************************/
size_t coco_internal_get_data_type_size(coco_std_data_type_t dataType);

 /********************************************//**
 * @brief   returns a standard error description for coco_std_cmd_error_code_t error codes
 * @details This function returns description of valid error for coco_std_cmd_error_code_t
 *          error code.
 * @param   errorCode   : valid error code registered in coco_std_cmd_error_code_t
 * @return  const char *: a string describing the error
 ***********************************************/
const char *coco_std_get_error_message(coco_std_cmd_error_code_t errorCode);

 /********************************************//**
 * @brief   Converts coco_std_upload_triggered_uri_t type struct to JSON
 * @details This function converts the provided coco_std_upload_triggered_uri_t type struct
 *          to JSON object adding it to the outJson object provided.
 * @param   uploadTriggeredUri   : Upload triggered URI
 * @param   outJson              : Out JSON object
 * @return  None
 ***********************************************/
void coco_std_triggered_uri_struct_to_json(coco_std_upload_triggered_uri_t *uploadTriggeredUri,
                                           ec_json_object_t *outJson);

 /********************************************//**
 * @brief   Converts coco_std_source_uri_t type struct to JSON
 * @details This function converts the provided coco_std_source_uri_t type struct
 *          to JSON object adding it to the outJson object provided.
 * @param   sourceUri   : Upload source URI
 * @param   outJson     : Out JSON object
 * @return  None
 ***********************************************/
void coco_std_source_uri_struct_to_json(coco_std_source_uri_t *sourceUri, ec_json_object_t *outJson);

 /********************************************//**
 * @brief   Converts provided JSON to coco_std_upload_triggered_uri_t type struct
 * @details This function extracts the coco_std_upload_triggered_uri_t type struct from the in JSON object
 *          and returns the extracted coco_std_upload_triggered_uri_t struct
 * @param   inJson      : In JSON object containing coco_std_upload_triggered_uri_t type struct
 * @param   ttl         : Time to live value for the coco_std_upload_triggered_uri_t struct in seconds
 * @return  coco_std_upload_triggered_uri_t   : Upload triggered URI pointer
 * @param   uploadTriggeredUri   : Upload triggered URI pointer
 * @return  int                  : Return -1 if inJson has no coco_std_upload_triggered_uri_t struct
 *                                 else 0
 ***********************************************/
int coco_std_triggered_uri_json_to_struct(ec_json_object_t *inJson,
                                          coco_std_upload_triggered_uri_t *uploadTriggeredUri,
                                          int ttl);

 /********************************************//**
 * @brief   Converts provided JSON to coco_std_source_uri_t type struct
 * @details This function extracts the coco_std_source_uri_t type struct from the in JSON object
 *          and returns the extracted coco_std_source_uri_t struct
 * @param   inJson      : In JSON object containing coco_std_source_uri_t type struct
 * @param   ttl         : Time to live value for the coco_std_source_uri_t struct in seconds
 * @param   sourceUri   : Upload source URI pointer
 * @return  int         : Return -1 if inJson has no coco_std_source_uri_t struct else 0.
 ***********************************************/
int coco_std_source_uri_json_to_struct(ec_json_object_t *inJson,
                                       coco_std_source_uri_t *sourceUri, int ttl);

 /********************************************//**
 * @brief   Free source URI
 * @details This function frees the allocated coco_std_source_uri_t structure.
 * @param   sourceUri   : Upload source URI
 * @return  None
 ***********************************************/
void coco_std_free_source_uri(coco_std_source_uri_t *sourceUri);

 /********************************************//**
 * @brief   Free upload triggered URI
 * @details This function frees the allocated coco_std_upload_triggered_uri_t structure.
 * @param   uploadTriggeredUri   : Upload triggered URI
 * @return  None
 ***********************************************/
void coco_std_free_triggered_uri(coco_std_upload_triggered_uri_t *uploadTriggeredUri);

 /********************************************//**
 * @brief   Free JSON string
 * @details This function should be used to free JSON string returned by coco_std_struct_to_json()
 * @param   jsonStr: String returned by coco_std_struct_to_json()
 * @return  None
 ***********************************************/
void coco_std_free_json_str(char *jsonStr);

 /********************************************//**
 * @brief   gets the platform size
 * @details This function returns size in bytes based on architecture
 * @param   None
 * @return  2 for 16 bit machine
 *          4 for 32 bit machine
 *          8 for 64 bit machine
 ***********************************************/
int get_platform_size(void);

#endif // COCO_STD_UTIL_H_INCLUDED
