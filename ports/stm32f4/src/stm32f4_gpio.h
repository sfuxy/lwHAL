
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

// port mode register
#define STM32F4_GPIOx_MODER_INPUT           (0U) // default
#define STM32F4_GPIOx_MODER_OUTPUT          (1U)
#define STM32F4_GPIOx_MODER_AF              (2U)
#define STM32F4_GPIOx_MODER_ANALOG          (3U)

// port output type register
#define STM32F4_GPIOx_OTYPE_PP              (0U) // default
#define STM32F4_GPIOx_OTYPE_OD              (1U)

// port output speed register
#define STM32F4_GPIOx_OSPEEDR_LOW           (0U) // default
#define STM32F4_GPIOx_OSPEEDR_MEDIUM        (1U)
#define STM32F4_GPIOx_OSPEEDR_HIGH          (2U)
#define STM32F4_GPIOx_OSPEEDR_VERY_HIGH     (3U)

// port pull-up/pull-down register
#define STM32F4_GPIOx_PUPDR_NOPULL          (0U) // default
#define STM32F4_GPIOx_PUPDR_PULLUP          (1U)
#define STM32F4_GPIOx_PUPDR_PULLDOWN        (2U)

// equivalent macros
#define GPIO_MODE_INPUT                     STM32F4_GPIOx_MODER_INPUT
#define GPIO_MODE_OUTPUT                    STM32F4_GPIOx_MODER_OUTPUT
#define GPIO_MODE_ANALOG                    STM32F4_GPIOx_MODER_ANALOG
#define GPIO_TYPE_PP                        (STM32F4_GPIOx_OTYPE_PP<<2)
#define GPIO_TYPE_OD                        (STM32F4_GPIOx_OTYPE_OD<<2)
#define GPIO_SPEED_LOW                      STM32F4_GPIOx_OSPEEDR_LOW
#define GPIO_SPEED_MEDIUM                   STM32F4_GPIOx_OSPEEDR_MEDIUM
#define GPIO_SPEED_HIGH                     STM32F4_GPIOx_OSPEEDR_HIGH
#define GPIO_SPEED_VERY_HIGH                STM32F4_GPIOx_OSPEEDR_VERY_HIGH
#define GPIO_PULL_NOPULL                    STM32F4_GPIOx_PUPDR_NOPULL
#define GPIO_PULL_UP                        STM32F4_GPIOx_PUPDR_PULLUP
#define GPIO_PULL_DOWN                      STM32F4_GPIOx_PUPDR_PULLDOWN



//GPIOC->MODER &= ~(GPIOx_MODER_INPUT << (PIN_8 * 2)); // port mode register
//GPIOC->OTYPER &= ~(GPIOx_OTYPE_PP << (PIN_8)); // output type register
//GPIOC->OSPEEDR &= ~(GPIOx_OSPEEDR_LOW << (PIN_8 * 2));
//GPIOC->PUPDR &= ~(GPIOx_PUPDR_NOPULL << (PIN_8 * 2));

#endif /* lwHAL_STM32F4_GPIO_H */
