#include "holberton.h"

/**
 *func_r-revert string when printf detect r custom specifier
 *@args: argument list
 *@flags: spec list
 *Return: return a reversed string
 */
char *func_r(va_list args, flags_t flags)
{
	char *buffer, *s;
	int i, j, len;

	(void)args;
	(void)flags;

	buffer = va_arg(args, char *);
	if (buffer == NULL)
		buffer = "(null)";
	for (len = 0; buffer[len]; len++)
		;
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	for (i = 0, j = 0; buffer[j]; i++, j++)
		s[i] = buffer[j];
	s[i] = '\0';
	s = revstr(s);
	return (s);
}

/**
 *rot13-encodes a string to rot13
 *@s: pointer to char
 *Return: return s
 */
char *rot13(char *s)
{
	char check[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char swap[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i, n;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (n = 0; check[n] != '\0'; n++)
		{
			if (s[i] == check[n])
			{
				s[i] = swap[n];
				break;
			}
		}
	}
	return (s);
}

/**
 *func_rot13-encodes a string to rot13 when printf detects R in the format
 *@args: argument list
 *@flags: spec list
 *Return: return a rot13 string
 */
char *func_rot13(va_list args, flags_t flags)
{
	char *buffer, *s;
	int i, j, len;

	(void)args;
	(void)flags;

	buffer = va_arg(args, char *);
	if (buffer == NULL)
		buffer = "(null)";
	for (len = 0; buffer[len]; len++)
		;
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	for (i = 0, j = 0; buffer[j]; i++, j++)
		s[i] = buffer[j];
	s[i] = '\0';
	s = rot13(s);
	return (s);
}

/**
 *func_S-convert a string with special case
 *@args: argument list
 *@flags: flags list
 *Return: return a string
 *convert characters which meet (0 < ASCII value < 32 or >= 127)
 *to '\x' with ASCII code in hexadecimal
 */
char *func_S(va_list args, flags_t flags)
{
	char *buffer, *s;
	int i = 0, j = 0, k = 0, len = 0, count = 0, size = 0;
	unsigned char c;

	(void)flags;

	buffer = va_arg(args, char *);
	if (buffer == NULL)
		buffer = "(null)";
	for (len = 0; buffer[len]; len++)
		;
	for (k = 0; buffer[k]; k++)
	{
		c = (unsigned char)buffer[k];
		if ((c > 0 && c < 32) || c >= 127)
			count++;
	}
	size = len + count * 3;
	s = malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (NULL);
	for (i = 0, j = 0; buffer[j]; i++, j++)
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
			i += 3;
		}
		else
			s[i] = (char)c;
	}
	s[i] = '\0';

	return (s);
}
