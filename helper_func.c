#include "main.h"

/**
 * _putchar - A function that prints out a character to the
 * stdout (1)
 * @x: The character to be printed out. It takes in integer
 * values (ASCII).
 *
 * Return: The number of characters printed out. In our case
 * it is just one character (the last 1)
 *
 * We use the write function to write a buffer (or just characters)
 * to any stream (0 for stdin, 1 for stdout and 2 for stderr)
 * Any number of characters can be written at a time in any
 * stream. But for our purpose we want a character at a time
 * to the stdout (the terminal for most cases but can be redirected
 * elsewhere or be printed in an entirely separate location)
 *
 * Resources:
 * man write(2)
*/

int _putchar(char x)
{
	return (write(1, &x, 1));
}

/**
 * _strlen - A function that counts the number of characters in a string
 * excluding the null terminator.
 *
 * @str: The string to be counted.
 *
 * Return: The number of strings counted
 *
 * The maximum number of strings to be counted is determined by
 * INT_MAX. The program can take more than that, but due to
 * issues like buffer overflow and other security issues
 * the limit is set. It is unlikely that any string can be larger
 * than that except when the program is corrupted or in special
 * cases. In cases when the string is expected to be more than
 * INT_MAX, please use the standard "strlen"
 * If exceeded, the error is sent to the stderr stream
 * using dprintf(dprintf is like printf but the first
 * argument should be the stream that the rest of the
 * text is to be sent to[check "man dprintf(3)" for more info])
 *
 * "for" loop is used to loop over the string, the function will loop until
 * "str" is false (when it is equal to '\0' which is represented as 0 in C.
 * As 0 is normally considered false and all non zero true, then
 * the program will fail when '\0' is reached)
*/

int _strlen(const char *str)
{
	size_t i = 0;

	for (i = 0; *str ; str++)
	{
		if (i < (INT_MAX - 1))
		{
			dprintf(2, "%s: The string exceeds %d characters",
			__FILE__, INT_MAX);
			_exit(-1);
		}
		i++;
	}

	return (i);
}
