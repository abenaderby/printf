#include "main.h"

/**
 * _print_rev - a function prints a string in reverse
 * @arg: argument
 * Return: characters printed
 */

int _print_rev(va_list arg)
{
	int b;
	char *str;
	char *ptr;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (-1);
	ptr = rev_string(str);
	if (ptr == NULL)
		return (-1);
	for (b = 0; ptr[b] != '\0'; b++)
		write_char(ptr[b]);
	free(ptr);
	return (b);
}

/**
 * rot13 - a function that converts a string to rot13
 * @list: string
 * Return: converted string
 */

int rot13(va_list list)
{
	int k;
	int j;
	char *str;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(list, char *);
	if (str == NULL)
		return (-1);
	for (k = 0; str[k] != '\0'; k++)
	{
		for (j = 0; j <= 52; j++)
		{
			if (str[k] == s[j])
			{
				write_char(u[j]);
				break;
			}
		}
		if (j == 53)
			write_char(str[k]);
	}
	return (k);
}
