/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_stationary_position_types.h
 * @brief     Attributes and commands belonging to stationary position capability
 * @details   This file contains attributes and commands belonging to stationary position
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
#ifndef COCO_STD_DATA_STATIONARY_POSITION_TYPES_H_INCLUDED
#define COCO_STD_DATA_STATIONARY_POSITION_TYPES_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/

/*************************************************************************************
 *                          GLOBAL MACROS                                            *
 *************************************************************************************/

/*************************************************************************************
 *                          GLOBAL TYPEDEFS                                          *
 *************************************************************************************/
// Possible values of stationary position type command
typedef enum {
  COCO_STD_CMD_STATIONARY_POSITION_MIN = -1,
  COCO_STD_CMD_STATIONARY_POSITTION_SET_DEVICE_LOC,
  COCO_STD_CMD_STATIONARY_POSITION_MAX,
  COCO_STD_CMD_STATIONARY_POSITION_UBOUND = 0x7FFFFFFF
} coco_std_cmd_stationary_position_type_t;

// Possible values of stationary position type attribute
typedef enum {
  COCO_STD_ATTR_STATIONARY_POSITION_MIN = -1,
  COCO_STD_ATTR_STATIONARY_POSITION_BEACON_LOC, // COCO_STD_DATA_TYPE_STRING
  COCO_STD_ATTR_STATIONARY_POSITION_DEVICE_LOC, // COCO_STD_DATA_TYPE_STRING
  COCO_STD_ATTR_STATIONARY_POSITION_MAX,
  COCO_STD_ATTR_STATIONARY_POSITION_UBOUND = 0x7FFF
} coco_std_attr_stationary_position_type_t;

// Structure of stationary position set device location command
typedef struct {
  char *locationIdStr;
  char *lotIdStr;
  double xCoordinate;
  double yCoordinate;
  double environmentalFactor;
} coco_std_cmd_stationary_position_set_device_loc_t;

// Structure of stationary position beacon location attribute
typedef struct {
  char *locationIdStr;
  char *lotIdStr;
  char *beaconIdStr;
  double avgRadiusOfBeacon;                        // Average radius of Beacon
  uint32_t avgTimeDurOfBeacon;                     // Average time of beacon
  double xCoordinate;
  double yCoordinate;
  double errorPrecision;
  char *deviceResourceNameStr;
} coco_std_attr_stationary_position_beacon_loc_t;  //  coco_std_attr_stationary_position_beacon_loc_t struct type cooresponds to
                                                   //  COCO_STD_STRUCT_ATTR_STATIONARY_POSITION_BEACON_LOC

// Structure of stationary position device location attribute
typedef struct {
  char *locationIdStr;
  char *lotIdStr;
  double xCoordinate;
  double yCoordinate;
  double environmentalFactor;
} coco_std_attr_stationary_position_device_loc_t; //  coco_std_attr_stationary_position_device_loc_t struct type cooresponds to
                                                  //  COCO_STD_STRUCT_ATTR_STATIONARY_POSITION_DEVICE_LOC

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_STATIONARY_POSITION_TYPES_H_INCLUDED
