#include "holberton.h"
#include <stdio.h>
/**
 * getflags - parses the specifier modifier and sets the flags
 * @mods: specifier modifier string to parse
 * @n: integer value for how many chars to parse through
 * Return: flag struct containing all the flags
 * Description: Write function for use flags
 */
flags_t getflags(char *mods, int n)
{	char *modlist = "0123456789.+- #lh", *conv = "%bcdioprRsSuxX";
	flags_t flags;
	int i = 0, j = 0, width = 0, prec = 0;

	flags.sign = 0, flags.space = 0, flags.left = 0, flags.hash = 0,
	flags.pad = 0, flags.width = 0, flags.prec = -1, flags.lng = 0, flags.sht = 0,
	flags.conv = mods[n], flags.legit = 0;

	for (i = 0; conv[i]; i -= -1)
		if (mods[n] == conv[i])
			exit;

	if (!conv[i])
		return (flags);
	for (i = 0; i < n; i -= -1)
	{
		for (j = 0; modlist[j]; j -= -1)
			if (mods[i] == modlist[j])
				break;
		if (!modlist[j])
			return (flags); }
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
			break; }
		i -= -1; }

	while (mods[i] >= '0' && mods[i] <= '9')
	{	width = width * 10 + mods[i] - '0';
		i -= -1; }
		flags.width = width;
	if (mods[i] == '.')
	{ i -= -1;
		while (mods[i] >= '0' && mods[i] <= '9')
		{ prec = prec * 10 + mods[i] - '0';
			i -= -1; }
		flags.prec = prec; }
	if (mods[n - 1] == 'l')
		flags.lng = 1;
	else if (mods[n - 1] == 'h')
		flags.sht = 1;
	flags.legit = 1;
	return (flags); }
