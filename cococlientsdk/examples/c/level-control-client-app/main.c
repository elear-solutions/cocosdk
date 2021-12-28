#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include "cococlientsdk/coco_client_api.h"
#include "cocostandard/coco_std_api.h"
#include "cocostandard/coco_std_util.h"
#include "cocostandard/coco_std_data_level_types.h"
#include "client_callback.h"

static void client_init(void) {
  char appAccessList[200] = "{\"appCapabilities\":[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28]}";
  char clientId[100] = "f0799bdea3aeadeb7429";
  coco_client_init_params_t clientInitParams = { 0 };
  char *cwd = "../data";

  coco_client_platform_fn_list_t platformFnList = {
    cocosdk_start_auth_cb,
    cocosdk_tokens_cb,
    NULL,
    NULL,
    NULL
  };

  coco_client_app_callbacks_t appCallbacks = {
    cocosdk_connect_status_cb,
    NULL,
    NULL,
    NULL,
    NULL,
    cocosdk_nw_list_cb,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    cocosdk_node_conn_status,
    NULL,
    NULL,
    NULL,
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

int main(int argc, char *argv[]) {
  int choice = 0;
  char networkIdArr[100];
  coco_client_coconet_t networkArr = { 0 };
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

  char networkId[100] = { 0 };
  char resourceEui[100] = { 0 };
  int deviceNodeId, variable;
  coco_std_resource_cmd_t onOffCmd = { 0 };
  coco_std_cmd_set_level_t levelAttr = { 0 };
  int count = 0;

  client_init();

  do {
    printf("App: Select one of the below:\n");
    printf("App: 0. Exit\n");
    printf("App: 1. Get all networks\n");
    printf("App: 2. Connect\n");
    printf("App: 3. Set tokens\n");
    printf("App: 4. Level control\n");

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

      case 3 :
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

      case 4:

        printf("App: Enter networkId: ");
        if (-1 == scanf("%s", networkId)) {
          printf("App: Failed to read from user\n");
          return EXIT_SUCCESS;
        }

        printf("App: Enter deviceNodeId: ");
        if (-1 == scanf("%d", &deviceNodeId)) {
          printf("App: Failed to read from user\n");
          return EXIT_SUCCESS;
        }

        printf("App: Enter resourceEui: ");
        if (-1 == scanf("%s", resourceEui)) {
          printf("App: Failed to read from user\n");
          return EXIT_SUCCESS;
        }

        printf("App: Enter timeOut: ");
        if (-1 == scanf("%d", &variable)) {
          printf("App: Failed to read from user\n");
          return EXIT_SUCCESS;
        }

        onOffCmd.deviceNodeId = (uint32_t)deviceNodeId;
        onOffCmd.timeoutMs = (uint32_t)variable;
        onOffCmd.resourceEui = resourceEui;
        onOffCmd.networkId  = networkId;
        onOffCmd.capabilityId = COCO_STD_CAP_LEVEL_CTRL;
        onOffCmd.cmdId = COCO_STD_CMD_SET_LEVEL;

        while(1) {

          levelAttr.levelPct = count;
          onOffCmd.cmdParams = &levelAttr;

          if (-1 == coco_client_send_resource_cmd(&onOffCmd, NULL)) {
            printf("App: Unable to send resource command, Kindly contact the platform team\n");
          }
          count++;

          if (count > 100) {
            count = 0;
          }

          sleep(5);
        }

        break;

    default :
      printf("App: Invalid option\n");
      break;

    }
  } while (true);

  return EXIT_SUCCESS;
}

