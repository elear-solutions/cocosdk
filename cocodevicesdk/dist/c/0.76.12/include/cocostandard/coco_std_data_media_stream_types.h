/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_media_stream_types.h
 * @brief     Attributes and commands belonging to media stream capability
 * @details   This file contains attributes and commands belonging to media stream
 *            capability.
 * @see
 * @author    Kishori Patil, kishoripatil@elear.solutions
 * @copyright Copyright (c) 2020-2021 ear Solutions Tech Private Limited. All rights
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
#ifndef COCO_STD_DATA_MEDIA_STREAM_TYPES_H_INCLUDED
#define COCO_STD_DATA_MEDIA_STREAM_TYPES_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/
#include <stdint.h>

/*************************************************************************************
 *                          GLOBAL MACROS                                            *
 *************************************************************************************/

/*************************************************************************************
 *                          GLOBAL TYPEDEFS                                          *
 *************************************************************************************/
typedef enum {
  COCO_STD_CMD_MEDIA_STREAM_MIN = -1,
  COCO_STD_CMD_MEDIA_STREAM_START,
  COCO_STD_CMD_MEDIA_STREAM_STOP,
  COCO_STD_CMD_MEDIA_RECORD_START,
  COCO_STD_CMD_MEDIA_RECORD_STOP,
  COCO_STD_CMD_MEDIA_RECORD_CONFIG,
  COCO_STD_CMD_MEDIA_STREAM_MAX,
  COCO_STD_CMD_MEDIA_STREAM_UBOUND = 0x7FFFFFFF,
} coco_std_cmd_media_stream_t;

typedef enum {
  COCO_STD_ATTR_MEDIA_MIN = - 1,
  COCO_STD_ATTR_MEDIA_DESCRIPTOR,                                // media stream description
                                                                 // COCO_STD_DATA_TYPE_JSON_STRING
  COCO_STD_ATTR_MEDIA_STREAM_ID_ARR,                             // array of streamingIds eg: {0, 1, 2}
                                                                 // COCO_STD_DATA_TYPE_UINT32
  COCO_STD_ATTR_MEDIA_STREAM_ACTIVE_CLIENTS_ARR,                 // array of active clients count per stream eg: {2, 2, 2}
                                                                 // COCO_STD_DATA_TYPE_UINT32_ARR
  COCO_STD_ATTR_MEDIA_STREAM_MAX_ACTIVE_CLIENTS_ARR,             // array of  max clients count per stream eg:{2, 2, 2}
                                                                 // COCO_STD_DATA_TYPE_UINT32_ARR
  COCO_STD_ATTR_MEDIA_STREAM_REC_STATUS_ARR,                     // array of streamIds recording status
                                                                 // eg: {true, false, false}  true indicates recording in-progress
                                                                 // COCO_STD_DATA_TYPE_BOOLEAN_ARR
  COCO_STD_ATTR_MEDIA_STREAM_REC_SUPPORTED_ARR,                  // Boolean array mapped to streamIds indicates the whether a stream supports recording
                                                                 // eg: {true, false, false} true indicates streamId supports recording
                                                                 // COCO_STD_DATA_TYPE_BOOLEAN_ARR
  COCO_STD_ATTR_MEDIA_STREAM_RECORDING_IN_PROGRESS,              // array of timers one-to-one mapped to streamIds in COCO_STD_ATTR_MEDIA_STREAM_ID_ARR
                                                                 // COCO_STD_DATA_TYPE_INT32_ARR
  COCO_STD_ATTR_MEDIA_STREAM_CONTENT_SEND_BUFFER_SIZE_ARR,       // array of send buffer sizes mapped to streamIds in COCO_STD_ATTR_MEDIA_STREAM_ID_ARR
                                                                 // COCO_STD_DATA_TYPE_UINT32
  COCO_STD_ATTR_MEDIA_STREAM_CONTENT_RECV_BUFFER_SIZE_ARR,       // array of receive buffer sizes mapped to streamIds in COCO_STD_ATTR_MEDIA_STREAM_ID_ARR
  COCO_STD_ATTR_MEDIA_MAX,
  COCO_STD_ATTR_MEDIA_UBOUND = 0x7FFF,
} coco_std_attr_media_stream_t;

