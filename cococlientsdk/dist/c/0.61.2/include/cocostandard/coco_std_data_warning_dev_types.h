/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_warning_dev_types.h
 * @brief     Attributes and commands belonging to warning device control capability
 * @details   This file contains attributes and commands belonging to warning device control
 *            capability.
 * @see
 * @author    Umesh Kshirsagar, umeshkshirsagar@elear.solutions
 *            Varun Kumar, varun.k@healthasyst.com
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
#ifndef COCO_STD_DATA_WARINING_DEV_TYPES_H_INCLUDED
#define COCO_STD_DATA_WARINING_DEV_TYPES_H_INCLUDED

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
  COCO_STD_CMD_WARNING_MIN = -1,
  COCO_STD_CMD_WARNING_START,
  COCO_STD_CMD_WARNING_STOP,
  COCO_STD_CMD_WARNING_MAX,
  COCO_STD_CMD_WARNING_UBOUND = 0x7FFFFFFF
} coco_std_cmd_warning_dev_t;

typedef enum {
  COCO_STD_WARNING_TYPE_MIN = -1,
  COCO_STD_WARNING_TYPE_BURGLAR,
  COCO_STD_WARNING_TYPE_FIRE,
  COCO_STD_WARNING_TYPE_EMERGENCY,
  COCO_STD_WARNING_TYPE_POLICE_PANIC,
  COCO_STD_WARNING_TYPE_FIRE_PANIC,
  COCO_STD_WARNING_TYPE_EMERGENCY_PANIC,
  COCO_STD_WARNING_TYPE_MAX,
  COCO_STD_ATTR_WARNING_UBOUND = 0x7FFFFFFF
} coco_std_warning_type_t;

typedef struct {
  int32_t warningType;
} coco_std_cmd_warning_start_t;

typedef enum {
  COCO_STD_ATTR_WARNING_MIN = -1,
  COCO_STD_ATTR_WARNING_STATE,
  COCO_STD_ATTR_WARNING_MAX,
  COCO_STD_WARNING_TYPE_UBOUND = 0x7FFFFFFF
} coco_std_attr_warning_dev_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_WARINING_DEV_TYPES_H_INCLUDED
