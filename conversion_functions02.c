#include "holberton.h"

/**
 * print_x - unsigned int argument is converted to hexa in lowercase
 * @args: pointer to arguments
 * Return: number of digits printed
 */

int print_x(va_list args)
{
	unsigned int n, buff[1024];
	int i = 0, len = 0;
	char p;

	n = va_arg(args, int);
	if (n < 1)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		buff[len] = n % 16;
		n /= 16;
		if (buff[len] > 9)
			buff[i] = buff[len] + 39;
		else
			buff[i] = buff[len];
		i++;
		len++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		p = buff[i] + '0';
		write(1, &p, 1);
	}
	return (len);
}

/**
 * print_X - unsigned int argument is converted to hexa in uppercase
 * @args: pointer to arguments
 * Return: number of digits printed
 */

int print_X(va_list args)
{
	unsigned int n, buff[1024];
	int i = 0, len = 0;
	char p;

	n = va_arg(args, int);
	if (n < 1)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		buff[len] = n % 16;
		n /= 16;
		if (buff[len] > 9)
			buff[i] = buff[len] + 7;
		else
			buff[i] = buff[len];
		i++;
		len++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		p = buff[i] + '0';
		write(1, &p, 1);
	}
	return (len);
}

/**
 * print_r - Prints a string in reverse.
 * @args: Variable string.
 *
 * Return: lenght of the string.
 */
int print_r(va_list args)
{
	char *p, s;
	int i = 0, len = 0;

	p = va_arg(args, char *);
	while (p[i] != '\0')
	{
		len++;
		i++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		s = p[i];
		write(1, &s, 1);
	}
	return (len);
}

/**
 * print_R - print a string to rot13 encode.
 * @args: Pointer to string.
 *
 * Return: lenght of the string encode in rot13
 */
int print_R(va_list args)
{
	int i, j, len = 0;
	char alpha[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
	char ch[] = {"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm"};
	char *p, *m;

	p = va_arg(args, char *);
	for (i = 0; p[i] != '\0'; i++)
		len++;
	m = malloc(sizeof(char) * (len + 1));
	if (!m)
		return ('\0');
	for (i = 0; i <= len; i++)
	{
		m[i] = p[i];
	}
	for (i = 0 ; m[i] != '\0' ; i++)
	{
		for (j = 0 ; alpha[j] != '\0' ; j++)
		{
			if (m[i] == alpha[j])
			{
				m[i] = ch[j];
				break;
			}
		}
	}
	for (i = 0; m[i] != '\0'; i++)
		write(1, &m[i], 1);
	free(m);
	return (len);
}
