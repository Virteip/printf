#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct flag_settings - structure for flags
 * @sign: sign
 * @space: space
 * @left: left
 * @hash: hash
 * @pad: pad
 * @width: width
 * @prec: precision
 * @lng: long
 * @sht: short
 * @conv: conversion
 * @legit: legit flags
 */
typedef struct flag_settings
{
	int sign;
	int space;
	int left;
	int hash;
	int pad;
	int width;
	int prec;
	int lng;
	int sht;
	char conv;
	int legit;
} flags_t;

/**
 * struct spec - structure for specifier to function
 * @s: specifier character
 * @f: function pointer
 */
typedef struct spec
{
	char s;
	char *(*f)(va_list, flags_t);
} spec_t;

int _printf(const char *format, ...);

/*conversion.c*/
char *func_d(va_list, flags_t);
char *func_c(va_list, flags_t);
char *func_s(va_list, flags_t);
char *func_percent(va_list, flags_t);
char *func_b(va_list, flags_t);
char *func_p(va_list, flags_t);
char *func_u(va_list, flags_t);
char *func_o(va_list, flags_t);
char *func_x(va_list, flags_t);
char *func_X(va_list, flags_t);
char *func_r(va_list, flags_t);
char *rot13(char *s);
char *func_rot13(va_list, flags_t);
char *func_S(va_list, flags_t);

/*misc.c*/
char *create_buffer(int);
char *revstr(char *);
int isconv(char);
flags_t getflags(char *, int);
int iswp(char c);
char *rot13(char *s);
char *addsign(char *s);
char *addspace(char *s);
char *addhash(char *s, int f);
char *addwidth(char *s, int width);
char *adjprecis(char *s, int prec);

#endif /*_HOLBERTON_H_*/
