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
	/* Variables declaration */
	int i = 0, j = 0, k = 0;
	int count = 0, countf = 0;
	p array[] = {
		{"s", print_str},
		{"c", print_char},
		{"%", print_per},
		{"i", print_int},
		{"d", print_int},
		{"u", print_unsigned_int},
		{"o", print_octal_num},
		{"X", print_HEX_num},
		{"x", print_hex_num},
		{NULL, NULL}
	};
	va_list ap;

	/* Return NULL if format is null */
	if (format == NULL)
		return (-1);

	va_start(ap, format);
	while (format[i] != '\0')
	{
		k = i + 1;
		if (format[i] == '%' && format[i + 1] == ' ')
		{
			while (format[k] == ' ')
				k++;
		}
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			/* Loop through array to check if format[i + 1] exists */
			j = 0;
			countf = 0;
			while (j < 10)
			{
				if (!format[k])
				{
					_putchar('%');
					count++;
				}
				if (array[j].format == NULL)
				{
/* printf % itself when no format matching */
					_putchar('%');
					count++;
				}
				else if (format[k] == *(array[j].format))
				{
					/* Call the func corresponding to char */
					countf = array[j].f(ap);
					count += countf;
					i++;
					j = 10;
				}
				j++;
			}
		}
		i++;
	}
	va_end(ap);
	return (count);
}
