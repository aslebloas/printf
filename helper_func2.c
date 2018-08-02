#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include "holberton.h"

/**
 * print_unsigned_int - prints a number as unsigned int type
 * @ap: characters of numbers
 *
 * Return: number of character(s) are printed
 */
int print_unsigned_int(va_list ap)
{
	unsigned int max_digit_int = 1000000000;
	int temp_num = 0;
	unsigned int num = va_arg(ap, unsigned int);
	int count = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	while (num / max_digit_int == 0)
		max_digit_int /= 10;
	while (max_digit_int > 0)
	{
		temp_num = num / max_digit_int;
		num = num % max_digit_int;
		_putchar(temp_num + '0');
		count++;
		max_digit_int /= 10;
	}
	return (count);
}

/**
 * print_octal_num - prints a octal numbers
 * @ap: characters of numbers
 *
 * Return: number of character(s) are printed
 */
int print_octal_num(va_list ap)
{
	int temp_num = 0, i = 0;
	unsigned int num = va_arg(ap, unsigned int);
	int count = 0;
	char *str_num;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	str_num = malloc(sizeof(char) * 11);
	if (str_num == NULL)
		return (-1);
	while (num > 0)
	{
		temp_num = num % 8;
		str_num[i++] = temp_num + '0';
		num = num / 8;
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

/**
 * print_HEX_num - prints a hex numbers. Letter will be CAP
 * @ap: characters of numbers
 *
 * Return: number of character(s) are printed
 */
int print_HEX_num(va_list ap)
{
	int temp_num = 0, i = 0;
	unsigned int num = va_arg(ap, unsigned int);
	int count = 0;
	char *str_num;
	char letter_array[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	str_num = malloc(sizeof(char) * 10);
	if (str_num == NULL)
		return (-1);
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

/**
 * print_hex_num - prints a hex numbers. Letter will be CAP
 * @ap: characters of numbers
 *
 * Return: number of character(s) are printed
 */
int print_hex_num(va_list ap)
{
	int temp_num = 0, i = 0;
	unsigned int num = va_arg(ap, unsigned int);
	int count = 0;
	char *str_num;
	char letter_array[6] = {'a', 'b', 'c', 'd', 'e', 'f'};

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	str_num = malloc(sizeof(char) * 10);
	if (str_num == NULL)
		return (-1);
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

/**
 * print_binary - prints unsigned int arg in binary
 * @ap: argument
 *
 * Return: number of character printed
 */
int print_binary(va_list ap)
{
	long num;
	unsigned int i, count = 0, countd = 0;
	unsigned int ui = UINT_MAX;

	num = va_arg(ap, unsigned int);

	/* if n is 0 or 1 print 0 or 1 */
	if (num < 2)
	{
		_putchar(num + '0');
		return (count + 1);
	}

	/* if num is the max, print 32 times 1 */
	i = 0;
	while (ui > 0)
	{
		ui /= 10;
		countd++;
	}
	countd--;
	if (num == ui)
	{
		while (i < countd)
		{
			_putchar('1');
			i++;
			count++;
		}
		return (count);
	}
	ui = (UINT_MAX / 2) + 1;
	/* if n is greater than 1 find the max number of binary digits */
	while (num < ui)
	{
		ui /= 2;
	}

	/* print num to binary */
	while (ui != 0)
	{
		if (num >= ui)
		{
			_putchar('1');
			num -= ui;
			count++;
		}
		else
		{
			_putchar('0');
			count++;
		}
		ui /= 2;
	}

	return (count);
}
