#ifndef INFO_H_INCLUDED
#define INFO_H_INCLUDED

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "cocostandard/coco_std_api.h"
#include "cocodevicesdk/coco_device_api.h"
#include "cocostandard/coco_std_data_temperature_types.h"
#include "cocostandard/coco_std_data_on_off_types.h"
static int maxVal = 1;
static int64_t curVal = 0;
static int reportChange = 1;
static int32_t protocolArr[] = {COCO_STD_PROTOCOL_ZIGBEE};

void coco_device_firmware_update_cb(coco_device_fw_update_details_t *fwUpdateDetails);
void coco_device_resource_cmd_cb(coco_std_resource_cmd_t *resourceCmd);
void coco_device_attribute_update_status(int32_t status, void *context);

static coco_std_resource_attribute_info_t onOffAttr = {
    NULL,
    0,
    "zigbee/0015BC0036000397/26",
    COCO_STD_CAP_ON_OFF_CONTROL,
    "ON OFF",
    COCO_STD_ATTR_ON_FLAG,
    "COCO_STD_ATTR_ON_FLAG",
    "on Off",
    COCO_STD_DATA_TYPE_BOOLEAN,
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

static coco_std_resource_attribute_info_t temperatureAttr = {
  NULL,
    0,
    "zigbee/0015BC0036000397/26",
    COCO_STD_CAP_TEMPERATURE_MEASUREMENT,
    "TEMPERATURE",
    COCO_STD_ATTR_CURRENT_TEMP_CELSIUS,
    "COCO_STD_ATTR_CURRENT_TEMP_CELSIUS",
    "COCO_STD_ATTR_CURRENT_TEMP_CELSIUS",
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
  0,//loggeroutput
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
