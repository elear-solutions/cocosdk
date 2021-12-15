/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_motion_types.h
 * @brief     Struct_to_json, json_to_struct and memory deallocator utilities for "data" structures,
 *            command and attribute enums belonging to motion sensing capability
 * @details   This file contains the implementation of struct_to_json, json_to_struct and
 *            memory deallocator utilities for command parameter "data" structures belonging
 *            to the motion sensing capability.
 * @see
 * @author    Prasad Makireddy, prasadmakireddy@elear.solutions
 *            Varun Kumar, varun.k@healthasyst.com
 * @copyright Copyright (c) 2019-2020 Elear Solutions Tech Private Limited. All rights
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
#ifndef COCO_STD_DATA_MOTION_TYPES_H_INCLUDED
#define COCO_STD_DATA_MOTION_TYPES_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/

/*************************************************************************************
 *                          GLOBAL MACROS                                            *
 *************************************************************************************/

 /*************************************************************************************
  *                          GLOBAL TYPEDEFS                                          *
  *************************************************************************************/
typedef enum {
  COCO_STD_CMD_MOTION_MIN = -1,
  COCO_STD_CMD_MOTION_SENSING_ENABLE,
  COCO_STD_CMD_MOTION_SENSING_DISABLE,
  COCO_STD_CMD_MOTION_SENSING_SET_ROI,
  COCO_STD_CMD_MOTION_SENSING_REMOVE_ROI,
  COCO_STD_CMD_MOTION_SENSING_REMOVE_ALL_ROI,
  COCO_STD_CMD_MOTION_SENSING_SET_SENSITIVITY,
  COCO_STD_CMD_MOTION_MAX,
  COCO_STD_CMD_MOTION_UBOUND = 0x7FFFFFFF
} coco_std_cmd_motion_t;

typedef enum {
  COCO_STD_ATTR_MOTION_MIN = -1,
  COCO_STD_ATTR_MOTION_DETECTED_FLAG,      // COCO_STD_DATA_TYPE_BOOLEAN
  COCO_STD_ATTR_MOTION_SENSING_ENABLED,    // COCO_STD_DATA_TYPE_BOOLEAN
  COCO_STD_ATTR_MOTION_IMAGE_WIDTH,        // COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_MOTION_IMAGE_HEIGHT,       // COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_MOTION_ROI_WIDTH,          // COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_MOTION_ROI_HEIGHT,         // COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_MOTION_ROI_INDICES_COUNT,  // COCO_STD_DATA_TYPE_UINT64
  COCO_STD_ATTR_MOTION_ROI_INDICES_ARR,    // COCO_STD_DATA_TYPE_UINT64_ARR
  COCO_STD_ATTR_MOTION_SENSITIVITY_PCT,    // COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_MOTION_MAX,
  COCO_STD_ATTR_MOTION_UBOUND = 0x7FFFFFFF
} coco_std_attr_motion_t;

typedef struct {
  uint8_t sensitivityPct;
} coco_std_cmd_motion_set_sensitivity_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/
#endif // COCO_STD_DATA_MOTION_TYPES_H_INCLUDED
