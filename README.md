# lwHAL
## A light-weight Hardware Abstraction Layer for micro-controllers
------------------------------------------------------------------------------------

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

#### Folder structure

  /docs   --> document folder with reference manual 
  
  /ports  --> folder with the port to the target micro-controllers 
  
  /src    --> folder with the source code of the template lwHAL used for the ports 
  

#### Quick overview

Run the makefile in /src to test the lwHAL
Run the makefile in /ports/stm32f4 to test the STM32F4 lwHAL port

#### Last log

Added support to gpio set(), toggle() and link() for STM32F4 port.
All tests passed successfully.

------------------------------------------------------------------------------------
MIT license.
lwHAL (c) 2021, Silvano Furlan.
