/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_color_types.h
 * @brief     Attributes and commands belonging to color control capability
 * @details   This file contains attributes and commands belonging to color control
 *            capability.
 * @see
 * @author    Prasad Makireddy, prasadmakireddy@elear.solutions
 *            Umesh Kshirsagar, umeshkshirsagar@elear.solutions
 *            Omkar Wagle, omkarwagle@elear.solutions
 *            Shrinivas Gutte, shrinivasgutte@elear.solutions
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
#ifndef COCO_STD_DATA_COLOR_TYPES_H_INCLUDED
#define COCO_STD_DATA_COLOR_TYPES_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/
#include <stdint.h>
#include <stdbool.h>

/*************************************************************************************
 *                          GLOBAL MACROS                                            *
 *************************************************************************************/

/*************************************************************************************
 *                          GLOBAL TYPEDEFS                                          *
 *************************************************************************************/
typedef enum {
  COCO_STD_CMD_COLOR_MIN = -1,
  COCO_STD_CMD_SET_COLOR_RGB,
  COCO_STD_CMD_SET_COLOR_HSL,
  COCO_STD_CMD_SET_COLOR_TEMP,
  COCO_STD_CMD_SET_COLOR_COMPONENTS,
  COCO_STD_CMD_FETCH_COLOR_RGB,
  COCO_STD_CMD_FETCH_COLOR_HSL,
  COCO_STD_CMD_FETCH_COLOR_TEMP,
  COCO_STD_CMD_FETCH_COLOR_COMPONENTS,
  COCO_STD_CMD_COLOR_MAX,
  COCO_STD_CMD_COLOR_UBOUND = 0x7FFFFFFF
} coco_std_cmd_color_control_t;

typedef enum {
  COCO_STD_ATTR_COLOR_MIN = -1,
  COCO_STD_ATTR_COLOR_RED,                // This attribute is deprecated
  COCO_STD_ATTR_COLOR_GREEN,              // This attribute is deprecated
  COCO_STD_ATTR_COLOR_BLUE,               // This attribute is deprecated
  COCO_STD_ATTR_COLOR_HUE_DEGREES,        // This attribute is deprecated
  COCO_STD_ATTR_COLOR_SATURATION_PCT,     // This attribute is deprecated
  COCO_STD_ATTR_COLOR_LUMINANCE_PCT,      // This attribute is deprecated
  COCO_STD_ATTR_COLOR_TEMP_KELVIN,
  COCO_STD_ATTR_COLOR_COMP_ID_ARR,
  COCO_STD_ATTR_COLOR_COMP_VALUES_ARR,
  COCO_STD_ATTR_COLOR_X,                  // This attribute is deprecated
  COCO_STD_ATTR_COLOR_Y,                  // This attribute is deprecated
  COCO_STD_ATTR_COLOR_MODE,               // This attribute is deprecated
  COCO_STD_ATTR_COLOR_HSL,
  COCO_STD_ATTR_COLOR_RGB,
  COCO_STD_ATTR_COLOR_MAX,
  COCO_STD_ATTR_COLOR_UBOUND = 0x7FFFFFFF
} coco_std_attr_color_control_t;

typedef struct {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  int32_t useDefaultTransTimeFlag;
  uint32_t transitionTimeMs;
} coco_std_cmd_set_color_rgb_t;

typedef struct {
  uint16_t hueDegrees;
  uint8_t saturationPct;
  uint8_t luminancePct;
  int32_t useDefaultTransTimeFlag;
  uint32_t transitionTimeMs;
} coco_std_cmd_set_color_hsl_t;

typedef struct {
  uint32_t colorTemperatureKelvin;
  int32_t useDefaultTransTimeFlag;
  uint32_t transitionTimeMs;
} coco_std_cmd_set_color_temp_t;

typedef struct {
  uint8_t *colorCompIdArr;
  uint8_t numOfColorCompIds;
} coco_std_cmd_fetch_color_components_t;

typedef struct {
  uint8_t *colorCompIdArr;
  uint8_t *colorCompValuesArr;
  uint8_t numOfColorCompIds;
  int32_t useDefaultTransTimeFlag;
  uint32_t transitionTimeMs;
} coco_std_cmd_set_color_components_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_COLOR_TYPES_H_INCLUDED
