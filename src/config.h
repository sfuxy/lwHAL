
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

//#define STM32F4xx // un-comment to enable the STM32F4 port configuration
//#define PIC16Fxx

#if defined (PIC16Fxx)
 #define lwHAL_PORT_CONFIG
 #define WBSIZE  U16

#elif defined (STM32F4xx)
 #define lwHAL_PORT_CONFIG
 #define WBSIZE  U16 // microcontroller word byte size (i.e. 32-bits, 16-bits, 8-bits,....)

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
 #define lwHAL_GPIO_MODE_INPUT               STM32F4_GPIOx_MODER_INPUT
 #define lwHAL_GPIO_MODE_OUTPUT              STM32F4_GPIOx_MODER_OUTPUT
 #define lwHAL_GPIO_MODE_ANALOG              STM32F4_GPIOx_MODER_ANALOG
 #define lwHAL_GPIO_TYPE_PP                  (STM32F4_GPIOx_OTYPE_PP<<2)
 #define lwHAL_GPIO_TYPE_OD                  (STM32F4_GPIOx_OTYPE_OD<<2)
 #define lwHAL_GPIO_SPEED_LOW                STM32F4_GPIOx_OSPEEDR_LOW
 #define lwHAL_GPIO_SPEED_MEDIUM             STM32F4_GPIOx_OSPEEDR_MEDIUM
 #define lwHAL_GPIO_SPEED_HIGH               STM32F4_GPIOx_OSPEEDR_HIGH
 #define lwHAL_GPIO_SPEED_VERY_HIGH          STM32F4_GPIOx_OSPEEDR_VERY_HIGH
 #define lwHAL_GPIO_PULL_NOPULL              STM32F4_GPIOx_PUPDR_NOPULL
 #define lwHAL_GPIO_PULL_UP                  STM32F4_GPIOx_PUPDR_PULLUP
 #define lwHAL_GPIO_PULL_DOWN                STM32F4_GPIOx_PUPDR_PULLDOWN

#else
  #define WBSIZE  U32 // microcontroller word byte size (i.e. 32-bits, 16-bits, 8-bits,....)
#endif

 #endif /* lwHAL_CONFIG_H */
