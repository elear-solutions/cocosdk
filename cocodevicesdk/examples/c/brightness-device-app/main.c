#include <stdio.h>
#include <unistd.h>
#include "info.h"

void coco_device_resource_cmd_cb(coco_std_resource_cmd_t *resourceCmd) {
  printf("App: Received LevelControl command with level %d....Setting Brightness....\n", ((coco_std_cmd_set_level_t *)resourceCmd->cmdParams)->levelPct);
  levelAttr.currentValue = (void *)&(((coco_std_cmd_set_level_t *)resourceCmd->cmdParams)->levelPct);
  coco_device_resource_attribute_update(&levelAttr, NULL);
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

  coco_device_resource_attribute_update(&rssiAttr, NULL);

  while (1) {
    val++;
    demandAttr.currentValue = &val;
    printf("App: Sending Energy Demand Attribute Update with value: %.2f\n", val);
    coco_device_tx_user_log_msg("App: Sending Energy Demand Attribute Update with value: %.2f\n", val);
    coco_device_resource_attribute_update(&demandAttr, NULL);
    sleep(5);
  }
}
