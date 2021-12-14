/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_remote_control_types.h
 * @brief     Attributes and commands belonging to remote control capability
 * @details   This file contains the declaration of attributes and commands belonging to
 *            remote control capability
 * @see
 * @author    Omkar Wagle, omkarwagle@elear.solutions
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
#ifndef COCO_STD_DATA_REMOTE_CONTROL_TYPES_H_INCLUDED
#define COCO_STD_DATA_REMOTE_CONTROL_TYPES_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/

/*************************************************************************************
 *                          GLOBAL MACROS                                            *
 *************************************************************************************/

 /*************************************************************************************
  *                          GLOBAL TYPEDEFS                                          *
  *************************************************************************************/
typedef enum {
  COCO_STD_CMD_REMOTE_MIN = -1,
  COCO_STD_CMD_REMOTE_TEST_COMMAND,
  COCO_STD_CMD_REMOTE_ADD_APPLIANCE,
  COCO_STD_CMD_REMOTE_SET_APPLIANCE_PAIRING_CODE,
  COCO_STD_CMD_REMOTE_SET_APPLIANCE_NAME,
  COCO_STD_CMD_REMOTE_REMOVE_APPLIANCE,
  COCO_STD_CMD_REMOTE_EXECUTE_COMMAND,
  COCO_STD_CMD_REMOTE_SET_SEARCH_MODE,
  COCO_STD_CMD_REMOTE_ENTER_LEARN_MODE,
  COCO_STD_CMD_REMOTE_CANCEL_LEARN_MODE,
  COCO_STD_CMD_REMOTE_RENAME_BUTTON,
  COCO_STD_CMD_REMOTE_TEST_LEARNED_COMMAND,
  COCO_STD_CMD_REMOTE_SAVE_LEARNED_COMMAND,
  COCO_STD_CMD_REMOTE_EXECUTE_LEARNED_COMMAND,
  COCO_STD_CMD_REMOTE_DELETE_BUTTON,
  COCO_STD_CMD_REMOTE_MAX,
  COCO_STD_CMD_REMOTE_UBOUND = 0x7FFFFFFF
} coco_std_cmd_remote_t;

typedef enum {
  COCO_STD_REMOTE_CATEGORY_MIN = -1,
  COCO_STD_REMOTE_CATEGORY_AIR_CONDITIONER,
  COCO_STD_REMOTE_CATEGORY_TELEVISION,
  COCO_STD_REMOTE_CATEGORY_OTHER,
  COCO_STD_REMOTE_CATEGORY_MAX,
  COCO_STD_REMOTE_CATEGORY_UBOUND = 0x7FFFFFFF
} coco_std_remote_categories_t;

typedef enum {
  COCO_STD_REMOTE_PROG_MODE_MIN = -1,
  COCO_STD_REMOTE_PROG_MODE_PRESET_MODE,
  COCO_STD_REMOTE_PROG_MODE_LEARN_MODE,
  COCO_STD_REMOTE_PROG_MODE_SEARCH_MODE,
  COCO_STD_REMOTE_PROG_MODE_MAX,
  COCO_STD_REMOTE_PROG_MODE_UBOUND = 0x7FFFFFFF
} coco_std_remote_prog_mode_t;

// Command parameter for COCO_STD_CMD_REMOTE_TEST_COMMAND command
typedef struct {
  int32_t categoryId;               // Values to be chosen from coco_std_remote_categories_t enum
  uint8_t brandId;
  uint16_t pairingCode;
  int32_t capabilityId;             // Sub capability Id supported by the remote control device.
  int32_t commandId;
  void *commandParamValuesStruct;   // Command struct supported by command of the subcapabilityId
} coco_std_cmd_remote_test_command_t;

// Command parameter for COCO_STD_CMD_REMOTE_ADD_APPLIANCE command
typedef struct {
  char *applianceName;
  int32_t categoryId;          // Values to be chosen from coco_std_remote_categories_t enum
  int32_t programmingMode;     // Values to be chosen from coco_std_remote_prog_mode_t enum
  uint8_t brandId;             // For learn mode, set it to 0xFF
  uint16_t pairingCode;        // For learn mode, set it to 0xFFFF
} coco_std_cmd_remote_add_appliance_t;

// Command parameter for COCO_STD_CMD_REMOTE_SET_APPLIANCE_PAIRING_CODE command
typedef struct {
  char *applianceId;
  uint8_t brandId;
  uint16_t pairingCode;
} coco_std_cmd_remote_set_appliance_pairing_code_t;

// Command parameter for COCO_STD_CMD_REMOTE_SET_APPLIANCE_NAME command
typedef struct {
  char *applianceId;
  char *applianceName;
} coco_std_cmd_remote_set_appliance_name_t;

// Command parameter for COCO_STD_CMD_REMOTE_REMOVE_APPLIANCE command
typedef struct {
  char *applianceId;
} coco_std_cmd_remote_remove_appliance_t;

// Command parameter for COCO_STD_CMD_REMOTE_EXECUTE_COMMAND command
typedef struct {
  char *applianceId;
  int32_t capabilityId;             // Sub capability Id supported by the remote control device.
  int32_t commandId;
  void *commandParamValuesStruct;   // Command struct supported by command of the subcapabilityId
} coco_std_cmd_remote_execute_command_t;

// Command response structure for COCO_STD_CMD_REMOTE_SET_SEARCH_MODE
typedef struct {
  uint16_t numOfPairingCodes;
  uint16_t *pairingCodesArr;
} coco_std_cmd_resp_remote_set_search_mode_t;

// Command response structure for COCO_STD_CMD_REMOTE_ADD_APPLIANCE
typedef struct {
  char *applianceId;
} coco_std_cmd_resp_remote_add_appliance_t;

// Command structure for enter learn mode
typedef struct {
  char *applianceId;
  char *buttonName;
} coco_std_cmd_remote_enter_learn_mode_t;

// Command structure for Rename button
typedef struct {
  char *applianceId;
  uint8_t buttonId;
  char *buttonName;
} coco_std_cmd_remote_rename_button_t;

// Command structure for execute learn command
typedef struct {
  char *applianceId;
  uint8_t buttonId;
} coco_std_cmd_remote_execute_learn_command_t;

// Command structure for delete button
typedef struct {
  char *applianceId;
  uint8_t buttonId;
} coco_std_cmd_remote_delete_button_t;

typedef enum {
  COCO_STD_ATTR_REMOTE_MIN = -1,
  COCO_STD_ATTR_REMOTE_SUPP_PROG_MODES_ARR,   // COCO_STD_DATA_TYPE_UINT8_ARR
  COCO_STD_ATTR_REMOTE_MAX_APPLIANCE_COUNT,   // COCO_STD_DATA_TYPE_UINT16
  COCO_STD_ATTR_REMOTE_CATEGORY_ID_ARR,       // COCO_STD_DATA_TYPE_UINT8_ARR
  COCO_STD_ATTR_REMOTE_APPLIANCE_LIST,        // COCO_STD_DATA_TYPE_JSON_STRING
  COCO_STD_ATTR_REMOTE_MAX_BUTTON_COUNT,      // COCO_STD_DATA_TYPE_UINT8
  COCO_STD_ATTR_REMOTE_MAX,
  COCO_STD_ATTR_REMOTE_UBOUND = 0x7FFFFFFF
} coco_std_attr_remote_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_REMOTE_CONTROL_TYPES_H_INCLUDED
