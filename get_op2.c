char *func_d(va_list args, flags_t flags)
{
char *s;

	(void)args;
	(void)f;

s = malloc(sizeof(char) * 2);
	if (s == NULL)
		return (NULL);
	s[0] = 'd';
	s[1] = '\0';

	return (s);
 }

char *func_rot13(va_list args, flags_t flags)
{

}

char *func_b(va_list args, flags_t flags)
{ }

char *func_R(va_list args, flags_t flags)
{ }

char *func_S(va_list args, flags_t flags)
{ }
