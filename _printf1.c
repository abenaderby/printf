#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int charCount = 0;
	char currentChar;

	while ((currentChar = *format++))
	{
		if (currentChar == '%')
	{
		char nextChar = *format++;

	{
		case 'c':
	
	{

	int character = va_arg(args, int);
	putchar((char)character);
	charCount++;
	break;
	}
		case 's':
	{

		char *string = va_arg(args, char *);
		while (*string)
	{
		putchar(*string++);
		charCount++;
	}	
	break;
	}
		case '%':
	{
		putchar('%');
		charCount++;
		break;
	}
	default:

	putchar('%');
	putchar(nextChar);
	charCount += 2;
	break;
	}
	}
	else
	{
		putchar(currentChar);
		charCount++;
	}
	}

	va_end(args);

	Return charCount;
}
