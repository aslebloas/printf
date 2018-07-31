#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - prints a string
 * @ap: string argument
 *
 * Return: number of character(s) are printed
 */
int print_str(va_list ap)
{
	int i = 0;
	char *str;

	str = va_arg(ap, char *);
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
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * print_per - prints a percentage sign
 *
 * Return: number of character(s) are printed
 */
int print_per(void)
{
	_putchar('%');
	return (1);
}

/**
 * print_char - prints a character
 * @ap: character
 *
 * Return: number of character(s) are printed
 */
int print_char(va_list ap)
{
	char c = va_arg(ap, int);

	_putchar(c);
	return (1);
}

/**
 * print_int - prints a number as int type
 * @ap: characters of numbers as int type
 *
 * Return: number of character(s) are printed
 */
int print_int(va_list ap)
{
	int max_digit_int = 1000000000;
	int temp_num = 0;
	int num = va_arg(ap, int);
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
		if (temp_num < 0)
		{
			_putchar('-');
			count++;
			temp_num = -temp_num;
			num = -num;
		}
		_putchar(temp_num + '0');
		count++;
		max_digit_int /= 10;
	}
	return (count);
}
