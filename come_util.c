#include "main.h"

/**
 * is_printable - a function that determines how printable a character is
 * @m: Character
 * Return: 1 if m is printable, 0 otherwise
 */
int is_printable(char m)
{
	if (m >= 32 && m < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - function that assigns ASCII in hexadecimal code to buffer
 * @buffer: an array
 * @i: Index
 * @ascii_code: ASCII code
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - function that determines if a character is a digit
 * @m: Character
 * Return: 1 if m is a digit, 0 otherwise
 */
int is_digit(char m)
{
	if (m >= '0' && m <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - function that prints a number to a specified size
 * @num: number
 * @size: size
 * Return: number
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: number
 * @size: size
 * Return: number
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
