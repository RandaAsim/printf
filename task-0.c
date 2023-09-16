#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 *  _printf - Custom printf function
 *  @format: Format stririg
 *  Return: number
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			count += write(1, format, 1);
		}
		else
		{
			format++;

			if (*format == 'c')
			{
				char c = va_arg(args, int);

				count += write(1, &c, 1);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				if (str)
					count += write(1, str, strlen(str));
				else
					count += write(1, "(null)", 6);
			}
			else if (*format == '%')
			{
				count += write(1, "%", 1);
			}
		}
		format++;
	}

	va_end(args);
	return (count);
}

/**
 * _strlen - Calculate the length
 * @str: string
 * Return: Lengt
 */

int _strlen(const char *str)
{
	int len = 0;

	while (str[len])
	{
		len++;
	}
	return (len);
}
