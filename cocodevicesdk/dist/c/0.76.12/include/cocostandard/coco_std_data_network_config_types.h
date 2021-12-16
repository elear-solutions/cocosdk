/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_network_config_types.h
 * @brief     Attributes and commands belonging to network configuration capability
 * @details   This file contains the declaration of attributes belonging
 *            to network configuration capability
 * @see
 * @author    Prasad Makireddy, prasadmakireddy@elear.solutions
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
#ifndef COCO_STD_DATA_NETWORK_CONFIG_TYPES_H_INCLUDED
#define COCO_STD_DATA_NETWORK_CONFIG_TYPES_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/

/*************************************************************************************
 *                          GLOBAL MACROS                                            *
 *************************************************************************************/

 /*************************************************************************************
  *                          GLOBAL TYPEDEFS                                          *
  *************************************************************************************/
// Possible values of network config attribute
typedef enum {
  COCO_STD_ATTR_NW_CONFIG_MIN = -1,
  COCO_STD_ATTR_NW_CONFIG_RSSI,      // COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_NW_CONFIG_NW_NAME,   // COCO_STD_DATA_TYPE_JSON_STRING
  COCO_STD_ATTR_NW_CONFIG_MAX,
  COCO_STD_ATTR_NW_CONFIG_UBOUND = 0x7FFFFFFF
} coco_std_attr_nw_config_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_NETWORK_CONFIG_TYPES_H_INCLUDED
