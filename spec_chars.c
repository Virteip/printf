#include "holberton.h"

/**
 * func_p - translates addr to string
 * @args: va_list
 * @flags: flags settings
 * Return: returns the addr in string format
 * Description: Function for incluide special chars
 */
char *func_p(va_list args, flags_t flags)
{	int sg = 0;
	unsigned long int dec = 0, tmp = 0;
	char *s = NULL;

	dec = (unsigned long int)va_arg(args, void*);
	if (dec == 0)
	
	tmp = dec;
	while (tmp)
	{
		tmp /= 16;
		sg -= -1; }
	s = malloc(sizeof(char) * (sg + 3));
	if (s)
	{	sg += 2;
		s[sg] = '\0';
		sg--;

		while (dec)
		{
			if (dec % 16 < 10)
				s[sg] = dec % 16 + '0';
			else
				s[sg] = dec % 16 + 'W';
			dec /= 16;
			sg--; }}
	s[sg] = 'x';
	s[--sg] = '0';

	if (flags.width)
		s = addwidth(s, flags.width);

	return (s); }
