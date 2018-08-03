#include <stdlib.h>
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
		if (str[i] < 32 || str[i] == 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			if (str[i] < 16)
			{
				_putchar('0');
			}
			_printf("%X", str[i]);
			count += 2;
		}
		else
		{
			_putchar(str[i]);
			count++;
		}
		i++;
	}
	return (count);
}

/**
 * print_add - prints a address
 * @ap: characters
 * Return: number of character(s) are printed
 */

int print_add(va_list ap)
{
	int temp_num = 0, i = 0;
	unsigned long num = va_arg(ap, long);
	int count = 0;
	char *str_num;
	char letter_array[6] = {'a', 'b', 'c', 'd', 'e', 'f'};

	if (!num)
	{
		_putchar('(');
		_putchar('n');
		_putchar('i');
		_putchar('l');
		_putchar(')');
		return (5);
	}
	str_num = malloc(sizeof(char) * 16);
	if (str_num == NULL)
		return (0);
	_putchar('0');
	_putchar('x');
	count = 2;
	while (num > 0)
	{
		temp_num = num % 16;
		if (temp_num < 10)
			str_num[i++] = temp_num + '0';
		else
		{
			temp_num = temp_num % 10;
			str_num[i++] = letter_array[temp_num];
		}
		num = num / 16;
	}
	i--;
	while (i >= 0)
	{
		_putchar(str_num[i--]);
		count++;
	}
	free(str_num);
	return (count);
}
