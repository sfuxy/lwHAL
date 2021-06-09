# lwHAL
## A light-weight Hardware Abstraction Layer for micro-controllers

### Description

lwHAL is an abstraction layer for the HW peripherals of micro-controllers.
This layer can be added as a static library or compiled together with your firmware source code.
Instead of using specific supplier HALs, lwHAL provides you with all the independence and reusability that your original firmware code needs to be deployed on multiple micro-controllers.
lwHAL is structured as an object oriented (oo) program, written in embedded C, and features a very minimalistic set of methods. While yet minimal, its oo structure bears the gears to be easily extended, maintained and scalable.

We compare lwHAL to other public HALs, like Wiring (used in Arduino) and the internal HAL of the micropython project.
See the documents in the /docs folder for reference, how-to and building with your own code.

### Contribution

Our commitment is to keep lwHAL small in size and simple in usage, without compromising on functionality.

In this initial implementation, we focus on providing abstraction to the GPIOs for two micro-controller targets, STM32F4xx and PIC16Fxx. Specific implementations are included in the /ports folder.

We are currently working on extending the support to the timers and add defensive methods against errors.

### Pro - Firmware customization and support

We provide professional services to customize and support additional features of lwHAL which goes beyond the
scope of the MIT license. Those services are targeted to the extension of the lwHAL project to:
- industrial and automotive proprietary embedded applications,
- compliance to the ISO26262-ASILx automotive regulation,
- support a new micro-controller platform from a supplier,
- integration into a micro-controller operating system or IoT platform;

Please, contact the lwHAL project owner S.Furlan for your customization queries.

------------------------------------------------------------------------------------

### Additional details

#### Folder structure

  /docs   --> document folder with reference manual

  /ports  --> folder with the port to the target micro-controllers

  /src    --> folder with the source code of the template lwHAL used for the ports

### Quick overview

Run the makefile in /src to test the lwHAL

Run the makefile in /ports/stm32f4 to test the STM32F4 lwHAL port

Run the makefile in /docs with the command 'make latexpdf; to compile the TeX. You will need to have pdflatex in your environment.

#### Last log

Tested gpio basic functions on NUCLEO-F429ZI.
All tests passed successfully.



------------------------------------------------------------------------------------
MIT license.
lwHAL (c) 2021, Silvano Furlan.
