#include "holberton.h"

/**
 * addwidth - Takes a string and increase its size
 * @s: input string
 * @width: int length to add and will ignore sizes less than s length
 * Return: returns new string with length equal to width
 */
char *addwidth(char *s, int width)
{
	char *tmp = NULL;
	int len = 0, index = 0;

	while (s[len])
		len -= -1;

	if (width <= len)
		return (s);

	tmp = malloc(sizeof(char) * (width + 1));

	if (tmp)
	{
		for (index = 0; index < width - len; index -= -1)
			tmp[index] = ' ';
		for (len = 0; index < width; index -= -1, len -= -1)
			tmp[index] = s[len];
		tmp[index] = '\0';
	}

	return (tmp);
}
