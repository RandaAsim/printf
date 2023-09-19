#include "main.h"

unsigned int convert_sbase(buffer_r *out, long int num, char *base,
		unsigned char flags, int w, int prec);
unsigned int convert_ubase(buffer_r *out,
		unsigned long int num, char *base,
		unsigned char flags, int w, int prec);

/**
 * convert_sbase - Converts a signed long
 * @out: buffer_t struct
 * @num: signed long
 * @base: pointer string
 * @flags: Flag modifiers
 * @w: width modifier
 * @prec: precision modifier
 * Return: The number of bytes stored to the buffer
*/

unsigned int convert_sbase(buffer_r *out, long int num, char *base,
		unsigned char flags, int w, int prec)
{
	int size;
	char digit, pad = '0';
	unsigned int t = 1;

	for (size = 0; *(base + size);)
		size++;

	if (num >= size || num <= -size)
		t += convert_sbase(out, num / size, base,
				flags, w - 1, prec - 1);

	else
	{
		for (; prec > 1; prec--, w--)
			t += _memcpy(out, &pad, 1);

		if (NEG_FLAG == 0)
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; w > 1; w--)
				t += _memcpy(out, &pad, 1);
		}
	}

	digit = base[(num < 0 ? -1 : 1) * (num % size)];
	_memcpy(out, &digit, 1);

	return (t);
}

/**
 * convert_ubase - Converts an unsigned long
 * @out: buffer_t struct
 * @num: An unsigned long
 * @base: pointer to a string
 * @flags: Flag modifiers
 * @w: width modifier
 * @prec: precision modifier
 * Return: The number of byte
*/

unsigned int convert_ubase(buffer_r *out, unsigned long int num, char *base,
		unsigned char flags, int w, int prec)
{
	unsigned int size, t = 1;
	char digit, pad = '0', *lead = "0x";

	for (size = 0; *(base + size);)
		size++;
	if (num >= size)
		t += convert_ubase(out, num / size, base,
				flags, w - 1, prec - 1);
	else
	{
		if (((flags >> 5) & 1) == 1)
		{
			w -= 2;
			prec -= 2;
		}
		for (; prec > 1; prec--, w--)
			t += _memcpy(out, &pad, 1);
		if (NEG_FLAG == 0)
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; w > 1; w--)
				t += _memcpy(out, &pad, 1);
		}
		if (((flags >> 5) & 1) == 1)
			t += _memcpy(out, lead, 2);
	}
	digit = base[(num % size)];
	_memcpy(out, &digit, 1);

	return (t);
}
