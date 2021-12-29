/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      client_callback.c
 * @brief     Definition of callbacks to be invoked by cococlientsdk
 * @details   Definition of callbacks to be invoked by cococlientsdk
 * @see
 * @author    Utkarsha Meshram, utkarshameshram@elear.com
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
#include <inttypes.h>
#include "cococlientsdk/coco_client_api.h"
#include "cocostandard/coco_std_api.h"

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
void cocosdk_connect_status_cb(char *networkId, int32_t coconetStatus,
                                void *coconetContext) {
  printf("App: networkId: %s, coconetStatus: %d\n", networkId, coconetStatus);

  if (NULL != networkId) {
    free(networkId);
  }

  return;
}

/*************************************************************************************
 * Refer to the header file for a detailed description                               *
 *************************************************************************************/
void cocosdk_start_auth_cb(const char *authorizationEndpoint, const char *tokenEndpoint) {
  printf("App: Access token is expired. Please set token using option \"Update access token\"\n");
  return;
}

/*************************************************************************************
 * Refer to the header file for a detailed description                               *
 *************************************************************************************/
void cocosdk_tokens_cb(char *token, int32_t status, void *context) {
  printf("App: status: %d\n", status);

  if (NULL != token) {
    printf("App: Token: %s\n", token);
    free(token);
  } else {
    printf("App: Token is NULL\n");
  }

  return;
}

/*************************************************************************************
 * Refer to the header file for a detailed description                               *
 *************************************************************************************/
void cocosdk_nw_list_cb(coco_client_coconet_t *coconetArr, int32_t coconetArrCnt,
                        void *requestContext) {
  int i;

  printf("App: coconetArrCnt: %" PRId32 "\n", coconetArrCnt);

  for (i = 0; i < coconetArrCnt; i++) {
    printf("App: coconetArr[%" PRId32 "].networkId: %s, networkName: %s "
           "coconetArr.coconetType: %" PRId32 "\n", i, coconetArr[i].networkId,
           coconetArr[i].networkName, coconetArr[i].coconetType);
  }

  if (coconetArrCnt > 0 && NULL!= coconetArr) {
    coco_client_free_coconets(coconetArr, coconetArrCnt);
  }

  return;
}

/*************************************************************************************
  Refer to the header file for a detailed description
 *************************************************************************************/
void cocosdk_node_conn_status(char *networkId, uint32_t nodeId,
                              int32_t nodeType, int32_t isOnline,
                              void *coconetContext) {
  printf("App: Got Node conn status callback callback\n");
  printf("App: networkId: %s\n", networkId);
  printf("App: nodeId: %d\n", nodeId);
  printf("App: nodeType: %d\n", nodeType);
  printf("App: isOnline: %d\n", isOnline);

  if (NULL != networkId) {
    free(networkId);
  }

  return;
}

/*************************************************************************************
 * Refer to the header file for a detailed description                               *
 *************************************************************************************/
void cocosdk_res_cmd_status_cb(coco_std_resource_cmd_status_t *resourceCmdStatus,
                               void *cmdContext, void *networkContext) {
  printf("Cmd status: %d", resourceCmdStatus->status);
  if (NULL != cmdContext) {
    printf("Cmd context: %d", *((int *)cmdContext));
  }
  coco_std_free_data(COCO_STD_STRUCT_RESOURCE_CMD_STATUS, 1, resourceCmdStatus);
  return;
}
