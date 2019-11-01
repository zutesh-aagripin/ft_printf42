/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:20:13 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/16 15:33:08 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		asterix(t_conv_spec *cs, char **f, va_list arg)
{
	if (cs->has_dot)
	{
		cs->precision = va_arg(arg, int);
		cs->precision_set = 1;
	}
	else
		cs->width = va_arg(arg, int);
	if (cs->width < 0)
	{
		cs->width = -cs->width;
		cs->flag_minus = 1;
	}
	if (cs->precision < 0)
	{
		cs->has_dot = 0;
		cs->precision_set = 0;
		cs->precision = 0;
	}
	*f += 1;
}

void		ft_length(char **f, t_conv_spec *cs)
{
	if (**f == 'h')
		cs->length = (*(*f + 1) == 'h') ? LEN_HH : LEN_H;
	else if (**f == 'l')
		cs->length = (*(*f + 1) == 'l') ? LEN_LL : LEN_L;
	else if (**f == 't' || **f == 'z' || **f == 'j')
		cs->length = LEN_LL;
	else if (**f == 'L')
		cs->length = LEN_BIG_L;
	*f += 1;
	if (cs->length == LEN_HH || (cs->length == LEN_LL && **f == 'l'))
		*f += 1;
	cs->length_set = 1;
}

int			mini_atoi(char **f, long int nb)
{
	nb = 0;
	while (**f && is_digit(**f))
	{
		nb = nb * 10 + (**f - '0');
		*f += 1;
	}
	return (nb);
}

void		ft_dot(char **f, t_conv_spec *cs)
{
	cs->width_set = 1;
	cs->has_dot = 1;
	*f += 1;
	if (!(is_digit(**f)))
	{
		cs->precision_set = 1;
		cs->precision = 0;
	}
}

void		parse_format(char **f, t_conv_spec *cs, va_list arg)
{
	while (**f)
	{
		if (!cs->precision_set && **f == '.')
			ft_dot(f, cs);
		else if (cs->has_dot && !cs->precision_set && is_digit(**f))
		{
			cs->precision = mini_atoi(f, cs->precision);
			cs->precision_set = 1;
		}
		else if (!cs->flags_set && is_flag(**f))
			*f += (set_flag(**f, cs));
		else if (!cs->width_set && is_digit(**f))
			cs->width = mini_atoi(f, cs->width);
		else if (**f == '*')
			asterix(cs, f, arg);
		else if (!cs->length_set && is_length(**f))
			ft_length(f, cs);
		else if (is_type(**f))
		{
			cs->type = **f;
			break ;
		}
		else if (**f)
			*f += 1;
	}
}
