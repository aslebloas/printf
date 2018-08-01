#ifndef _HOLBERTON_H
#define _HOLBERTON_H

int _putchar(char c);
int print_str(va_list ap);
int print_per(void);
int print_char(va_list ap);
int print_int(va_list ap);
int print_unsigned_int(va_list ap);
int print_octal_num(va_list ap);
int print_HEX_num(va_list ap);
int print_hex_num(va_list ap);
int print_binary(va_list ap);
int _printf(const char *format, ...);
int print_add(va_list ap);
int print_HEX_ASCII_num(va_list ap);

/**
 * struct _printf_ - Store data of format and function pointer
 * @format: format will be printed
 * @f: function pointer
 *
 * Description: No
 */
typedef struct _printf_
{
	char *format;
	int (*f)();
} p;

#endif /* _HOLBERTON_H */
