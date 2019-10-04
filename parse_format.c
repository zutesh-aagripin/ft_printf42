/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:20:13 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/04 22:29:45 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_flag(char c)
{
	return (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ');
}

void	set_flag(char c, t_conv_spec *cs)
{
	if (c == '#')
		cs->flag_sharp = 1;
	else if (c == '0')
		cs->flag_zero = 1;
	else if (c == '-')
		cs->flag_minus = 1;
	else if (c == '+')
		cs->flag_plus = 1;
	else if (c == ' ')
		cs->flag_space = 1;
}

int		is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int		is_length(char c)
{
	return (c == 'h' || c == 'l' || c == 'L');
}

int		is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'o' || c == 'u' || c == 'x' || c == 'X');
}

int		parse_format(char *format, t_conv_spec *cs)
{
	char		*f;

	cs->width = 0;
	cs->precision = 0;
	cs->type_set = 0;
	cs->width_set = 0;
	cs->flags_set = 0;
	cs->flag_minus = 0;
	f = format;
	while (*f)
	{
		if (!cs->flags_set && is_flag(*f))
		{
			set_flag(*f, cs);
			f++;
		}
		else if (!cs->width_set && is_digit(*f))
		{
			cs->flags_set = 1;
			while (*f && is_digit(*f))
			{
				cs->width = cs->width * 10 + (*f - '0');
				f++;
			}
		}
		else if (!cs->precision_set && *f == '.')
		{
			cs->flags_set = 1;
			cs->width_set = 1;
			cs->has_dot = 1;
			f++;
		}
		else if (cs->has_dot && !cs->precision_set && is_digit(*f))
		{
			while (*f && is_digit(*f))
			{
				cs->precision = cs->precision * 10 + (*f - '0');
				f++;
			}
			cs->precision_set = 1;
		}
		else if (!cs->length_set && is_length(*f))
		{
			cs->flags_set = 1;
			cs->width_set = 1;
			cs->precision_set = 1;
			if (*f == 'h')
				cs->length = (*(f + 1) == 'h') ? LEN_HH : LEN_H;
			else if (*f == 'l')
				cs->length = (*(f + 1) == 'l') ? LEN_LL : LEN_L;
			else if (*f == 'L')
				cs->length = LEN_BIG_L;
			f++;
			if (cs->length == LEN_HH || cs->length == LEN_LL)
				f++;
			cs->length_set = 1;
		}
		else if (is_type(*f))
		{
			cs->type = *f;
			cs->type_set = 1;
			f++;
			break ;
		}
		else
			return (f - format);
	}
	ft_putnbr((int)cs->width);
	ft_putnbr(cs->flag_minus);
	ft_putnbr(f - format);
	ft_putchar('\n');
	return (f - format);
}
