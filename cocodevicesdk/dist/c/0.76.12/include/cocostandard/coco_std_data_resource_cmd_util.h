/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_resource_cmd_util.h
 * @brief     This file provides dispatcher for struct_to_json, json_to_struct and free API
 * @details   This file contains the capability wise dispatchers for Json to structure
 *            and structure to Json utilities for coco standard commands
 * @see
 * @author    Prasad Makireddy, prasadmakireddy@elear.solutions
 *            Umesh Kshirsagar, umeshkshirsagar@elear.solutions
 * @copyright Copyright (c) 2019 Elear Solutions Tech Private Limited. All rights
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
#ifndef COCO_STD_DATA_RESOURCE_CMD_UTIL_H_INCLUDED
#define COCO_STD_DATA_RESOURCE_CMD_UTIL_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/
#include "coco_std_api.h"
#include "elearcommon/json_services.h"

/*************************************************************************************
 *                          GLOBAL MACROS                                            *
 *************************************************************************************/

 /*************************************************************************************
  *                          GLOBAL TYPEDEFS                                          *
  *************************************************************************************/
typedef void *(*coco_internal_json_to_struct_hndlr_fn_t)(int32_t commandId, ec_json_object_t * inJson,
                                                         uint16_t ttl);
typedef void *(*coco_internal_cmd_json_to_struct_fn_t)(ec_json_object_t *inJson, uint16_t ttl);
typedef ec_json_object_t *(*coco_internal_struct_to_json_hndlr_fn_t)(int32_t commandId, void *inStruct);
typedef int (*coco_internal_cap_struct_to_json_hndlr_fn_t)(void *inStruct, ec_json_object_t *outJson);
typedef int (*coco_internal_free_hndlr_fn_t)(int32_t commandId, void *inStruct);
typedef int (*coco_internal_free_cmd_hndlr_t)(void *inStruct);

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/
/********************************************//**
 * @brief   Converts struct to JSON
 * @details This function converts the provided struct object to JSON by calling a specific
 *          handler based upon the capabilityId and commandId.
 *          This API is not required by the developers.
 * @param   capabilityId       : capabilityId for which cmd JSON is given
 * @param   commandId          : commandId supported by capability
 * @param   inStruct           : struct which is to be converted to
 *                               the corresponding JSON object.
 * @param   ttl                : Time to live in seconds (0 will default to 120)
 *                               EC_TTL_DEFAULT_VALUE - for default (120 seconds).
 *                               EC_TTL_INFINITY      - for infinite time.
 *                               Any other value      - the given no. of seconds.
 * @return  ec_json_object_t * : Pointer to JSON object in case of Success.
 *                               NULL with coco_std_error number in case of failure
 *                               or command with no payload
 ***********************************************/
ec_json_object_t *coco_internal_struct_to_json(coco_std_capability_t capabilityId, int32_t commandId,
                                               void *inStruct);

/********************************************//**
 * @brief   Converts JSON to struct
 * @details This function converts the provided JSON object to struct by calling a specific
 *          handler based upon the capabilityId and commandId.
 *          This API is not required by the developers.
 * @param   capabilityId   : capabilityId for which cmd JSON is given
 * @param   commandId      : commandId supported by capability
 * @param   inJson         : JSON object which is to be converted to
 *                           the corresponding struct.
 * @param   ttl            : Time to live in seconds (0 will default to 120)
 *                           EC_TTL_DEFAULT_VALUE - for default (120 seconds).
 *                           EC_TTL_INFINITY      - for infinite time.
 *                           Any other value      - the given no. of seconds.
 * @return  void *         : Pointer to Output Structure in case of Success.
 *                           NULL with coco_std_error number in case of failure
 *                           or command with no payload
 ***********************************************/
void *coco_internal_cmd_json_to_struct(coco_std_capability_t capabilityId, int32_t commandId,
                                       ec_json_object_t *inJson, uint16_t ttl);

/********************************************//**
 * @brief     Deallocates the memory for a command parameters structure
 * @details   This function deallocates all the memory for a command parameters structure for a
 *            given capability ID and command ID.
 * @param     capabilityId: The capability the structure belongs to
 * @param     commandId: The command the structure belongs to
 * @param     inStruct : Pointer to Input Structure to be deallocated
 * @return    0 on Success,
 *            -1 on Failure
 ***********************************************/
int coco_internal_cmd_free(coco_std_capability_t capabilityId, int32_t commandId, void *inStruct);

