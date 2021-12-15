#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <syslog.h>
#include <time.h>
#include "cocodevicesdk/coco_device_api.h"
#include "cocostandard/coco_std_api.h"
#include "cocostandard/coco_std_data_illuminance_types.h"
#include "cocostandard/coco_std_data_network_config_types.h"
#include "cocostandard/coco_std_data_meter_types.h"
#include "cocostandard/coco_std_data_level_types.h"
void coco_device_firmware_update_cb(coco_device_fw_update_details_t *fwUpdateDetails);
void coco_device_resource_cmd_cb(coco_std_resource_cmd_t *resourceCmd);
void coco_device_attribute_update_status(int32_t status, void *context);
/* Local Variables */
static int maxVal = 100;
static int64_t curVal = 50;
static int32_t rssiVal = 4;
static int reportChange = 1;
static int32_t protocolArr[] = {COCO_STD_PROTOCOL_ZIGBEE};
char dataPath[20] = {"../../data"};
char configPath[20] = {"../../config.txt"};
char resourceInfoPath[] = {"../../resourceTemplate.txt"};
char downloadPath[] = {"./"};
char firmwareVersion[] = {"1.0.1"};
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

static coco_device_init_params_t deviceInitParams = {
  dataPath,
  0,
  0,
  configPath,
  downloadPath,
  0,
  firmwareVersion,
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
  resourceInfoPath,
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

void coco_device_data_corruption_cb() {
  printf("App: cocodevicesdk data corrupted\n");
  exit(1);
}

void coco_device_attribute_update_status(int32_t status, void *context) {
  printf("App: coco_device_attribute_update_status() status: %d\n", status);
  return;
}

void coco_device_add_res_status_cb(int32_t status, void *context) {
  printf("App: coco_device_add_res_status_cb() status: %d\n", status);
  return;
}

void coco_device_resource_cmd_cb(coco_std_resource_cmd_t *resourceCmd) {
  coco_std_cmd_set_level_t *resCmd = (coco_std_cmd_set_level_t *)resourceCmd->cmdParams;

  if (COCO_STD_CAP_LEVEL_CTRL == resourceCmd->capabilityId &&
      COCO_STD_CMD_SET_LEVEL_WITH_ON_OFF == resourceCmd->cmdId) {
    printf("App: Received LevelControl command with level %d....Setting Brightness....\n", resCmd->levelPct);
    levelAttr.currentValue = (void *)&resCmd->levelPct;
    coco_device_resource_attribute_update(&levelAttr, NULL);
    }
    return;
}

void coco_device_firmware_update_cb(coco_device_fw_update_details_t *fwUpdateDetails) {
//  char command[200] = {0};
//  printf(" App: New firmware version:%s found!!, Downloaded at %s\n",
//          fwUpdateDetails->version, fwUpdateDetails->filePath);
//  if (snprintf(command, sizeof(command), "%s %s %s", "mv", fwUpdateDetails->filePath, FIRMWARE_VERSION_PATH) < 0) {
//    printf("App: Unable to create firmwarepath\n");
//  } else {
//    if (-1 == system(command)) {
//      printf("App: Unable to upadte firmware\n");
//      exit(1);
//    }
//    sleep(5);
//    printf("App: Installed firmware version %s....System Rebooting....\n", fwUpdateDetails->version);
//    exit(1);
//  }
  return;
}

int main(int argc, char *argv[]) {
  double val;
  int retVal;

  if (-1 == (retVal = coco_device_init(&deviceInitParams))) {
    exit(1);
  } else if (0 == retVal) {
    while (-1 == (coco_device_init_auth())) {
      printf("Sending Auth\n");
      sleep(3);
    }
  }
  coco_device_resource_attribute_update(&rssiAttr, NULL);
  while (1) {
    val++;
    demandAttr.currentValue = &val;
    coco_device_tx_user_log_msg("App: Sending Energy Demand Attribute Update with value: %.2f\n", val);
    coco_device_resource_attribute_update(&demandAttr, NULL);
    sleep(5);
  }
  return EXIT_SUCCESS;
}
