int (*get_func(const char *s))(va_list ap)
{
spec_t specs[] = {
		{'d', op_d},
		{'i', op_d},
		{'c', op_c},
		{'s', op_s},
		}

	int i;
	i = 0;

	while (specs[i].function != NULL)
	{
		if (*s == *specs[i].op[0])
			return (specs[i].f);
		i++;
	}
	exit(1);
}

