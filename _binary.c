#include "main.h"
#include <stdio.h>

int _hex_check(int, char);

/**
 * print_binary - argument converted to binary
 * @list: Arguments list
 * Return: The length of the number
 */
int print_binary(va_list list)
{
	unsigned int fig;
	int j, length;
	char *str;
	char *rev_str;

	fig = va_arg(list, unsigned int);
	if (fig == 0)
		return (write_char('0'));
	if (fig < 1)
		return (-1);
	len = base_length(fig, 2);
	str = malloc(sizeof(char) * length + 1);
	if (str == NULL)
		return (-1);

	for (j = 0; fig > 0; j++)
	{
		if (fig % 2 == 0)
			str[j] = '0';
		else
			str[j] = '1';
		fig = fig / 2;
	}
	str[j] = '\0';
	rev_str = rev_string(str);
	if (rev_str == NULL)
		return (-1);
	write_base(rev_str);
	free(str);
	free(rev_str);
	return (length);
}

/**
 * print_octal - prints a number to octal base
 * @list: list of arguments
 * Return: (0) Always
 */

int print_octal(va_list list)
{
	unsigned int fig;
	int l;
	char *octal_rep;
	char *rev_str;

	fig = va_arg(list, unsigned int);

	if (fig == 0)
		return (_write_char('0'));
	if (fig < 1)
		return (-1);
	l = base_l(fig, 8);

	octal_rep = malloc(sizeof(char) * l + 1);
	if (octal_rep == NULL)
		return (-1);
	for (l = 0; fig > 0; l++)
	{
		octal_rep[l] = (fig % 8) + 48;
		fig = fig / 8;

	}
	octal_rep[l] = '\0';
	rev_str = rev_string(octal_rep);
	if (rev_str == NULL)
		return (-1);

	write_base(rev_str);
	free(octal_rep);
	free(rev_str);
	return (l);
}

/**
 * print_hexa - prints a decimal number of base 16
 * @list: Arguments list
 * Return: Number of characters
 */

int print_hexa(va_list list)
{
	unsigned int fig;
	int length;
	int rem_fig;
	char *hex_rep;
	char *rev_hex;

	fig = va_arg(list, unsigned int);

	if (fig == 0)
		return (_write_char('0'));
	if (fig < 1)
		return (-1);
	length = base_len(fig, 16);
	hex_rep = malloc(sizeof(char) * length + 1);
	if (hex_rep == NULL)
		return (-1);
	for (length = 0; fig > 0; length++)
	{
		rem_fig = fig % 16;
		if (rem_fig > 9)
		{
			rem_fig = hex_check(rem_fig, 'x');
			hex_rep[length] = rem_fig;
		}
		else
			hex_rep[length] = rem_fig + 48;
		fig = fig / 16;
	}
	hex_rep[length] = '\0';
	rev_hex = rev_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (length);
}

/**
 * print_hexxa - prints a decimal number (uppercase)
 * @list: Arguments list
 * Return: Number of characters
 */

int print_hexxa(va_list list)
{
	unsigned int fig;
	int length;
	int rem_fig;
	char *hex_rep;
	char *rev_hex;

	fig = va_arg(list, unsigned int);

	if (fig == 0)
		return (_write_char('0'));
	if (fig < 1)
		return (-1);
	length = base_len(fig, 16);
	hex_rep = malloc(sizeof(char) * length + 1);
	if (hex_rep == NULL)
		return (-1);
	for (length = 0; fig > 0; length++)
	{
		rem_fig = fig % 16;
		if (rem_fig > 9)
		{
			rem_fig = hex_check(rem_fig, 'X');
			hex_rep[length] = rem_fig;
		}
		else
			hex_rep[length] = rem_fig + 48;
		fig = fig / 16;
	}
	hex_rep[length] = '\0';
	rev_hex = rev_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (length);
}

/**
 * _hex_check - confirms the particular hex function
 * @fig: the number
 * @z: declares the particular hex function
 * Return: ASCII value for the letter
 */

int _hex_check(int fig, char z)
{
	char *hex = "abcdef";
	char *hexxa = "ABCDEF";

	fig = fig - 10;
	if (z == 'z')
		return (hex[fig]);
	else
		return (hexxa[fig]);
	return (0);
}
