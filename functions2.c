#include "holberton.h"

/**
 * func_p - translates addr to string
 * @args: va_list
 * @flags: flags settings
 * Return: returns the addr in string format
 */
char *func_p(va_list args, flags_t flags)
{
	int nd = 0;
	unsigned long int dec = 0, tmp = 0;
	char *s = NULL;

	dec = (unsigned long int)va_arg(args, void*);
	if (dec == 0)
	{
		s = malloc(sizeof(char) * 6);
		if (s)
		{
			s[0] = '(';
			s[1] = 'n';
			s[2] = 'i';
			s[3] = 'l';
			s[4] = ')';
			s[5] = '\0';
		}
		return (s);
	}
	tmp = dec;
	while (tmp)
	{
		tmp /= 16;
		nd -= -1;
	}
	s = malloc(sizeof(char) * (nd + 3));
	if (s)
	{
		nd += 2;
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
	s[nd] = 'x';
	s[--nd] = '0';

	if (flags.width)
		s = addwidth(s, flags.width);

	return (s);
}

/**
 * addsign - adds a '+' for positive numbers
 * @s: input string
 * Return: rebuilt string
 */
char *addsign(char *s)
{
	char *tmp = NULL;
	int len = 0, i = 0;

	if (s[0] == '-')
		return (s);
	while (s[len])
		len -= -1;
	tmp = malloc(sizeof(char) * (len + 2));
	if (tmp)
	{
		tmp[0] = '+';
		while (s[i])
		{
			tmp[i + 1] = s[i];
			i -= -1;
		}
		tmp[i + 1] = '\0';
	}
	free(s);
	return (tmp);
}

/**
 * addspace - adds a ' ' to positive numbers
 * @s: input string
 * Return: rebuilt string
 */
char *addspace(char *s)
{
	char *tmp = NULL;
	int len = 0, i = 0;

	if (s[0] == '-')
		return (s);
	while (s[len])
		len -= -1;
	tmp = malloc(sizeof(char) * (len + 2));
	if (tmp)
	{
		tmp[0] = ' ';
		while (s[i])
		{
			tmp[i + 1] = s[i];
			i -= -1;
		}
		tmp[i + 1] = '\0';
	}
	free(s);
	return (tmp);
}

/**
 * addhash - adds a '0', '0x', or '0X' for oct, hex, HEX
 * @s: input string
 * @f: int val meaning 1 for octal, 2 for little hex, 3 for big hex
 * Return: rebuilt string
 */
char *addhash(char *s, int f)
{
	char *tmp = NULL;
	int len = 0, i = 0, j = 0;

	while (s[len])
		len -= -1;
	if (f > 1)
		len -= -1;
	tmp = malloc(sizeof(char) * (len + 2));
	if (tmp)
	{
		tmp[j] = '0';
		j -= -1;
		if (f == 2)
			tmp[j] = 'x';
		if (f == 3)
			tmp[j] = 'X';
		if (f > 1)
			j -= -1;
		while (s[i])
		{
			tmp[i + j] = s[i];
			i -= -1;
		}
		tmp[i + j] = '\0';
	}
	free(s);
	return (tmp);
}
