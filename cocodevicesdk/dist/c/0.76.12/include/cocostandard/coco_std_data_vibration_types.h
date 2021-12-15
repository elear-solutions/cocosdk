/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_vibration_types.h
 * @brief     Attributes and commands belonging to vibration sensing capability
 * @details   This file contains the declaration of attributes and commands belonging to \
 *            vibration sensing capability
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
#ifndef COCO_STD_DATA_VIBRATION_TYPES_H_INCLUDED
#define COCO_STD_DATA_VIBRATION_TYPES_H_INCLUDED

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
  COCO_STD_CMD_VIBRATION_MIN = -1,
  COCO_STD_CMD_VIBRATION_MAX,
  COCO_STD_CMD_VIBRATION_UBOUND = 0x7FFFFFFF
} coco_std_cmd_vibration_t;

typedef enum {
  COCO_STD_ATTR_VIBRATION_MIN = -1,
  COCO_STD_ATTR_MOVEMENT_DETECTED_FLAG,   // COCO_STD_DATA_TYPE_BOOLEAN
  COCO_STD_ATTR_VIBRATION_DETECTED_FLAG,  // COCO_STD_DATA_TYPE_BOOLEAN
  COCO_STD_ATTR_VIBRATION_MAX,
  COCO_STD_ATTR_VIBRATION_UBOUND = 0x7FFFFFFF
} coco_std_attr_vibration_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_VIBRATION_TYPES_H_INCLUDED
