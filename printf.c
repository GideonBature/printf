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
		return (nullLength);
	}

	while (*str != '\0')
	{
		count++;
		_putchar(*str);
		str++;
	}

	return (count);
}

/**
 * countchar - count number of chars
 * @str: string to count
 * Return: Length of char
 */
int countchar(char *str)
{
	int charcount = 0;

	while (*str != '\0')
	{
		charcount++;
		str++;
	}
	return (charcount);
}

/**
 * printreverse - Print reversed string
 * @str: String to reverse
 * Return: length of written string
 */
int printreverse(char *str)
{
	int count = 0, nullLength = 6, charcount = 0;

	if (str == _NULL)
	{
		print_null();
		return (nullLength);
	}

	charcount = countchar(str);

	while (charcount != 0)
	{
		count++;
		_putchar(str[--charcount]);
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
int print_bin(int num, int *count)
{

	if (num > 0)
	{
		print_bin(num / 2, count);
		_putchar((num % 2) + '0');
		(*count)++;
	}

	return (0);
}

/**
 * print_unsigned_int - print unsigned int
 * @num: number to be printed
 * Return: 0
 */
int print_unsigned_int(unsigned int num, int *count)
{
	if (num >= 10)
	{
		print_unsigned_int(num / 10, count);
	}
	_putchar((num % 10) + '0');
	(*count)++;
	return (0);
}

/**
 * print_octal - converts interger to binary
 * @num: number to be converted
 * Return: number of characters printed
 */
int print_octal(unsigned int num, int *count)
{
	if (num > 0)
	{
		print_octal(num / 8, count);
		_putchar((num % 8) + '0');
		(*count)++;
	}
	return (0);
}

/**
 * print_hexa_x - converts interger to hexadecimal
 * @num: number to be converted
 * Return: number of characters printed
 */
int print_hexa_x(unsigned int num, int *count)
{
	int rem;

	int count_x = 0;

	if (num >= 16)
	{
		print_hexa_x((num / 16), count);
	}
	rem = num % 16;
	if (rem < 10)
	{
		_putchar(rem + '0');
		count_x++;
	}
	else
	{
		_putchar('a' + rem - 10);
		count_x++;
	}
	*count += count_x;
	return (count_x);
}

/**
 * print_hexa_X - converts interger to hexadecimal
 * @num: number to be converted
 * Return: number of characters printed
 */
int print_hexa_X(unsigned int num, int *count)
{
	int rem;
	int count_X = 0;

	if (num >= 16)
	{
		print_hexa_X(num / 16, count);
	}
	rem = num % 16;
	if (rem < 10)
	{
		_putchar(rem + '0');
		count_X++;
	}
	else
	{
		_putchar('A' + rem - 10);
		count_X++;
	}
	*count += count_X;
	return (count_X);
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

	if (format == NULL)
	{
		return (-1);
	}

	va_start(ap, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*++format == 'c')
			{
				_putchar((unsigned char)va_arg(ap, int));
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(ap, char *);

				count += printstring(str);
			}
			else if (*format == 'r')
			{
				char *str = va_arg(ap, char *);

				count += printreverse(str);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(ap, long int);

				count += print_num(num);
			}
			else if (*format == 'b')
			{
				int num = va_arg(ap, int);
				count += print_bin(num, &count);
			}
			else if (*format == 'u')
			{
				unsigned int num = va_arg(ap, unsigned int);
				count += print_unsigned_int(num, &count);
			}
			else if (*format == 'o')
			{
				unsigned int num = va_arg(ap, unsigned int);
				count += print_octal(num, &count);
			}
			else if (*format == 'x')
			{
				int num = va_arg(ap, int);
				count += print_hexa_x(num, &count);
				count--;
			}
			else if (*format == 'X')
			{
				int num = va_arg(ap, int);
				count += print_hexa_X(num, &count);
				count--;
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
