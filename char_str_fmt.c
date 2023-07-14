#include "main.h"

/**
 * handle_char - Prints out a character to the stdout
 * @args: The argument that handle_char will take
 *
 * Return: The number of character(s) printed (1)
 *
 * We get the values from va_list args
 * After we get it, we pass it to putchar which simply prints
 * the value of the character
 *
 * We check if it was successful before returning 1
 * else we return 0
 *
*/

int handle_char(va_list args)
{
	char x = va_arg(args, int);

	if (_putchar(x))
		return (1);

	return (0);
}

/**
 * handle_str - A function to print out strings
 * to the stdout
 *
 * @args: The arguments to be passed into our function
 * Return: 0 if empty, null if NULL and the number of
 * characters printed if successful
 *
 * The "array" or pointer to the location of the first character
 * is retrieved from va_list using va_arg. This enables us to now
 * be able to start its manipulation.
 *
 * The counter is initialized for tracking how many characters are
 * printed. It is initialized to 0 to make sure that if nothing
 * prints then the functions using it will get 0 instead of
 * undefined behaviour.
 *
 * If our string is NULL, we change its value to "(null)", this ensures that
 * our program doesn't produce undesired behaviour. The loop is true
 * in all non zero values (check ASCII, man ascii for more),
 * this means that if it is equal to null ('\0') it evaluates to false
 * effectively terminating the loop and returning the umber of characters
 * printed
 *
*/

int handle_str(va_list args)
{
	char *str = va_arg(args, char *);
	size_t i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}

/**
 * handle_pc - A function that handles extra percentage
 * @args: Not applicable
 * Return: 0 if nothing is printed or an error, and 1 if
 * successful
 *
 * The __attribute__((unused)) is used to silence GCC
 * whenever there is an attribute that is unused. This is
 * the case here since we don't need to get any value from
 * va_list args.
 *
 * Resources:
 * https://lms.fun-mooc.fr/asset-v1:inria+41020+session01+type@asset+block/forum-unused-parameters-attribute-unused-2181.html
 * https://developer.arm.com/documentation/dui0491/i/Compiler-specific-Features/--attribute----unused---variable-attribute
 * https://gcc.gnu.org/onlinedocs/gcc-3.4.6/gcc/Variable-Attributes.html
*/

int handle_pc(__attribute__((unused)) va_list args)
{
	if (_putchar('%'))
		return (1);

	return (0);
}
