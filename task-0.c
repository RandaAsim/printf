#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: format string
 * Return: number of chat
 */
int _printf(const char *format, ...)
{
	print_str(va_list args);
	va_list args;
	int printed_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	printed_chars = parse_format(format, args);
	va_end(args);

	return (printed_chars);
}

/**
 * parse_format - Parse format string
 * @format: format string
 * @args: arguments
 * Return: number of char
 */

int parse_format(const char *format, va_list args)
{
	int i = 0, printed_chars = 0;

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			printed_chars += _putchar(format[i]);
			i++;
			continue;
		}

		i++;

		if (format[i] == '\0')
			return (-1);

		switch (format[i])
		{
			case 'c':
				printed_chars += print_char(va_arg(args, int));
				break;
			case 's':
				printed_chars += print_str(va_arg(args, char *));
				break;
			case '%':
				printed_chars += _putchar('%');
				break;
			default:
				printed_chars += _putchar('%');
				printed_chars += _putchar(format[i]);
		}

		i++;
	}

	return (printed_chars);
}

/**
 * print_char - Print a character to stdout
 * @c: char
 * Return: 1
 */
int print_char(char c)
{
	return (_putchar(c));
}

/**
 * print_str - Print a string
 * @str: string
 * Return: number
 */

int print_str(char *str)
{
	int i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}
