#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "holberton.h"

/**
 * _printf - format and print data in standard output
 * @format: constant string argument
 * @..." elipses
 * Return: number of char printed or -1 if fails.
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0;
	int count = 0;
	p array[] = {
		{'s', print_str},
		{'c', print_char},
		{'%', print_per},
		{'i', print_int},
		{'d', print_int},
	};
	va_list ap;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			j = 0;
			while (j < 5)
			{
				if (format[i + 1] == array[j].format)
				{
					count += array[j].f(ap);
					i++;
					j = 5;
				}
				j++;
			}
		}
		i++;
	}
	va_end(ap);
	return (count);
}
