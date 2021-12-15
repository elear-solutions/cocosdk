/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_data_tunnel_types.h
 * @brief     Attributes and commands belonging to tunnel capability
 * @details   This file contains attributes and commands belonging
 *            to the tunnel capability.
 * @see
 * @author    Utkarsha Meshram, utkarshameshram@gmail.com
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
#ifndef COCO_STD_DATA_TUNNEL_TYPES_H_INCLUDED
#define COCO_STD_DATA_TUNNEL_TYPES_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/
#include <stdint.h>
#include <stdbool.h>

/*************************************************************************************
 *                          GLOBAL MACROS                                            *
 *************************************************************************************/

/*************************************************************************************
 *                          GLOBAL TYPEDEFS                                          *
 *************************************************************************************/
typedef struct {
  uint16_t channelPort;
  int32_t tunnelProtocol;  // Use coco_std_tunnel_protocol_t
  int32_t tunnelType;      // Use coco_std_tunnel_type_t
  int32_t transportType;   // Use coco_std_tunnel_transport_type_t
  void *protocolParams;    // Params associated with respective protocol
  int32_t sessionId;       // User defined session Id
} coco_std_cmd_tunnel_open_t;

typedef struct {
  uint16_t port;         // Ignored if port = 0
} coco_std_tunnel_rtsp_params_t;

typedef struct {
  uint16_t channelPort;
} coco_std_cmd_tunnel_close_t;

typedef enum {
  COCO_STD_CMD_TUNNEL_MIN = -1,
  COCO_STD_CMD_TUNNEL_OPEN,
  COCO_STD_CMD_TUNNEL_CLOSE,
  COCO_STD_CMD_TUNNEL_MAX,
  COCO_STD_CMD_TUNNEL_UBOUND = 0x7FFFFFFF
} coco_std_cmd_tunnel_t;

typedef enum {
  COCO_STD_ATTR_TUNNEL_MIN = -1,
  COCO_STD_ATTR_TUNNEL_SUPPORTED_TRANSPORT_TYPE_COUNT,   // supported transport type count
                                                         // COCO_STD_DATA_TYPE_INT32
  COCO_STD_ATTR_TUNNEL_SUPPORTED_TRANSPORT_TYPE_ARR,     // array of transport types supported by tunnel
                                                         // COCO_STD_DATA_TYPE_INT32_ARR
  COCO_STD_ATTR_TUNNEL_SUPPORTED_PROTOCOL_COUNT,         // supported protocol count
                                                         // COCO_STD_DATA_TYPE_INT32
  COCO_STD_ATTR_TUNNEL_SUPPORTED_PROTOCOL_ARR,           // array of protocols supported by tunnel
                                                         // COCO_STD_DATA_TYPE_INT32_ARR
  COCO_STD_ATTR_TUNNEL_SUPPORTED_PROTOCOL_METADATA_ARR,  // array of protocol metadata supported by tunnel
                                                         // COCO_STD_DATA_TYPE_STRING_ARR
  COCO_STD_ATTR_TUNNEL_CURRENT_ACTIVE_CLIENTS_COUNT,     // no of active clients that are accessing tunnel
                                                         // COCO_STD_DATA_TYPE_UINT16
  COCO_STD_ATTR_TUNNEL_CURRENT_ACTIVE_CLIENTS_ARR,       // array of active client ids that are accessing tunnel.
                                                         // COCO_STD_DATA_TYPE_UINT16_ARR
  COCO_STD_ATTR_TUNNEL_MAX_ACTIVE_CLIENTS_COUNT,         // max active clients allowed to access tunnel
                                                         // COCO_STD_DATA_TYPE_UINT16
  COCO_STD_ATTR_TUNNEL_UBOUND = 0x7FFF
} coco_std_attr_tunnel_t;

// Tunnel enum
// Uses coco_std_tunnel_ip_ver_t
typedef enum {
  COCO_STD_TUNNEL_IP_VER_MIN = -1,
  COCO_STD_TUNNEL_IP_VER_4,
  COCO_STD_TUNNEL_IP_VER_6,
  COCO_STD_TUNNEL_IP_VER_MAX,
  COCO_STD_TUNNEL_IP_VER_UBOUND = 0x7FFF
} coco_std_tunnel_ip_ver_t;

// Uses coco_std_tunnel_transport_type_t
typedef enum {
  COCO_STD_TUNNEL_TRANSPORT_MIN = -1,
  COCO_STD_TUNNEL_TRANSPORT_TCP,
  COCO_STD_TUNNEL_TRANSPORT_UDP,
  COCO_STD_TUNNEL_TRANSPORT_MAX,
  COCO_STD_TUNNEL_TRANSPORT_UBOUND = 0x7FFF
} coco_std_tunnel_transport_type_t;

// Uses coco_std_tunnel_type_t
typedef enum {
  COCO_STD_TUNNEL_TYPE_MIN = -1,
  COCO_STD_TUNNEL_TYPE_LISTEN,
  COCO_STD_TUNNEL_TYPE_CONNECT,
  COCO_STD_TUNNEL_TYPE_MAX,
  COCO_STD_TUNNEL_TYPE_UBOUND = 0x7FFF
} coco_std_tunnel_type_t;

// Uses coco_std_tunnel_protocol_t
typedef enum {
  COCO_STD_TUNNEL_PROTOCOL_MIN = -1,
  COCO_STD_TUNNEL_PROTOCOL_RTSP,
  COCO_STD_TUNNEL_PROTOCOL_MAX,
  COCO_STD_TUNNEL_PROTOCOL_UBOUND = 0x7FFF
} coco_std_tunnel_protocol_t;


 /*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/

#endif // COCO_STD_DATA_TUNNEL_TYPES_H_INCLUDED
