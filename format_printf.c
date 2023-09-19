/**
 * format_printf - the format string for _printf
 * Description: function int
 * @format: charcter
 * @out: buffer
 * @args: va_list of arguments
 * Return: number
 */
int format_printf(const char *format, va_list args, buffer_r *out)
{
	int i, w, prec, t = 0;
	char tmp;
	unsigned char flags, len;
	unsigned int (*f)(va_list, buffer_r *,
			unsigned char, int, int, unsigned char);

	for (i = 0; *(format + i); i++)
	{
		len = 0;
		if (*(format + i) == '%')
		{
			tmp = 0;
			flags = h_flags(format + i + 1, &tmp);
			w = h_width(args, format + i + tmp + 1, &tmp);
			prec = h_precision(args, format + i + tmp + 1,
					&tmp);
			len = h_length(format + i + tmp + 1, &tmp);

			f = h_specifiers(format + i + tmp + 1);
			if (f != NULL)
			{
				i += tmp + 1;
				t += f(args, out, flags, w, prec, len);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				t = -1;
				break;
			}
		}
		t += _memcpy(out, (format + i), 1);
		i += (len != 0) ? 1 : 0;
	}
	cleanall(args, out);
	return (t);
}
