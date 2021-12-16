/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_meter_types.h
 * @brief     Attributes and commands belonging to metering capability
 * @details   This file contains attributes and commands belonging
 *            to the metering capability.
 * @see
 * @author    Prasad Makireddy, prasadmakireddy@elear.solutions
 *            Umesh Kshirsagar, umeshkshirsagar@elear.solutions
 *            Matta Vamsi Krishna, vamsikrishna@elear.solutions
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
#ifndef COCO_STD_DATA_METER_TYPES_H_INCLUDED
#define COCO_STD_DATA_METER_TYPES_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/
#include <stdint.h>

/*************************************************************************************
 *                          GLOBAL MACROS                                            *
 *************************************************************************************/

/*************************************************************************************
 *                          GLOBAL TYPEDEFS                                          *
 *************************************************************************************/
// Possible values of meter command
typedef enum {
  COCO_STD_CMD_METER_MIN = -1,
  COCO_STD_CMD_METER_RESET,
  COCO_STD_CMD_METER_FETCH_CONSUMPTION,
  COCO_STD_CMD_METER_FETCH_DEMAND,
  COCO_STD_CMD_METER_MAX,
  COCO_STD_CMD_METER_UBOUND = 0x7FFFFFFF
} coco_std_cmd_meter_t;

// Possible values of meter attribute
typedef enum {
  COCO_STD_ATTR_METER_MIN = -1,
  COCO_STD_ATTR_METER_CONSUMPTION_KWH,        // COCO_STD_DATA_TYPE_DOUBLE
  COCO_STD_ATTR_METER_DEMAND_WATT,            // COCO_STD_DATA_TYPE_DOUBLE
  COCO_STD_ATTR_METER_LAST_READ_TIME_ARR,     // COCO_STD_DATA_TYPE_DOUBLE_ARR
  COCO_STD_ATTR_METER_MULTIPLIER,             // Zigbee specific attributes, To be removed COCO_STD_DATA_TYPE_INT32
  COCO_STD_ATTR_METER_DIVISOR,                // Zigbee specific attributes, To be removed COCO_STD_DATA_TYPE_INT32
  COCO_STD_ATTR_METER_CONS_PROD_FMT_DIGITS,   // Zigbee specific attributes, To be removed COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_METER_CONS_PROD_FMT_DECIMALS, // Zigbee specific attributes, To be removed COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_METER_DEMAND_FMT_DIGITS,      // Zigbee specific attributes, To be removed COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_METER_DEMAND_DECIMALS,        // Zigbee specific attributes, To be removed COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_METER_PRODUCTION_KWH,         // COCO_STD_DATA_TYPE_DOUBLE
  COCO_STD_ATTR_METER_UNIT_OF_MEASURE,        // Zigbee specific attributes, To be removed COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_METER_MAX,
  COCO_STD_ATTR_METER_UBOUND = 0x7FFFFFFF
} coco_std_attr_meter_t;

// Structure of fetch consumption command
typedef struct {
  int32_t scale;
} coco_std_cmd_fetch_consumption_t;

// Structure of fetch demand command
typedef struct {
  int32_t scale;
} coco_std_cmd_fetch_demand_t;

// Possible values of consumption scale
typedef enum {
  COCO_STD_CONS_SCALE_MIN = -1,
  COCO_STD_CONS_SCALE_KW,
  COCO_STD_CONS_SCALE_CUBIC_METER_PER_HR,
  COCO_STD_CONS_SCALE_CUBIC_FEET_PER_HR,
  COCO_STD_CONS_SCALE_CENTI_CUBIC_FEET_PER_HR,
  COCO_STD_CONS_SCALE_US_GALLON_PER_HR,
  COCO_STD_CONS_SCALE_IMP_GALLON_PER_HR,
  COCO_STD_CONS_SCALE_BTU_PER_HR,
  COCO_STD_CONS_SCALE_LITERS_PER_HR,
  COCO_STD_CONS_SCALE_KPA_GAUGE,
  COCO_STD_CONS_SCALE_KPA_ABSOLUTE,
  COCO_STD_CONS_SCALE_KILO_CUBIC_FEET_PER_HR,
  COCO_STD_CONS_SCALE_UNITLESS,
  COCO_STD_CONS_SCALE_MJ_PER_SEC,
  COCO_STD_CONS_SCALE_MAX,
  COCO_STD_CONS_SCALE_UBOUND = 0x7FFFFFFF
} coco_std_consumption_scale_t;

// Possible values of demand scale
typedef enum {
  COCO_STD_DEMAND_SCALE_MIN = -1,
  COCO_STD_DEMAND_SCALE_KWH,
  COCO_STD_DEMAND_SCALE_CUBIC_METER,
  COCO_STD_DEMAND_SCALE_CUBIC_FEET,
  COCO_STD_DEMAND_SCALE_CENTI_CUBIC_FEET,
  COCO_STD_DEMAND_SCALE_US_GALLON,
  COCO_STD_DEMAND_SCALE_IMP_GALLON,
  COCO_STD_DEMAND_SCALE_BTU,
  COCO_STD_DEMAND_SCALE_LITERS,
  COCO_STD_DEMAND_SCALE_KPA_GAUGE,
  COCO_STD_DEMAND_SCALE_KPA_ABSOLUTE,
  COCO_STD_DEMAND_SCALE_KILO_CUBIC_FEET,
  COCO_STD_DEMAND_SCALE_UNITLESS,
  COCO_STD_DEMAND_SCALE_MJ,
  COCO_STD_DEMAND_SCALE_MAX,
  COCO_STD_DEMAND_SCALE_UBOUND = 0x7FFFFFFF
} coco_std_demand_scale_t;

/*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_METER_TYPES_H_INCLUDED
