#include "holberton.h"
/**
 * create_buffer-helper function to create buffer
 * @size: size of the buffer
 * Return: pointer to buffer
 * Description: Write function for create buffer
 */
char *create_buffer(int size)
{
	char *ptr;

	ptr = malloc(sizeof(char) * size);
	if (ptr == NULL)
		return (NULL);

	return (ptr);
}


/**
 * isconv-helper function for check if character is in the CONVLIST
 * @c: variable type char
 * Return: 1 if c is in FLAGS list, 0 otherwise
 * Description: Function for check characters
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
 * revstr-helper function to reverse the string
 * @s: pointer to char
 * Return: return string
 * Description: Write function for reverse a string
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
