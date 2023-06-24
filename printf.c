#include "main.h"
/**
 * print_null - Print null as string
 */
void print_null(void)
{
	char *nullstr = "(null)";

	while (*nullstr != '\0')
	{
		_putchar(*nullstr);
		nullstr++;
	}
}

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

				if (str == NULL)
					print_null();
				else
				{
					while (*str != '\0')
					{
						_putchar(*str);
						str++;
					}
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
