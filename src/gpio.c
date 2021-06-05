
 /*******************************************************************************
 *                            G P I O . C
 ********************************************************************************
 * Description:
 *   Header file for the gpio class of lwHAL.
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

 static void * Gpio_ctor (void * _self, va_list * app)
 {
   //struct Gpio * self = ((const struct Class *) Pin) -> ctor(_self, app);
   //self -> rad = va_arg(* app, int);
   //return self;
   struct Gpio * self = _self;
   self->_mode = (U8) va_arg(*app, int);
   self->_speed = (U8) va_arg(*app, int);
   self->_pull = (U8) va_arg(*app, int);
   //self->value = va_arg(*app, uint16_t);
   return self;
 }
/*
 static WBSIZE Gpio_read(const void * _self, va_list * app)
 {
   struct Pin * self = _self;
   return self->_value;
 }
 */

 static void Gpio_write(const void * _self, va_list * app)
 {
   struct Gpio * self = _self;
   int reg = va_arg(*app, int);
   switch(reg) {
     case GPIO_MODE:
      self -> _mode = (U8) va_arg(*app, int);
      break;
     case GPIO_SPEED:
      self -> _speed = (U8) va_arg(*app, int);
      break;
     case GPIO_PULL:
      self -> _pull = (U8) va_arg(*app, int);
      break;
   }
 }

 void toggle (const void * _self, ...)
 {
   struct Pin * self = _self;
   // get the pin object pointer and toggle the _value.
   struct Gpio * cp = (struct Gpio *)(self->_link);
   if (cp->_mode == GPIO_MODE_OUTPUT_PP || cp->_mode == GPIO_MODE_OUTPUT_OD)
    self->_value = (self->_value>0) ? 0 : 1;

   //= va_arg(ap, (struct Pin *));
   //return 0; //self->_;
 }



 // gpio type descriptor
 static const struct Class _Gpio = {
   sizeof(struct Gpio),
   Gpio_ctor,
   0, //Gpio_dtor,
   0, //Gpio_read,
   Gpio_write
 };

 const void * Gpio = & _Gpio;
