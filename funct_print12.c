#include "main.h"

/**Print unsigned number**/
/**
 * print_unsigned - a function that prints an unsigned number
 * @types: arguments list
 * @buffer: Buffer
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: printed characters
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int n = BUFF_SIZE - 2;
	unsigned long int m = va_arg(types, unsigned long int);

	m = convert_size_unsgnd(m, size);

	if (m == 0)
		buffer[n--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (m > 0)
	{
		buffer[n--] = (m % 10) + '0';
		m /= 10;
	}

	n++;

	return (write_unsgnd(0, n, buffer, flags, width, precision, size));
}

/**Print unsigned number in octal**/
/**
 * print_octal - a function that prints an unsigned number in octal
 * @types: arguments list
 * @buffer: Buffer
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: printed characters
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int n = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[n--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[n--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[n--] = '0';

	n++;

	return (write_unsgnd(0, n, buffer, flags, width, precision, size));
}

/**Print unsigned number in hexadecimal**/
/**
 * print_hexadecimal - a function that prints an unsigned number in hexadecimal
 * @types: arguments list
 * @buffer: Buffer
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: printed characters
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**Prints unsigned number in uppercase(hexadecimal)**/
/**
 * print_hexa_upper - function that prints unsigned number in upper hexadecimal
 * @types: arguments list
 * @buffer: Buffer
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: printed characters
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**Print hexx number in upper or lowercase**/
/**
 * print_hexa - function that prints a hexadecimal number(upper/lowercase)
 * @types: arguments list
 * @map_to: values to map to
 * @buffer: Buffer
 * @flags:  flags
 * @flag_ch: active flags
 * @width: width
 * @precision: Precision
 * @size: Size specifier
 * @size: specification size
 * Return: characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int n = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[n--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[n--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[n--] = flag_ch;
		buffer[n--] = '0';
	}

	n++;

	return (write_unsgnd(0, n, buffer, flags, width, precision, size));
}