typedef enum {
  COCO_STD_MEDIA_TRANSPORT_MIN = -1,
  COCO_STD_MEDIA_TRANSPORT_TCP,
  COCO_STD_MEDIA_TRANSPORT_UDP,
  COCO_STD_MEDIA_TRANSPORT_RTP_UDP,
  COCO_STD_MEDIA_TRANSPORT_MAX,
  COCO_STD_MEDIA_TRANSPORT_UBOUND = 0x7FFF,
} coco_std_media_transport_type_t;

typedef enum {
  COCO_STD_MEDIA_SESSION_MIN = -1,
  COCO_STD_MEDIA_SESSION_BUFFERED,
  COCO_STD_MEDIA_SESSION_LIVE,
  COCO_STD_MEDIA_SESSION_MAX,
  COCO_STD_MEDIA_SESSION_UBOUND = 0x7FFF,
} coco_std_media_session_type_t;

typedef enum {
  COCO_STD_MEDIA_STREAM_STATUS_MIN = -1,
  COCO_STD_MEDIA_STREAM_STARTED,
  COCO_STD_MEDIA_STREAM_START_FAILED,
  COCO_STD_MEDIA_STREAM_STOPPED,
  COCO_STD_MEDIA_STREAM_STOP_FAILED,
  COCO_STD_MEDIA_STREAM_STATUS_MAX,
  COCO_STD_MEDIA_STREAM_STATUS_UBOUND = 0x7FFFFFFF,
} coco_std_media_stream_status_t;

typedef enum {
  COCO_STD_MEDIA_REC_MIN = -1,
  COCO_STD_MEDIA_REC_STARTED,
  COCO_STD_MEDIA_REC_START_FAILED,
  COCO_STD_MEDIA_REC_STOPPED,
  COCO_STD_MEDIA_REC_STOP_FAILED,
  COCO_STD_MEDIA_REC_STATUS_MAX,
  COCO_STD_MEDIA_REC_STATUS_UBOUND = 0x7FFFFFFF
} coco_std_media_record_status_t;

typedef enum {
  COCO_STD_MEDIA_RECORD_MIN = -1,
  COCO_STD_MEDIA_RECORD_MANUAL_STOP,
  COCO_STD_MEDIA_RECORD_TIME,
  COCO_STD_MEDIA_RECORD_SIZE,
  COCO_STD_MEDIA_RECORD_MAX,
  COCO_STD_MEDIA_RECORD_UNBOUND = 0x7FFFFFFF
} coco_std_cmd_media_record_mode_t;

typedef struct {
  uint32_t streamId;
  int32_t streamSessionId;                 // SessionId per stream
  char *streamDescription;                 // Description of stream
  uint16_t channelPortCount;               // Stream channel count
  uint16_t *channelPortArr;                // Stream channel port Array
  int32_t *streamTransportTypeArr;         // stream transport type, array of coco_std_media_transport_type_t
  int32_t streamSessionType;               // stream session type, defined in coco_std_media_session_type_t
} coco_std_cmd_media_stream_start_t;

typedef struct {
  uint32_t streamId;
  int32_t streamSessionId;             // -1 to close all stream sessions
} coco_std_cmd_media_stream_stop_t;

typedef struct {
  uint32_t streamIdCount;               // no of streamIds
  uint32_t *streamIdArray;              // Array of streamIds
  char **streamDescriptionArr;
} coco_std_cmd_media_record_start_t;

typedef struct {
  uint32_t streamIdCount;               // no of streamIds, Recordings on all streams will be stopped if streamIdCount = 0
  uint32_t *streamIdArray;              // Array of streamIds
} coco_std_cmd_media_record_stop_t;

typedef struct {
  int32_t recordMode;               // one of the values from coco_std_cmd_media_record_mode_t
  uint32_t size;                    // in MB
  uint32_t timeMs;                  // time in milli sec
  uint32_t recordCoolOffTimeMs;     // time in milli sec
} coco_std_media_record_config_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_MEDIA_STREAM_TYPES_H_INCLUDED
