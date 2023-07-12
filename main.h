#ifndef MAIN_H_
#define MAIN_H_


#include <stdarg.h> /* For variadic functions*/
#include <limits.h> /* For useful limits that should not be reached*/
#include <stdio.h>
#include <unistd.h>

/* Printf prototype (Takes in variable arguments)*/

int _printf(const char *format, ...);


/**
 * struct fmt_specifiers - A blueprint for declaring printf formats
 *
 * @fmt: This is the format that will be handled by the printf function.
 * Examples of values that fmt should take are s and c.
 *
 *
 * @function: This is the format of the functions that will be used
 * to handle @fmt. It should return an int value (as seen in the first part)
 * and the name of the function is user defined but should be descriptive.
 * Function names should be nouns if represent something (which is rare)
 * and verbs when performing an action (most of the time)
 * An example can be "handle_string"
 *
 * An example of a function that can be made using this struct is
 * int handle_string(va_list args)
 *
 * It is not mandatory to use this format for all the function
 * implemented but should be used for all format specifiers
 *
 * Exceptions include _putchar(char x) and family
 *
*/

typedef struct fmt_specifiers
{
	char *fmt;
	int (*function)(va_list);
} fmt_specifier;

/* Preprocessor Definations */

#define BUFFER_S 1024

/**
 * _F_NAME_ - Get function name
 * If __func__ is available use it (Recommended by Betty)
 * Else use __FUNCTION__ (Available for gcc only)
 * This operation causes Betty to raise a Warning
 * You can remove the operation and replace it with
 * #define _F_NAME_ __func__ and everything will work just fine
 * and as an added bonus no Betty to deal with
*/
#ifdef __func__
	#define _F_NAME__ __func__
#else
	#define _F_NAME__ __FUNCTION__
#endif

/* Helper Functions */

int _putchar(char x);
int _strlen(const char *str);

/* Format specifiers */

int handle_char(va_list args);

#endif /* End of MAIN_H_ */
