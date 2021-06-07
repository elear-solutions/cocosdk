# Boilerplate for building a device app on top of COCO Device SDK

It is a CLI application to act as boilerplate for building a device app using COCO Device SDK. It demonstrates the following:
- Onboarding the device onto the COCO Network
- Adding an illumination sensor as a resource to the device
- Publishing attribute updates for the illumination sensor for every 2 Sec

## Build on host machine
```
$ rm -rf <path to build folder>
$ mkdir <path to build folder>
$ cd <path to build folder>
$ CC = gcc cmake ..
$ make
The built binary can be found inside <path to build folder>
```

## Build using Conan on host machine
```
$ rm -rf <path to build folder>
$ mkdir <path to build folder>
$ conan install . -if=<path to build folder>
$ conan build . -bf=<path to build folder>
The built binary can be found inside <path to build folder>/bin
```

## Downloading device license file from Manage the Buzz portal
1. Login to https://manage.getcoco.buzz/home using the verified credential
2. From the **Developer Dashboard** choose the **Devices** tile
3. From **List of Products** page click on **Product** button for adding the new product (If the product is already created, go tp step 6)
4. In the **Create Product** page fill the product information such as Product Name, Make, Model, Description, Setup Instructions and select **TYPE OF PRODUCT** as **Self Managed** then click on **SUBMIT**
5. Once the above process is successfully completed page will be redirected to **List of Products** page and newly added product can be found from **List of Products**
6. From **List of Products** page click on the product name
7. From **Product Details** page click on **Device Licenses**
8. Enter the number of Licenses as 1 for downloading one device liceses and click on **GENERATE**
9. Download the license file

## Running the executable
```
To run the built executable:
$ ./<path to build folder>/bin/deviceapp -d <current-working-directory> -c <license-file-path>

<current-working-directory> is the directory path where the application will store its data
<license-file-path> is the path to the device license file downloaded from Manage the Buzz portal
```
## Adding the deviceApp into the cocoNet
- Run the deviceApp executable by following the commands from ``Running the executable ``
- After the successful initialisation of deviceApp send the add device request from the client application

License
==========
Proprietary and Confidential

Copyright (c) 2018-2021 Elear Solutions Tech Private Limited. All rights reserved.

To any person (the "Recipient") obtaining a copy of this software and
associated documentation files (the "Software"):
All information contained in or disclosed by this software is confidential
and proprietary information of Elear Solutions Tech Private Limited and all
rights therein are expressly reserved. By accepting this material the
recipient agrees that this material and the information contained therein is
held in confidence and in trust and will NOT be used, copied, modified,
merged, published, distributed, sublicensed, reproduced in whole or in part,
nor its contents revealed in any manner to others without the express
written permission of Elear Solutions Tech Private Limited.

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
