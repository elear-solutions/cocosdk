/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      main.c
 * @brief     Device app built on top of COCO Device SDK
 * @details   Device app to demonstatrate capabilities of COCO Device SDK like adding a
 *            resource and publishing attribute updates
 * @see
 * @author    Utkarsha Meshram, utkarshameshram@elear.solutions
 * @author    Varun Kumar, varun.k@healthasyst.com
 * @test
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
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <syslog.h>
#include <time.h>
#include "cocodevicesdk/coco_device_api.h"
#include "cocostandard/coco_std_api.h"
#include "cocostandard/coco_std_data_illuminance_types.h"
#include "cocostandard/coco_std_data_network_config_types.h"
#include "device_callback.h"
#include "cocostandard/coco_std_data_meter_types.h"

/*************************************************************************************
 *                          LOCAL MACROS                                             *
 *************************************************************************************/
char dataPath[20] = {"../data"};
char configPath[20] = {"../config.txt"};
char resourceInfoPath[] = {"../resourceTemplate.txt"};
char downloadPath[] = {"./"};
char firmwareVersion[] = {"1.0.1"};

/*************************************************************************************
 *                          LOCAL TYPEDEFS                                           *
 *************************************************************************************/
/*************************************************************************************
 *                          LOCAL PROTOTYPES                                         *
 ************************************************************************************/
/*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/
/*************************************************************************************
 *                          LOCAL VARIABLES                                          *
 *************************************************************************************/
static int32_t rssiVal = 4;
static int reportChange = 1;

static coco_std_resource_attribute_info_t rssiAttr = {
    NULL,
    0,
    "zigbee/0015BC0036000397/26",
    COCO_STD_CAP_NETWORK_CONFIGURATION,
    "NETWORK CONFIG",
    COCO_STD_ATTR_NW_CONFIG_RSSI,
    "RSSI",
    "rssi",
    COCO_STD_DATA_TYPE_UINT8,
    0,
    NULL,
    NULL,
    NULL,
    &rssiVal,
    0,
    0,
    &reportChange,
    1,
    0,
    0,
    1556539804,
    0
};

coco_std_resource_attribute_info_t demandAttr = {
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
/******************************************************************************
Name        : main
Input(s)    : Command line arguments
Output(s)   : int: exit status of the application
Description : Initialise cocodevicesdk, add the device to COCONet, add a resource
              and publish attribute update once every 2 seconds
*******************************************************************************/
int main(int argc, char *argv[]) {
  double val;
  printf("HI");
  int32_t protocolArr[] = {COCO_STD_PROTOCOL_ZIGBEE};
   int retVal;

  coco_device_init_params_t deviceInitParams = { 0 };
  deviceInitParams.loggerOutput = 1;
  deviceInitParams.resInfoPath = resourceInfoPath;
  deviceInitParams.cwdPath = dataPath;
  deviceInitParams.configFilePath = configPath;
  deviceInitParams.downloadPath = downloadPath;
  deviceInitParams.firmwareVersion = firmwareVersion;
  deviceInitParams.attributeUpdateCb = coco_device_attribute_update_status;
  deviceInitParams.dataCorruptionCb = coco_device_data_corruption_cb;
  deviceInitParams.resourceCmdCb = coco_device_resource_cmd_cb;
  deviceInitParams.firmwareUpdateCb = coco_device_firmware_update_cb;
  deviceInitParams.skipSSLVerification = 1;
  deviceInitParams.protocolIdArr = protocolArr;
  deviceInitParams.protocolIdArrCnt = 1;
  if (-1 == (retVal = coco_device_init(&deviceInitParams))) {
    exit(1);
  } else if (0 == retVal) {
    while (-1 == (coco_device_init_auth())) {
      printf("Sending Auth\n");
      sleep(3);
    }
  }

  coco_device_resource_attribute_update(&rssiAttr, NULL);

  while (1) {
    val = (rand() % 50) + 1;
    demandAttr.currentValue = &val;
    coco_device_resource_attribute_update(&demandAttr, NULL);
    sleep(5);
  }
  return EXIT_SUCCESS;
}
