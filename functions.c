/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:22:07 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/15 17:16:17 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_to_null(t_conv_spec *cs)
{
	cs->width = 0;
	cs->precision = 0;
	cs->type_set = 0;
	cs->width_set = 0;
	cs->flags_set = 0;
	cs->flag_minus = 0;
	cs->flag_zero = 0;
	cs->flag_sharp = 0;
	cs->length = LEN_NONE;
	cs->flag_plus = 0;
	cs->length_set = 0;
	cs->flag_space = 0;
	cs->type = 0;
	cs->has_dot = 0;
	cs->precision_set = 0;
}

int		putout(char *print, int fd, int nbr, t_conv_spec cs)
{
	int len;

	if (cs.type == 'X')
		ft_strupcase(print);
	len = ft_strlen(print);
	write(fd, print, len);
	return (nbr + len);
}

int		character(char *print, int fd, int nbr, t_conv_spec cs)
{
	int		len;
	char	c;

	len = 1;
	if (cs.flag_minus)
	{
		ft_putchar_fd(*print, fd);
		while (cs.width > len)
		{
			ft_putchar_fd(' ', fd);
			len++;
		}
	}
	else
	{
		c = cs.flag_zero ? '0' : ' ';
		while (cs.width > len)
		{
			ft_putchar_fd(c, fd);
			len++;
		}
		ft_putchar_fd(*print, fd);
	}
	return (nbr + len);
}
