#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

/**
 * struct format_func- functions of formating text
 *
 * @c: argument character
 * @f: formating function
 */

typedef struct format_func
{
	char *c;
	int (*f)();
} print_fx;

int _printf(const char *format, ...);
int aux_func(const char *format, va_list args, print_fx *fx);
int print_c(va_list args);
int print_s(va_list args);
int print_i(va_list args);
int print_b(va_list args);
int print_o(va_list args);
int print_X(va_list args);
int print_x(va_list args);
int print_r(va_list args);
int print_R(va_list args);
int _putchar(char c);

#endif
