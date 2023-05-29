#include "main.h"

/**
 * get_precision - a function that computes the precision for printing
 * @format: formatted string
 * @i: iterator
 * @list: arguments list
 * Return: 0
 */
int get_precision(const char *format, int *i, va_list list)
{
	int ruc_i = *i + 1;
	int precision = -1;

	if (format[ruc_i] != '.')
		return (precision);

	precision = 0;

	for (ruc_i += 1; format[ruc_i] != '\0'; ruc_i++)
	{
		if (is_digit(format[ruc_i]))
		{
			precision *= 10;
			precision += format[ruc_i] - '0';
		}
		else if (format[ruc_i] == '*')
		{
			ruc_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = ruc_i - 1;

	return (precision);
}
