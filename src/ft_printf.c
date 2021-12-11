/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:54:19 by cmanzano          #+#    #+#             */
/*   Updated: 2021/12/10 22:11:04 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

int	put_string(char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
		i += write(1, str + i, 1);	
	return (i);
}

int rec_put_number(long int n)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

int	put_number(int n)
{
	long int	n_;

	n_ = (long int) n;
	if (n == 0)
		return (write(1, "0", 1);
	if (n < 0)
		return (write(1, "-", 1) + rec_put_number());
}

int	insert_arg(char c, va_list args)
{
	if (c == 'c')
	{
		return (write(1, va_arg(args, char *), 1));
	}
	else if (c == 's')
	{
		return (put_string(va_arg(args, char *)));
	}
	else if (c == 'i')
	{
	}
	return (0);
}



int	ft_printf(const char *s, ...)
{
	va_list			args;
	unsigned int	i;
	
	i = 0;
	va_start(args, s);
	while(s[i])
	{
		if (s[i] == '%')
		{
			i++;
			insert_arg(s[i], args);
		}
		else
			write(1, s + i, 1);
		i++;
	}
	va_end(args);
	return (0);
}
