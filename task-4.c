#include "main.h"

/**
 * print_di - Converts an argument
 * @args: va_list pointing to the argument
 * @out: A buffer_t struct
 * @flags: Flag modifiers
 * @w: width modifie
 * @prec: precision modifier
 * @len: length modifier
 * Return: number of byte
*/

unsigned int print_di(va_list args, buffer_r *out,
		unsigned char flags, int w, int prec, unsigned char len)
{
	long int d, copy;
	unsigned int t = 0, count = 0;
	char pad, space = ' ', neg = '-', plus = '+';

	if (len == LONG)
		d = va_arg(args, long int);
	else
		d = va_arg(args, int);
	if (len == SHORT)
		d = (short)d;
	if (SPACE_FLAG == 1 && d >= 0)
		t += _memcpy(out, &space, 1);
	if (prec <= 0 && NEG_FLAG == 0)
	{
		if (d == LONG_MIN)
			count += 19;
		else
		{
			for (copy = (d < 0) ? -d : d; copy > 0; copy /= 10)
				count++;
		}
		count += (d == 0) ? 1 : 0;
		count += (d < 0) ? 1 : 0;
		count += (PLUS_FLAG == 1 && d >= 0) ? 1 : 0;
		count += (SPACE_FLAG == 1 && d >= 0) ? 1 : 0;
		if (ZERO_FLAG == 1 && PLUS_FLAG == 1 && d >= 0)
			t += _memcpy(out, &plus, 1);
		if (ZERO_FLAG == 1 && d < 0)
			t += _memcpy(out, &neg, 1);
		pad = (ZERO_FLAG == 1) ? '0' : ' ';
		for (w -= count; w > 0; w--)
			t += _memcpy(out, &pad, 1);
	}
	if (ZERO_FLAG == 0 && d < 0)
		t += _memcpy(out, &neg, 1);
	if (ZERO_FLAG == 0 && (PLUS_FLAG == 1 && d >= 0))
		t += _memcpy(out, &plus, 1);
	if (!(d == 0 && prec == 0))
		t += convert_sbase(out, d, "0123456789",
				flags, 0, prec);
	t += print_neg_width(out, t, flags, w);
	return (t);
}

/**
 * print_b - Converts an unsigned int
 * @args: va_list pointing
 * @out: buffer_t stru
 * @flags: Flag modifiers
 * @w: A width modifier
 * @prec: precision modifier
 * @len: length modifier
 * Return: number of byte
*/

unsigned int print_b(va_list args, buffer_r *out,
		unsigned char flags, int w, int prec, unsigned char len)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	(void)len;

	return (convert_ubase(out, num, "01", flags, w, prec));
}

/**
 * printt_o - Converts an unsigned int to octal
 * @args: va_list pointing
 * @out: buffer_t struct
 * @flags: Flag modifiers
 * @w: A width modifier
 * @prec: precision modifier
 * @len: A length modifier
 * Return: number of bytes
*/

unsigned int print_o(va_list args, buffer_r *out,
		unsigned char flags, int w, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int t = 0;
	char zero = '0';

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		t += _memcpy(out, &zero, 1);

	if (!(num == 0 && prec == 0))
		t += convert_ubase(out, num, "01234567",
				flags, w, prec);


	t += print_neg_width(out, t, flags, w);

	return (t);
}

/**
 * print_u - converts an unsigned int argument to decimal
 * @args: va_list pointing
 * @out: buffer_t struct
 * @flags: Flag modifiers
 * @w: A width modifier
 * @prec: precision modifier
 * @len: A length modifier
 * Return: number of bytes
*/

unsigned int print_u(va_list args, buffer_r *out,
		unsigned char flags, int w, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int t = 0;

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (!(num == 0 && prec == 0))
		t += convert_ubase(out, num, "0123456789",
				flags, w, prec);

	t += print_neg_width(out, t, flags, w);


	return (t);
}
