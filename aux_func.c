#include "holberton.h"

/**
 * aux_func - selects the function to format the text
 *
 * @format: text to be formated
 * @args: list of arguments
 * @fx: list of functions to format text
 * Return: size of printed text
 */

int aux_func(const char *format, va_list args, print_fx *fx)
{
	int i = 0, j, size = 0, test = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
			while (fx[j].c != NULL)
			{
				if (format[i + 1] == '%')
				{
					write(1, &format[i], 1);
					size++;
					i++;
					test = 1;
					break;
				}
				else if (fx[j].c[0] == format[i + 1])
				{
					size += fx[j].f(args);
					i++;
					test = 1;
					break;
				}
				j++;
			}
			if (test == 0)
			{
				write(1, &format[i], 1);
				size++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			size++;
		}
		i++;
	}
	return (size);
}
