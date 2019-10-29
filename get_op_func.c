#include "holberton.h"
/**
 * _printf - identify function
 * @format: funct
 *
 * Return: int
 *
 **/
int _printf(const char *format, ...)
{
	va_list args;
	op_t ops[] = {
		{'c', print_c},
		{'s', print_s},
		{NULL, NULL},
	};
	int i, i2;
	va_start(args, format);

	i = 0;

	while (i < 2)
	{
		if (format[i] == ops[i2].op)
		{
			return (ops[i].f);
		}
		i++;
	}

	va_end(args);
	return (0);
}
