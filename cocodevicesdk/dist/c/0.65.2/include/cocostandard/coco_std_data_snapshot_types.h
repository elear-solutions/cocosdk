/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_snapshot_types.h
 * @brief     Attributes and commands belonging to snapshot capability
 * @details   This file contains attributes and commands belonging
 *            to the snapshot capability.
 * @see
 * @author    Kishori Patil, Kishoripatil@elear.solutions
 * @copyright Copyright (c) 2020 Elear Solutions Tech Private Limited. All rights
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
#ifndef COCO_STD_DATA_SNAPSHOT_TYPES_H_INCLUDED
#define COCO_STD_DATA_SNAPSHOT_TYPES_H_INCLUDED

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
typedef struct {
  uint32_t channelPort;            // channel port for snapshot, if set to 0 it's ignored.
  uint16_t pixelHeight;            // 0 for default height
  uint16_t pixelWidth;             // 0 for default width
} coco_std_cmd_snapshot_img_t;

typedef enum {
  COCO_STD_CMD_SNAPSHOT_MIN = -1,
  COCO_STD_CMD_SNAPSHOT_IMAGE,
  COCO_STD_CMD_SNAPSHOT_MAX,
  COCO_STD_CMD_SNAPSHOT_UBOUND = 0x7FFFFFFF
} coco_std_cmd_snapshot_t;

typedef enum {
  COCO_STD_ATTR_SNAPSHOT_MIN = -1,
  COCO_STD_ATTR_SNAPSHOT_IMG_SUPPORT_RESOLUTION_HEIGHT_ARR,
  COCO_STD_ATTR_SNAPSHOT_IMG_SUPPORT_RESOLUTION_WIDTH_ARR,
  COCO_STD_ATTR_SNAPSHOT_IMG_DEFAULT_RESOLUTION_HEIGHT,
  COCO_STD_ATTR_SNAPSHOT_IMG_DEFAULT_RESOLUTION_WIDTH,
  COCO_STD_ATTR_SNAPSHOT_MAX,
  COCO_STD_ATTR_SNAPSHOT_UBOUND = 0x7FFFFFFF
} coco_std_attr_snapshot_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_SNAPSHOT_TYPES_H_INCLUDED
