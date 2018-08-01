#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "holberton.h"

/**
 * print_HEX_ASCII_num - prints a sring with converting non_printable char
 * @ap: characters of numbers
 *
 * Return: number of character(s) are printed
 */

int print_HEX_ASCII_num(va_list ap)
{
	int i = 0;
	int count = 0;

	char *str = va_arg(ap, char *);
	if (!str)
        {
                _putchar('(');
                _putchar('n');
                _putchar('u');
                _putchar('l');
                _putchar('l');
                _putchar(')');
                return (6);
        }
	while (str[i] != '\0')
	{
		if (str[i] >= 32)
		{
			_putchar(str[i]);
			count++;
		}
		else
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			if (str[i] < 16)
			{
				_putchar('0');
				count++;
			}
			_printf("%X",str[i]);
			count++;
		}
		i++;
	}
	return (count);
}
