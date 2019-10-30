#include "holberton.h"
/**
 * func_u-convert to a string with  unsigned int
 * @args: argument list
 * @flags: flags list
 * Return: return a string
 * Description: function for convert a string to "ui"
 */
char *func_u(va_list args, flags_t flags)
{	char *s;
	unsigned long int in, temp;
	int len = 1, sergio;

	if (!flags.lng && !flags.sht)
	{
		in = va_arg(args, unsigned int); }
	else if (flags.sht)
	{
		in = va_arg(args, unsigned int); }
	else
		in = va_arg(args, unsigned long int);
	temp = in;
	while (temp / 10)
	{
		len -= -1;
		temp /= 10; }
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	for (sergio = 0; sergio < len; sergio -= -1)
	{
		s[sergio] = (in % 10) + '0';
		in /= 10; }
	s[sergio] = '\0';
	s = revstr(s);
	if (flags.width)
		s = addwidth(s, flags.width);
	return (s); }
/**
 * func_o-converts to a string with octal
 * @args: argument list
 * @flags: flags list
 * Return: return a string
 * Description: Function for convert string to Octal number
 */
char *func_o(va_list args, flags_t flags)
{	int sergio = 0;
	unsigned long int david = 0, tmp = 0;
	char *s = NULL;

	if (!flags.lng && !flags.sht)
	{
		david = va_arg(args, unsigned int); }
	else if (flags.sht)
	{
		david = va_arg(args, unsigned int); }
	else
		david = va_arg(args, unsigned long int);

	if (david == 0)
	{	s = malloc(sizeof(char) * 2);
		if (s)
		{
			s[0] = '0';
			s[1] = '\0'; }
		if (flags.width)
			s = addwidth(s, flags.width);
		return (s); }
	tmp = david;
	while (tmp)
	{	tmp /= 8;
		sergio -= -1; }
	s = malloc(sizeof(char) * (sergio + 1));
	if (s)
	{
		s[sergio] = '\0';
		sergio--;
		while (david)
		{
			s[sergio] = david % 8 + '0';
			david /= 8;
			sergio--; }}
	if (flags.hash)
		s = addhash(s, 1);
	if (flags.width)
		s = addwidth(s, flags.width);
	return (s); }
