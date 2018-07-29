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
	char *str;
	va_list ap;

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
			switch (format[i + 1])
			{
			case 'c':
				_putchar(va_arg(ap, int));
				count++;
				break;
			case 's':
				str = va_arg(ap, char *);
				count += print_str(str);
				break;
			case '%':
				_putchar('%');
				count++;
				break;
			default:
			       break;
			}
		i++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
