#include "main.h"

/**
 * print_char - prints a character
 * @list: Arguments list
 * Return: (0) Always
 */

int print_char(va_list list)
{
	write_char(va_arg(list, int));
	return (1);
}

/**
 * print_string - prints a string
 * @list: Arguments list
 * Return: number of characters
 */

int print_string(va_list list)
{
	int j;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (j = 0; str[j] != '\0'; j++)
		write_char(str[j]);
	return (j);
}

/**
 * print_percent - prints the percentage symbol
 * @list: arguments list
 * Return: number of characters
 */

int print_percent(__attribute__((unused))va_list list)
{
	write_char('%');
	return (1);
}

/**
 * print_integer - prints an integer
 * @list: arguments list
 * Return: number of characters
 */

int print_integer(va_list list)
{
	int fig_len;

	fig_len = print_number(list);
	return (fig_len);
}

/**
 * unsigned_integer - function that prints an unsigned integer
 * @list: arguments list
 * Return: numbers
 */

int unsigned_integer(va_list list)
{
	unsigned int fig;

	fig = va_arg(list, unsigned int);

	if (fig == 0)
		return (print_unsgined_number(fig));

	if (fig < 1)
		return (-1);
	return (print_unsgined_number(fig));
}
