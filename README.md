# ft_printf

A simplified version of printf from libc

*Prints a string in at the standard output and returns the number of printed characters. You can include the following datatypes.*
| Supported Data types| Syntax |
|---------------------|---|
|Integers| ``%i`` ``%d``|
|Unsigned integers |``%u``|
|Unsigned integers in hexadecimal in lowercase| ``%x``|
|Unsigned integers in hexadecimal in uppercase| ``%X``|
|Characters | ``%c``|
|Strings| ``%s``|
|Pointer directions| ``%p``|
|%| ``%%``|

* This version of printf does not support **flags**
* Neither handles **buffering**

## Installation
```console
git clone https://github.com/chriss1245/printf.git
```
```console
make -C printf
```

## Usage
*Inside your files*
```c 
#include "printf/inc/ft_printf.h"
````
```c 
ft_printf("Hello world %d", 1);
````

*When compiling*
```console
gcc your_files.c printf/libftprintf.a
``` 

## How it works
It uses a data type ``va_list`` which can handle an arbitrary amount of arguments inside a funciton. That way we can recieve in our function a string and an arbitrary amount of arguments. 

Inside it runs a loop which writes a character in the standard output. If the character to be writen is a ``%`` it runs a helper function which determines which type of data is going to be printed and then calls the corresponding funciton. 

## Headerfile
There are primitive functions required by ft_printf. These funcitons are available an can be used importing the ``ft_printf.h``.

### Primitive funcitons
|Function|Description|
|:-------:|:--------:|
|``put_number``|Writes an integer in the standard output|
|``put_unsigned_number``|Writes an unsigned integer in the standard outpu|
|``put_string``|Writes an string in the standard output|
|``put_char``|Writes a character in the standard output|
|``put_hex``|Writes an hexadecimal number in the standar output (in lowercase if 'a' is passed or in uppercase if 'A' is passed)|
|``put_ptr``|Writes a pointer direction in lowercase in the standard output|
