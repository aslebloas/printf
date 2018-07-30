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
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * print_per - prints a percentage sign
 * @ap: percentage
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
