
 /*******************************************************************************
 *                      S T M 3 2 F 4 _ T E S T . C
 ********************************************************************************
 * Description:
 *   Source file for testing lwHAL.
 *
 * lwHAL (c) 2021, Silvano Furlan.
 *******************************************************************************/

 #include <stdio.h>

 /* Private includes ----------------------------------------------------------*/
 /* USER CODE BEGIN Includes */
  #include "pin.h"
  #include "stm32f4_gpio.h"
 /* USER CODE END Includes */

 int main () {

   /* USER CODE BEGIN 2 */
   void * pin_B0 = new(Pin, 0, 'B'); // green LED on NUCLEO-F429zi
   void * pin_B14 = new(Pin, 14, 'B'); // red LED on NUCLEO-F429zi

   /* Set pin_ as a GPIO output and toggle it */
   void * gpio_B0 = new(stm32f4_Gpio);
   write(gpio_B0, lwHAL_GPIO_MODE,  lwHAL_GPIO_MODE_OUTPUT | lwHAL_GPIO_TYPE_PP);
   write(gpio_B0, lwHAL_GPIO_SPEED, lwHAL_GPIO_SPEED_LOW);
   write(gpio_B0, lwHAL_GPIO_PULL, lwHAL_GPIO_PULL_NOPULL);
   link(pin_B0, gpio_B0); // is the initialization between the peripheral and the phy pin.

   void * gpio_B14 = new(stm32f4_Gpio, lwHAL_GPIO_MODE_OUTPUT | lwHAL_GPIO_TYPE_PP, lwHAL_GPIO_SPEED_LOW, lwHAL_GPIO_PULL_NOPULL);
   link(pin_B14, gpio_B14);

   write(gpio_B0, lwHAL_GPIO_SET, lwHAL_GPIO_PIN_SET);
   write(gpio_B14, lwHAL_GPIO_SET, lwHAL_GPIO_PIN_SET);
   /* USER CODE END 2 */

   /* Infinite loop */
   /* USER CODE BEGIN WHILE */
   while (1)
   {
     /* USER CODE END WHILE */

     /* USER CODE BEGIN 3 */
 	toggle(pin_B0);
 	HAL_Delay(1000);
   }
   /* USER CODE END 3 */

   //delete(pin_A1);
   //detele(pin_A2);

   return 0;
 }
