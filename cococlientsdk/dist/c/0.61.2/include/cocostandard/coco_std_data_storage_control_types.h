/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_storage_control_types.h
 * @brief     Attributes and commands belonging to storage control capability
 * @details   This file contains attributes and commands belonging to storage control
 *            capability.
 * @see
 * @author    Kishori Patil, kishoripatil@elear.solutions
 * @author    Utkarsha Meshram, utkarshameshram@elear.solutions
 * @copyright Copyright (c) 2020-2021 Elear Solutions Tech Private Limited. All rights
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
#ifndef COCO_STD_DATA_STORAGE_CONTROL_TYPES_H_INCLUDED
#define COCO_STD_DATA_STORAGE_CONTROL_TYPES_H_INCLUDED

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
  COCO_STD_CMD_STORAGE_CONTROL_MIN = -1,
  COCO_STD_CMD_STORAGE_UPLOAD,
  COCO_STD_CMD_STORAGE_DOWNLOAD,
  COCO_STD_CMD_STORAGE_CONTROL_MAX,
  COCO_STD_CMD_STORAGE_CONTROL_UBOUND = 0x7FFFFFFF
} coco_std_cmd_storage_control_t;

typedef enum {
  COCO_STD_ATTR_STORAGE_CONTROL_MIN = -1,
  COCO_STD_ATTR_STORAGE_CONTENT_COUNT,
  COCO_STD_ATTR_STORAGE_CAPACITY_MB,                     // Storage Capacity of storage node in Megabytes
  COCO_STD_ATTR_STORAGE_AVAILABLE_MB,                    // Storage currently available, in Megabytes
  COCO_STD_ATTR_STORAGE_SUPPORTED_TYPES_ARR,             // Supported content types, array of coco_std_storage_content_type_t
  COCO_STD_ATTR_STORAGE_RECORDING_TIME_CONFIG,           // configuration for max time allowed for recording
  COCO_STD_ATTR_STORAGE_RECORDING_SIZE_CONFIG,           // configuration for max size allowed for recording
  COCO_STD_ATTR_STORAGE_LAST_UPDATED_CONTENT_METADATA,   // last updated content metadata
  COCO_STD_ATTR_STORAGE_COOL_OFF_PERIOD,                 // Cool off period between 2 consecutive recordings
  COCO_STD_ATTR_STORAGE_RECORDING_STARTED,               // This attribute is to be updated whenever a recording is started
  COCO_STD_ATTR_STORAGE_SUPPORTED_STREAM_PROTOCOLS,      // Supported stream protocol types, array of coco_std_stream_protocol_type_t
  COCO_STD_ATTR_STORAGE_CONTROL_MAX,
  COCO_STD_ATTR_STORAGE_CONTROL_UBOUND = 0x7FFF
} coco_std_attr_storage_control_t;

typedef struct {
  int32_t contentType;                    // one of the values from coco_std_storage_content_type_t
  int32_t uploadTriggerType;              // one of the values from coco_std_storage_upload_trigger_type_t
  coco_std_source_uri_t sourceUri;
  coco_std_upload_triggered_uri_t uploadTriggeredUri;
  uint16_t channelPortArrCount;
  uint16_t *channelPortArr;
  int32_t appendFlag;                     // <overwrite / append>
  uint32_t offset;                        // ignored for streams
  uint32_t size;                          // ignored for streams
  char **channelDescriptionArr;
  uint32_t *channelRxBuffSizeArr;         // Specify the Rx buffer sizes
  time_t createdTimestamp;
} coco_std_cmd_storage_upload_t;

typedef struct {
  uint64_t contentId;
  uint16_t channelPort;
  uint32_t offset;
  uint32_t size;
} coco_std_cmd_storage_download_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_STORAGE_CONTROL_TYPES_H_INCLUDED
