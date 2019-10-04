/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:22:07 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/04 21:16:13 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		number(int d, int fd, int nbr)
{
	ft_putnbr_fd(d, fd);
	if (d < 0)
		nbr++;
	while (d/10)
	{
		nbr++;
		d = d/10;
	}
	nbr++;
	return (nbr);
}

int		string(char *s, int fd, int nbr, t_conv_spec cs)
{
	size_t len;

	len = ft_strlen(s);
	if (cs.flag_minus)
	{	
		while (cs.width > len)
		{
			ft_putchar_fd(' ', fd);
			len++;
		}
	}
	ft_putstr_fd(s, fd);
	while (cs.width > len)
	{
		ft_putchar_fd(' ', fd);
		len++;
	}
	return (nbr + len);
}

int		character(int d, int fd, int nbr)
{
	ft_putchar_fd(d, fd);
	return (nbr + 1);
}
