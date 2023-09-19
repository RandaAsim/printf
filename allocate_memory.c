#include "main.h"

unsigned int _memcpy(buffer_r *out, const char *src, unsigned int n);
void free_buffer(buffer_r *out);
buffer_r *init_buffer(void);

/**
 * _memcpy - copies n bytes from memory area
 * @out: buffer_t struct
 * @src: pointer to the memory area
 * @n: number of bytes
 * Return: n
*/
unsigned int _memcpy(buffer_r *out, const char *src, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
	{
		*(out->buffer) = *(src + index);
		(out->len)++;

		if (out->len == 1024)
		{
			write(1, out->start, out->len);
			out->buffer = out->start;
			out->len = 0;
		}

		else
			(out->buffer)++;
	}

	return (n);
}

/**
 * free_buffer - Frees a buffer_r struct
 * @out: The buffer_r struct
*/

void free_buffer(buffer_r *out)
{
	free(out->start);
	free(out);
}

/**
 * init_buffer - Initializes a variable
 * Return: pointer to initialized buffer_r
*/

buffer_r *init_buffer(void)
{
	buffer_r *out;

	out = malloc(sizeof(buffer_r));
	if (out == NULL)
		return (NULL);

	out->buffer = malloc(sizeof(char) * 1024);
	if (out->buffer == NULL)
	{
		free(out);
		return (NULL);
	}

	out->start = out->buffer;
	out->len = 0;

	return (out);
}
