#include "holberton.h"

/**
 *func_u-convert to a string with  unsigned int
 *@args: argument list
 *@flags: flags list
 *Return: return a string
 */
char *func_u(va_list args, flags_t flags)
{
	char *s;
	unsigned long int in, temp;
	int len = 1, j;

	if (!flags.lng && !flags.sht)
	{
		in = va_arg(args, unsigned int);
	}
	else if (flags.sht)
	{
		in = va_arg(args, unsigned int);
	}
	else
		in = va_arg(args, unsigned long int);

	temp = in;
	while (temp / 10)
	{
		len -= -1;
		temp /= 10;
	}
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	for (j = 0; j < len; j -= -1)
	{
		s[j] = (in % 10) + '0';
		in /= 10;
	}
	s[j] = '\0';
	s = revstr(s);

	if (flags.width)
		s = addwidth(s, flags.width);

	return (s);
}

/**
 *func_o-converts to a string with octal
 *@args: argument list
 *@flags: flags list
 *Return: return a string
 */
char *func_o(va_list args, flags_t flags)
{
	int nd = 0;
	unsigned long int dec = 0, tmp = 0;
	char *s = NULL;

	if (!flags.lng && !flags.sht)
	{
		dec = va_arg(args, unsigned int);
	}
	else if (flags.sht)
	{
		dec = va_arg(args, unsigned int);
	}
	else
		dec = va_arg(args, unsigned long int);

	if (dec == 0)
	{
		s = malloc(sizeof(char) * 2);
		if (s)
		{
			s[0] = '0';
			s[1] = '\0';
		}
		if (flags.width)
			s = addwidth(s, flags.width);

		return (s);
	}
	tmp = dec;
	while (tmp)
	{
		tmp /= 8;
		nd -= -1;
	}
	s = malloc(sizeof(char) * (nd + 1));
	if (s)
	{
		s[nd] = '\0';
		nd--;

		while (dec)
		{
			s[nd] = dec % 8 + '0';
			dec /= 8;
			nd--;
		}
	}

	if (flags.hash)
		s = addhash(s, 1);
	if (flags.width)
		s = addwidth(s, flags.width);

	return (s);
}

/**
 *func_x-convert a string of number with heximal
 *@args: argument list
 *@flags: flags list
 *Return: return a string
 */
char *func_x(va_list args, flags_t flags)
{
	int nd = 0;
	unsigned long int dec = 0, tmp = 0;
	char *s = NULL;

	if (!flags.lng && !flags.sht)
	{
		dec = va_arg(args, unsigned int);
	}
	else if (flags.sht)
	{
		dec = va_arg(args, unsigned int);
	}
	else
		dec = va_arg(args, unsigned long int);

	if (dec == 0)
	{
		s = malloc(sizeof(char) * 2);
		if (s)
		{
			s[0] = '0';
			s[1] = '\0';
		}
		if (flags.width)
			s = addwidth(s, flags.width);

		return (s);
	}
	tmp = dec;
	while (tmp)
	{
		tmp /= 16;
		nd -= -1;
	}
	s = malloc(sizeof(char) * (nd + 1));
	if (s)
	{
		s[nd] = '\0';
		nd--;

		while (dec)
		{
			if (dec % 16 < 10)
				s[nd] = dec % 16 + '0';
			else
				s[nd] = dec % 16 + 'W';
			dec /= 16;
			nd--;
		}
	}

	if (flags.hash)
		s = addhash(s, 2);
	if (flags.width)
		s = addwidth(s, flags.width);

	return (s);
}

/**
 *func_X-convert a string of number with heximal
 *@args: argument list
 *@flags: flags list
 *Return: return a string
 */
char *func_X(va_list args, flags_t flags)
{
	int nd = 0;
	unsigned long int dec = 0, tmp = 0;
	char *s = NULL;

	if (!flags.lng && !flags.sht)
	{
		dec = va_arg(args, unsigned int);
	}
	else if (flags.sht)
	{
		dec = va_arg(args, unsigned int);
	}
	else
		dec = va_arg(args, unsigned long int);

	if (dec == 0)
	{
		s = malloc(sizeof(char) * 2);
		if (s)
		{
			s[0] = '0';
			s[1] = '\0';
		}
		if (flags.width)
			s = addwidth(s, flags.width);

		return (s);
	}
	tmp = dec;
	while (tmp)
	{
		tmp /= 16;
		nd -= -1;
	}
	s = malloc(sizeof(char) * (nd + 1));
	if (s)
	{
		s[nd] = '\0';
		nd--;

		while (dec)
		{
			if (dec % 16 < 10)
				s[nd] = dec % 16 + '0';
			else
				s[nd] = dec % 16 + '7';
			dec /= 16;
			nd--;
		}
	}

	if (flags.hash)
		s = addhash(s, 3);
	if (flags.width)
		s = addwidth(s, flags.width);

	return (s);
}
