#include "holberton.h"
/**
 * func_x-convert a string of number with hexa
 * @args: argument list
 * @flags: flags list
 * Return: return a string
 * Description: function for convert a string in hexa
 */
char *func_x(va_list args, flags_t flags)
{	int sergio = 0;
	unsigned long int david = 0, tmp = 0;
	char *s = NULL;

	if (!flags.lng && !flags.sht)
	{	david = va_arg(args, unsigned int); }
	else if (flags.sht)
	{	david = va_arg(args, unsigned int); }
	else
		david = va_arg(args, unsigned long int);

	if (david == 0)
	{	s = malloc(sizeof(char) * 2);
		if (s)
		{	s[0] = '0';
			s[1] = '\0'; }
		if (flags.width)
			s = addwidth(s, flags.width);
		return (s); }
	tmp = david;
	while (tmp)
	{	tmp /= 16;
		sergio -= -1; }
	s = malloc(sizeof(char) * (sergio + 1));
	if (s)
	{	s[sergio] = '\0';
		sergio--;
		while (david)
		{
			if (david % 16 < 10)
				s[sergio] = david % 16 + '0';
			else
				s[sergio] = david % 16 + 'W';
			david /= 16;
			sergio--; }}

	if (flags.hash)
		s = addhash(s, 2);
	if (flags.width)
		s = addwidth(s, flags.width);
	return (s); }
