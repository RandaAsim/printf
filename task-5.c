#include "main.h"

/**
 * print_x - Converts an unsigned int argument to hex
 * @args: va_list pointing to the argument
 * @out: buffer_r
 * @flags: Flag modifiers
 * @w: A width modifier
 * @prec: A precision modifier
 * @len: A length modifier
 * Return: number of bytes
*/

unsigned int print_x(va_list args, buffer_r *out,
		unsigned char flags, int w, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int t = 0;
	char *lead = "0x";

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		t += _memcpy(out, lead, 2);

	if (!(num == 0 && prec == 0))
		t += convert_ubase(out, num, "0123456789abcdef",
				flags, w, prec);

	t += print_neg_width(out, t, flags, w);

	return (t);
}

/**
 * print_X - Converts an unsigned int argument to hex
 * @args: va_list pointing to the argument
 * @flags: Flag modifiers
 * @w: width modifier
 * @prec: precision modifier
 * @len: length modifier
 * @out: buffer_t struct
 * Return: number of bytes/
*/

unsigned int print_X(va_list args, buffer_r *out,
		unsigned char flags, int w, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int t = 0;
	char *lead = "0X";

	if (len == LONG)
		num = va_arg(args, unsigned long);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		t += _memcpy(out, lead, 2);

	if (!(num == 0 && prec == 0))
		t += convert_ubase(out, num, "0123456789ABCDEF",
				flags, wid, prec);

	t += print_neg_width(out, t, flags, w);

	return (t);
}
