/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_real_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbryce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:46:46 by kbryce            #+#    #+#             */
/*   Updated: 2019/10/15 21:20:25 by kbryce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_float.h"
#include "libftprintf.h"

static int		calc_chars(char *res, t_float *fff, t_conv_spec *cs)
{
	int		len;

	len = 0;
	if (!fff->is_nan && (fff->sign == '-' || cs->flag_plus ||
		cs->flag_space))
		len++;
	if (!fff->is_nan && !fff->is_inf && cs->flag_sharp &&
		!ft_strchr(res, '.'))
		len++;
	len += ft_strlen(res);
	return (len);
}

static void		print_sign(char sign, t_conv_spec *cs, int is_nan)
{
	if (is_nan)
		return ;
	if (sign == '-')
		ft_putchar('-');
	else
	{
		if (cs->flag_plus)
			ft_putchar('+');
		else if (cs->flag_space)
			ft_putchar(' ');
	}
}

static void		real_print_f_3(char *res, int p, t_float *fff, t_conv_spec *cs)
{
	if (fff->is_inf || fff->is_nan)
	{
		pad(' ', p);
		print_sign(fff->sign, cs, fff->is_nan);
	}
	else
	{
		print_sign(fff->sign, cs, fff->is_nan);
		pad('0', p);
	}
	ft_putstr(res);
	if (!fff->is_nan && !fff->is_inf && cs->flag_sharp &&
		!ft_strchr(res, '.'))
		ft_putchar('.');
}

static void		real_print_f_2(char *res, int p, t_float *fff, t_conv_spec *cs)
{
	pad(' ', p);
	print_sign(fff->sign, cs, fff->is_nan);
	ft_putstr(res);
	if (!fff->is_nan && !fff->is_inf && cs->flag_sharp &&
		!ft_strchr(res, '.'))
		ft_putchar('.');
}

int				real_print_float(char *res, int w, t_float *fff,
	t_conv_spec *cs)
{
	int	nbr;

	nbr = calc_chars(res, fff, cs);
	if (cs->flag_minus)
	{
		print_sign(fff->sign, cs, fff->is_nan);
		ft_putstr(res);
		if (!fff->is_nan && !fff->is_inf && cs->flag_sharp &&
			!ft_strchr(res, '.'))
			ft_putchar('.');
		pad(' ', w - nbr);
	}
	else
	{
		if (cs->flag_zero)
			real_print_f_3(res, w - nbr, fff, cs);
		else
			real_print_f_2(res, w - nbr, fff, cs);
	}
	if (w - nbr > 0)
		return (w);
	else
		return (nbr);
}
