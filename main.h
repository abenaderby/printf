#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
* struct convert - defines a structure for symbols and functions
*
* @sym: The operator
* @f: The function associated
*/
struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;

/***Main functions***/
int write_char(char);
int _printf(const char *format, ...);
int parser(const char *format, conver_t f_list[], va_list arg_list);
int print_char(va_list);
int print_percent(va_list);
int print_integer(va_list);
int print_string(va_list);
int _print_number(va_list);
int print_binary(va_list);
int _print_rev(va_list arg);
int unsigned_integer(va_list);
int print_octal(va_list list);
int print_hexa(va_list list);
int rot13(va_list);
int print_hexxa(va_list list);

/***Sub functions***/
void create_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int _print_unsgined_number(unsigned int k);
unsigned int base_len(unsigned int num, int base);
char *rev_string(char *s);



#endif
