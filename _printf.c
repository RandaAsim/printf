#include "main.h"

/**
 * _printf - Outputs a formatted string
 * @format: Character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	buffer_r *out;
	va_list args;
	int t;

	if (format == NULL)
		return (-1);
	out = init_buffer();
	if (out == NULL)
		return (-1);

	va_start(args, format);

	t = format_printf(format, args, out);

	return (t);
}
