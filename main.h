#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>


#define SHORT 1
#define LONG 2

#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)

/**
 * struct buffer_s - defining a buffer struct
 * @buffer: pointer character array
 * @start: pointe string
 * @len: length string stored in buffer
 */
typedef struct buffer_s
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_t;

/**
 * struct print_s - defining a converter struct
 * @specifier: character
 * @func: pointer specifier
 */
typedef struct print_s
{
	unsigned char specifier;
	unsigned int (*func)(va_list, buffer_r *,
			unsigned char, int, int, unsigned char);
} converter_t;

/**
 * struct flag_s - defining a flags struct
 * @flag: character representing a flag
 * @value: value of the flag
*/
typedef struct flag_s
{
	unsigned char flag;
	unsigned char value;
} flag_t;

int _printf(const char *format, ...);

buffer_r *init_buffer(void);
void free_buffer(buffer_r *out);
unsigned int _memcpy(buffer_r *out, const char *src, unsigned int n);
unsigned int convert_sbase(buffer_r *out, long int num, char *base,
		unsigned char flags, int w, int prec);
unsigned int convert_ubase(buffer_r *out, unsigned long int num, char *base,
		unsigned char flags, int w, int prec);

unsigned int print_c(va_list args, buffer_r *out,
		unsigned char flags, int w, int prec, unsigned char len);
unsigned int print_string(va_list args, buffer_r *out,
		unsigned char flags, int w, int prec, unsigned char len);
unsigned int print_di(va_list args, buffer_r *out,
		unsigned char flags, int w, int prec, unsigned char len);
unsigned int print_percent(va_list args, buffer_r *out,
		unsigned char flags, int w, int prec, unsigned char len);
unsigned int print_b(va_list args, buffer_r *out,
		unsigned char flags, int w, int prec, unsigned char len);
unsigned int print_u(va_list args, buffer_r *out,
		unsigned char flags, int w, int prec, unsigned char len);
unsigned int print_o(va_list args, buffer_r *out,
		unsigned char flags, int w, int prec, unsigned char len);
unsigned int print_x((va_list args, buffer_r *out,
			unsigned char flags, int w, int prec, unsigned char len);
		unsigned int print_X(va_list args, buffer_r *out,
			unsigned char flags, int w, int prec, unsigned char len);
		unsigned int print_S(va_list args, buffer_r *out,
			unsigned char flags, int w, int prec, unsigned char len);
		unsigned int print_p(va_list args, buffer_r *out,
			unsigned char flags, int w, int prec, unsigned char len);
		unsigned int print_r(va_list args, buffer_r *out,
			unsigned char flags, int w, int prec, unsigned char len);
		unsigned int printt_R(va_list args, buffer_r *out,
			unsigned char flags, int w, int prec, unsigned char len);

		unsigned int print_width(buffer_r *out, unsigned int printed,
			unsigned char flags, int w);
		unsigned int print_string_width(buffer_r *out,
			unsigned char flags, int w, int prec, int size);
		unsigned int print_neg_width(buffer_r *out, unsigned int printed,
			unsigned char flags, int w);

		unsigned char h_flags(const char *flags, char *index);
unsigned char h_length(const char *modifier, char *index);
int h_width(va_list args, const char *modifier, char *index);
int h_precision(va_list args, const char *modifier, char *index);
unsigned int (*h_specifiers(const char *specifier))(va_list, buffer_r *,
		unsigned char, int, int, unsigned char);

#endif/*MAIN.H*/
