
 /*******************************************************************************
 *                            C O N F I G . H
 ********************************************************************************
 * Description:
 *   Header file for the configuration of lwHAL.
 *
 * lwHAL (c) 2021, Silvano Furlan.
 *******************************************************************************/

#ifndef lwHAL_CONFIG_H
#define lwHAL_CONFIG_H

#define WEAK __attribute__((weak))

#define U8     uint8_t
#define U16    uint16_t
#define U32    uint32_t
#define WBSIZE  U16 // microcontroller word byte size (i.e. 32-bits, 16-bits, 8-bits,....)

//#define STM32F4xx // un-comment to enable the STM32F4 port configuration
//#define PIC16Fxx

 #if defined (STM32F4xx) || defined (PIC16Fxx)
  #define PORT
 #endif

 #endif /* lwHAL_CONFIG_H */
