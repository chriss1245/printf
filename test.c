#include "inc/ft_printf.h"
int main()
{
	char c = 'a';
	char s[] = "carlitos";
	ft_printf("it should be (a) (%c) \n", c);
	ft_printf("it should be (carlitos) (%s) \n", s);
}
