/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_image_ctrl_types.h
 * @brief     Attributes and commands belonging to image control capability
 * @details   This file contains attributes and commands belonging to image control
 *            capability.
 * @see
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
#ifndef COCO_STD_DATA_IMAGE_CTRL_TYPES_H_INCLUDED
#define COCO_STD_DATA_IMAGE_CTRL_TYPES_H_INCLUDED

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
// Possible values of image command
typedef enum {
  COCO_STD_CMD_IMAGE_MIN = -1,
  COCO_STD_CMD_IMAGE_SET_AF_MODE,
  COCO_STD_CMD_IMAGE_SET_AE_MODE,
  COCO_STD_CMD_IMAGE_SET_AWB_MODE,
  COCO_STD_CMD_IMAGE_SET_ZOOM,
  COCO_STD_CMD_IMAGE_SET_IRCUT_MODE,
  COCO_STD_CMD_IMAGE_SET_PRESET,
  COCO_STD_CMD_IMAGE_SET_HUE,
  COCO_STD_CMD_IMAGE_SET_SATURATION,
  COCO_STD_CMD_IMAGE_SET_CONTRAST,
  COCO_STD_CMD_IMAGE_SET_BRIGHTNESS,
  COCO_STD_CMD_IMAGE_SET_FLIP,
  COCO_STD_CMD_IMAGE_SET_MIRROR,
  COCO_STD_CMD_IMAGE_SET_TEXT,
  COCO_STD_CMD_IMAGE_MAX,
  COCO_STD_CMD_IMAGE_UBOUND = 0x7FFFFFFF
} coco_std_cmd_image_t;

// Possible values of image control attribute
typedef enum {
  COCO_STD_ATTR_IMAGE_CTRL_MIN = -1,
  COCO_STD_ATTR_IMAGE_CTRL_AF_MODE_FLAG,            // COCO_STD_DATA_TYPE_BOOLEAN
  COCO_STD_ATTR_IMAGE_CTRL_AE_MODE_FLAG,            // COCO_STD_DATA_TYPE_BOOLEAN
  COCO_STD_ATTR_IMAGE_CTRL_AWB_MODE_FLAG,           // COCO_STD_DATA_TYPE_BOOLEAN
  COCO_STD_ATTR_IMAGE_CTRL_ZOOM_TYPE,               // COCO_STD_DATA_TYPE_BOOLEAN
  COCO_STD_ATTR_IMAGE_CTRL_IRCUT_MODE_TYPE,         // COCO_STD_DATA_TYPE_INT32
  COCO_STD_ATTR_IMAGE_CTRL_IMG_PRESET_TYPE,         // COCO_STD_DATA_TYPE_INT32
  COCO_STD_ATTR_IMAGE_CTRL_IMG_HUE_PCT,             // COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_IMAGE_CTRL_IMG_SATURATION_PCT,      // COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_IMAGE_CTRL_IMG_CONTRAST_PCT,        // COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_IMAGE_CTRL_IMG_BRIGHTNESS_PCT,      // COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_IMAGE_CTRL_IMG_FLIP_FLAG,           // Image flip is enabled if true
                                                    // COCO_STD_DATA_TYPE_BOOLEAN
  COCO_STD_ATTR_IMAGE_CTRL_IMG_MIRROR_FLAG,         // Image mirror is enabled if true
                                                    // COCO_STD_DATA_TYPE_BOOLEAN
  COCO_STD_ATTR_IMAGE_CTRL_IMG_TEXT,                // COCO_STD_DATA_TYPE_STRING
  COCO_STD_ATTR_IMAGE_CTRL_IMG_TEXT_XPOSITION,      // COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_IMAGE_CTRL_IMG_TEXT_YPOSITION,      // COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_IMAGE_CTRL_MAX,
  COCO_STD_ATTR_IMAGE_CTRL_UBOUND = 0x7FFFFFFF
} coco_std_attr_image_ctrl_t;

// Structure of image set text command
typedef struct {
  char *text;
  uint8_t xPosition;
  uint8_t yPosition;
} coco_std_cmd_img_set_text;

// Structure of image set mirror command
typedef struct {
  int32_t onFlag;                        // 0 = off, 1 = on
} coco_std_cmd_img_set_mirror_t;

// Structure of image set flip command
typedef struct {
  int32_t onFlag;                        // 0 = off, 1 = on
} coco_std_cmd_img_set_flip_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_IMAGE_CTRL_TYPES_H_INCLUDED
