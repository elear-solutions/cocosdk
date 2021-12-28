/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      client_callback.h
 * @brief     Declaration of callbacks to be invoked by cococlientsdk
 * @details   Declaration of callbacks to be invoked by cococlientsdk
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
#ifndef CLIENT_CALLBACK_H_INCLUDED
#define CLIENT_CALLBACK_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/
#include "cococlientsdk/coco_client_api.h"

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
 * @brief   cocosdk_connect_status_cb
 * @details This function acts as the callback for connection status to COCONet
 * @param   networkId
 * @param   coconetStatus
 * @param   coconetContext
 * @return  none
 ***********************************************/
void cocosdk_connect_status_cb(char *networkId, int32_t coconetStatus,
                               void *coconetContext);

/********************************************//**
 * @brief   Start auth callback
 * @details A callback to indicate the applocation to set the tokens.
 * @param   authorizationEndpoint: authorization endpoint for coco authorization server
 * @param   tokenEndpoint        : token endpoint for coco authorization server
 * @return  None
 ***********************************************/
void cocosdk_start_auth_cb(const char *authorizationEndpoint, const char *tokenEndpoint);

/********************************************//**
 * @brief   Tokens callback
 * @details This callback in invoked with the tokens when requested
 * @param   token  : token
 * @param   status  : status
 * @param   context: context
 * @return  None
 ***********************************************/
void cocosdk_tokens_cb(char *token, int32_t status, void *context);

/********************************************//**
 * @brief   Callback which provides the list of networks to which the user belongs to
 * @details This is invoked in reponse to coco_client_get_all_coconets() API call
 * @param   coconetArr     : array of networks
 * @param   coconetArrCnt  : number of networks
 * @param   requestContext : context passed during the API call
 * @return  None
 ***********************************************/
void cocosdk_nw_list_cb(coco_client_coconet_t *coconetArr, int32_t coconetArrCnt,
                        void *requestContext);

/********************************************//**
 * @brief
 * @details
 * @param
 * @return
 ***********************************************/
void cocosdk_node_conn_status(char *networkId, uint32_t nodeId,
                              int32_t nodeType, int32_t isOnline,
                              void *coconetContext);

/*************************************************************************************
 *                          EXTERNAL FUNCTIONS                                       *
 *************************************************************************************/

#endif //CLIENT_CALLBACK_H_INCLUDED
