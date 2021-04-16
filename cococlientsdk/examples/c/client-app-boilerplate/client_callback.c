/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      client_callback.c
 * @brief     Definition of callbacks to be invoked by cococlientsdk
 * @details   Definition of callbacks to be invoked by cococlientsdk
 * @see
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
#include <inttypes.h>
#include "cococlientsdk/coco_client_api.h"

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
void cocosdk_resource_summay_cb(coco_std_resource_t *resourceSummary,
                                void *networkContext) {
  printf("App: nwId: %s, gwNodeId: %u, resourceEui: %s\n",
         resourceSummary->resourceSummaryInfo.networkId,
         resourceSummary->resourceSummaryInfo.deviceNodeId,
         resourceSummary->resourceSummaryInfo.resourceEui);
  coco_std_free_data(COCO_STD_STRUCT_RESOURCE_ENTITY, 1, resourceSummary);
  return;
}

/*************************************************************************************
 * Refer to the header file for a detailed description                               *
 *************************************************************************************/
void cocosdk_resrc_capability_summay_cb(coco_std_resource_capability_info_t *capabilitySummary,
                                  void *networkContext) {
  printf("App: nwId: %s, gwNodeId: %u, resourceEui: %s, capabilityId: %" PRIi8 "\n",
         capabilitySummary->networkId, capabilitySummary->deviceNodeId,
         capabilitySummary->resourceEui, capabilitySummary->capabilityId);
  coco_std_free_data(COCO_STD_STRUCT_CAPABILITY_INFO, 1, capabilitySummary);
  return;
}

/*************************************************************************************
 * Refer to the header file for a detailed description                               *
 *************************************************************************************/
void cocosdk_attribute_summay_cb(coco_std_resource_attribute_info_t *resourceAttribute,
                                 void *networkContext) {
  printf("App: nwId: %s, gwNodeId: %u, resourceEui: %s, capabilityId: %" PRIi8 ", attributeId: %" PRIi8 "\n",
         resourceAttribute->networkId, resourceAttribute->deviceNodeId,
         resourceAttribute->resourceEui, resourceAttribute->capabilityId, resourceAttribute->attributeId);
  coco_std_free_data(COCO_STD_STRUCT_ATTRIBUTE_INFO, 1, resourceAttribute);
  return;
}

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
 * Refer to the header file for a detailed description                               *
 *************************************************************************************/
void cocosdk_resource_inclusion_cb(coco_std_added_resource_t *resrcInclusion,
                                   void *networkContext) {
  printf("App: networkId: %s, deviceNodeId: %u\n",
         resrcInclusion->networkId, resrcInclusion->deviceNodeId);

  coco_std_free_data(COCO_STD_STRUCT_ADDED_RESOURCE, 1, resrcInclusion);
  return;
}

/*************************************************************************************
 * Refer to the header file for a detailed description                               *
 *************************************************************************************/
void cocosdk_device_info_cb(coco_std_device_info_t *deviceInfo, void *networkContext) {
  printf("App: networkId: %s,deviceNodeId: %u\n",
               deviceInfo->networkId, deviceInfo->deviceNodeId);

  coco_std_free_data(COCO_STD_STRCUT_DEVICE_INFO, 1, deviceInfo);
  return;
}

/*************************************************************************************
 * Refer to the header file for a detailed description                               *
 *************************************************************************************/
void cocosdk_fw_update_notif_cb(coco_std_fw_update_notif_t *fwUpdateNotif,
                                  void *coconetContext) {
  printf("App: oldVersion: %s, newVersion: %s, status:%d, networkId:%s, deviceNodeId:%u\n",
         fwUpdateNotif->oldVersion, fwUpdateNotif->newVersion,
         fwUpdateNotif->status, fwUpdateNotif->networkId,
         fwUpdateNotif->deviceNodeId);
  coco_std_free_data(COCO_STD_STRUCT_FW_UPDATE_NOTIF, 1, fwUpdateNotif);
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
  Refer to the header file for a detailed description
 *************************************************************************************/
void cocosdk_resource_removed_cb(coco_std_removed_resource_t *resourceRemoveNotf,
                                 void *coconetContext) {

  printf("App: networkId: %s\n", resourceRemoveNotf->networkId);
  printf("App: deviceNodeId: %u\n", resourceRemoveNotf->deviceNodeId);
  printf("App: Removed resourceEui: %s\n", resourceRemoveNotf->resourceEui);

  coco_std_free_data(COCO_STD_STRUCT_REMOVED_RESOURCE, 1, resourceRemoveNotf);
  return;
}

/*************************************************************************************
  Refer to the header file for a detailed description
 *************************************************************************************/
void coco_client_network_data_cb(coco_client_network_data_t *networkData, void *coconetContext) {
  int i;
  
  if (NULL == networkData) {
    printf("App: Received networkData as NULL\n");
    return;
  }

  for (i = 0; i < networkData->deviceArrCnt; i++) {
     printf("App: Device nodeId: %" PRIu32 "\n", networkData->deviceArr[i].deviceNodeId);
     printf("App: Device Name: %s\n", networkData->deviceArr[i].deviceName);
  }

  coco_client_free_network_data(networkData, 1);

  return;
}
