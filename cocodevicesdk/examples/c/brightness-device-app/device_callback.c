/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      device_callback.c
 * @brief     Declaration of callbacks to be invoked by cococlientsdk
 * @details   Declaration of callbacks to be invoked by cococlientsdk
 * @see
 * @author    Utkarsha Meshram, utkarshameshram@elear.solutions
 * @author    Varun Kumar, varun.k@healthasyst.com
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
#include <stdio.h>
#include <stdlib.h>
#include "cocodevicesdk/coco_device_api.h"
#include "cocostandard/coco_std_data_level_types.h"
#include "cocostandard/coco_std_data_meter_types.h"
#include "device_callback.h"

/*************************************************************************************
 *                          LOCAL MACROS                                             *
 *************************************************************************************/

/*************************************************************************************
 *                          LOCAL TYPEDEFS                                           *
 *************************************************************************************/

/*************************************************************************************
 *                          LOCAL PROTOTYPES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/
 int64_t maxBrightness;
static int maxVal = 100;
static int64_t curVal = 50;
static int reportChange = 1;

/*************************************************************************************
 *                          LOCAL VARIABLES                                          *
 *************************************************************************************/
static coco_std_resource_attribute_info_t levelAttr = {
    NULL,
    0,
    "zigbee/0015BC0036000397/26",
    COCO_STD_CAP_LEVEL_CTRL,
    "LEVEL",
    COCO_STD_ATTR_LEVEL_PCT,
    "COCO_STD_ATTR_LEVEL_PCT",
    "level control",
    COCO_STD_DATA_TYPE_UINT8,
    0,
    0,
    &maxVal,
    NULL,
    (void *)&curVal,
    0,
    0,
    &reportChange,
    1,
    0,
    0,
    1556539804,
    0
};

coco_std_resource_attribute_info_t consumption = {
NULL,
    0,
    "zigbee/0015BC0036000397/26",
    COCO_STD_CAP_ENERGY_METERING,
    "ENERGYMETERINGCONSUMPTION",
    COCO_STD_ATTR_METER_CONSUMPTION_KWH,
    "COCO_STD_ATTR_METER_CONSUMPTION_KWH",
    "COCO_STD_ATTR_METER_CONSUMPTION_KWH",
    COCO_STD_DATA_TYPE_DOUBLE,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    &reportChange,
    1,
    0,
    0,
    1556539804,
    0
};
coco_std_resource_attribute_info_t demand = {
  NULL,
    0,
    "zigbee/0015BC0036000397/26",
    COCO_STD_CAP_ENERGY_METERING,
    "ENERGYMETERING",
    COCO_STD_ATTR_METER_DEMAND_WATT,
    "COCO_STD_ATTR_METER_DEMAND_WATT",
    "COCO_STD_ATTR_METER_DEMAND_WATT",
    COCO_STD_DATA_TYPE_DOUBLE,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    &reportChange,
    1,
    0,
    0,
    1556539804,
    0
};

/*************************************************************************************
 *                          PRIVATE FUNCTIONS                                        *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/
/*************************************************************************************
 * Refer to the header file for a detailed description                               *
 *************************************************************************************/
void coco_device_join_nw_status_cb(int32_t status) {
  printf("App: coco_device_join_nw_status_cb() status: %d\n", status);
  return;
}

/*************************************************************************************
 * Refer to the header file for a detailed description                               *
 *************************************************************************************/
void coco_device_add_res_status_cb(int32_t status, void *context) {
  printf("App: coco_device_add_res_status_cb() status: %d\n", status);
  return;
}

/*************************************************************************************
 * Refer to the header file for a detailed description                               *
 *************************************************************************************/
void coco_device_attribute_update_status(int32_t status, void *context) {
  printf("App: coco_device_attribute_update_status() status: %d\n", status);
  return;
}

/*************************************************************************************
 * Refer to the header file for a detailed description                               *
 *************************************************************************************/
void coco_device_data_corruption_cb() {
  printf("App: cocodevicesdk data corrupted\n");
  exit(1);
}
/*************************************************************************************
 * Refer to the header file for a detailed description                               *
 *************************************************************************************/
void map_brightness_values() {
  ec_debug_log(LOG_AUTHPRIV, "get", NULL);
  int fd;
  char maxBrightStr[10];
  if (-1 == (fd = open("/sys/class/backlight/intel_backlight/max_brightness", O_RDONLY))) {
    ec_debug_log(LOG_ERR, "Unable to open the file", NULL);
    return;
  }
  if (-1 == (read(fd, maxBrightStr, 10))) {
    ec_debug_log(LOG_ERR, "unable to read the file", NULL);
    close(fd);
    return;
  }

  close(fd);

  if (false == ec_str_to_int(maxBrightStr, &maxBrightness)) {
    ec_debug_log(LOG_ERR, "Unable to convert the string", NULL);
    return;
  }
}

/*************************************************************************************
 * Refer to the header file for a detailed description                               *
 *************************************************************************************/
void coco_device_resource_cmd_cb(coco_std_resource_cmd_t *resourceCmd) {
  coco_std_cmd_set_level_t *resCmd = (coco_std_cmd_set_level_t *)resourceCmd->cmdParams;
  int fd, setLevel, len;
  char *setLevelStr;
  if (COCO_STD_CAP_LEVEL_CTRL == resourceCmd->capabilityId &&
      COCO_STD_CMD_SET_LEVEL_WITH_ON_OFF == resourceCmd->cmdId) {
        if (NULL == resCmd) {
          printf("CmdParams not passed");
          return;
        }

        if (resCmd->levelPct > 100 || resCmd->levelPct < 0) {
          printf("error: invalid value for levelPct, %d", resCmd->levelPct);
          return;
        }

        setLevel = resCmd->levelPct * (maxBrightness/100);

        if (-1 == (fd = open("/sys/class/backlight/intel_backlight/brightness", O_RDWR))) {
          printf("Unable to open the file");
          return;
        }
        len = ec_strlen_int(setLevel);
        setLevelStr = ec_allocate_and_set(len, EC_TTL_INFINITY, 0);

        if (NULL == (setLevelStr = ec_int_to_str(setLevel, setLevelStr, len))) {
          printf("Unable to convert");
          return;
        }

        if (-1 == write(fd, setLevelStr, strlen(setLevelStr))) {
          printf("Unable to write");
          close(fd);
        }

        levelAttr.currentValue = (void *)&resCmd->levelPct;

        if (-1 == coco_device_resource_attribute_update(&levelAttr, NULL)) {
          printf("App: Update attribute failed\n");
        }
        update_consumption_and_demand((double)resCmd->levelPct);
        ec_deallocate(setLevelStr);
        close(fd);
      }
      return;
}

void update_consumption_and_demand(double currentValue) {
printf("HIIIIIIIIII");
  double val = 50 + (currentValue/2.0);
  consumption.currentValue = (void *)&val;
  if (-1 == coco_device_resource_attribute_update(&consumption, NULL)) {
          printf("App: Update attribute failed\n");
  }
  val = (currentValue/2.0);
  demand.currentValue = (void *)&val;

  if (-1 == coco_device_resource_attribute_update(&demand, NULL)) {
          printf("App: Update attribute failed\n");
  }
}
