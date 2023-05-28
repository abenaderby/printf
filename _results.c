#include "main.h"
#include <stdio.h>

/**
 * rev_string - a function that reverses a string
 * @s: string
 * Return: (0) Always
 */

char *rev_string(char *s)
{
	int l;
	int d;
	char tmp;
	char *dest;

	for (l = 0; s[l] != '\0'; l++)
	{}

	dest = malloc(sizeof(char) * l + 1);
	if (dest == NULL)
		return (NULL);

	_memcpy(dest, s, l);
	for (d = 0; d < l; d++, l--)
	{
		tmp = dest[l - 1];
		dest[l - 1] = dest[d];
		dest[d] = tmp;
	}
	return (dest);
}

/**
 * create_base - creates a character into a standard output
 * @str: string
 */

void create_base(char *str)
{
	int j;

	for (j = 0; str[j] != '\0'; j++)
		write_char(str[j]);
}

/**
 * base_len - function that determines the length of an octal number
 * @num: number to be determined
 * @base: base
 * Return: an integer
 */

unsigned int base_len(unsigned int num, int base)
{
	unsigned int k;

	for (k = 0; num > 0; k++)
	{
		num = num / base;
	}
	return (k);
}

/**
 * _memcpy - function that copies a memory area
 * @dest: destination of memory
 * @src: source
 * @n: number of bytes
 * Return: pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int k;

	for (k = 0; k < n; k++)
		dest[k] = src[k];
	dest[k] = '\0';
	return (dest);
}
