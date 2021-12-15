#include "info.h"

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
