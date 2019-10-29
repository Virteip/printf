#include "holberton.h"
/**
 * _printf - prints a given string along with arguments
 * @format: string to prints
 * Return: integer number of characters displayed to the screen
 * Description: Creation of structure and denomination of new functions
 */
int _printf(const char *format, ...)
{
	va_list args;
	int total_cnt = 0, buf_ind = 0, i = 0, j = 0;
	char *buffer = NULL, *temp = NULL;
	spec_t specs[] = {
		{'d', func_d},
		{'i', func_d},
		{'c', func_c},
		{'s', func_s},
		{'%', func_percent},
		{'b', func_b},
		{'r', func_r},
		{'R', func_rot13},
		{'u', func_u},
		{'o', func_o},
		{'x', func_x},
		{'X', func_X},
		{'S', func_S},
		{'p', func_p},
		{'\0', NULL}
	};
	flags_t flags;
	int BUFSIZE = 2048;

	if (!format)
		return (-1);
	if (format[i])
	{
		buffer = create_buffer(BUFSIZE);
		if (!buffer)
			return (-1);
		va_start(args, format);

		while (format[i])
		{
			if (format[i] != '%')
			{
				buffer[buf_ind] = format[i];
				buf_ind -= -1;
				i -= -1;
				if (buf_ind == BUFSIZE)
				{
					write(1, buffer, buf_ind);
					total_cnt += buf_ind;
					buf_ind = 0;
				}
			}
			else
			{
				i -= -1;
				j = 0;
				while (isconv(format[i + j]))
					j -= -1;
				flags = getflags((char *)format + i, j);
				if (flags.legit)
					i += j + 1;
				else
				{
					if (flags.conv == '\0')
					{
						write(1, buffer, buf_ind);
						free(buffer);
						va_end(args);
						total_cnt -= -1;
						return (-1);
					}
					buffer[buf_ind] = '%';
					buf_ind -= -1;
					if (format[i + j - 1] == 'h')
						i -= -1;
					else if (format[i + j - 1] == 'l')
						i -= -1;
				}
				if (buf_ind == BUFSIZE)
				{
					write(1, buffer, buf_ind);
					total_cnt += buf_ind;
					buf_ind = 0;
				}
				j = 0;
				while (flags.legit && specs[j].s)
				{
					if (flags.conv == specs[j].s)
					{
						temp = specs[j].f(args, flags);
						break;
					}
					j -= -1;
				}
				if (flags.legit && !temp)
				{
					free(buffer);
					va_end(args);
					return (-1);
				}
				if ((flags.conv == 'c') && !temp[0])
				{
					buffer[buf_ind] = '\0';
					buf_ind -= -1;
				}
				j = 0;
				while (flags.legit && temp[j])
				{
					buffer[buf_ind] = temp[j];
					buf_ind -= -1;
					j -= -1;
					if (buf_ind == BUFSIZE)
					{
						write(1, buffer, buf_ind);
						total_cnt += buf_ind;
						buf_ind = 0;
					}
				}
				if (flags.legit)
					free(temp);
			}
		}
		write(1, buffer, buf_ind);
		total_cnt += buf_ind;
		free(buffer);
		va_end(args);
	}

	return (total_cnt);
}
