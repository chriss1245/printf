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
#include "printf/inc/ft_libft.h"
````
```c 
ft_printf("Hello world %d", 1);
````

*When compiling*
```console
gcc your_files.c printf/libftprintf.a
``` 
