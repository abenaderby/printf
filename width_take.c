#include "main.h"

/**
 * get_width - a function that computes the width for printing
 * @format: formatted string
 * @i: iterator
 * @list: arguments
 * Return: the width
 */

int get_width(const char *format, int *i, va_list list)
{
	int ruc_i;
	int width = 0;

	for (ruc_i = *i + 1; format[ruc_i] != '\0'; ruc_i++)
	{
		if (is_digit(format[ruc_i]))
		{
			width *= 10;
			width += format[ruc_i] - '0';
		}
		else if (format[ruc_i] == '*')
		{
			ruc_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = ruc_i - 1;

	return (width);
}
