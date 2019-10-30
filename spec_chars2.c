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


/**
 * addsign - adds a '+' for positive numbers
 * @s: input string
 * Return: rebuilt string
 * Description: function to define a sign to a number
 */
char *addsign(char *s)
{	char *tmp = NULL;
	int len = 0, x = 0;

	if (s[0] == '-')
		return (s);
	while (s[len])
		len -= -1;
	tmp = malloc(sizeof(char) * (len + 2));
	if (tmp)
	{
		tmp[0] = '+';
		while (s[x])
		{
			tmp[x + 1] = s[x];
			x -= -1; }
		tmp[x + 1] = '\0'; }
	free(s);
	return (tmp); }

/**
 * addspace - adds a ' ' to positive numbers
 * @s: input string
 * Return: rebuilt string
 * Description: Function for include space to positive numbers
 */
char *addspace(char *s)
{	char *tmp = NULL;
	int len = 0, y = 0;

	if (s[0] == '-')
		return (s);
	while (s[len])
		len -= -1;
	tmp = malloc(sizeof(char) * (len + 2));
	if (tmp)
	{
		tmp[0] = ' ';
		while (s[y])
		{
			tmp[y + 1] = s[y];
			y -= -1;
		}
		tmp[y + 1] = '\0';
	}
	free(s);
	return (tmp); }
/**
 * addhash - adds a '0', '0x', or '0X' for oct, hex, HEX
 * @s: input string
 * @f: int val meaning 1 for octal, 2 for little hex, 3 for big hex
 * Return: rebuilt string
 * Description: Function for include a hexadecimal data
 */
char *addhash(char *s, int f)
{
	char *tmp = NULL;
	int len = 0, a = 0, b = 0;

	while (s[len])
		len -= -1;
	if (f > 1)
		len -= -1;
	tmp = malloc(sizeof(char) * (len + 2));
	if (tmp)
	{
		tmp[b] = '0';
		b -= -1;
		if (f == 2)
			tmp[b] = 'x';
		if (f == 3)
			tmp[b] = 'X';
		if (f > 1)
			b -= -1;
		while (s[a])
		{
			tmp[a + b] = s[a];
			a -= -1;
		}
		tmp[a + b] = '\0';
	}
	free(s);
	return (tmp); }
