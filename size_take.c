#include "main.h"

/**
 * get_size - a function that computes the size of the argument
 * @format: formatted string
 * @i: arguments to be printed
 * Return: Precision.
 */

int get_size(const char *format, int *i)
{
	int ruc_i = *i + 1;
	int size = 0;

	if (format[ruc_i] == 'l')
		size = S_LONG;
	else if (format[ruc_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = ruc_i - 1;
	else
		*i = ruc_i;

	return (size);
}
