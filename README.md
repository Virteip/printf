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

[**holberton.h**](./holberton.h) : contains prototypes of functions and structures to be called.

[**_printf.c**](./_printf.c): selects function to be called given a certain character and then uses the string saved in the buffer along with the write function to print the result. 

[**buffyflags.c**](./buffyflags.c):  creates buffer and saves string to be later printed with write.

[**buffyflags2.c**](./buffyflags2.c): scans argument for certain chars and uses boolean variables (flags) to add the character to the print.

[**functions.c**](./functions.c): functions to convert chars to string, handle ints, change args to strings, and to binary.

[**numbering_system.c**](./numbering_system.c): change unsigned int to string, octal to string.

[**numbering_system2.c**](./numbering_system2.c): string with hexa.

[**spc_chars.c**](./spc_chars.c): nil array to be printed, prints address.

[**spc_chars2.c**](./spc_chars.c): malloc for % sign; adds '+', '  ', '0', '0x', or '0X'.

[**width.c**](./width.c): adjusts string length.

[**convertions.c**](./convertions.c):  base funcs to convert to rot13, rev.

[**convertions_2.c**](./convertions_2.c):  strings with special case.

README.md: this.

## General Flow Chart:

<a href="https://ibb.co/QpnwmV3"><img src="https://i.ibb.co/mbtWzKV/Untitled-Diagram.png" alt="Untitled-Diagram" border="0"></a>

### Contact Info:
Git: [David Castellanos](https://github.com/davidcastellanos), [Sergio Pietri](https://github.com/Virteip)
Twitter: [@davcastellanosp](https://twitter.com/davcastellanosp), [@sergiopietri](https://twitter.com/sergiopietri)
