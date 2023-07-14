#ifndef MAIN_H_
#define MAIN_H_

/*
 *======--------- main.h - _printf header file ---------------------------===
 *
 * This header file is part of the Codetrybe project to simplify the
 * implementation of the printf function.
 * It utilizes the concepts taught at ALX.
 * Please refrain from directly copying and pasting this code into
 * your project, as doing so violates academic integrity
 * and risks your standing in the ALX program.
 *
 * It is important to have a some understanding of the concepts
 * taught in ALX for easier comprehension of this code.
 *
 * Please note that this "documentation" does not replace official
 * documentation, man pages, or online resources.
 * For doubts or questions about specific concepts or functions,
 * refer to the authoritative sources, such as man pages.
 * Relevant resources are mentioned where necessary,
 * but the list is not comprehensive and may vary depending
 * on the author of the function or feature.
 * Reading all provided resources is not mandatory;
 * they serve as guides for specific concepts.
 *
 * The author(s) of this project, either in part or as a whole,
 * shall not be liable for any damages caused.
 * Efforts have been made to provide accurate information.
 *
 * This project should be compiled on LINUX x86_64 architecture,
 * preferably Ubuntu 22.04 LTS, using the -std=gnu89 flag.
 * Refer to the link
 * https://gcc.gnu.org/gcc-5/porting_to.html
 * for more information on why this flag is necessary.
 *
 * This project is released under the copyleft license GNU GPL v3.
 * Visit: https://www.fsf.org/
 * for more information on free software (as in freedom).
 *
 *======--------------------------------------------------------------------===
 */



/* Standard Libraries */

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
 * Resources:
 * man stdarg(3)
 * https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html
 * https://en.wikipedia.org/wiki/Variadic_function
 * https://youtu.be/oDC208zvsdg
 * https://youtu.be/3iX9a_l9W9Y
 *
 * https://publications.gbdirect.co.uk//c_book/chapter8/typedef.html
 * https://en.wikipedia.org/wiki/Struct_(C_programming_language)
 * https://www.geeksforgeeks.org/structures-c/
 * https://www.educative.io/answers/how-to-use-structures-in-c
 * https://youtu.be/oKXP1HZ8xIs
 * https://youtu.be/dqa0KMSMx2w
 * https://youtu.be/LpHnHRI6gLc?t=134
 * https://youtu.be/6Z-silgul48
 *
*/

typedef struct fmt_specifiers
{
	char *fmt;
	int (*function)(va_list);
} fmt_specifier;

/* Preprocessor Definations */

#define BUFFER_S 1024

/*
 *===---- predefined identifier (function name)----------===
 *
 * In previous iteration of this project there was a
 * preprocessor _F_NAME__ that was either defined to
 * __FUNCTION__ or __func__ but it has proved challenging
 * to keep it. At first it is not portable to C90 and below
 * apparently it was introduced in 1992 (__FUNCTION__) so
 * it is not available. This was of course only for GCC.
 * https://stackoverflow.com/questions/7008485/
 * https://github.com/grpc/grpc/issues/1739
 * And __func__ was added in ISO C 1999 so its availability is
 * not available for most compilers.
 * You can easily silence this warnings as explained here
 * https://stackoverflow.com/questions/52962812/ but it is not
 * worth the hassle.
 * You can check out the official bug report about the issue
 * https://bugzilla.gnome.org/show_bug.cgi?id=758541
 *
 * But if you want to recreate what was here then:
 *
 * #ifdef __func__
 * 	#define _F_NAME__ __func__
 * #else
 * 	#define _F_NAME__ __FUNCTION__
 * #endif
 *
 * The if's are not necessary since the identifier was later
 * standardized to use __func__, but __FUNCTION__ can be used
 * when compiling with GCC (kept for backward compatibility)
 *
 *===-------------------------------------------------------===
 */

/* Helper Functions */

int _putchar(char x);
int _strlen(const char *str);

/* Format specifiers */

int handle_char(va_list args);
int handle_str(va_list args);
int handle_pc(__attribute__((unused)) va_list args);

#endif /* End of MAIN_H_ */
