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
   _printf("Character:[%c%c%c]\n", 'H', 'I', '!');
    printf("Character:[%c%c%c]\n", 'H', 'I', '!');
   _printf("null Character:[%c%c%c]\n", 'H', 'I', NULL);
    printf("null Character:[%c%c%c]\n", 'H', 'I', NULL);

   _printf("Character:[%c %c %c]\n", 'H', 'I', '!');
    printf("Character:[%c %c %c]\n", 'H', 'I', '!');
   _printf("Character:[%c %c]\n", 'H', 'I');
    printf("Character:[%c %c]\n", 'H', 'I');
   _printf("empty String:[%s]\n", "");
    printf("empty String:[%s]\n", "");
   _printf("empty String:[%s]\n", " ");
    printf("empty String:[%s]\n", " ");
   _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
   _printf("String:[%s%s]\n", "I am a string !", "second string !");
    
    std = printf("String:[%s%s]\n", "I am a string !", "second string !");
    ours = _printf("String:[%s%s]\n", "I am a string !", "second string !");
    printf("Length:[%d, %i]\n", std, ours);

    printf("String:[%s %s]\n", "I am a string !", "second string !");
    printf("String:[%s%s]\n", "I am a string !", NULL);
    _printf("String:[%s%s]\n", "I am a string !", NULL);
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
    return (0);
}
