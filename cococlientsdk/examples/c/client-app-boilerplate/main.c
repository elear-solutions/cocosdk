/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      main.c
 * @brief     Client app built on top of COCO Client SDK
 * @details   Client app to demonstatrate capabilities of COCO Client SDK like connecting
 *            to network and receiving resource/attribute updates
 * @see
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
#include <inttypes.h>
#include "cococlientsdk/coco_client_api.h"
#include "client_callback.h"

/*************************************************************************************
 *                          LOCAL MACROS                                             *
 *************************************************************************************/
#define print_usage() \
  printf("App: Usage: %s -d current-working-directory\n", argv[0])

/*************************************************************************************
 *                          LOCAL TYPEDEFS                                           *
 *************************************************************************************/
typedef struct {
  char *cwd;
} cmdline_params_t;

/*************************************************************************************
 *                          LOCAL PROTOTYPES                                         *
 ************************************************************************************/
static void parse_cmdline_options(int argc, char *argv[]);
static void client_init(char *cwd);

/*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          LOCAL VARIABLES                                          *
 *************************************************************************************/
static cmdline_params_t appConfig = { NULL };

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
  while ( (opt = getopt(argc, argv, "d:")) != -1) {
    switch (opt) {
      case 'd':
        appConfig.cwd = optarg;
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

  if (printUsage) {
    print_usage();
    exit(1);
  }

  return;
}

/******************************************************************************
Name        : client_init
Input(s)    : cwd: current working directory for client SDK
Output(s)   : void
Description : Initialize client SDK
*******************************************************************************/
static void client_init(char *cwd) {
  char appAccessList[200] = "{\"appCapabilities\":[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28]}";
  char clientId[100] = "f0799bdea3aeadeb7429";
  coco_client_init_params_t clientInitParams = { 0 };

  coco_client_platform_fn_list_t platformFnList = {
    cocosdk_start_auth_cb,
    cocosdk_tokens_cb,
    NULL,
    NULL,
    NULL
  };

  coco_client_app_callbacks_t appCallbacks = {
    cocosdk_connect_status_cb,
    cocosdk_resource_summay_cb,
    cocosdk_resrc_capability_summay_cb,
    cocosdk_attribute_summay_cb,
    NULL,
    cocosdk_nw_list_cb,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    cocosdk_resource_inclusion_cb,
    cocosdk_resource_removed_cb,
    cocosdk_device_info_cb,
    NULL,
    cocosdk_fw_update_notif_cb,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    cocosdk_node_conn_status,
    NULL,
    NULL,
    coco_client_network_data_cb,
    NULL,
    NULL,
    NULL,
    NULL
  };

  clientInitParams.platformFnList = &platformFnList;
  clientInitParams.appCallbacks = &appCallbacks;

  clientInitParams.cwdPath = cwd;
  clientInitParams.appAccessList = appAccessList;
  clientInitParams.clientId = clientId;
  clientInitParams.downloadPath = cwd;

  if (-1 == coco_client_init(&clientInitParams)) {
    printf("App: coco_client_init failed %"PRId32"\n", cocoClientErrno);
    exit(1);
  }
}

/******************************************************************************
Name        : main
Input(s)    : Command line arguments
Output(s)   : int: exit status of the application
Description : Initialise cococlientsdk and display menu for next set of actions
*******************************************************************************/
int main(int argc, char *argv[]) {
  int choice = 0;
  char networkIdArr[100];
  coco_client_coconet_t networkArr = { 0 };
  coco_client_coconet_t *coconetArr;
  int32_t retVal;
  int expires_in;
  char jwt[10000] = { 0 };
  char refreshToken[100] = { 0 };
  char accessToken[20000] = { 0 };
  const char *accessTokenString =
    "{ \"token_type\": \"Bearer\", "\
    "\"access_token\": \"%s\", "\
    "\"expires_in\": %d, "\
    "\"refresh_token\": \"%s\" }";

  // Extract working directory from command line arguments
  // These will be passed to COCO client SDK during init
  parse_cmdline_options(argc, argv);

  // This utility will initialize COCO client SDK
  client_init(appConfig.cwd);

  do {
    printf("App: Select one of the below:\n");
    printf("App: 0. Exit\n");
    printf("App: 1. Get all networks\n");
    printf("App: 2. Connect\n");
    printf("App: 3. Disconnect\n");
    printf("App: 4. Get tokens\n");
    printf("App: 5. Set tokens\n");
    printf("App: 6. Get saved networks\n");

    if (-1 == scanf("%d", &choice)) {
      printf("App: Failed to read from user\n");
      return EXIT_SUCCESS;
    }

    switch(choice) {
      case 0:
        return EXIT_SUCCESS;

      case 1:
        if (-1 == coco_client_get_all_coconets(NULL)) {
          printf("App: coco_client_get_all_coconets failed %"PRId32"\n", cocoClientErrno);
          exit(1);
        }
        break;

      case 2:
        printf("App: networkId: ");
        if (-1 == scanf("%s", networkIdArr)) {
          printf("App: Failed to read from user\n");
          return EXIT_SUCCESS;
        }

        networkArr.networkId = networkIdArr;
        networkArr.networkName = NULL;
        networkArr.coconetContext = NULL;
        networkArr.accessType = 1;
        networkArr.userRole = 1;
        networkArr.clusterPort = 0;

        retVal = coco_client_connect(&networkArr);
        printf("App: coco_client_connect() returned %"PRId32"\n", retVal);
        if (0 != retVal) {
          printf("App: coco_client_connect() errno %"PRId32"\n", cocoClientErrno);
        }

        break;

      case 3:
        printf("App: networkId: ");
        if (-1 == scanf("%s", networkIdArr)) {
          printf("App: Failed to read from user\n");
          return EXIT_SUCCESS;
        }

        networkArr.networkId = networkIdArr;
        networkArr.networkName = NULL;
        networkArr.coconetContext = NULL;
        networkArr.accessType = 1;
        networkArr.userRole = 0;
        coco_client_disconnect(&networkArr);
        break;

      case 4:
        coco_client_get_access_token(NULL);
        break;

      case 5 :
        printf("App: Enter Access token: ");
        if (-1 == scanf("%s", jwt)) {
          printf("App: Failed to read from user\n");
          return EXIT_SUCCESS;
        }

        printf("App: Enter expires_in: ");
        if (-1 == scanf("%d", &expires_in)) {
          printf("App: Failed to read from user\n");
          return EXIT_SUCCESS;
        }

        printf("App: Enter refresh token: ");
        if (-1 == scanf("%s", refreshToken)) {
          printf("App: Failed to read from user\n");
          return EXIT_SUCCESS;
        }

        snprintf(accessToken, 19999, accessTokenString, jwt, expires_in, refreshToken);

        if (0 != coco_client_set_tokens(accessToken)) {
          printf("App: Set tokens failed\n");
          return EXIT_SUCCESS;
        }

        break;

      case 6 :
        if (-1 == (retVal = coco_client_get_saved_coconets(&coconetArr))) {
          printf("App: Get saved coconet failed\n");
          break;
        }

        printf("App: Number of connected cocoNetList: %"PRId32"\n", retVal);
        for(int i = 0; i < retVal; i++) {
          printf("App: coconetArr[%d].networkId: %s, coconetArr[%d].networkName: %s "
                 "coconetArr[%d].coconetType: %" PRId32 "\n", i, coconetArr[i].networkId, i,
                 coconetArr[i].networkName, i, coconetArr[i].coconetType);
        }

        if (0 < retVal) {
          coco_client_free_coconets(coconetArr, retVal);
        }

        break;

    default :
      printf("App: Invalid option\n");
      break;

    }
  } while (true);

  return EXIT_SUCCESS;
}
