
 /*******************************************************************************
 *                        S T M 3 2 F 4 _ G P I O . C
 ********************************************************************************
 * Description:
 *   Source file for the gpio class of lwHAL ported to the STM32F4 micro-controller.
 *
 * lwHAL (c) 2021, Silvano Furlan.
 *******************************************************************************/

 #include <stdio.h>
 #include <assert.h>
 #include <stdlib.h>

 #include "pin.h"
 #include "pin.def"
 #include "gpio.h"
 #include "gpio.def"

 #include "config.h"
 #include "stm32f4_gpio.h"


#if defined (STM32F4xx)
  #include "stm32f4xx.h"
#endif


 static void stm32f4_Gpio_link (const void * _self)
 {
   // TODO: add pin linking initialization code with GPIO specific for micro-controller port
   //uint32_t* gpio_addr = AHB1PERIPH_BASE + (port-24)*(0x0400U);
#if defined (STM32F4xx)
   struct Gpio * self = _self;
   uint8_t port = (self -> _pin -> _port) - 65; // "A" ascii = 65
   self -> _pin = self -> _pin -> _pin;
   self -> _gpio_addr = AHB1PERIPH_BASE + port*(0x0400U);

   uint32_t pin = self -> _pin;
   uint32_t * gpio_addr = self -> _gpio_addr;

   RCC -> AHB1ENR       |= (1U << port); //__HAL_RCC_GPIOI_CLK_ENABLE();

   gpio_addr -> MODER   |= ((self -> _mode & 0x3) << (pin*2));
   gpio_addr -> OTYPER  |= (((self -> _mode & 0x4) >> 2) << pin);
   gpio_addr -> OSPEEDR |= (self -> _speed << (pin*2));
   gpio_addr -> PUPDR   |= (self -> _pull << (pin*2));
#endif

 }


 static void stm32f4_Gpio_set (const void * _self, int v)
 {
   //printf("\n here gpio toggle stm32f4"); getchar();
#if defined (STM32F4xx)
  struct Gpio * self = _self;
  if ((self -> _mode & 0x3) == GPIO_MODE_OUTPUT) {
    uint32_t pin = self -> _pin;
    uint32_t * gpio_addr = self -> _gpio_addr;
    if (v == GPIO_PIN_SET) { gpio_addr -> BSRR = (1U << pin); }
    else { gpio_addr -> BSRR = (uint32_t) 1U << (16U+pin) }
  } // if GPIO_MODE_OUTPUT
#endif
 }


 static void stm32f4_Gpio_toggle (const void * _self)
 {
   //printf("\n here gpio toggle stm32f4"); getchar();
#if defined (STM32F4xx)
    //printf("\n here gpio toggle stm32f4"); getchar();
    struct Gpio * self = _self;
    uint32_t pin = self -> _pin;
    uint32_t * gpio_addr = self -> _gpio_addr;
    gpio_addr -> ODR ^= (1U << pin);
#endif
 }

// gpio type descriptor
static const struct Gpio _stm32f4_Gpio = {
  sizeof(struct Gpio),
  Gpio_ctor,
  0, //Gpio_dtor,
  0, //Gpio_read,
  Gpio_write,
  stm32f4_Gpio_link,
  0,
  stm32f4_Gpio_set,
  stm32f4_Gpio_toggle
};

const void * stm32f4_Gpio = & _stm32f4_Gpio;
