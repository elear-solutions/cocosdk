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
#define print_usage() \
  printf("App: Usage: %s -d current-working-directory -c config-file-path\n", argv[0])

/*************************************************************************************
 *                          LOCAL TYPEDEFS                                           *
 *************************************************************************************/
typedef struct {
  char *cwd;
  char *configFilePath;
  char *resInfoPath;
} cmdline_params_t;

/*************************************************************************************
 *                          LOCAL PROTOTYPES                                         *
 ************************************************************************************/
static void parse_cmdline_options(int argc, char *argv[]);
static void device_init(void);

/*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          LOCAL VARIABLES                                          *
 *************************************************************************************/
static cmdline_params_t appConfig = { NULL };

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
Name        : parse_cmdline_options
Input(s)    : int argc, char *argv[] - standard inputs from the main routine
Output(s)   : None
Description : Parses the options passed on the command line and validates the
              presence of all mandatory command-line options. The program is
              terminated if mandatory options are found missing.
*******************************************************************************/
static void parse_cmdline_options(int argc, char *argv[]) {
  char opt;
  bool printUsage = false;
  int i;

  opterr = 0;     // Suppress log messages from getopt()

  // See the print_usage() macro definition for the meaning of each command-line option
  // being parsed below
  while ( (opt = getopt(argc, argv, "d:c:r:")) != -1) {
    switch (opt) {
      case 'd':
        appConfig.cwd = optarg;
        break;

      case 'c':
        appConfig.configFilePath = optarg;
        break;

      case 'r':
        appConfig.resInfoPath = optarg;
        break;

      case '?':
        printf("App: Warning: Ignoring unknown cmd-line option '-%c'\n", optopt);
        break;
    }
  }

  // Iterate through and print out the un-recognized command-line options, to let the
  // user know they are being ignored
  if (optind < argc) {
    for (i = optind; i < argc; i++) {
      printf("App: Warning: Ignoring unknown cmd-line arg '%s'\n", argv[i]);
    }
  }

  // Print out command-line arguments parsed
  // If one or more arguments are missing, print out usage information
  if (NULL != appConfig.cwd) {
    printf("App: Got working directory = %s\n", appConfig.cwd);
  } else {
    printf("App: Error: No cmd-line option for working directory found\n");
    printUsage = true;
  }

  if (NULL != appConfig.configFilePath) {
    printf("App: Got config file path = %s\n", appConfig.configFilePath);
  } else {
    printf("App: Error: No cmd-line option for config file path found\n");
    printUsage = true;
  }

  if (NULL != appConfig.resInfoPath) {
    printf("App: Got config file path = %s\n", appConfig.resInfoPath);
  } else {
    printf("App: Error: No cmd-line option for config file path found\n");
    printUsage = true;
  }

  if (printUsage) {
    print_usage();
    exit(1);
  }

  return;
}

/******************************************************************************
Name        : device_init
Input(s)    : cwd           : current working directory for device SDK
              configFilePath: path to device license file
Output(s)   : void
Description : Initialize device SDK and onboard device to COCO Network
*******************************************************************************/
static void device_init(void) {
  int retVal;

  coco_device_init_params_t deviceInitParams = { 0 };
  deviceInitParams.loggerOutput = 1;
  deviceInitParams.resInfoPath = appConfig.resInfoPath;//"/home/gangeya/Desktop/resJson1.txt";
  deviceInitParams.cwdPath = appConfig.cwd;
  deviceInitParams.configFilePath = appConfig.configFilePath;
  deviceInitParams.downloadPath = appConfig.cwd;
  deviceInitParams.coconetConnStatusCb = coco_device_join_nw_status_cb;
  deviceInitParams.addResStatusCb = coco_device_add_res_status_cb;
  deviceInitParams.attributeUpdateCb = coco_device_attribute_update_status;
  deviceInitParams.dataCorruptionCb = coco_device_data_corruption_cb;
  deviceInitParams.resourceCmdCb = coco_device_resource_cmd_cb;
  deviceInitParams.skipSSLVerification = 1;
  deviceInitParams.firmwareVersion = "1.0.0";
  if (-1 == (retVal = coco_device_init(&deviceInitParams))) {
    printf("App: coco_device_init failed\n");
    exit(1);
  }

  // Keep calling COCO backend every 3 seconds
  if (0 == retVal) {
    printf("App: Device is not provisioned yet\n");
    while (-1 == (coco_device_init_auth())) {
      printf("App: Will re-try init auth after 3 seconds\n");
      sleep(3);
    }
  }
  //Updating rssi value
  if (-1 == coco_device_resource_attribute_update(&rssiAttr, NULL)) {
    printf("App: Update attribute failed\n");
  }
}

/******************************************************************************
Name        : main
Input(s)    : Command line arguments
Output(s)   : int: exit status of the application
Description : Initialise cocodevicesdk, add the device to COCONet, add a resource
              and publish attribute update once every 2 seconds
*******************************************************************************/
int main(int argc, char *argv[]) {
  double val;
  // Extract working directory and config file path from command line arguments
  // These will be passed to COCO device SDK during init
  parse_cmdline_options(argc, argv);

  // This utility will initialize COCO device SDK
  device_init();

  // Run a loop  every 5 seconds
  while(1) {
    val = (rand() % 50) + 1;
    demandAttr.currentValue = &val;
    if (-1 == coco_device_resource_attribute_update(&demandAttr, NULL)) {
          printf("App: Update attribute failed\n");
  }
    sleep(5);
  }
  return EXIT_SUCCESS;
}
