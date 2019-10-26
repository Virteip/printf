#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;




int _printf(const char *format, ...);

#endif /*_HOLBERTON_H_*/
