
 /*******************************************************************************
 *                            P I N . H
 ********************************************************************************
 * Description:
 *   Header file for the pin class of lwHAL.
 *
 * lwHAL (c) 2021, Silvano Furlan.
 *******************************************************************************/

 #ifndef lwHAL_PIN_H
 #define lwHAL_PIN_H

 #include <stddef.h>
 #include <stdarg.h>
 #include <stdint.h>

 #include "config.h"

 extern const void * Pin;
 //extern const void * Function;

 void * new (const void * type, ...);
 void delete (void * item);

 //void * Pin_ctor (void * _self, va_list * app);
 //void * Pin_dtor (void * _self);

 //int value (const void * self, ...); // get or set the value of the pin
 WBSIZE read (const void * type, ...);
 void write (const void * type, ...);
 void link (const void * _self, const void * _func);

 int pin (const void * _self);
 char port (const void * _self);




 #endif /* lwHAL_PIN_H */
