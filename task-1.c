#include "main.h"

/**
 * print_s - converts an argument to a string
 * @args: va_list pointing
 * @out: buffer_t struct
 * @flags: Flag modifiers
 * @w: A width modifier
 * @prec: precision modifier
 * @len: A length modifier
 * Return: number of bytes
*/

unsigned int print_s(va_list args, buffer_r *out,
		unsigned char flags, int w, int prec, unsigned char len)
{
	char *str, *null = "(null)";
	int size;
	unsigned int t = 0;

	(void)flags;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(out, null, 6));

	for (size = 0; *(str + size);)
		size++;

	t += print_string_width(out, flags, w, prec, size);

	prec = (prec == -1) ? size : prec;
	while (*str != '\0' && prec > 0)
	{
		t += _memcpy(out, str, 1);
		prec--;
		str++;
	}

	t += print_neg_width(out, t, flags, w);

	return (t);
}

/**
 * print_S - converts an argument to a string
 * Description: Non-printable char (ASCII values < 32 or >= 127) value in hex
 * @args: va_list pointing
 * @out: buffer_t struct
 * @flags: Flag modifiers
 * @wid: A width modifier
 * @prec: precision modifier
 * @len: A length modifier
 * Return: number of bytes
*/

unsigned int print_S(va_list args, buffer_r *out,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *str, *null = "(null)", *hex = "\\x", zero = '0';
	int size, index;
	unsigned int t = 0;

	(void)len;
	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(out, null, 6));

	for (size = 0; str[size];)
		size++;

	t += print_string_width(out, flags, w, prec, size);

	prec = (prec == -1) ? size : prec;
	for (index = 0; *(str + index) != '\0' && index < prec; index++)
	{
		if (*(str + index) < 32 || *(str + index) >= 127)
		{
			t += _memcpy(out, hex, 2);
			if (*(str + index) < 16)
				t += _memcpy(out, &zero, 1);
			t += convert_ubase(out, *(str + index),
					"0123456789ABCDEF", flags, 0, 0);
			continue;
		}
		t += _memcpy(out, (str + index), 1);
	}

	t += print_neg_width(out, t, flags, w);

	return (t);
}

/**
 * print_r - reverses a string
 * @args: va_list pointing
 * @out: buffer_t struct
 * @flags: Flag modifiers
 * @w: A width modifier
 * @prec: precision modifier
 * @len: A length modifier
 * Return: number of bytes
*/

unsigned int print_r(va_list args, buffer_r *out,
		unsigned char flags, int w, int prec, unsigned char len)
{
	char *str, *null = "(null)";
	int size, end, i;
	unsigned int t = 0;

	(void)flags;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(out, null, 6));

	for (size = 0; *(str + size);)
		size++;

	t += print_string_width(out, flags, wid, prec, size);

	end = size - 1;
	prec = (prec == -1) ? size : prec;
	for (i = 0; end >= 0 && i < prec; i++)
	{
		t += _memcpy(out, (str + end), 1);
		end--;
	}

	t += print_neg_width(out, t, flags, w);

	return (t);
}

/**
 * print_R - Converts a string to ROT13
 * @args: va_list pointing
 * @out: buffer_t struct
 * @flags: Flag modifiers
 * @w: A width modifier
 * @prec: precision modifier
 * @len: A length modifier
 * Return: number of bytes
*/

unsigned int print_R(va_list args, buffer_r *out,
		unsigned char flags, int w, int prec, unsigned char len)
{
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str, *null = "(null)";
	int i, j, size;
	unsigned int t = 0;

	(void)flags;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(out, null, 6));

	for (size = 0; *(str + size);)
		size++;

	t += print_string_width(out, flags, w, prec, size);

	prec = (prec == -1) ? size : prec;
	for (i = 0; *(str + i) != '\0' && i < prec; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (*(str + i) == *(alpha + j))
			{
				t += _memcpy(out, (rot13 + j), 1);
				break;
			}
		}
		if (j == 52)
			t += _memcpy(out, (str + i), 1);
	}

	t += print_neg_width(out, t, flags, w);

	return (t);
}