/********************************************//**
 * @brief   Converts struct to JSON
 * @details This function converts the provided struct object to JSON by calling a specific
 *          handler based upon the key.
 *          This API is not required by the developers.
 * @param   key                : The key or enum of the params that needs to be converted to JSON
 * @param   inStruct           : struct which is to be converted to
 *                               the corresponding JSON object.
 * @param   ttl                : Time to live in seconds (0 will default to 120)
 *                               EC_TTL_DEFAULT_VALUE - for default (120 seconds).
 *                               EC_TTL_INFINITY      - for infinite time.
 *                               Any other value      - the given no. of seconds.
 * @return  ec_json_object_t * : Pointer to JSON object in case of Success.
 *                               NULL with coco_std_error number in case of failure
 *                               or command with no payload
 ***********************************************/
ec_json_object_t *coco_internal_cmd_status_param_struct_to_json(coco_std_parameter_key_t key,
                                                                void *inStruct, uint16_t ttl);

/********************************************//**
 * @brief   Converts JSON to struct
 * @details This function converts in JSON object to the respective key's struct value.
 *          This API is not required by the developers.
 * @param   key      : The key or enum of the params specified in coco_std_parameter_key_t
 *                     that needs to be fetched.
 * @param   inJson   : JSON object which is to be converted to the corresponding struct.
 * @param   ttl      : Time to live in seconds (0 will default to 120)
 *                     EC_TTL_DEFAULT_VALUE - for default (120 seconds).
 *                     EC_TTL_INFINITY      - for infinite time.
 *                     Any other value      - the given no. of seconds.
 * @return    0 on Success, -1 on Failure
 ***********************************************/
void *coco_internal_cmd_status_param_json_to_struct(coco_std_parameter_key_t key,
                                                    ec_json_object_t *inJson, uint16_t ttl);

/********************************************//**
 * @brief   Deallocates the memory for a command status parameters structure
 * @details This function deallocates all the memory for a command status parameters structure
 *          for a given key and value.
 * @param   key    : The key or enum of the params specified in coco_std_parameter_key_t
 *                   that needs to be freed
 * @param   value  : The value of the key specified that needs to be freed.
 * @return  0 on Success, -1 on Failure
 ***********************************************/
int coco_internal_cmd_status_param_free(coco_std_parameter_key_t key, void *value);

/********************************************//**
 * @brief   Converts struct to JSON
 * @details This function converts the provided struct object to JSON by calling a specific
 *          handler based upon the capabilityId and commandId.
 *          This API is not required by the developers.
 * @param   capabilityId       : capabilityId for which cmd JSON is given
 * @param   commandId          : commandId supported by capability
 * @param   inStruct           : struct which is to be converted to
 *                               the corresponding JSON object.
 * @param   ttl                : Time to live in seconds (0 will default to 120)
 *                               EC_TTL_DEFAULT_VALUE - for default (120 seconds).
 *                               EC_TTL_INFINITY      - for infinite time.
 *                               Any other value      - the given no. of seconds.
 * @return  ec_json_object_t * : Pointer to JSON object in case of Success.
 *                               NULL with coco_std_error number in case of failure
 *                               or command with no payload
 ***********************************************/
ec_json_object_t *coco_internal_cmd_resp_struct_to_json(coco_std_capability_t capabilityId,
                                                        int32_t commandId, void *inStruct);

/********************************************//**
 * @brief   Converts JSON to struct
 * @details This function converts the provided JSON object to struct by calling a specific
 *          handler based upon the capabilityId and commandId.
 *          This API is not required by the developers.
 * @param   capabilityId   : capabilityId for which cmd JSON is given
 * @param   commandId      : commandId supported by capability
 * @param   inJson         : JSON object which is to be converted to
 *                           the corresponding struct.
 * @param   ttl            : Time to live in seconds (0 will default to 120)
 *                           EC_TTL_DEFAULT_VALUE - for default (120 seconds).
 *                           EC_TTL_INFINITY      - for infinite time.
 *                           Any other value      - the given no. of seconds.
 * @return  void *         : Pointer to Output Structure in case of Success.
 *                           NULL with coco_std_error number in case of failure
 *                           or command with no payload
 ***********************************************/
void *coco_internal_cmd_resp_json_to_struct(coco_std_capability_t capabilityId, int32_t commandId,
                                            ec_json_object_t *inJson, uint16_t ttl);

/********************************************//**
 * @brief     Deallocates the memory for a command response parameters structure
 * @details   This function deallocates all the memory for a command response parameters structure for a
 *            given capability ID and command ID.
 * @param     capabilityId: The capability the structure belongs to
 * @param     commandId: The command the structure belongs to
 * @param     inStruct : Pointer to Input Structure to be deallocated
 * @return    0 on Success,
 *            -1 on Failure
 ***********************************************/
int coco_internal_cmd_resp_free(coco_std_capability_t capabilityId, int32_t commandId, void *inStruct);

#endif // COCO_STD_DATA_RESOURCE_CMD_UTIL_H_INCLUDED
