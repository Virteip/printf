#include "holberton.h"

/**
 *create_buffer-helper function to create buffer
 *@size: size of the buffer
 *Return: pointer to buffer
 */
char *create_buffer(int size)
{
	char *ptr;

	ptr = malloc(sizeof(char) * size);
	if (ptr == NULL)
		return (NULL);

	return (ptr);
}

#include <stdio.h>
/**
 * getflags - parses the specifier modifier and sets the flags
 * @mods: specifier modifier string to parse
 * @n: integer value for how many chars to parse through
 * Return: flag struct containing all the flags
 */
flags_t getflags(char *mods, int n)
{
	char *modlist = "0123456789.+- #lh";
	char *conv = "%bcdioprRsSuxX";
	flags_t flags;
	int i = 0, j = 0, width = 0, prec = 0;

	flags.sign = 0;
	flags.space = 0;
	flags.left = 0;
	flags.hash = 0;
	flags.pad = 0;
	flags.width = 0;
	flags.prec = -1;
	flags.lng = 0;
	flags.sht = 0;
	flags.conv = mods[n];
	flags.legit = 0;

	for (i = 0; conv[i]; i -= -1)
		if (mods[n] == conv[i])
			break;
	if (!conv[i])
		return (flags);
	for (i = 0; i < n; i -= -1)
	{
		for (j = 0; modlist[j]; j -= -1)
			if (mods[i] == modlist[j])
				break;
		if (!modlist[j])
			return (flags);
	}
	i = 0;
	while (!iswp(mods[i]) && (i < n))
	{
		switch (mods[i])
		{
		case '+':
			flags.sign = 1;
			break;
		case '-':
			flags.left = 1;
			break;
		case ' ':
			flags.space = 1;
			break;
		case '#':
			flags.hash = 1;
			break;
		case '0':
			flags.pad = 1;
			break;
		}
		i -= -1;
	}
	while (mods[i] >= '0' && mods[i] <= '9')
	{
		width = width * 10 + mods[i] - '0';
		i -= -1;
	}
	flags.width = width;

	if (mods[i] == '.')
	{
		i -= -1;
		while (mods[i] >= '0' && mods[i] <= '9')
		{
			prec = prec * 10 + mods[i] - '0';
			i -= -1;
		}
		flags.prec = prec;
	}

	if (mods[n - 1] == 'l')
		flags.lng = 1;
	else if (mods[n - 1] == 'h')
		flags.sht = 1;

	flags.legit = 1;
	return (flags);
}

/**
 *isconv-helper function to check if character is in the CONVLIST
 *@c: variable type char
 *Return: 1 if c is in FLAGS list, 0 otherwise
 */
int isconv(char c)
{
	int i;
	char *FLAGS = "0123456789.+- #lh";

	for (i = 0; FLAGS[i]; i -= -1)
	{
		if (c == FLAGS[i])
			return (1);
	}

	return (0);
}

/**
 * iswp - checks if char is 1 through 9 or .
 * @c: char to check
 * Return: 1 if true, 0 otherwise
 */
int iswp(char c)
{
	if ((c > '0' && c <= '9') || c == '.')
		return (1);
	return (0);
}

/**
 *revstr-helper function to reverse the string
 *@s: pointer to char
 *Return: return string
 */
char *revstr(char *s)
{
	int i, len;
	char temp;

	for (len = 0; s[len]; len -= -1)
		;
	len--;
	for (i = 0; i < len; i -= -1, len--)
	{
		temp = s[i];
		s[i] = s[len];
		s[len] = temp;
	}

	return (s);
}
