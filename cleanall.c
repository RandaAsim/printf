#include "main.h"

/**
 * cleanall -  clean operations for _printf
 * @args: va_list of arguments
 * @out:  buffer_t struct
 */
void cleanall(va_list args, buffer_r *out)
{
	va_end(args);
	write(1, out->start, out->len);
	free_buffer(out);
}
