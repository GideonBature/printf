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
 * Return: Number of characters printed
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
 * print_num - print all digit of numbers
 * @num: number to be printed
 * Return: number of characters printed
 */
int print_num(int num)
{
	int count = 0;

	char str[20];
	int len = sprintf(str, "%d", num);

	return (write(1, str, len));
}

/**
 * print_bin - converts interger to binary
 * @num: number to be converted
 * Return: number of characters printed
 */
int print_bin_backwards(int num)
{
	int count = 0;

	if (num > 0)
	{
		count++;
		print_bin_backwards(num / 2);
		putchar(num % 2 + '0');
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
		exit(-1);

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
			else if (*format == 'd' || *format == 'i')
			{
				count += print_num(va_arg(ap, int));
			}
			else if (*format == 'b')
			{
				count += print_bin_backwards(va_arg(ap, int));
			}
			else if (*format == '%')
			{
				count++;
				_putchar(*format);
			}
			else
			{
				count++;
				_putchar(*--format);
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
