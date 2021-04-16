/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_humidity_types.h
 * @brief     Attributes and commands belonging to relative humidity measurement capability
 * @details   This file contains attributes and commands belonging to relative humidity
 *            measurement capability.
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
#ifndef COCO_STD_DATA_HUMIDITY_TYPES_H_INCLUDED
#define COCO_STD_DATA_HUMIDITY_TYPES_H_INCLUDED

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
  COCO_STD_CMD_HUMIDITY_MIN = -1,
  COCO_STD_CMD_FETCH_RELATIVE_HUMIDITY_PCT,
  COCO_STD_CMD_HUMIDITY_MAX,
  COCO_STD_CMD_HUMIDITY_UBOUND = 0x7FFFFFFF
} coco_std_cmd_humidity_t;

typedef enum {
  COCO_STD_ATTR_HUMIDITY_MIN = -1,
  COCO_STD_ATTR_CURRENT_REL_HUMIDITY_PCT,
  COCO_STD_ATTR_HUMIDITY_MAX,
  COCO_STD_ATTR_HUMIDITY_UBOUND = 0x7FFFFFFF
} coco_std_attr_humidity_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_HUMIDITY_TYPES_H_INCLUDED
