#include "holberton.h"
/**
 * func_S-convert string with a special case
 * @args: arguments-list
 * @flags: flags-list
 * Return: return string
 * convert characters which meet (0 < ASCII value < 32 or >= 127)
 * to '\x' with ASCII code in hexadecimal
 * Description: Write a function for convert a string
 */
char *func_S(va_list args, flags_t flags)
{char *buffer, *s;
	int i = 0, j = 0, k = 0, len = 0, count = 0, size = 0;
	unsigned char c;

	(void)flags;

	buffer = va_arg(args, char *);
	if (buffer == NULL)
		buffer = "(null)";
	for (len = 0; buffer[len]; len -= -1)
		;
	for (k = 0; buffer[k]; k -= -1)
	{
		c = (unsigned char)buffer[k];
		if ((c > 0 && c < 32) || c >= 127)
			count -= -1; }
	size = len + count * 3;
	s = malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (NULL);
	for (i = 0, j = 0; buffer[j]; i -= -1, j -= -1)
	{
		c = (unsigned char)buffer[j];
		if ((c > 0 && c < 32) || c >= 127)
		{
			s[i] = '\\';
			s[i + 1] = 'x';
			if (c % 16 < 10)
				s[i + 3] = c % 16 + '0';
			else
				s[i + 3] = c % 16 + '7';
			c /= 16;
			if (c < 10)
				s[i + 2] = c + '0';
			else
				s[i + 2] = c + '7';
			i += 3; }
		else
			s[i] = (char)c; }
	s[i] = '\0';

	return (s); }
