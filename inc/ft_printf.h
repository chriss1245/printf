/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:50:14 by cmanzano          #+#    #+#             */
/*   Updated: 2021/12/12 13:48:56 by cmanzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...) __attribute__((format(printf, 1, 2)));
int	put_number(int n);
int	put_unsigned_number(unsigned int n);
int	put_string(char *str);
int	put_char(int c);
int	put_hex(unsigned int n, char a);
int	put_ptr(void *p);
#endif
