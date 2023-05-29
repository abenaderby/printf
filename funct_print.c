#include "main.h"

/**Print Characters**/

/**
 * print_char - a function that prints a character
 * @types: Arguments list
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of printed characters
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char d = va_arg(types, int);

	return (handle_write_char(d, buffer, flags, width, precision, size));
}
/**Prints a string**/

/**
 * print_string - a function that prints a string
 * @types: Arguments list
 * @buffer: Buffer
 * @flags:  Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of printed characters
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, n;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (n = width - len; n > 0; n--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (n = width - len; n > 0; n--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}
/**Prints percentage sign**/
/**
 * print_percent - function that prints a percentage sign
 * @types: Arguments list
 * @buffer: Buffer
 * @flags:  Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: printed characters
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**Prints integer**/
/**
 * print_int - a function that prints an integer
 * @types: arguments list
 * @buffer: Buffer
 * @flags:  flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: printed characters
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int d = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int m;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[d--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	m = (unsigned long int)n;

	if (n < 0)
	{
		m = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (m > 0)
	{
		buffer[d--] = (m % 10) + '0';
		m /= 10;
	}

	d++;

	return (write_number(is_negative, d, buffer, flags, width, precision, size));
}

/**Print binary**/
/**
 * print_binary - a function that prints an unsigned number
 * @types: arguments list
 * @buffer: Buffer
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: printed character
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int b, m, i, s;
	unsigned int a[32];
	int calc;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	b = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = b / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (b / m) % 2;
	}
	for (i = 0, s = 0, calc = 0; i < 32; i++)
	{
		s += a[i];
		if (s || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			calc++;
		}
	}
	return (calc);
}
