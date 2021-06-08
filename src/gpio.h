
 /*******************************************************************************
 *                            G P I O . H
 ********************************************************************************
 * Description:
 *   Header file for the gpio class of lwHAL.
 *
 * lwHAL (c) 2021, Silvano Furlan.
 *******************************************************************************/

 #ifndef lwHAL_GPIO_H
 #define lwHAL_GPIO_H

 #include "config.h"

 extern const void * Gpio;

#ifndef PORT
 #define GPIO_MODE            (0)
 #define GPIO_SPEED           (1)
 #define GPIO_PULL            (2)
 #define GPIO_SET             (3)

 #define GPIO_MODE_INPUT      (0)
 #define GPIO_MODE_OUTPUT     (1)
 #define GPIO_MODE_ANALOG     (2)

 #define GPIO_TYPE_PP         (0)
 #define GPIO_TYPE_OD         (4)

 #define GPIO_SPEED_LOW       (0)
 #define GPIO_SPEED_MEDIUM    (1)
 #define GPIO_SPEED_HIGH      (2)
 #define GPIO_SPEED_VERY_HIGH (3)

 #define GPIO_PULL_NOPULL     (0)
 #define GPIO_PULL_UP         (1)
 #define GPIO_PULL_DOWN       (2)

 #define GPIO_PIN_RESET       (0)
 #define GPIO_PIN_SET         (1)
#endif

  void toggle (const void * _self, ...); // it can toggle multiple pins at once

  void * Gpio_ctor (void * _self, va_list * app);
  void Gpio_write(const void * _self, va_list * app);



 #endif /* lwHAL_GPIO_H */
