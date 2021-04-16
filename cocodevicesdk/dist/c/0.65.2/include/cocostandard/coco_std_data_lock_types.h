/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_lock_types.h
 * @brief     Attributes and commands belonging to lock capability
 * @details   This file contains Attributes and commands belonging
 *            to the lock capability.
 * @see
 * @author    Prasad Makireddy, prasadmakireddy@elear.solutions
 *	          Umesh Kshirsagar, umeshkshirsagar@elear.solutions
 *            Omkar Wagle, omkarwagle@elear.solutions
 *            Shrinivas Gutte, shrinivasgutte@elear.solutions
 *            Varun Kumar, varun.k@healthasyst.com
 * @copyright Copyright (c) 2019-2020 Elear Solutions Tech Private Limited. All rights
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
#ifndef COCO_STD_DATA_LOCK_TYPES_H_INCLUDED
#define COCO_STD_DATA_LOCK_TYPES_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/
#include <stdint.h>

/*************************************************************************************
 *                          GLOBAL MACROS                                            *
 *************************************************************************************/

 /*************************************************************************************
  *                          GLOBAL TYPEDEFS                                          *
  *************************************************************************************/
typedef enum {
  COCO_STD_CMD_LOCK_MIN = -1,
  COCO_STD_CMD_LOCK,
  COCO_STD_CMD_UNLOCK,
  COCO_STD_CMD_LOCK_TOGGLE,
  COCO_STD_CMD_LOCK_SET_PIN,
  COCO_STD_CMD_LOCK_CLEAR_PIN,
  COCO_STD_CMD_LOCK_SET_USER_STATUS,
  COCO_STD_CMD_LOCK_SET_USER_TYPE,
  COCO_STD_CMD_FETCH_LOCK_STATUS,
  COCO_STD_CMD_FETCH_LOCK_PIN_CODE,
  COCO_STD_CMD_FETCH_LOCK_USER_STATUS,
  COCO_STD_CMD_FETCH_LOCK_USER_TYPE,
  COCO_STD_CMD_LOCK_MAX,
  COCO_STD_CMD_LOCK_UBOUND = 0x7FFFFFFF
} coco_std_cmd_lock_control_t;

typedef enum {
  COCO_STD_ATTR_LOCK_MIN = -1,
  COCO_STD_ATTR_LOCKED_FLAG,
  COCO_STD_ATTR_LOCK_USER_ID_ARR,
  COCO_STD_ATTR_LOCK_PIN_CODE_ARR,
  COCO_STD_ATTR_LOCK_USER_STATUS_ARR,
  COCO_STD_ATTR_LOCK_USER_TYPE_ARR,
  COCO_STD_ATTR_LOCK_MAX,
  COCO_STD_ATTR_LOCK_UBOUND = 0x7FFFFFFF
} coco_std_attr_lock_control_t;

typedef enum {
  COCO_STD_LOCK_USER_STATUS_MIN = -1,
  COCO_STD_LOCK_USER_STATUS_AVAILABLE,
  COCO_STD_LOCK_USER_STATUS_ENABLED,
  COCO_STD_LOCK_USER_STATUS_DISABLED,
  COCO_STD_LOCK_USER_STATUS_MAX,
  COCO_STD_LOCK_USER_STATUS_UBOUND = 0x7FFFFFFF
} coco_std_lock_user_status_t;

typedef enum {
  COCO_STD_LOCK_USER_TYPE_MIN = -1,
  COCO_STD_LOCK_USER_TYPE_UNRESTRICTED_USER,
  COCO_STD_LOCK_USER_TYPE_YEAR_DAY_SCH_USER,
  COCO_STD_LOCK_USER_TYPE_WEEK_DAY_SCH_USER,
  COCO_STD_LOCK_USER_TYPE_MASTER_USER,
  COCO_STD_LOCK_USER_TYPE_NON_ACCESS_USER,
  COCO_STD_LOCK_USER_TYPE_MAX,
  COCO_STD_LOCK_USER_TYPE_UBOUND = 0x7FFFFFFF
} coco_std_lock_user_type_t;

typedef struct {
  char *pinRfidCode;
} coco_std_cmd_lock_t;

typedef struct {
  char *pinRfidCode;
  uint32_t timeoutMs;
} coco_std_cmd_unlock_t;

typedef struct {
  char *pinRfidCode;
} coco_std_cmd_lock_toggle_t;

typedef struct {
  uint32_t userId;
  int32_t userStatus;
  int32_t userType;
  char *pinRfidCode;
} coco_std_cmd_lock_set_pin_t;

typedef struct {
  uint32_t userId;
} coco_std_cmd_lock_clear_pin_t;

typedef struct {
  uint32_t userId;
  int32_t userStatus;
} coco_std_cmd_lock_set_user_status_t;

typedef struct {
  uint32_t userId;
  int32_t userType;
} coco_std_cmd_lock_set_user_type_t;

typedef struct {
  uint32_t userId;
} coco_std_cmd_fetch_lock_pin_code_t;

typedef struct {
  uint32_t userId;
} coco_std_cmd_fetch_lock_user_status_t;

typedef struct {
  uint32_t userId;
} coco_std_cmd_fetch_lock_user_type_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_LOCK_TYPES_H_INCLUDED
