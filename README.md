![Holberton school logo](https://secure.meetupstatic.com/photos/event/b/c/5/6/highres_475548214.jpeg)
# _Printf project repository

This repository contains the files for Holberton's **printf project**. It can be compiled using GCC and will produce an expected output given certain parameters.

# Pre-requisites

### Authorized functions and macros:
-   `write`  (`man 2 write`)
-   `malloc`  (`man 3 malloc`)
-   `free`  (`man 3 free`)
-   `va_start`  (`man 3 va_start`)
-   `va_end`  (`man 3 va_end`)
-   `va_copy`  (`man 3 va_copy`)
-   `va_arg`  (`man 3 va_arg`)

### GCC command to compile:
```
gcc -Wall -Werror -Wextra -pedantic *.c
```

### Main.c template to test output:
```
#include <limits.h>
#include <stdio.h>
#include "holberton.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    return (0);
}
```

After you clone this repository and compile the program with the command above, you will generate a file called **a.out** that can be executed by entering  ```./a.out``` in your terminal.

The output after the program is executed should look something like this:
```
Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
Length:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Unsigned:[2147484671]
Unsigned:[2147484671]
Unsigned octal:[20000001777]
Unsigned octal:[20000001777]
Unsigned hexadecimal:[800003ff, 800003FF]
Unsigned hexadecimal:[800003ff, 800003FF]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Address:[0x7ffe637541f0]
Address:[0x7ffe637541f0]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12]
```

## Files contained:

Brief description of files contained in project:

|                File                          |Content                         |
|----------------|-------------------------------|-----------------------------|
|holberton.h|Contains prototypes of functions and structures to be called.            
|_printf.c          |Selects function to be called given a certain character and then uses the string saved in the buffer along with the write function to print the result.          |
|buffyflags.c          |Scans argument for certain chars and uses boolean variables (flags) to add the character to the print.
|numbering_system.c          |Functions to handle hex, oct, unsigned int conversions. 
|convertions.c|Functions to handle rot13, rev, and special case conversions.
|functions.c|Functions to handle int, string, %, and binary conversions.
|spec_chars.c          |Functions to handle address prints, spaces for numbers, special 0's to hex and oct conversions.
|width.c | Function to increase size of string and adapt length to space or provide minimum length.
|README| .this




### Contact Info:
Git: [David Castellanos](https://github.com/davidcastellanos), [Sergio Pietri](https://github.com/Virteip)
Twitter: [@davcastellanosp](https://twitter.com/davcastellanosp), [@sergiopietri](https://twitter.com/sergiopietri)
