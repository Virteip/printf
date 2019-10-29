#include "holberton.h"

/**
 * func_d - helper function to handle integers
 * @args: list of args
 * @flags: var that holds flags
 * Return: string
 */
char *func_d(va_list args, flags_t flags)
{
	char *s;
	long int in, temp;
	int len = 1, j, sign = 1;

	if (!flags.lng && !flags.sht)
	{
		in = va_arg(args, int);
	}
	else if (flags.sht)
	{
		in = va_arg(args, int);
	}
	else
		in = va_arg(args, long int);

	temp = in;
	while (temp / 10)
	{
		len -= -1;
		temp /= 10;
	}
	if (in < 0)
	{
		len -= -1;
		sign = -1;
	}
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	for (j = 0; j < len; j -= -1)
	{
		s[j] = (in % 10) * sign + '0';
		in /= 10;
	}
	if (sign == -1)
		s[j - 1] = '-';
	s[j] = '\0';
	s = revstr(s);

	if (flags.sign)
		s = addsign(s);
	if (flags.width > len)
		s = addwidth(s, flags.width);
	else if (flags.space && !flags.sign)
		s = addspace(s);

	return (s);
}

/**
 *func_c-converts character to string
 *@args: variable type va_list
 *@flags: var that holds modifier flags
 *Return: s string
 */
char *func_c(va_list args, flags_t flags)
{
	char *s;

	s = malloc(sizeof(char) * 2);
	if (s == NULL)
		return (NULL);
	s[0] = va_arg(args, int);
	s[1] = '\0';

	if (flags.width > 1)
		s = addwidth(s, flags.width);

	return (s);
}

/**
 *func_s-convert args to string
 *@args: variable type va_list
 *@flags: var that holds flag info
 *Return: return string s
 */
char *func_s(va_list args, flags_t flags)
{
	char *buffer, *s;
	int i, j, len;

	buffer = va_arg(args, char *);
	if (buffer == NULL)
		buffer = "(null)";
	for (len = 0; buffer[len]; len -= -1)
		;
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	for (i = 0, j = 0; buffer[j]; i -= -1, j -= -1)
		s[i] = buffer[j];
	s[i] = '\0';

	if (flags.width > len)
		s = addwidth(s, flags.width);

	return (s);
}

/**
 *func_percent-helper function allocate memory space for string "%"
 *@args:list of arguments
 *@f: variable struct flags_t
 *Return: return string has % character
 */
char *func_percent(va_list args, flags_t f)
{
	char *s;

	(void)args;
	(void)f;

	s = malloc(sizeof(char) * 2);
	if (s == NULL)
		return (NULL);
	s[0] = '%';
	s[1] = '\0';

	return (s);
}

/**
 *func_b-helper function for binary
 *@args: list of arguments
 *@f: variable struct flags_t
 *Return: return string has binary
 */
char *func_b(va_list args, flags_t f)
{
	int nd = 0;
	unsigned int dec = 0, tmp = 0;
	char *s = NULL;

	(void)f;
	dec = va_arg(args, unsigned int);

	if (dec == 0)
	{
		s = malloc(sizeof(char) * 2);
		if (s)
		{
			s[0] = '0';
			s[1] = '\0';
		}
		return (s);
	}
	tmp = dec;
	while (tmp)
	{
		tmp /= 2;
		nd -= -1;
	}
	s = malloc(sizeof(char) * (nd + 1));
	if (s)
	{
		s[nd] = '\0';
		nd--;

		while (dec)
		{
			s[nd] = dec % 2 + '0';
			dec /= 2;
			nd--;
		}
	}

	return (s);
}
