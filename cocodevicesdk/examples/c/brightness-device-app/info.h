#ifndef INFO_H_INCLUDED
#define INFO_H_INCLUDED

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "cocostandard/coco_std_data_meter_types.h"
#include "cocostandard/coco_std_api.h"
#include "cocodevicesdk/coco_device_api.h"
#include "cocostandard/coco_std_data_level_types.h"
#include "cocostandard/coco_std_data_network_config_types.h"
static int maxVal = 100;
static int64_t curVal = 40;
static int32_t rssiVal = 4;
static int reportChange = 1;
static int32_t protocolArr[] = {COCO_STD_PROTOCOL_ZIGBEE};

void coco_device_firmware_update_cb(coco_device_fw_update_details_t *fwUpdateDetails);
void coco_device_resource_cmd_cb(coco_std_resource_cmd_t *resourceCmd);
void coco_device_attribute_update_status(int32_t status, void *context);

static coco_std_resource_attribute_info_t levelAttr = {
    NULL,
    0,
    "zigbee/0015BC0036000397/26",
    COCO_STD_CAP_LEVEL_CTRL,
    "LEVEL",
    COCO_STD_ATTR_LEVEL_PCT,
    "COCO_STD_ATTR_LEVEL_PCT",
    "level control",
    COCO_STD_DATA_TYPE_UINT8,
    0,
    0,
    &maxVal,
    NULL,
    (void *)&curVal,
    0,
    0,
    &reportChange,
    1,
    0,
    0,
    1556539804,
    0
};

static coco_std_resource_attribute_info_t rssiAttr = {
    NULL,
    0,
    "zigbee/0015BC0036000397/26",
    COCO_STD_CAP_NETWORK_CONFIGURATION,
    "NETWORK CONFIG",
    COCO_STD_ATTR_NW_CONFIG_RSSI,
    "RSSI",
    "rssi",
    COCO_STD_DATA_TYPE_UINT8,
    0,
    NULL,
    NULL,
    NULL,
    &rssiVal,
    0,
    0,
    &reportChange,
    1,
    0,
    0,
    1556539804,
    0
};

static coco_std_resource_attribute_info_t demandAttr = {
  NULL,
    0,
    "zigbee/0015BC0036000397/26",
    COCO_STD_CAP_ENERGY_METERING,
    "ENERGYMETERING",
    COCO_STD_ATTR_METER_DEMAND_WATT,
    "COCO_STD_ATTR_METER_DEMAND_WATT",
    "COCO_STD_ATTR_METER_DEMAND_WATT",
    COCO_STD_DATA_TYPE_DOUBLE,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    &reportChange,
    1,
    0,
    0,
    1556539804,
    0
};

static coco_device_init_params_t deviceInitParams = {
  "../../data",
  0,
  0,
  "../../config.txt",
  "./",
  0,
  "1.0.0",
  protocolArr,
  1,
  0,
  0,
  0,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,//loggeroutput
  "../../resourceTemplate.json",
  coco_device_resource_cmd_cb,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  coco_device_attribute_update_status,
  0,
  coco_device_firmware_update_cb,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
};

#endif // INFO_H_INCLUDED
