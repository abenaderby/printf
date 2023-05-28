#include "main.h"

/**
 * _print_number - a function that prints a number
 * @args: variable for arguments
 * Return: (0) Always
 */

int _print_number(va_list args)
{
	int i;
	int sub;
	int length;
	unsigned int fig;

	i  = va_arg(args, int);
	sub = 1;
	length = 0;

	if (i < 0)
	{
		length += write_char('-');
		fig = i * -1;
	}
	else
		fig = i;

	for (; fig / sub > 9; )
		sub *= 10;

	for (; sub != 0; )
	{
		length += write_char('0' + fig / sub);
		fig %= sub;
		sub /= 10;
	}

	return (length);
}

/**
 * _print_unsgined_number - a function that prints an unsigned number
 * @k: the integer
 * Return: numbers printed
 */

int _print_unsgined_number(unsigned int k)
{
	int sub;
	int length;
	unsigned int fig;

	sub = 1, length = 0;

	fig = k;

	for (; fig / sub > 9; )
		sub *= 10;

	for (; sub != 0; )
	{
		length += write_char('0' + fig / sub);
		fig %= sub;
		sub /= 10;
	}

	return (length);
}
