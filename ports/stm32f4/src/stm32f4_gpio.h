
 /*******************************************************************************
 *                       S T M 3 2 F 4 _ G P I O . H
 ********************************************************************************
 * Description:
 *   Header file for the gpio class of lwHAL ported to the STM32F4 micro-controller.
 *
 * lwHAL (c) 2021, Silvano Furlan.
 *******************************************************************************/

#ifndef lwHAL_STM32F4_GPIO_H
#define lwHAL_STM32F4_GPIO_H

#include "gpio.h"

extern const void * stm32f4_Gpio;


//#define   set               GPIOC->BSRR = GPIO_PIN_8
//#define   reset              GPIOC->BSRR = (uint32_t)GPIO_PIN_8 << 16U





//GPIOC->MODER &= ~(GPIOx_MODER_INPUT << (PIN_8 * 2)); // port mode register
//GPIOC->OTYPER &= ~(GPIOx_OTYPE_PP << (PIN_8)); // output type register
//GPIOC->OSPEEDR &= ~(GPIOx_OSPEEDR_LOW << (PIN_8 * 2));
//GPIOC->PUPDR &= ~(GPIOx_PUPDR_NOPULL << (PIN_8 * 2));

#endif /* lwHAL_STM32F4_GPIO_H */
