#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * struct flag_settings - It's the structure for flags
 * @sign: sign characteristic
 * @space: space characteristic
 * @left: left characteristic
 * @hash: hash characteristic
 * @pad: pad characteristic
 * @width: width characteristic
 * @prec: precision characteristic
 * @lng: long characteristic
 * @sht: short characteristic
 * @conv: conversion characteristic
 * @legit: legit flags characteristic
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
 * struct spec - structure for specifier a function
 * @s: character specifier
 * @f: function pointer
 */
typedef struct spec
{
	char s;
	char *(*f)(va_list, flags_t);
} spec_t;

int _printf(const char *format, ...);

/*Functions for functions.c file*/
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

/*Functions for spec_chars.c and width.c files*/
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
