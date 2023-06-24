#include "main.h"
/**
 * _printf - Print Formatted output
 * @format: Formatted for given string
 * Return: Int
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0;

	va_start(ap, format);

	if (format == NULL)
		exit(98);

	while (*format != '\0')
	{
		count++;
		if (*format == '%')
		{
			if (*++format == 'c')
			{
				_putchar((unsigned char) va_arg(ap, int));
			}
			else if (*format == 's')
			{
				char *str = va_arg(ap, char *);

				while (*str != '\0')
				{
					_putchar(*str);
					str++;
				}
			}
		}
		else
		{
			_putchar(*format);
		}
		format++;
	}
	va_end(ap);
	return (count);
}
