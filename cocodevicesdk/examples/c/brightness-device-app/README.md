# Sample app for building a device app on top of COCO Device SDK

It is a CLI application to act as boilerplate for building a device app using COCO Device SDK. It demonstrates the following:
- Onboarding the device with resource template supporting LEVEL CONTROL, ENERGY METER and NEWTWORK CONFIGURATION capabilties onto the COCO Network.
- Supports handling of Level control commands, OTA. Remote device diagnosis
- Publishes energy demand attribute update every 5 secs.
- Publishes level Percentage attribute on recieving level control command.

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

## Running the executable
```
To run the built executable:
$ ./<path to build folder>/bin/deviceapp 
```

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
