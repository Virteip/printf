/**
 * _strlen_recursion - str len
 * @s: char
 * Return: int
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



/**
 *create_buffer - creates buffer to save string
 *@size: size of the buffer
 *@format: string
 *@f: flag
 *Return: pointer to buffer
 */
char *create_buffer(const char format, flags_t f, int size)
{
	char *ptr, *tmp;
	int i = 0;

	ptr = malloc(sizeof(char) * size);

	if (ptr == NULL)
	{
		return (NULL);
	}

	length = _strlen_recursion(format);

	while (i < length)
	{
		ptr[i] = format[i];
		i++;
	}

	return (ptr);
}
