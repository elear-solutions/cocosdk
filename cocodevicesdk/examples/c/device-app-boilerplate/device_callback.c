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
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include "elearcommon/util.h"
#include "elearcommon/logger.h"
#include "elearcommon/allocate.h"
#include "cocodevicesdk/coco_device_api.h"
#include "cocostandard/coco_std_data_level_types.h"

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
static int64_t maxBrightness;
static int change;
/*************************************************************************************
 *                          LOCAL VARIABLES                                          *
 *************************************************************************************/

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
void get_brightness_values() {
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

  if (maxBrightness == 100) {
    change = 1;
  } else if (1< (maxBrightness/100)){
    change = maxBrightness/100;
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
          ec_debug_log(LOG_ERR, "CmdParams not passed", NULL);
          return;
        }

        if (resCmd->levelPct > 100 || resCmd->levelPct < 0) {
          ec_debug_log(LOG_ERR, "error: invalid value for levelPct, %d", resCmd->levelPct);
          return;
        }

        if (change > 1) {
          setLevel = resCmd->levelPct * change;
        } else {
          setLevel = resCmd->levelPct;
        }

        if (-1 == (fd = open("/sys/class/backlight/intel_backlight/brightness", O_RDWR))) {
          ec_debug_log(LOG_INFO, "Unable to open the file", NULL);
          return;
        }
        len = ec_strlen_int(setLevel);
        setLevelStr = ec_allocate_and_set(len, EC_TTL_INFINITY, 0);

        if (NULL == (setLevelStr = ec_int_to_str(setLevel, setLevelStr, len))) {
          ec_debug_log(LOG_INFO, "Unable to convert", NULL);
          return;
        }

        if (-1 == write(fd, setLevelStr, strlen(setLevelStr))) {
          ec_debug_log(LOG_INFO, "Unable to write", NULL);
          close(fd);
        }

        ec_deallocate(setLevelStr);
        close(fd);
      }
      return;
}
