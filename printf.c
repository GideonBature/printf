#include "main.h"
#include <limits.h>
#define _NULL NULL

int _printf(const char *format, ...);

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

	if (str == _NULL)
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
int print_num(long int num)
{
	long int rev = 0, digit, count = 0;

	if (num == INT_MIN)
	{
		_putchar('-');
		_putchar('2');
		num = 147483648;
		count += 2;
	}

	if (num == INT_MAX)
	{
		_putchar('2');
		num = 147483647;
		count += 1;
	}

	if (num < 0)
	{
		_putchar('-');
		num = -num;
		count += 1;
	}

	if (num == 0)
	{
		_putchar('0');
		count += 1;
		return (count);
	}
	while (num > 0)
	{
		int digit = num % 10;

		rev = rev * 10 + digit;
		num /= 10;
		count += 1;
	}
	while (rev > 0)
	{
		digit = rev % 10;
		_putchar(digit + '0');
		rev /= 10;
	}

	return (count);
}

/**
 * print_bin - converts interger to binary
 * @num: number to be converted
 * Return: number of characters printed
 */
int print_bin(int num)
{
	if (num > 0)
	{
		print_bin(num / 2);
		_putchar((num % 2) + '0');
	}
	return (0);
}

/**
 * print_unsigned_int - print unsigned int
 * @num: number to be printed
 * Return: 0
 */
int print_unsigned_int(unsigned int num)
{
	if (num >= 10)
	{
		print_unsigned_int(num / 10);
	}
	_putchar((num % 10) + '0');
	return (0);
}

/**
 * print_octal - converts interger to binary
 * @num: number to be converted
 * Return: number of characters printed
 */
int print_octal(int num)
{
	if (num > 0)
	{
		print_octal(num / 8);
		_putchar((num % 8) + '0');
	}
	return (0);
}

/**
 * print_hexa_x - converts interger to hexadecimal
 * @num: number to be converted
 * Return: number of characters printed
 */
int print_hexa_x(int num)
{
	int rem;

	if (num >= 16)
	{
		print_hexa_x(num / 16);
	}
	rem = num % 16;
	if (rem < 10)
	{
		_putchar(rem + '0');
	}
	else
	{
		_putchar('a' + rem - 10);
	}
	return (0);
}

/**
 * print_hexa_X - converts interger to hexadecimal
 * @num: number to be converted
 * Return: number of characters printed
 */
int print_hexa_X(int num)
{
	int rem;

	if (num >= 16)
	{
		print_hexa_X(num / 16);
	}
	rem = num % 16;
	if (rem < 10)
	{
		_putchar(rem + '0');
	}
	else
	{
		_putchar('A' + rem - 10);
	}
	return (0);
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

	if (!format)
	{
		return (-1);
	}

	if (format == NULL)
		exit(139);

	va_start(ap, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*++format == 'c')
			{
				_putchar((unsigned char) va_arg(ap, int));
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(ap, char *);

				count += printstring(str);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(ap, long int);
				count += print_num(num);
			}
			else if (*format == 'b')
			{
				print_bin(va_arg(ap, int));
			}
			else if (*format == 'u')
			{
				print_unsigned_int(va_arg(ap, unsigned int));
			}
			else if (*format == 'o')
			{
				print_octal(va_arg(ap, int));
			}
			else if (*format == 'x')
			{
				print_hexa_x(va_arg(ap, int));
			}
			else if (*format == 'X')
			{
				print_hexa_X(va_arg(ap, int));
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
