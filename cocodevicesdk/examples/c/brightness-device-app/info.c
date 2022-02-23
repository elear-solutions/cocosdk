#include "info.h"


int maxVal = 100;
int64_t curVal = 40;
int32_t rssiVal = 4;
int reportChange = 1;
int32_t protocolArr[] = {COCO_STD_PROTOCOL_ZIGBEE};

coco_std_resource_attribute_info_t levelAttr = {
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

coco_std_resource_attribute_info_t rssiAttr = {
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

coco_std_resource_attribute_info_t demandAttr = {
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

coco_device_init_params_t deviceInitParams = {
  "../../cwd/data",
  0,
  0,
  "../../cwd/config.json",
  "../../cwd/download",
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
  0,
  "../../templates/resourceTemplate.json",
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

void coco_device_firmware_update_cb(coco_device_fw_update_details_t *fwUpdateDetails) {
  char command[200] = {0};
  printf(" App: New firmware version:%s found!!, Downloaded at %s\n",
          fwUpdateDetails->version, fwUpdateDetails->filePath);
  snprintf(command, sizeof(command), "%s %s", "chmod +x", fwUpdateDetails->filePath);
  system(command);
  snprintf(command, sizeof(command), "%s %s %s%s", "mv", fwUpdateDetails->filePath, "./", "deviceapp");
  if (0 == fork()) {
    system(command);
    sleep(5);
    printf("App: Installed firmware version %s....System Rebooting....\n", fwUpdateDetails->version);
    exit(1);
  } else {
    sleep(20);
    exit(1);
    }
}

void coco_device_attribute_update_status(int32_t status, void *context) {
}

void coco_device_add_res_status_cb(int32_t status, void *context) {
}
