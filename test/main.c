#include <limits.h>
#include <stdio.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    int std; 
    int ours; 
    unsigned int ui;
    void *addr;
    int n1;
	int n2;

    n1 = 0;
    n2 = 0;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i], [%d, %i]\n", len2, len2, len, len);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("empty Character:[%c]\n", ' ');
    printf("empty Character:[%c]\n", ' ');
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
   _printf("Character:[%c%c]\n", 'H', 'I');
   printf("Character:[%c%c]\n", 'H', 'I');
   _printf("Character:[%c%c%c]\n", 'H', 'I', '!');
    printf("Character:[%c%c%c]\n", 'H', 'I', '!');


   _printf("Character:[%c %c %c]\n", 'H', 'I', '!');
    printf("Character:[%c %c %c]\n", 'H', 'I', '!');
   _printf("Two c with Space:[%c %c]\n", 'H', 'I');
    printf("Two c with Space:[%c %c]\n", 'H', 'I');
   _printf("empty String:[%s]\n", "");
    printf("empty String:[%s]\n", "");
   _printf("Space String:[%s]\n", " ");
    printf("Space String:[%s]\n", " ");
   _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
   _printf("String:[%s%s]\n", "I am a string !", "second string !");
    
    std = printf("String:[%s%s]\n", "I am a string !", "second string !");
    ours = _printf("String:[%s%s]\n", "I am a string !", "second string !");
    printf("Length:[%d, %i]\n", std, ours);

    printf("String:[%s %s]\n", "I am a string !", "second string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    _printf("Binary:[%b]\n", 98);
    printf("Binary:[%b]\n", 98);
    _printf("Decimal:[%i]\n", 58);
    printf("Decimal:[%i]\n", 58);
    _printf("Decimal:[%i]\n", 524);
    printf("Decimal:[%i]\n", 524);
    _printf("Negative Decimal:[%i]\n", -58);
    printf("Negative Decimal:[%i]\n", -58);
    _printf("Zero:[%i]\n", 0);
    printf("Zero:[%i]\n", 0);
    _printf("hello:[%i]\n", "He");
    printf("hello:[%i]\n", "Hello");
    _printf("NULL:[%i]\n", NULL);
    printf("NULL:[%i]\n", NULL);
    _printf("INT_MAX: [%i]\n", INT_MAX);
    printf("INT_MAX: [%i]\n", INT_MAX);
    _printf("INT_MIN: [%i]\n", INT_MIN);
    printf("INT_MIN: [%i]\n", INT_MIN);
	
	n1 = _printf("\nNumber: [%d], [%i]\n", 4034, 4034);
	n2 = printf("Number: [%d], [%i]\n", 4034, 4034);
	printf("Len:[%d]\n", n1);
	printf("Len1:[%d]\n\n", n2);
	
	n1 = _printf("Negative: [%i], [%d]\n", -4034, -4034);
	n2 = printf("Negative: [%i], [%d]\n", -4034, -4034);
	printf("Len:[%d]\n", n1);
	printf("Len1:[%d]\n\n", n2);

	n1 = _printf("long: [%i], [%d]\n", 4545439394949595, 4545439394949595);
	n2 = printf("long: [%i], [%d]\n", 4545439394949595, 4545439394949595);
	printf("Len:[%d]\n", n1);
	printf("Len1:[%d]\n\n", n2);

	n1 = _printf("long: [%i], [%d]\n", -4545439394949595, -4545439394949595);
	n2 = printf("long: [%i], [%d]\n", -4545439394949595, -4545439394949595);
	printf("Len:[%d]\n", n1);
	printf("Len1:[%d]\n\n", n2);

	n1 = _printf("NULL: [%i]\n", NULL);
	n2 = printf("NULL: [%i]\n", NULL);
	printf("Len:[%d]\n", n1);
	printf("Len1:[%d]\n\n", n2);

	n1 = _printf("[%d]\n", INT_MAX);
	n2 = printf("[%d]\n", INT_MAX);
	printf("Len:[%d]\n", n1);
	printf("Len1:[%d]\n\n", n2);

	n1 = _printf("[%d]\n", INT_MIN);
	n2 = printf("[%d]\n", INT_MIN);
	printf("Len:[%d]\n", n1);
	printf("Len1:[%d]\n\n", n2);


    _printf(NULL);
    printf(NULL);
    return (0);
}
