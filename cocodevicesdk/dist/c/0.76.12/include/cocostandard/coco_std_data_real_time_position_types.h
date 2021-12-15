/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_real_time_position_types.h
 * @brief     Attributes and commands belonging to real time position capability
 * @details   This file contains attributes and commands belonging to real time position
 *            capability.
 * @see
 * @author    Matta Vamsi Krishna, vamsikrishna@elear.solutions
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
#ifndef COCO_STD_DATA_REAL_TIME_POSITION_TYPES_H_INCLUDED
#define COCO_STD_DATA_REAL_TIME_POSITION_TYPES_H_INCLUDED

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
  COCO_STD_ATTR_REAL_TIME_POSITION_MIN = -1,
  COCO_STD_ATTR_REAL_TIME_POSITION_BEACON_LOC,  // COCO_STD_DATA_TYPE_JSON_STRING
  COCO_STD_ATTR_REAL_TIME_POSITION_MAX,
  COCO_STD_ATTR_REAL_TIME_POSITION_UBOUND = 0x7FFF
} coco_std_attr_real_time_position_t;

typedef struct {
  char *locationIdStr;
  char *lotIdStr;
  char *beaconIdStr;
  double radiusOfBeacon;
  double xCoordinate;
  double yCoordinate;
  double errorPrecision;
  int32_t rssi;
  int32_t measuredPower;
  char *deviceResourceNameStr;
} coco_std_attr_real_time_position_beacon_loc_t;  //  coco_std_attr_real_time_position_beacon_loc_t struct type cooresponds to
                                                  //  COCO_STD_STRUCT_ATTR_REAL_TIME_POSITION_BEACON_LOC

/*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_REAL_TIME_POSITION_TYPES_H_INCLUDED
