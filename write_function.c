#include "main.h"

/**Write win**/
/**
 * handle_write_char - a function that prints a string
 * @c: character
 * @buffer: a buffer
 * @width: width
 * @flags: flags
 * @precision: precision
 * @size: size
 * Return: 0
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0;
	char pa = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		pa = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = pa;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**Write figures**/
/**
 * write_number - a function that prints a string
 * @is_negative: arguments
 * @size: size
 * @buffer: Buffer
 * @flags:  flags
 * @width: width
 * @precision: precision
 * @ind: character
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char pa = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pa = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		len, pa, extra_ch));
}

/**
 * write_num - a function that writes a number using bufffer
 * @ind: Index
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: precision
 * @len: length
 * @pa: character
 * @extra_c: extra char
 * Return: characters
 */
int write_num(int ind, char buffer[], int flags, int width, int prec,
	int len, char pa, char extra_c)
{
	int j, pa_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = pa = ' ';
	if (prec > 0 && prec < len)
		pa = ' ';
	while (prec > len)
		buffer[--ind] = '0', len++;
	if (extra_c != 0)
		len++;
	if (width > len)
	{
		for (j = 1; j < width - len + 1; j++)
			buffer[j] = pa;
		buffer[j] = '\0';
		if (flags & F_MINUS && pa == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], len) + write(1, &buffer[1], j - 1));
		}
		else if (!(flags & F_MINUS) && pa == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], j - 1) + write(1, &buffer[ind], len));
		}
		else if (!(flags & F_MINUS) && pa == '0')
		{
			if (extra_c)
				buffer[--pa_start] = extra_c;
			return (write(1, &buffer[pa_start], j - pa_start) +
				write(1, &buffer[ind], len - (1 - pa_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], len));
}

/**
 * write_unsgnd - a function that writes an unsigned number
 * @is_negative: number
 * @ind: Index
 * @buffer: an array
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: size
 * Return: characters
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[], int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1, j = 0;
	char pa = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < len)
		pa = ' ';

	while (precision > len)
	{
		buffer[--ind] = '0';
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pa = '0';

	if (width > len)
	{
		for (j = 0; j < width - len; j++)
			buffer[j] = pa;

		buffer[j] = '\0';

		if (flags & F_MINUS)
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], j));

		else
		{
			return (write(1, &buffer[0], j) + write(1, &buffer[ind], len));
		}
	}

	return (write(1, &buffer[ind], len));
}

/**
 * write_pointer - a function that writes a memory address
 * @buffer: an array
 * @ind: Index
 * @len: length
 * @width: width
 * @flags: flags
 * @k: Character
 * @extra_c: extra character
 * @k_start: where padding starts from
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int ind, int len,
	int width, int flags, char k, char extra_c, int k_start)
{
	int j;

	if (width > len)
	{
		for (j = 3; j < width - len + 3; j++)
			buffer[j] = k;
		buffer[j] = '\0';
		if (flags & F_MINUS && k == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], len) + write(1, &buffer[3], (j - 3)));
		}
		else if (!(flags & F_MINUS) && k == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], (j - 3)) + write(1, &buffer[ind], len));
		}
		else if (!(flags & F_MINUS) && k == '0')
		{
			if (extra_c)
				buffer[--k_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[k_start], j - k_start) +
				write(1, &buffer[ind], len - (1 - k_start) - 2));

		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
