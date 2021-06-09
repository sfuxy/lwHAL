
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

 void * Gpio_ctor (void * _self, va_list * app)
 {
   //struct Gpio * self = ((const struct Class *) Pin) -> ctor(_self, app);
   //self -> rad = va_arg(* app, int);
   //return self;
   //struct Gpio * self = ((const struct Class *) Class) -> ctor(_self, app);
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

 void Gpio_write (const void * _self, va_list * app)
 {
   struct Gpio * self = _self;
   const struct Gpio * const * cpp;
   int reg = va_arg(*app, int), v;
   switch(reg) {
     case lwHAL_GPIO_MODE:
      self -> _mode = (U8) va_arg(*app, int);
      break;
     case lwHAL_GPIO_SPEED:
      self -> _speed = (U8) va_arg(*app, int);
      break;
     case lwHAL_GPIO_PULL:
      self -> _pull = (U8) va_arg(*app, int);
      break;
     case lwHAL_GPIO_SET:
      v = va_arg(*app, int);
      cpp = (struct Gpio *)(_self);
      assert((* cpp) -> set);
      (* cpp) -> set(_self, v);
      break;

   }
 }

 void toggle (const void * _self, ...)
 {
   struct Pin * self = _self;
   // get the pin object pointer and toggle the _value.
   struct Gpio * cp = (struct Gpio *)(self->_link_func);
   //const struct Gpio * const * cp = (struct Gpio *)(self->_func);
   if ((( cp) -> _mode & 0x3) == lwHAL_GPIO_MODE_OUTPUT) {
     self->_value = (self->_value>0) ? 0 : 1;
     const struct Gpio * const * cpp = (struct Gpio *)(self->_link_func);
     assert((* cpp) -> toggle);
      (* cpp) -> toggle(self->_link_func);
   }

   //= va_arg(ap, (struct Pin *));
   //return 0; //self->_;
 }

 static void Gpio_link (const void * _self)
 {
   // TODO: add pin linking initialization code with GPIO specific for micro-controller port

 }


 static void Gpio_set (const void * _self, int v)
 {
   // TODO: add set code for GPIO specific for micro-controller port
   printf("\n gpio set () = %d", v); getchar();
 }


 static void Gpio_toggle (const void * _self)
 {
   // TODO: add toggle code for GPIO specific for micro-controller port
   printf("\n gpio toggle ()"); getchar();
 }


 // gpio type descriptor
 static const struct Gpio _Gpio = {
   sizeof(struct Gpio),
   Gpio_ctor,
   0, //Gpio_dtor,
   0, //Gpio_read,
   Gpio_write,
   Gpio_link,
   0, // const void * _pin
   Gpio_set,
   Gpio_toggle //void (* toggle)(const void * self);
 };

 const void * Gpio = & _Gpio;
