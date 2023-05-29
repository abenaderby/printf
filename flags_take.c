#include "main.h"

/**
 * get_flags - a function that computes active flags
 * @format: formatted string
 * @i: parameter
 * Return: the flags
 */
int get_flags(const char *format, int *i)
{
	int k, ruc_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (ruc_i = *i + 1; format[ruc_i] != '\0'; ruc_i++)
	{
		for (k = 0; FLAGS_CH[k] != '\0'; k++)
			if (format[ruc_i] == FLAGS_CH[k])
			{
				flags |= FLAGS_ARR[k];
				break;
			}

		if (FLAGS_CH[k] == 0)
			break;
	}

	*i = ruc_i - 1;

	return (flags);
}
