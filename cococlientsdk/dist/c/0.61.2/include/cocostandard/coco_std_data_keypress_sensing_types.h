/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_keypress_sensing_types.h
 * @brief     Attributes and commands belonging to keypress sensing capability
 * @details   This file contains attributes and commands belonging to keypress sensing capability.
 * @see
 * @author    Umesh Kshirsagar, umeshkshirsagar@elear.solutions
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
#ifndef COCO_STD_DATA_KEYPRESS_SENSING_TYPES_H_INCLUDED
#define COCO_STD_DATA_KEYPRESS_SENSING_TYPES_H_INCLUDED

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
  COCO_STD_CMD_KEYPRESS_MIN = -1,
  COCO_STD_CMD_KEYPRESS_SET_COMBO_NAME,
  COCO_STD_CMD_KEYPRESS_MAX,
  COCO_STD_CMD_KEYPRESS_UBOUND = 0x7FFFFFFF
} coco_std_cmd_keypress_t;

typedef enum {
  COCO_STD_ATTR_KEYPRESS_MIN = -1,
  COCO_STD_ATTR_KEYPRESS_SCENE_ID,            // This attribute is deprecated
  COCO_STD_ATTR_KEYPRESS_SCENE_KEY,           // This attribute is deprecated
  COCO_STD_ATTR_KEYPRESS_DISARM_FLAG,         // This attribute is deprecated
  COCO_STD_ATTR_KEYPRESS_ARM_DAY_FLAG,        // This attribute is deprecated
  COCO_STD_ATTR_KEYPRESS_ARM_NIGHT_FLAG,      // This attribute is deprecated
  COCO_STD_ATTR_KEYPRESS_ARM_ALL_FLAG,        // This attribute is deprecated
  COCO_STD_ATTR_KEYPRESS_PANIC_FLAG,          // This attribute is deprecated
  COCO_STD_ATTR_KEYPRESS_EMERGENCY_FLAG,      // This attribute is deprecated
  COCO_STD_ATTR_KEYPRESS_FALL_TRIGGER_FLAG,   // This attribute is deprecated
  COCO_STD_ATTR_KEYPRESS_ACTIVATED_COMBO_ID,
  COCO_STD_ATTR_KEYPRESS_COMBO_NAME_ARR,
  COCO_STD_ATTR_KEYPRESS_MAX,
  COCO_STD_ATTR_KEYPRESS_UBOUND = 0x7FFFFFFF
} coco_std_attr_keypress_t;

typedef enum {
  COCO_STD_KEYPRESS_SCENE_MIN = -1,
  COCO_STD_KEYPRESS_SCENE_SINGLE,     // key pressed 1 time
  COCO_STD_KEYPRESS_SCENE_DOUBLE,     // key pressed 2 time
  COCO_STD_KEYPRESS_SCENE_TRIPLE,     // key pressed 3 time
  COCO_STD_KEYPRESS_SCENE_QUAD,       // key pressed 4 time
  COCO_STD_KEYPRESS_SCENE_QUINT,      // key pressed 5 time
  COCO_STD_KEYPRESS_SCENE_HOLD,       // key pressed and hold down
  COCO_STD_KEYPRESS_SCENE_RELEASE,    // key pressed and released
  COCO_STD_KEYPRESS_SCENE_MAX,
  COCO_STD_KEYPRESS_SCENE_UBOUND = 0x7FFFFFFF
} coco_std_keypress_scene_t;

typedef struct {
  int16_t comboId;
  char *comboName;
} coco_std_cmd_set_keypress_combo_name_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_KEYPRESS_SENSING_TYPES_H_INCLUDED
