#include "main.h"


/**
 *  h_flags – Matches
 *  @flag: pointer
 *  @index: An index counter for format string
 *  Return: corresponding value or 0
 */

unsigned char h_flags(const char *flag, char *index)
{
	int i, j;
	unsigned char t = 0;
	flag_t flags[] = {
		{'+', PLUS},
		{' ', SPACE},
		{'#', HASH},
		{'0', ZERO},
		{'-', NEG},
		{0, 0}
	};

	for (i = 0; flag[i]; i++)
	{
		for (j = 0; flags[j].flag != 0; j++)
		{
			if (flag[i] == flags[j].flag)
			{
				(*index)++;
				if (t == 0)
					t = flags[j].value;
				else
					t |= flags[j].value;
				break;
			}
		}
		if (flags[j].value == 0)
			break;
	}

	return (t);
}

/**
 * h_length - Matches length
 * @modifier: pointer to length modifier
 * @index: An index counter for format string
 * Return: corresponding value or 0
 */

unsigned char h_length(const char *modifier, char *index)
{
	if (*modifier == 'h')
	{
		(*index)++;
		return (SHORT);
	}

	else if (*modifier == 'l')
	{
		(*index)++;
		return (LONG);
	}

	return (0);
}

/**
 * h_width - Matches a width
 * @args: va_list of arguments
 * @modifier: A pointer to width modifier
 * @index: An index for format string
 * Return: its value or 0
 */

int h_width(va_list args, const char *modifier, char *index)
{
	int value = 0;

	while ((*modifier >= '0' && *modifier <= '9') || (*modifier == '*'))
	{
		(*index)++;

		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}

		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}

	return (value);
}

/**
 * h_precision - Matches a precision
 * @args: va_list of arguments
 * @modifier: A pointer to precision modifier
 * @index: An index counter for format string
 * Return: its value
 * If the precision modifier is empty, zero, or negative – 0
 * Otherwise - -1
 */

int h_precision(va_list args, const char *modifier, char *index)
{
	int value = 0;

	if (*modifier != '.')
		return (-1);

	modifier++;
	(*index)++;

	if ((*modifier <= '0' || *modifier > '9') &&
			*modifier != '*')
	{
		if (*modifier == '0')
			(*index)++;
		return (0);
	}

	while ((*modifier >= '0' && *modifier <= '9') ||
			(*modifier == '*'))
	{
		(*index)++;

		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}

		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}

	return (value);
}

/**
 * h_specifiers - Matches a conversion specifie
 * @specifier: pointer to specifier
 * Return: If it is matched  a pointer to the function
 * Otherwise  NULL
 */
unsigned int (*h_specifiers(const char *specifier))(va_list, buffer_r *,
		unsigned char, int, int, unsigned char)
{
	int i;
	converter_t converters[] = {
		{'c', print_c},
		{'s', print_s},
		{'d', print_di},
		{'i', print_di},
		{'%', print_percent},
		{'b', print_b},
		{'u', print_u},
		{'o', print_o},
		{'x', print_x},
		{'X', print_X},
		{'S', print_S},
		{'p', print_p},
		{'r', print_r},
		{'R', print_R},
		{0, NULL}
	};

	for (i = 0; converters[i].func; i++)
	{
		if (converters[i].specifier == *specifier)
			return (converters[i].func);
	}

	return (NULL);
}
