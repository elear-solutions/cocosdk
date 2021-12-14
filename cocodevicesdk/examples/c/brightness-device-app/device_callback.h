/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      device_callback.h
 * @brief     Declaration of callbacks to be invoked by cocodevicesdk
 * @details   Declaration of callbacks to be invoked by cocodevicesdk
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
#ifndef DEVICE_CALLBACK_H_INCLUDED
#define DEVICE_CALLBACK_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/
#include "cocodevicesdk/coco_device_api.h"

/*************************************************************************************
 *                          GLOBAL MACROS                                            *
 *************************************************************************************/

/*************************************************************************************
 *                          GLOBAL TYPEDEFS                                          *
 *************************************************************************************/

/*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/
/********************************************//**
 * @brief   Called when data maintained by cocodevicesdk gets corrupted
 * @details Nothing to be done in the app layer in this case
 * @param   None
 * @return  None
 ***********************************************/
void coco_device_data_corruption_cb();

void coco_device_resource_cmd_cb(coco_std_resource_cmd_t *resourceCmd);
void coco_device_attribute_update_status(int32_t status, void *context);
void coco_device_add_res_status_cb(int32_t status, void *context);
void map_brightness_values();

void update_consumption_and_demand();

void coco_device_firmware_update_cb(coco_device_fw_update_details_t *fwUpdateDetails);

/*************************************************************************************
 *                          EXTERNAL FUNCTIONS                                       *
 *************************************************************************************/

#endif //DEVICE_CALLBACK_H_INCLUDED
