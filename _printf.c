#include "holberton.h"

/**
 * _printf - prints formated text
 *
 * @format: text to be formated
 * Return: Lenght of the text
 */

int _printf(const char *format, ...)
{
	va_list args;
	int size = 0;
	print_fx fx[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_i},
		{"u", print_i},
		{"b", print_b},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{"r", print_r},
		{"R", print_R},
		{NULL, NULL}
	};
	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}
	size = aux_func(format, args, fx);
	va_end(args);
	return (size);
}
