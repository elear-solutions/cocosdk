/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_air_quality_types.h
 * @brief     Attributes and commands belonging to air quality sensing capability
 * @details   This file contains the declaration of attributes and commands belonging to
 *            air quality sensing capability
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
#ifndef COCO_STD_DATA_AIR_QUALITY_TYPES_H_INCLUDED
#define COCO_STD_DATA_AIR_QUALITY_TYPES_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/

/*************************************************************************************
 *                          GLOBAL MACROS                                            *
 *************************************************************************************/

 /*************************************************************************************
  *                          GLOBAL TYPEDEFS                                          *
  *************************************************************************************/
// Possible values of air quality command
typedef enum {
  COCO_STD_CMD_AIRQLTY_MIN = -1,
  COCO_STD_CMD_AIRQLTY_MAX,
  COCO_STD_CMD_AIRQLTY_UBOUND = 0x7FFFFFFF
} coco_std_cmd_air_quality_t;

// Possible values of air quality attribute
typedef enum {
  COCO_STD_ATTR_AIRQLTY_MIN = -1,
  COCO_STD_ATTR_AIRQLTY_TOTAL_VOC_PPB, // Volatile Organic Compounds Particles measured in the air,
                                       // in parts per billion (PPB)
                                       // COCO_STD_DATA_TYPE_UINT16
  COCO_STD_ATTR_AIRQLTY_MAX,
  COCO_STD_ATTR_AIRQLTY_UBOUND = 0x7FFFFFFF
} coco_std_attr_air_quality_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_AIR_QUALITY_TYPES_H_INCLUDED
