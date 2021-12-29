#include <stdio.h>
#include <unistd.h>
#include "info.h"

void coco_device_resource_cmd_cb(coco_std_resource_cmd_t *resourceCmd) {
  coco_device_fetch_attr_param_t fetchAttrParam;
  coco_std_resource_attribute_info_t *attributeInfo;
  uint32_t attributeCount;
  int currentValue;

  if(0 == resourceCmd->capabilityId) {
    printf("App: Received ONOFF command with command ID %d \n", resourceCmd->cmdId);
    if(0 == resourceCmd->cmdId) {
      currentValue = 1;
    } else if(1 == resourceCmd->cmdId) {
      currentValue = 0;
    } else if(2 == resourceCmd->cmdId) {
      fetchAttrParam.resourceEui = onOffAttr.resourceEui;
      fetchAttrParam.capabilityId = 0;
      fetchAttrParam.attributeId = 0;
      coco_device_resource_attribute_fetch(&fetchAttrParam, 1, &attributeInfo, &attributeCount);
      currentValue = !(attributeInfo->currentValue);
    }
    onOffAttr.currentValue = (void *)&currentValue;
    printf("App: Received on off command with status is %d ......\n", onOffAttr.currentValue);
    coco_device_resource_attribute_update(&onOffAttr, NULL);
  }
}

int main(int argc, char *argv[]) {
  double val = 0;
  int retVal;

  if (0 == (retVal = coco_device_init(&deviceInitParams))) {
    while (-1 == (coco_device_init_auth())) {
      sleep(3);
    }
    printf("App: Device authentication success\n");
  }

  while (1) {
    val++;
    temperatureAttr.currentValue = &val;
    printf("App: Sending temperature Attribute Update with value: %.2f\n", val);
    coco_device_tx_user_log_msg("App: Sending Temperature Attribute Update with value: %.2f\n", val);
    coco_device_resource_attribute_update(&temperatureAttr, NULL);
    sleep(5);
  }
}
