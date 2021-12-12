/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:54:19 by cmanzano          #+#    #+#             */
/*   Updated: 2021/12/12 14:03:10 by cmanzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	insert_arg(char c, va_list args)
{
	if (c == 'c')
		return (put_char(va_arg(args, int)));
	else if (c == 's')
		return (put_string(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (put_number(va_arg(args, int)));
	else if (c == 'u')
		return (put_unsigned_number(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (put_hex(va_arg(args, unsigned int), 'a'));
	else if (c == 'X')
		return (put_hex(va_arg(args, unsigned int), 'A'));
	else if (c == '%')
		return (write(1, "%", 1));
	else if (c == 'p')
		return (put_ptr(va_arg(args, void *)));
	else if (c != 0)
		return (write(1, &c, 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list			args;
	unsigned int	i;
	int				printed;

	if (s == 0)
		return (0);
	i = 0;
	printed = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			printed += insert_arg(s[i], args);
		}
		else
			printed += write(1, s + i, 1);
		i++;
	}
	va_end(args);
	return (printed);
}
