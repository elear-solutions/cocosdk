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
} cmdline_params_t;

/*************************************************************************************
 *                          LOCAL PROTOTYPES                                         *
 ************************************************************************************/
static void parse_cmdline_options(int argc, char *argv[]);
static void device_init(char *cwd, char *configFilePath);
static double get_next_lux_val(double currVal);
static double get_next_rssi_val();

/*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          LOCAL VARIABLES                                          *
 *************************************************************************************/
static cmdline_params_t appConfig = { NULL };

static double luxVal = 198.56;
static int32_t rssiVal = 4;

static coco_std_resource_attribute_info_t luxAttr = {
    NULL,
    0,
    "res-1",
    COCO_STD_CAP_ILLUMINANCE_MEASUREMENT,
    "illuminance",
    COCO_STD_ATTR_CURRENT_LUMINANCE_LUX,
    "lux",
    "illuminance lux",
    COCO_STD_DATA_TYPE_DOUBLE,
    0,
    &luxVal,
    &luxVal,
    &luxVal,
    &luxVal,
    0,
    10,
    &luxVal,
    1,
    0,
    0,
    1556539804
};

static coco_std_resource_attribute_info_t rssiAttr = {
    NULL,
    0,
    "res-1",
    COCO_STD_CAP_NETWORK_CONFIGURATION,
    "NetworkConfiguration",
    COCO_STD_ATTR_NW_CONFIG_RSSI,
    "rssi",
    "rssi",
    COCO_STD_DATA_TYPE_INT32,
    0,
    &rssiVal,
    &rssiVal,
    &rssiVal,
    &rssiVal,
    0,
    10,
    &rssiVal,
    1,
    0,
    0,
    1556539804
};

static coco_std_resource_capability_t capArr[2] = {
  {
    {
      NULL,
      0,
      "res-1",
      COCO_STD_CAP_ILLUMINANCE_MEASUREMENT,
      "illuminance",
      0,
      NULL,
      0,
      0
    },
    1,
    &luxAttr
  }, {
    {
      NULL,
      0,
      "res-1",
      COCO_STD_CAP_NETWORK_CONFIGURATION,
      "NetworkConfiguration",
      0,
      NULL,
      0,
      0
    },
    1,
    &rssiAttr
  }
};

static coco_std_resource_t resourceInfo = {
  {
    NULL,
    0,
    "res-1",
    "Illuminance Sensor",
    "Anchor",
    "V1",
    "1.0.0",
    "ILLUMINATION_SENSOR",
    COCO_STD_POWER_SRC_BATTERY,
    COCO_STD_RCVR_TYPE_WHEN_STIMULATED,
    COCO_STD_STATUS_SUCCESS,
    0,
    0
  },
  2,
  capArr
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
  while ( (opt = getopt(argc, argv, "d:c:")) != -1) {
    switch (opt) {
      case 'd':
        appConfig.cwd = optarg;
        break;

      case 'c':
        appConfig.configFilePath = optarg;
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
static void device_init(char *cwd, char *configFilePath) {
  int retVal;

  coco_device_init_params_t deviceInitParams = { 0 };
  deviceInitParams.cwdPath = cwd;
  deviceInitParams.configFilePath = configFilePath;
  deviceInitParams.downloadPath = cwd;
  deviceInitParams.coconetConnStatusCb = coco_device_join_nw_status_cb;
  deviceInitParams.addResStatusCb = coco_device_add_res_status_cb;
  deviceInitParams.attributeUpdateCb = coco_device_attribute_update_status;
  deviceInitParams.dataCorruptionCb = coco_device_data_corruption_cb;
  deviceInitParams.firmwareVersion = "1.0.0";
  deviceInitParams.isExtendable = true;
  deviceInitParams.powerSource = COCO_STD_POWER_SRC_BATTERY;
  deviceInitParams.receiverType = COCO_STD_RCVR_TYPE_RX_ON_WHEN_IDLE;
  deviceInitParams.skipSSLVerification = 1;

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
}

/******************************************************************************
Name        : get_next_lux_val
Input(s)    : currVal: current lux value
Output(s)   : double: next lux value
Description : Randomly generate next lux value based upon current lux value
*******************************************************************************/
static double get_next_lux_val(double currVal) {
  double nextVal = 0.0;
  int whole, decimal, sign;

  // Generated signed number to be added to the current attribute value
  sign = rand() % 2;
  whole = (rand() % 3) + 1;
  decimal = (rand() % 100);
  if ((0 == sign && currVal >= 253) || currVal >= 498) {
    sign = -1;
  }
  else {
    sign = 1;
  }

  // Add number generated above to the current attribute value to get the new attribute value
  nextVal = currVal + (sign * ((double)whole + ((double)decimal/100)));
  printf("App: next lux val: %lf\n", nextVal);

  return nextVal;
}

/******************************************************************************
Name        : get_next_rssi_val
Input(s)    : None
Output(s)   : double: next rssi value
Description : Randomly generate next rssi value
*******************************************************************************/
static double get_next_rssi_val() {
  int nextVal;

  // Generated random number
  nextVal = (rand() % 4) + 1;
  printf("App: next rssi val: %d\n", nextVal);
  
  return nextVal;
}

/******************************************************************************
Name        : main
Input(s)    : Command line arguments
Output(s)   : int: exit status of the application
Description : Initialise cocodevicesdk, add the device to COCONet, add a resource
              and publish attribute update once every 2 seconds
*******************************************************************************/
int main(int argc, char *argv[]) {
  // Extract working directory and config file path from command line arguments
  // These will be passed to COCO device SDK during init
  parse_cmdline_options(argc, argv);

  // This utility will initialize COCO device SDK
  device_init(appConfig.cwd, appConfig.configFilePath);

  // Add a resource using COCO device SDK API
  if (-1 == coco_device_add_resource(&resourceInfo, 1, 0, 0, NULL)) {
    printf("App: Add resource failed\n");
    exit(1);
  }

  // Run a loop to update the attribute value of the added resource every 2 seconds
  while(1) {
    printf("App: Update attribute\n");
    
    // Set next lux attribute value
    *(double *)(luxAttr.currentValue) = get_next_lux_val(*(double *)(luxAttr.currentValue));

    // Update the lux attribute value of the added resource using COCO device SDK API
    if (-1 == coco_device_resource_attribute_update(&luxAttr, NULL)) {
      printf("App: Update attribute failed\n");
      break;
    }

    // Set next rssi attribute value
    *(int32_t *)(rssiAttr.currentValue) = get_next_rssi_val();

    // Update the lux attribute value of the added resource using COCO device SDK API
    if (-1 == coco_device_resource_attribute_update(&rssiAttr, NULL)) {
      printf("App: Update attribute failed\n");
      break;
    }
    
    sleep(2);
  }

  sleep(10);

  return EXIT_SUCCESS;
}
