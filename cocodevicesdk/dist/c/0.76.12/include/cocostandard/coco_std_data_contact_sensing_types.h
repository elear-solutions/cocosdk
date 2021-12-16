/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_contact_sensing_types.h
 * @brief     Attributes and commands belonging to contact sensing capability
 * @details   This file contains the attributes and commands belonging to contact sensing
 *            capability.
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
#ifndef COCO_STD_DATA_CONTACT_SENSING_TYPES_H_INCLUDED
#define COCO_STD_DATA_CONTACT_SENSING_TYPES_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/

/*************************************************************************************
 *                          GLOBAL MACROS                                            *
 *************************************************************************************/

 /*************************************************************************************
  *                          GLOBAL TYPEDEFS                                          *
  *************************************************************************************/
// Possible values of contact sensing command
typedef enum {
  COCO_STD_CMD_CONTACT_SENSING_MIN = -1,
  COCO_STD_CMD_CONTACT_SENSING_ENABLE,
  COCO_STD_CMD_CONTACT_SENSING_DISABLE,
  COCO_STD_CMD_CONTACT_SENSING_MAX,
  COCO_STD_CMD_CONTACT_SENSING_UBOUND = 0x7FFFFFFF
} coco_std_cmd_contact_sensing_t;

// Possible values of contact sensing attribute
typedef enum {
  COCO_STD_ATTR_CONTACT_SENSING_MIN = -1,
  COCO_STD_ATTR_CONTACT_1_OPEN_FLAG,   // COCO_STD_DATA_TYPE_BOOLEAN
  COCO_STD_ATTR_CONTACT_2_OPEN_FLAG,   // COCO_STD_DATA_TYPE_BOOLEAN
  COCO_STD_ATTR_CONTACT_SENSING_MAX,
  COCO_STD_ATTR_CONTACT_SENSING_UBOUND = 0x7FFFFFFF
} coco_std_attr_contact_sensing_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_CONTACT_SENSING_TYPES_H_INCLUDED
