/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:54:19 by cmanzano          #+#    #+#             */
/*   Updated: 2021/12/08 17:24:43 by cmanzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

int	insert_arg(char c, va_list args)
{
	if (c == 'c')
	{
		return (write(1, va_arg(args, char *), 1));
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
