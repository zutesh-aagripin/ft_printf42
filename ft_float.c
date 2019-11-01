/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbryce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:49:24 by kbryce            #+#    #+#             */
/*   Updated: 2019/10/15 20:51:15 by kbryce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_float.h"
#include "libftprintf.h"

static t_fbits		get_bits(long double *pf)
{
	unsigned char	*p;
	unsigned short	*pe;
	unsigned long	*pm;

	p = (unsigned char *)(pf);
	pe = (unsigned short *)(p + 8);
	pm = (unsigned long *)(p + 0);
	return ((t_fbits){pe, pm});
}

static t_float		parse_float(long double f)
{
	unsigned int	expo;
	unsigned long	mant;
	t_float			res;
	t_fbits			bits;

	res = (t_float){f, 0, 0l, 0, 0, 0, 0};
	bits = get_bits(&f);
	expo = *bits.pe;
	expo &= ~(1UL << 15);
	mant = *bits.pm;
	res.sign = (*bits.pe >> 15) ? '-' : '+';
	if (!expo && !mant)
		res.is_zero = 1;
	else if (expo == ((1U << 15) - 1) && mant == (1UL << 63))
		res.is_inf = 1;
	else if (expo == ((1U << 15) - 1) && (mant << 1))
		res.is_nan = 1;
	else
	{
		res.m = mant;
		res.power_of_2 = (int)expo - (16383 + 63);
	}
	return (res);
}

char				*process_special(t_float *f)
{
	char	*res;

	if ((res = ft_strnew(5)) == NULL)
		return (NULL);
	if (f->is_inf)
	{
		res[0] = 'i';
		res[1] = 'n';
		res[2] = 'f';
		res[3] = '\0';
	}
	else if (f->is_nan)
	{
		res[0] = 'n';
		res[1] = 'a';
		res[2] = 'n';
		res[3] = '\0';
	}
	else if (f->is_zero)
	{
		res[0] = '0';
		res[1] = '\0';
	}
	return (res);
}

static char			*print_float_normal(t_float *fff)
{
	char	*res;

	res = get_full_string(fff);
	if (!res)
		return (NULL);
	normalize_str(res);
	reverse_str(res);
	if (fff->power_of_2 < 0)
	{
		res = insert_comma(res, -1 * fff->power_of_2);
		if (!res)
			return (NULL);
		clear_tail_zeroes(res);
	}
	return (res);
}

int					print_float(long double f, t_conv_spec *cs)
{
	t_float		fff;
	char		*res;
	int			nbr;

	res = NULL;
	fff = parse_float(f);
	if (fff.is_inf || fff.is_nan || fff.is_zero)
	{
		if (!(res = process_special(&fff)))
			return (0);
		if (fff.is_zero)
			handle_precision(&res, cs->precision);
	}
	else
	{
		if (!(res = print_float_normal(&fff)))
			return (0);
		handle_precision(&res, cs->precision);
		if (res[ft_strlen(res) - 1] == '.')
			res[ft_strlen(res) - 1] = '\0';
	}
	nbr = real_print_float(res, cs->width, &fff, cs);
	free(res);
	return (nbr);
}
