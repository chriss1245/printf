#include "inc/ft_printf.h"
#include <limits.h>
#include <stdio.h>
int main()
{
	char c = 'a';
	char s[] = "carlitos";
	int zero = 0;
	unsigned int uzero = 0;
	void *p;

	ft_printf("(%p)\n", s);
	ft_printf("%X\n", UINT_MAX);
	ft_printf("(%x) \n",123);
	ft_printf("(%X) \n",123);
	ft_printf("it should be (a) (%c) \n", c);
	ft_printf("it should be (carlitos) (%s) \n", s);
	ft_printf("it should be (0) (%i) \n", zero);
	ft_printf("it should be (max integer) (%i) \n", INT_MAX);
	ft_printf("it should be (min integer) (%i) \n", INT_MIN);
	ft_printf("it should be (0) (%u) \n", uzero);
	ft_printf("it should be (max uint) (%u)\n", UINT_MAX);
	ft_printf("it should be (-2) (%i)\n", -2);
}
