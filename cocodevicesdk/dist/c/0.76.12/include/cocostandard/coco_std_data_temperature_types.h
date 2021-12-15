/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_temperature_types.h
 * @brief     Struct_to_json, json_to_struct and memory deallocator utilities for "data" structures,
 *            command and attribute enums belonging to temperature measurement capability
 * @details   This file contains the implementation of struct_to_json, json_to_struct and
 *            memory deallocator utilities for command parameter "data" structures belonging
 *            to the temperature measurement capability.
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
#ifndef COCO_STD_DATA_TEMPERATURE_TYPES_H_INCLUDED
#define COCO_STD_DATA_TEMPERATURE_TYPES_H_INCLUDED

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
  COCO_STD_CMD_TEMPERATURE_MIN = -1,
  COCO_STD_CMD_TEMPERATURE_MAX,
  COCO_STD_CMD_TEMPERATURE_UBOUND = 0x7FFFFFFF
} coco_std_cmd_temperature_t;

typedef enum {
  COCO_STD_ATTR_TEMPERATURE_MIN = -1,
  COCO_STD_ATTR_CURRENT_TEMP_CELSIUS,  // COCO_STD_DATA_TYPE_DOUBLE
  COCO_STD_ATTR_TEMPERATURE_MAX,
  COCO_STD_ATTR_TEMPERATURE_UBOUND = 0x7FFFFFFF
} coco_std_attr_temperature_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_TEMPERATURE_TYPES_H_INCLUDED
