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
		
		for (len = 0; index < width; index -= -1, len -= -1)
			tmp[index] = s[len];
		tmp[index] = NULL;
	}

	return (tmp);
}

/**
 * adjprecis - adjusts precision of a value
 * @s: input string
 * @prec: gives minimum number of digits
 * Return: returns new string with length equal to width
 */
char *adjprecis(char *s, int prec)
{
	char *tmp = NULL;
	(void)s;
	(void)prec;
	return (tmp);
}
