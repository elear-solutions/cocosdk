/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_motor_types.h
 * @brief     Attributes and commands belonging to motor control capability
 * @details   This file contains attributes and commands belonging to motor control
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
#ifndef COCO_STD_DATA_MOTOR_TYPES_H_INCLUDED
#define COCO_STD_DATA_MOTOR_TYPES_H_INCLUDED

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
  COCO_STD_CMD_MOTOR_MIN = -1,
  COCO_STD_CMD_MOTOR_PAN,
  COCO_STD_CMD_MOTOR_TILT,
  COCO_STD_CMD_MOTOR_SET_PRESET,
  COCO_STD_CMD_MOTOR_CLEAR_PRESET,
  COCO_STD_CMD_MOTOR_GO_TO_PRESET,
  COCO_STD_CMD_MOTOR_START_TRACK,
  COCO_STD_CMD_MOTOR_STOP_TRACK,
  COCO_STD_CMD_MOTOR_MAX,
  COCO_STD_CMD_MOTOR_UBOUND = 0x7FFFFFFF
} coco_std_cmd_motor_t;

typedef enum {
  COCO_STD_ATTR_MOTOR_MIN = -1,
  COCO_STD_ATTR_MOTOR_PAN_DOF,                   // Max degrees from initial
  COCO_STD_ATTR_MOTOR_TILT_DOF,
  COCO_STD_ATTR_MOTOR_SPEED_RPM,                 // motor speed in RPM
  COCO_STD_ATTR_MOTOR_PRESET_POINT_ARR,          // array of preset points
  COCO_STD_ATTR_MOTOR_TRACK_PRESET_POINT_ARR,    // array of track preset points
  COCO_STD_ATTR_MOTOR_TRACK_ACTIVE_FLAG,         // track active flag, true if the track is active
  COCO_STD_ATTR_MOTOR_TRACK_REPEAT_COUNT,        // track repeat count
  COCO_STD_ATTR_MOTOR_TRACK_DELAY_MS,            // delay in milliseconds between two preset points in track
  COCO_STD_ATTR_MOTOR_MAX,
  COCO_STD_ATTR_MOTOR_UBOUND = 0x7FFFFFFF
} coco_std_attr_motor_ctrl_t;

typedef enum {
  COCO_STD_MOTOR_PAN_DIREC_MIN = -1,
  COCO_STD_MOTOR_PAN_DIREC_LEFT,
  COCO_STD_MOTOR_PAN_DIREC_RIGHT,
  COCO_STD_MOTOR_PAN_DIREC_MAX,
  COCO_STD_MOTOR_PAN_DIREC_UBOUND = 0x7FFFFFFF
} coco_std_motor_pan_direction_t;

typedef enum {
  COCO_STD_MOTOR_TILT_DIREC_MIN = -1,
  COCO_STD_MOTOR_TILT_DIREC_UP,
  COCO_STD_MOTOR_TILT_DIREC_DOWN,
  COCO_STD_MOTOR_TILT_DIREC_MAX,
  COCO_STD_MOTOR_TILT_DIREC_UBOUND = 0x7FFFFFFF
} coco_std_motor_tilt_direction_t;

typedef struct {
  int32_t direction;                             // one of the value from coco_std_motor_pan_direction_t
  uint16_t degree;                               // 0 to 360 degrees
  int32_t speed;                                 // 0 to 1000 and -1 for default speed
} coco_std_cmd_motor_pan_t;

typedef struct {
  int32_t direction;                             // one of the value from coco_std_motor_tilt_direction_t
  uint16_t degree;                               // 0 to 360 degrees
  int32_t speed;                                 // 0 to 1000 and -1 for default speed
} coco_std_cmd_motor_tilt_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_MOTOR_TYPES_H_INCLUDED
