#include "main.h"

/**
 * _review - function that formats string after receiving main string
 * @format: string containing all characters
 * @f_list: list of functions
 * @arg_list: list of arguments
 * Return: (0) Always
 */

int _review(const char *format, conver_t f_list[], va_list arg_list)
{
	int k, b, value, charprint;

	charprint = 0;
	for (k = 0; format[k] != '\0'; k++)
	{
		if (format[k] == '%')
		{
			for (b = 0; f_list[b].sym != NULL; b++)
			{
				if (format[k + 1] == f_list[b].sym[0])
				{
					value = f_list[b].f(arg_list);
					if (value == -1)
						return (-1);
					charprint += value;
					break;
				}
			}
			if (f_list[b].sym == NULL && format[k + 1] != ' ')
			{
				if (format[k + 1] != '\0')
				{
					write_char(format[k]);
					write_char(format[k + 1]);
					charprint = charprint + 2;
				}
				else
					return (-1);
			}
			k = k + 1;
		}
		else
		{
			write_char(format[k]);
			charprint++;
		}
	}
	return (charprint);
}
