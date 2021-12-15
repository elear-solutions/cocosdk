/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_hvac_control_types.h
 * @brief     Attributes and commands belonging to hvac control capability
 * @details   This file contains the declaration of attributes and commands belonging to
 *            hvac control capability
 * @see
 * @author    Omkar Wagle, omkarwagle@elear.solutions
 * @copyright Copyright (c) 2021 Elear Solutions Tech Private Limited. All rights
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
#ifndef COCO_STD_DATA_HVAC_CONTROL_TYPES_H_INCLUDED
#define COCO_STD_DATA_HVAC_CONTROL_TYPES_H_INCLUDED

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
  COCO_STD_CMD_HVAC_MIN = -1,
  COCO_STD_CMD_HVAC_SET_STATE,
  COCO_STD_CMD_HVAC_SYNC_STATE,
  COCO_STD_CMD_HVAC_MAX,
  COCO_STD_CMD_HVAC_UBOUND = 0x7FFFFFFF
} coco_std_cmd_hvac_t;

typedef enum {
  COCO_STD_HVAC_MODE_MIN = -1,
  COCO_STD_HVAC_MODE_COOL,
  COCO_STD_HVAC_MODE_HEAT,
  COCO_STD_HVAC_MODE_AUTO,
  COCO_STD_HVAC_MODE_EMERGENCY_HEAT,
  COCO_STD_HVAC_MODE_PRECOOLING,
  COCO_STD_HVAC_MODE_FAN_ONLY,
  COCO_STD_HVAC_MODE_DRY,
  COCO_STD_HVAC_MODE_SLEEP,
  COCO_STD_HVAC_MODE_MAX,
  COCO_STD_HVAC_MODE_UBOUND = 0x7FFFFFFF
} coco_std_hvac_mode_t;

typedef enum {
  COCO_STD_HVAC_FAN_SPEED_MIN = -1,
  COCO_STD_HVAC_FAN_SPEED_OFF,
  COCO_STD_HVAC_FAN_SPEED_LOW,
  COCO_STD_HVAC_FAN_SPEED_MEDIUM,
  COCO_STD_HVAC_FAN_SPEED_HIGH,
  COCO_STD_HVAC_FAN_SPEED_AUTO,
  COCO_STD_HVAC_FAN_SPEED_MAX,
  COCO_STD_HVAC_FAN_SPEED_UBOUND = 0x7FFFFFFF
} coco_std_hvac_fan_speed_t;

// Command parameter for COCO_STD_CMD_HVAC_SET_STATE command
typedef struct {
  bool powerOnFlag;
  int32_t mode;                  // Refer enum coco_std_hvac_mode_t
  uint8_t temperatureCelsius;
  int32_t fanSpeed;             // Refer enum coco_std_hvac_fan_speed_t
  bool swingOnFlag;
} coco_std_cmd_hvac_set_state_t;

typedef enum {
  COCO_STD_ATTR_HVAC_MIN = -1,
  COCO_STD_ATTR_HVAC_SUPPORTED_MODES_ARR,  // COCO_STD_DATA_TYPE_UINT8_ARR
  COCO_STD_ATTR_HVAC_POWER_ON_FLAG,        // COCO_STD_DATA_TYPE_BOOLEAN
  COCO_STD_ATTR_HVAC_TEMPERATURE_CELSIUS,  // COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_HVAC_MODE,                 // COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_HVAC_FAN_SPEED,            // COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_HVAC_SWING_ON_FLAG,        // COCO_STD_DATA_TYPE_BOOLEAN
  COCO_STD_ATTR_HVAC_MAX,
  COCO_STD_ATTR_HVAC_UBOUND = 0x7FFFFFFF
} coco_std_attr_hvac_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_HVAC_CONTROL_TYPES_H_INCLUDED
