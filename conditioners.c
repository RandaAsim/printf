#include "main.h"

unsigned int print_width(buffer_r *out, unsigned int printed,
		unsigned char flags, int w);
unsigned int print_string_width(buffer_r *out,
		unsigned char flags, int w, int prec, int size);
unsigned int print_neg_width(buffer_r *out, unsigned int printed,
		unsigned char flags, int w);

/**
 * print_width - width modifier
 * @out: buffer_r struct
 * @printed: number
 * @flags: Flag modifiers
 * @w:  width modifier
 * Return: The number of bytes
*/

unsigned int print_width(buffer_r *out, unsigned int printed,
		unsigned char flags, int w)
{
	unsigned int t = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		for (w -= printed; w > 0;)
			r += _memcpy(out, &width, 1);
	}

	return (t);
}

/**
 * print_string_width - width modifier
 * @out: buffer_t struct
 * @flags: Flag modifiers
 * @w: width modifier
 * @prec: precision modifier
 * @size: size of string
 * Return: The number of bytes
*/

unsigned int print_string_width(buffer_r *out,
		unsigned char flags, int w, int prec, int size)
{
	unsigned int t = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		wid -= (prec == -1) ? size : prec;
		for (; w > 0; w--)
			t += _memcpy(out, &width, 1);
	}

	return (t);
}

/**
 * print_neg_width - buffer for a '-' flag
 * @out: buffer_t struct
 * @printed: number of bytes
 * @flags: Flag modifiers
 * @w: width modifier
 * Return: The number of bytes
*/

unsigned int print_neg_width(buffer_r *out, unsigned int printed,
		unsigned char flags, int w)
{
	unsigned int t = 0;
	char width = ' ';

	if (NEG_FLAG == 1)
	{
		for (w -= printed; w > 0; w--)
			t += _memcpy(out, &width, 1);
	}
	return (t);
}
