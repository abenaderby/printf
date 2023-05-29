#include "main.h"

/**Print pointer**/
/**
 * print_pointer - a function that prints the value of a pointer
 * @types: arguments list
 * @buffer: Buffer
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: printed characters
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int n = BUFF_SIZE - 2, len = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[n--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', len++;
	else if (flags & F_SPACE)
		extra_c = ' ', len++;

	n++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, n, len,
		width, flags, padd, extra_c, padd_start));
}

/**Print non printable**/
/**
 * print_non_printable - function that prints ASCII codes in hexa
 * @types: arguments list
 * @buffer: Buffer
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: printed characters
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int b = 0, set = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[b] != '\0')
	{
		if (is_printable(str[b]))
			buffer[b + set] = str[b];
		else
			set += append_hexa_code(str[b], buffer, b + set);

		b++;
	}

	buffer[b + set] = '\0';

	return (write(1, buffer, b + set));
}

/**Prints reverse**/
/**
 * print_reverse - a function that prints a reverse string.
 * @types: arguments
 * @buffer: Buffer
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: characters
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int n, calc = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (n = 0; str[n]; n++)
		;

	for (n = n - 1; n >= 0; n--)
	{
		char z = str[n];

		write(1, &z, 1);
		calc++;
	}
	return (calc);
}
/**Print a string in ROT13**/
/**
 * print_rot13string - a function that prints a string in rot13.
 * @types: arguments
 * @buffer: Buffer
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: characters
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, k;
	int calc = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (k = 0; in[k]; k++)
		{
			if (in[k] == str[i])
			{
				x = out[k];
				write(1, &x, 1);
				calc++;
				break;
			}
		}
		if (!in[k])
		{
			x = str[i];
			write(1, &x, 1);
			calc++;
		}
	}
	return (calc);
}
