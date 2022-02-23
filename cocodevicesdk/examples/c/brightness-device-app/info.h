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

extern int maxVal;
extern int maxVal;
extern int64_t curVal;
extern int32_t rssiVal;
extern int reportChange;

void coco_device_firmware_update_cb(coco_device_fw_update_details_t *fwUpdateDetails);
void coco_device_resource_cmd_cb(coco_std_resource_cmd_t *resourceCmd);
void coco_device_attribute_update_status(int32_t status, void *context);

extern coco_std_resource_attribute_info_t levelAttr;
extern coco_std_resource_attribute_info_t rssiAttr;
extern coco_std_resource_attribute_info_t demandAttr;
extern coco_device_init_params_t deviceInitParams;

#endif // INFO_H_INCLUDED
