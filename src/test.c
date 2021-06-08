
 /*******************************************************************************
 *                            M A I N . C
 ********************************************************************************
 * Description:
 *   Source file for testing lwHAL.
 *
 * lwHAL (c) 2021, Silvano Furlan.
 *******************************************************************************/

 #include <stdio.h>

 #include "pin.h"
 #include "gpio.h"

 int main () {

   void * pin_A1 = new(Pin, 1, 'A');
   void * pin_A2 = new(Pin, 2, 'A');

   printf("\n !> Added pin #%d on port %c\n",pin(pin_A1),port(pin_A1));

   write(pin_A1, 10);

   printf("\n !> value of pin: %d", read(pin_A1));

   /* Set pin_A1 as a GPIO output and toggle it */

   void * gpio_A1 = new(Gpio);
   write(gpio_A1, GPIO_MODE, GPIO_MODE_OUTPUT | GPIO_TYPE_PP);
   write(gpio_A1, GPIO_SPEED, GPIO_SPEED_LOW);
   write(gpio_A1, GPIO_PULL, GPIO_PULL_NOPULL);

   write(pin_A1, 1);


   printf("\n !> value of pin: %d", read(pin_A1));



   link(pin_A1, gpio_A1); // is the initialization between the peripheral and the phy pin.
   write(pin_A1,1); // which is equivalent to write(gpio_A1,GPIO_STATE,1);

   void * gpio_A2 = new(Gpio, GPIO_MODE_INPUT, GPIO_SPEED_LOW, GPIO_PULL_NOPULL);
   link(pin_A2, gpio_A2);
   //write(pin_A2, 0); // it is not making any effect
   int v_A2  = read(pin_A2);

   toggle(pin_A1);

   printf("\n !> value of pin: %d", read(pin_A1));

   toggle(pin_A1, pin_A2);


   /* Set TIM4_ch2 to call trigger() on RISING EDGE at 2Hz freq */
   /*
   void * tim4_ch2 = new(Timer, 4, 2);

   freq(tim4_ch2, 2);
   callback(tim4_ch2, trigger, TIM_RISING_EDGE);
   link(pin_A1, tim4_ch2);
   */


   delete(pin_A1);

   return 0;
 }
