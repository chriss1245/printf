/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:30:39 by cmanzano          #+#    #+#             */
/*   Updated: 2021/12/12 13:51:23 by cmanzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	put_hex_long(unsigned long long int n)
{
	char	c;
	int		i;

	if (n < 16)
	{
		if (n > 9)
			c = (n - 10) + 'a';
		else
			c = n + '0';
		return (write(1, &c, 1));
	}
	i = put_hex_long(n / 16);
	if (n % 16 > 9)
		c = (n % 16 - 10) + 'a';
	else
		c = (n % 16) + '0';
	return (i + write(1, &c, 1));
}

int	put_ptr(void *p)
{
	unsigned long long int	ptr;
	int						len;

	ptr = (unsigned long long int) p;
	len = write(1, "0x", 2);
	return (len + put_hex_long(ptr));
}
