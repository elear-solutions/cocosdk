/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_window_covering_types.h
 * @brief     Attributes and commands belonging to window covering capability
 * @details   This file contains the declaration of attributes and commands belonging to
 *            window covering capability
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
#ifndef COCO_STD_DATA_WINDOW_COVERING_TYPES_H_INCLUDED
#define COCO_STD_DATA_WINDOW_COVERING_TYPES_H_INCLUDED

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
  COCO_STD_CMD_WNDW_COVER_MIN = -1,
  COCO_STD_CMD_WNDW_COVER_UP,             //  Window blinds are completely open
  COCO_STD_CMD_WNDW_COVER_DOWN,           //  Window blinds are completely closed
  COCO_STD_CMD_WNDW_COVER_STOP,           //  Window blinds can be stopped at any given open
                                          //  percentage
  COCO_STD_CMD_WNDW_COVER_SET_OPEN_PCT,   //  Shut the window blinds to a specific percent
  COCO_STD_CMD_WNDW_COVER_MAX,
  COCO_STD_CMD_WNDW_COVER_UBOUND = 0x7FFFFFFF
} coco_std_cmd_wndw_cover_t;

// Command parameter for COCO_STD_CMD_WNDW_COVER_SET_OPEN_PCT command
typedef struct {
  uint8_t openPct;
} coco_std_cmd_set_open_pct_t;

typedef enum {
  COCO_STD_ATTR_WNDW_COVER_MIN = -1,
  COCO_STD_ATTR_WNDW_COVER_OPEN_PCT,
  COCO_STD_ATTR_WNDW_COVER_MAX,
  COCO_STD_ATTR_WNDW_COVER_UBOUND = 0x7FFFFFFF
} coco_std_attr_wndw_cover_t;

 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_WINDOW_COVERING_TYPES_H_INCLUDED
