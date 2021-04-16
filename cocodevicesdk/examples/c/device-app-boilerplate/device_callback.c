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
