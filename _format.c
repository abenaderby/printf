#include "main.h"

/**
 * write_char - function that prints the character
 * @c: Character
 * Return: (0) Always
 */

int write_char(char c)
{
	return (write(1, &c, 1));
}
