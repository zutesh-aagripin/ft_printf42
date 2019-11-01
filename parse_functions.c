/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:20:13 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/15 20:59:00 by kbryce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		set_flag(char c, t_conv_spec *cs)
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
	return (1);
}

char	is_flag(char c)
{
	return (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ');
}

int		is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int		is_length(char c)
{
	return (c == 'h' || c == 'l' || c == 'L' || c == 't' || c == 'z'
			|| c == 'j');
}

int		is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == '%'
			|| c == 'Z' || c == 'f');
}
