/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:53:48 by cmanzano          #+#    #+#             */
/*   Updated: 2021/12/11 18:49:07 by cmanzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int put_unsigned_number(unsigned int n)
{
	char	c;
	int		i;

	if (n < 10)
	{
		c = n + '0';
		return (write(1, &c, 1));
	}
	i = put_unsigned_number(n / 10);
	c = (n % 10) + '0';
	return (i + write(1, &c, 1));
}

int	put_number(int n)
{
	long int	n_;

	n_ = (long int) n;
	if (n < 0)
		return (write(1, "-", 1) + put_unsigned_number(n_ * -1));
	return (put_unsigned_number(n_));
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
