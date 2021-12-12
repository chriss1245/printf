/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:30:39 by cmanzano          #+#    #+#             */
/*   Updated: 2021/12/11 22:55:29 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	put_hex()

int	put_ptr(void *p)
{
	unsigned long long int	ptr;

	ptr = (unsigned long long int) p;
	
	return (0);
}



int put_hex(unsigned int n, char a)
{
	char	c;
	int		i;

	if (n < 16)
	{
		if (n > 9)
			c = (n - 10) + a;
		else
			c = n + '0';

		return (write(1, &c, 1));
	}
	i = put_hex(n / 16, a);
	if (n % 16 > 9)
		c = (n % 16 - 10) + a;
	else
		c = (n % 16) + '0';
	return (i + write(1, &c, 1));
}
