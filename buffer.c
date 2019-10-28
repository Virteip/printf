#include "holberton.h"
/**
 *create_buffer
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
