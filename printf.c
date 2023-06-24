#include "main.h"
/**
 * _printf - Print Formatted output
 * @format: Formatted for given string
 * Return: Int
 */
int _printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);

	if (format == NULL)
		exit(98);

	// %c or %s
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if ((*++format) == 'c')
			{
				_putchar((unsigned char) va_arg(ap, int));
			}

			printf("%s", *format);
			if ((*++format) == 's')
			{
				char *str = va_arg(ap, char *);
				printf("\n Ours: %s\n", *str);
				/**
				while (*str != '\0')
				{
					_putchar(*str);
					*str++;
				}
				*/
			}
		}
		_putchar(*format);
		*format++;
	}
	va_end(ap);
	return (0);
}
