/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:22:07 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/05 15:29:19 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		number(int d, int fd, int nbr, t_conv_spec cs)
{
	int len;
    int i;
	char c;

	i = d;
	len = 0;
	c = ' ';
	if (d < 0)
		len++;
	while (d/10)
	{
		len++;
		d = d/10;
	}
	len++;
	if (cs.flag_zero)
		c = '0';
	if (cs.flag_plus || cs.flag_space)
		len++;
	if (cs.flag_minus)
	{	
		if (cs.flag_plus)
			ft_putchar_fd('+', fd);
		else if (cs.flag_space)
			ft_putchar_fd(' ', fd);
		ft_putnbr_fd(i, fd);
		while (cs.width > len)
		{
			ft_putchar_fd(c, fd);
			len++;
		}
	}
	else 
	{
		if (cs.flag_zero && cs.flag_plus)
			ft_putchar_fd('+', fd);
		else if (cs.flag_space && cs.flag_zero)
			ft_putchar_fd(' ', fd);
		while (cs.width > len)
		{
			ft_putchar_fd(c, fd);
			len++;
		}
		if (cs.flag_plus && !cs.flag_zero)
			ft_putchar_fd('+', fd);
		else if (cs.flag_space && !cs.flag_zero)
			ft_putchar_fd(' ', fd);
		ft_putnbr_fd(i, fd);
	}
	return (nbr + len);
}

int		string(char *s, int fd, int nbr, t_conv_spec cs)
{
	size_t len;

	len = ft_strlen(s);
	if (cs.flag_minus)
	{	
		ft_putstr_fd(s, fd);
		while (cs.width > len)
		{
			ft_putchar_fd(' ', fd);
			len++;
		}
	}
	else
	{
		while (cs.width > len)
		{
			ft_putchar_fd(' ', fd);
			len++;
		}
		ft_putstr_fd(s, fd);
	}
	return (nbr + len);
}

int		character(int d, int fd, int nbr, t_conv_spec cs)
{
	size_t len;

	len = 1;	
	if (cs.flag_minus)
	{
		ft_putchar_fd(d, fd);
		while (cs.width > len)
		{
			ft_putchar_fd(' ', fd);
			len++;
		}
	}
	else 
	{
		while (cs.width > len)
		{
			ft_putchar_fd(' ', fd);
			len++;
		}
		ft_putchar_fd(d, fd);
	}
	return (nbr + len);
}
