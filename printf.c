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
 * printstring - print a string
 * @str: String to print
 * Return: Integer
 */
int printstring(char *str)
{
	int count = 0, nullLength = 6;

	if (str == NULL)
	{
		print_null();
		count += nullLength;
	}
	else
	{
		while (*str != '\0')
		{
			count++;
			_putchar(*str);
			str++;
		}
	}
	return (count);
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
		if (*format == '%')
		{
			if (*++format == 'c')
			{
				count++;
				_putchar((unsigned char) va_arg(ap, int));
			}
			else if (*format == 's')
			{
				char *str = va_arg(ap, char *);

				count += printstring(str);
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(ap);
	return (count);
}
