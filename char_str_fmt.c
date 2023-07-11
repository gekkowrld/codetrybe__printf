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
*/

int handle_char(va_list args)
{
    char x = va_arg(args, int);

    return (_putchar(x));
}
