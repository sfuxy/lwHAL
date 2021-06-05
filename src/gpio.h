
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

 extern const void * Gpio;

 #define GPIO_MODE            (0)
 #define GPIO_SPEED           (1)
 #define GPIO_PULL            (2)

 #define GPIO_MODE_INPUT      (0)
 #define GPIO_MODE_OUTPUT_PP  (1)
 #define GPIO_MODE_OUTPUT_OD  (2)
 #define GPIO_MODE_ANALOG     (3)

 #define GPIO_SPEED_LOW       (0)
 #define GPIO_SPEED_MEDIUM    (1)
 #define GPIO_SPEED_HIGH      (2)
 #define GPIO_SPEED_VERY_HIGH (3)

 #define GPIO_PULL_NOPULL     (0)
 #define GPIO_PULL_UP         (1)
 #define GPIO_PULL_DOWN       (2)

  void toggle (const void * _self, ...); // it can toggle multiple pins at once


 #endif /* lwHAL_GPIO_H */
