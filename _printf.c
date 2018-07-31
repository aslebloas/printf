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
	int i = 0, j = 0;
	int count = 0, countf = 0;
	p array[] = {
		{'s', print_str},
		{'c', print_char},
		{'%', print_per},
		{'i', print_int},
		{'d', print_int},
	};
	va_list ap;

	/* Return NULL if format is null */
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
			/* Loop through array to check if format[i + 1] exists */
			j = 0;
			while (j < 5)
			{
				if (format[i + 1] == array[j].format)
				{
					countf = array[j].f(ap);

					if (countf == -1)
					{
						va_end(ap);

						return (-1);
					}
					count += countf;
					i++;
					j = 5;
				}
				j++;
			}

			/* if format[i + 1] is not in array, print it */
			if (countf == 0)
				count += print_per();
		}
		i++;
	}
	va_end(ap);
	return (count);
}