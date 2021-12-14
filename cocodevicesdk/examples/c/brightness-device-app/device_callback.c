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
#include <unistd.h>
#include <fcntl.h>
#include "cocodevicesdk/coco_device_api.h"
#include "cocostandard/coco_std_data_level_types.h"
#include "cocostandard/coco_std_data_meter_types.h"
#include "device_callback.h"

/*************************************************************************************
 *                          LOCAL MACROS                                             *
 *************************************************************************************/
#define FIRMWARE_VERSION_PATH             "./firmwareversion"

#define MAX_BRIGHTNESS_FILE_PATH    "/sys/class/backlight/intel_backlight/max_brightness"

#define BRIGHTNESS_FILE_PATH        "/sys/class/backlight/intel_backlight/brightness"
/*************************************************************************************
 *                          LOCAL TYPEDEFS                                           *
 *************************************************************************************/
/*************************************************************************************
 *                          LOCAL PROTOTYPES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/
/*************************************************************************************
 *                          LOCAL VARIABLES                                          *
 *************************************************************************************/
static int maxVal = 100;
static int64_t curVal = 50;
static int reportChange = 1;

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

/*************************************************************************************
 *                          PRIVATE FUNCTIONS                                        *
 *************************************************************************************/
/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

/*************************************************************************************
 * Refer to the header file for a detailed description                               *
 *************************************************************************************/
void coco_device_data_corruption_cb() {
  printf("App: cocodevicesdk data corrupted\n");
  exit(1);
}

void coco_device_attribute_update_status(int32_t status, void *context) {
  printf("App: coco_device_attribute_update_status() status: %d\n", status);
  return;
}

void coco_device_add_res_status_cb(int32_t status, void *context) {
  printf("App: coco_device_add_res_status_cb() status: %d\n", status);
  return;
}

/*************************************************************************************
 * Refer to the header file for a detailed description                               *
 *************************************************************************************/
void coco_device_resource_cmd_cb(coco_std_resource_cmd_t *resourceCmd) {
  coco_std_cmd_set_level_t *resCmd = (coco_std_cmd_set_level_t *)resourceCmd->cmdParams;

  if (COCO_STD_CAP_LEVEL_CTRL == resourceCmd->capabilityId &&
      COCO_STD_CMD_SET_LEVEL_WITH_ON_OFF == resourceCmd->cmdId) {
    if (resCmd->levelPct > 100 || resCmd->levelPct < 0) {
      return;
    }
    printf("App: Received LevelControl command with level %d....Setting Brightness....\n", resCmd->levelPct);
    levelAttr.currentValue = (void *)&resCmd->levelPct;
    coco_device_resource_attribute_update(&levelAttr, NULL);
    }
    return;
}

/*************************************************************************************
 * Refer to the header file for a detailed description                               *
 *************************************************************************************/
void coco_device_firmware_update_cb(coco_device_fw_update_details_t *fwUpdateDetails) {
//  char command[200] = {0};
//  printf(" App: New firmware version:%s found!!, Downloaded at %s\n",
//          fwUpdateDetails->version, fwUpdateDetails->filePath);
//  if (snprintf(command, sizeof(command), "%s %s %s", "mv", fwUpdateDetails->filePath, FIRMWARE_VERSION_PATH) < 0) {
//    printf("App: Unable to create firmwarepath\n");
//  } else {
//    if (-1 == system(command)) {
//      printf("App: Unable to upadte firmware\n");
//      exit(1);
//    }
//    sleep(5);
//    printf("App: Installed firmware version %s....System Rebooting....\n", fwUpdateDetails->version);
//    exit(1);
//  }
  return;
}
