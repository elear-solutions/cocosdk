/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_on_off_types.h
 * @brief     Attributes and commands belonging to on off control capability
 * @details   This file contains the declaration of attributes and commands belonging
 *            to on off control capability
 * @see
 * @author    Prasad Makireddy, prasadmakireddy@elear.solutions
 *            Umesh Kshirsagar, umeshkshirsagar@elear.solutions
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
#ifndef COCO_STD_DATA_ON_OFF_TYPES_H_INCLUDED
#define COCO_STD_DATA_ON_OFF_TYPES_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/

/*************************************************************************************
 *                          GLOBAL MACROS                                            *
 *************************************************************************************/

 /*************************************************************************************
  *                          GLOBAL TYPEDEFS                                          *
  *************************************************************************************/
// Possible values of on off command
typedef enum {
  COCO_STD_CMD_ON_OFF_MIN = -1,
  COCO_STD_CMD_ON,
  COCO_STD_CMD_OFF,
  COCO_STD_CMD_ON_OFF_TOGGLE,
  COCO_STD_CMD_FETCH_ON_OFF_STATUS,
  COCO_STD_CMD_ON_OFF_MAX,
  COCO_STD_CMD_ON_OFF_UBOUND = 0x7FFFFFFF
} coco_std_cmd_on_off_t;

// Possible values of on off attribute
typedef enum {
  COCO_STD_ATTR_ON_OFF_MIN = -1,
  COCO_STD_ATTR_ON_FLAG,            // COCO_STD_DATA_TYPE_BOOLEAN
  COCO_STD_ATTR_ON_OFF_MAX,
  COCO_STD_ATTR_ON_OFF_UBOUND = 0x7FFFFFFF
} coco_std_attr_on_off_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_ON_OFF_TYPES_H_INCLUDED
