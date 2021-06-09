
 /*******************************************************************************
 *                            P I N . C
 ********************************************************************************
 * Description:
 *   Source file for the pin class of lwHAL.
 *
 * lwHAL (c) 2021, Silvano Furlan.
 *******************************************************************************/

 #include <stdio.h>
 #include <assert.h>
 #include <stdlib.h>

 #include "pin.h"
 #include "pin.def"

 // dynamic linking
 void * new (const void * _class, ...)
 {
   const struct Class * class = _class;
 	 void * p = calloc(1, class -> size);
 	 assert(p);
 	* (const struct Class **) p = class;

 	if (class -> ctor) {
    va_list ap;
 		va_start(ap, _class);
 		p = class -> ctor(p, & ap);
 		va_end(ap);
 	}
 	return p;
 }

 void delete (void * self)
 {
   const struct Class ** cp = self;
 	 if (self && * cp && (* cp) -> dtor) {
 		self = (* cp) -> dtor(self);
  }
 	free(self);
 }

 WBSIZE read (const void * self, ...)
 {
   const struct Class * const * cp = self;
   WBSIZE res;
   assert(self && * cp && (* cp) -> read);
   va_list ap;
   va_start(ap, self);
   //res = (* cp) -> read(self, & ap);
   //va_end(ap);
   //return res;
   return (* cp) -> read(self, & ap);
 }

 void write (const void * self, ...)
 {
   const struct Class * const * cp = self;
   assert(self && * cp && (* cp) -> write);
   va_list ap;
   va_start(ap, self);
   (* cp) -> write(self, & ap);
   va_end(ap);
 }

 static void * Pin_ctor (void * _self, va_list * app)
 {
   struct Pin * self = _self;
   self->_pin = va_arg(*app, int);
   self->_port = (char) va_arg(*app, int);
   //self->value = va_arg(*app, uint16_t);
   return self;
 }

 static void * Pin_dtor (void * _self)
 {
   struct Pin * self = _self;
   return self;
 }

 int pin (const void * _self)
 {
   struct Pin * self = _self;
   return self->_pin;
 }

 char port (const void * _self)
 {
   struct Pin * self = _self;
   return self->_port;
 }

 void link (const void * _self, const void * _func)
 {
   struct Pin * self = _self;
   struct Function * func = _func;

   const struct Function * const * cp = _func;
   self->_link_func = _func;
   func -> _link_pin = _self;
   //assert(self && * cp && (* cp) -> link);
   assert(* cp && (* cp) -> link);
   (* cp) -> link(_func);
   //(* cp) -> link(_func);
 }

 /*WEAK*/
 /*
 void link (const void * _self, void * func)
 {
   struct Pin * self = _self;
   self->_func = func;

 }
 */

/*
 int value (const void * _self, ...)
 {
   struct Pin * self = _self;
   //if (*app != NULL) {
   char *frm = (char*) _self;
   va_list ap;
   va_start(ap, frm);
   printf("\n");
   while ( *frm != '\0') {
     printf("here");
     //return self->_value;
     if ( *frm == 's') {
       self->_value = va_arg(ap, int);
       printf("%d,",self->value);
     }
     *frm++;
   }
   va_end(ap);
   //else self->_value = (int) va_arg(ap, int);
   //int v = va_arg(ap, int);
   //va_arg(ap, int);
   //printf("\n\n %d",v);
   //va_end(ap);
   //if (v==10) printf("yes");
   //self->_value = v;
   //if (v==-1) {
  //   return self->_value;
   //}
   //else self->_value = v;
   //printf("\n here %d",va_arg(*app, int)); getchar();

 }
 */

 static WBSIZE Pin_read(const void * _self, va_list * app)
 {
   struct Pin * self = _self;

   // TODO: add specific read pin instructions depending on linked function
   return self->_value;
 }

 static void Pin_write(const void * _self, va_list * app)
 {
   struct Pin * self = _self;
   self->_value = (WBSIZE) va_arg(*app, int);

   // TODO: add specific write pin instructions depending on linked function
   // i.e.: if digital output then set 0 or 1, if DAC analog output set the value

 }


 // pin type descriptor
 static const struct Class _Pin = {
   sizeof(struct Pin),
   Pin_ctor,
   0, //Pin_dtor,
   Pin_read,
   Pin_write,
   //pin,
   //port
 };

 const void * Pin = & _Pin;

/*
 void draw (const void * self)
 {
   const struct Class * const * cp = self;
 	assert(self && * cp && (* cp) -> draw);
 	(* cp) -> draw(self);
 }
 */
