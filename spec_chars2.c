#include "holberton.h"
/**
 * func_percent-helper function allocate memory space for string "%"
 * @args:list of arguments
 * @f: variable struct flags_t
 * Return: return string has % character
 * Description: Write a function that allocate memory space for s%
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
