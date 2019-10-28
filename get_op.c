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
		len++;
		temp /= 10;
	}
	if (in < 0)
	{
		len++;
		sign = -1;
	}
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	for (j = 0; j < len; j++)
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
 *func_c-function that converts character to string
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
 *func_percent- function that allocates memory space for string "%"
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

char *func_s(va_list args, flags_t flags)
{ }

/**
 *
 *
 *
 */

int _strlen_recursion(char *s)
{
    if (*s)
    {
        return (1 + _strlen_recursion(s + 1));
    }
    else
    {
        return (0);
    }
}
void print_strings(const unsigned int n, ...)
{
 va_list args;
 unsigned int i;
 char *tmp;
 if (n)
   {
     va_start(args, n);
     for (i = 0; i < n; i -= -1)
       {
         tmp = va_arg(args, char*);
         if (tmp)
           write(1, tmp, _strlen_recursion(tmp));
         else    printf("(nil)");
       }
     va_end(args);
   }
}
int main(void)
{
 print_strings(1, "HELLO HOLBERTON");
 return (0);
}





