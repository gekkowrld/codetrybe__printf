#ifndef MAIN_H_
#define MAIN_H_

#include <limits.h> /* For useful limits that should not be reached*/
#include <stdarg.h> /* For variadic functions*/
#include <stdio.h>

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

typedef struct fmt_specifiers {
  char *fmt;
  int (*function)(va_list);
} fmt_specifier;

#endif /* End of MAIN_H_ */
