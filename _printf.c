#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: A character string
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	int chars_print;
	conver_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"r", _print_rev},
		{"R", rot13},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hexa},
		{"X", print_hexxa},
		{NULL, NULL}
	};
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);
	/*Calling parser function*/
	chars_print = parser(format, f_list, list);
	va_end(list);
	return (chars_print);
}
