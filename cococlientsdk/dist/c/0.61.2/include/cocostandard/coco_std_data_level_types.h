/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_level_types.h
 * @brief     Attributes and commands belonging to level Control capability
 * @details   This file contains attributes and commands belonging
 *            to the level Control capability.
 * @see
 * @author    Prasad Makireddy, prasadmakireddy@elear.solutions
 *            Umesh Kshirsagar, umeshkshirsagar@elear.solutions
 *            Omkar Wagle, omkarwagle@elear.solutions
 *            Shrinivas Gutte, shrinivasgutte@elear.solutions
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
#ifndef COCO_STD_DATA_LEVEL_TYPES_H_INCLUDED
#define COCO_STD_DATA_LEVEL_TYPES_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/
#include <stdint.h>
#include <stdbool.h>

/*************************************************************************************
 *                          GLOBAL MACROS                                            *
 *************************************************************************************/

/*************************************************************************************
 *                          GLOBAL TYPEDEFS                                          *
 *************************************************************************************/
typedef enum {
  COCO_STD_CMD_LEVEL_MIN = -1,
  COCO_STD_CMD_SET_LEVEL,
  COCO_STD_CMD_SET_LEVEL_WITH_ON_OFF,
  COCO_STD_CMD_FETCH_LEVEL,
  COCO_STD_CMD_LEVEL_MAX,
  COCO_STD_CMD_LEVEL_UBOUND = 0x7FFFFFFF
} coco_std_cmd_level_t;

typedef enum {
  COCO_STD_ATTR_LEVEL_MIN = -1,
  COCO_STD_ATTR_LEVEL_PCT,
  COCO_STD_ATTR_LEVEL_MAX,
  COCO_STD_ATTR_LEVEL_UBOUND = 0x7FFFFFFF
} coco_std_attr_level_t;

typedef struct {
  uint8_t levelPct;
  int32_t useDefaultTransTimeFlag;
  uint32_t transitionTimeMs;
} coco_std_cmd_set_level_t;

typedef struct {
  uint8_t levelPct;
  int32_t useDefaultTransTimeFlag;
  uint32_t transitionTimeMs;
  int32_t restoreLevelFlag;
} coco_std_cmd_set_level_with_onoff_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_LEVEL_TYPES_H_INCLUDED
