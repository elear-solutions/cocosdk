/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_storage_config_types.h
 * @brief     Attributes and commands belonging to storage config capability
 * @details   This file contains attributes and commands belonging to storage config
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
#ifndef COCO_STD_DATA_STORAGE_CONFIG_TYPES_H_INCLUDED
#define COCO_STD_DATA_STORAGE_CONFIG_TYPES_H_INCLUDED

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
  COCO_STD_CMD_STORAGE_CONFIG_MIN = -1,
  COCO_STD_CMD_STORAGE_CONFIG,
  COCO_STD_CMD_STORAGE_CONFIG_MAX,
  COCO_STD_CMD_STORAGE_CONFIG_UBOUND = 0x7FFFFFFF
} coco_std_cmd_id_storage_config_t;

typedef enum {
  COCO_STD_ATTR_STORAGE_CONFIG_MIN = -1,
  COCO_STD_ATTR_STORAGE_STORAGE_NODE,
  COCO_STD_ATTR_STORAGE_CONFIG_MAX,
  COCO_STD_ATTR_STORAGE_CONFIG_UBOUND = 0x7FFF
} coco_std_attr_storage_config_t;

typedef struct {
  uint32_t storageNodeId;
  char *resourceEui;
} coco_std_cmd_storage_config_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_STORAGE_CONFIG_TYPES_H_INCLUDED
