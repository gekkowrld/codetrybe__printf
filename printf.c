#include "main.h"

static int parser(const char *format, fmt_specifier fmt[], va_list args);

/**
 * _printf - A custom function like that found in stdio.h
 *
 * @format: The formats that will be accepted by _printf
 * Return: The number of characters printed
 *
 * printf in its core (standard one) is a variadic function as explained here
 * https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html
 * It returns the number of characters printed (we use printed char
 * variable to do that)
 * Then get the arguments passed by using va_list args
 * In the struct specified in main.h, we create a list of format
 * handlers. This is the only part that needs to be edited for now
 * The first part fmt[].fmt[0] is the one that holds the actual format
 * and fmt.fmt[1] holds the function that holds the format specifier
 *
 * The pass the arguments to the "parser" where they are mapped to their
 * respective handlers.
*/

int _printf(const char *format, ...)
{
	int printed_char = 0;
	va_list args;

	fmt_specifier fmt[] = {
		{"c", handle_char},
		{"s", handle_str},
		{"%", handle_pc},
		{NULL, NULL}
	};

	va_start(args, format);
	printed_char = parser(format, fmt, args);
	va_end(args);
	return (printed_char);
}

/**
 * parser - A function that "parses" the formats
 *
 * @format: The actual format to to parsed
 * @fmt: An array of formats that will be considered during
 * parsing
 * @args: The arguments that parser will take
 *
 * Return: The number of characters parsed
 *
 * At first the common variables are declared. This will be used
 * later.
 * If format is null, it should be assumed that it is empty so that it
 * doesn't break the code
 * j is initialized inside the outside loop so that every time the loop
 * runs, it us reset to 0. It is crucial for it to behave this way
 * so that if there are more than one format specifiers they will
 * all be evaluated.
 * We check if the current character iteration of format is equal to
 * t_fmt which was set to '%' (The format specifiers start with %).
 * The code checks if it has looped over all the available options
 * in our fmt[] array. If false then it checks if the next character
 * of format[] is the same as the value specified in fmt[].fmt[0]
 * If it is then call the appropriate function. It breaks so that the loop
 * can begin and look from the start of the fmt[] array instead
 * of continuing with the current position
 * If the code has looped over all the available options, then just
 * print the current character (which should be %).
 *
 * If the current value of format[] isn't equal to % then print
 * the character.
 * Increase the format and return the number of characters
 * parsed
*/

static int parser(const char *format, fmt_specifier fmt[], va_list args)
{
	int i = 0, j, p_char = 0;
	char t_fmt = '%';

	if (format == NULL)
		format = "";

	while (*format)
	{
		j = 0;

		if (format[i] == t_fmt)
		{
			while (fmt[j].fmt != NULL)
			{
				if (fmt[j].fmt[0] == format[i + 1])
				{
					p_char += fmt[j].function(args);
					i++; /* Move forward in the format[] string*/
					break; /* Exit the loop */
				}
				j++;
			}

			if (fmt[j].fmt == NULL && format[i + 1])
			{
				_putchar(format[i]);
				p_char++;
			}

		}
		else
		{
			_putchar(format[i]);
			p_char++;
		}

		format++;
	}

	return (p_char);
}
