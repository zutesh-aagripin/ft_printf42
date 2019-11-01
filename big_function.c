/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:20:13 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/16 16:35:17 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_float.h"

void	length(char *format, va_list arg, char **print, t_conv_spec cs)
{
	if (cs.length == LEN_L)
		ft_switchl(format, arg, print);
	else if (cs.length == LEN_LL || cs.length == LEN_BIG_L)
		ft_switchll(format, arg, print);
	else if (cs.length == LEN_NONE)
		ft_switch(format, arg, print);
	else if (cs.length == LEN_H)
		ft_switchh(format, arg, print);
	else if (cs.length == LEN_HH)
		ft_switchhh(format, arg, print);
}

int		process_float(va_list arg, t_conv_spec *cs, int nbr)
{
	if (cs->precision_set == 0)
		cs->precision = 6;
	if (cs->length == LEN_BIG_L)
		return (nbr + print_float((va_arg(arg, long double)), cs));
	else
		return (nbr + print_float((long double)(va_arg(arg, double)), cs));
}

int		funpart(int fd, char **format, va_list arg, int nbr)
{
	t_conv_spec cs;
	char		*print;

	print = NULL;
	set_to_null(&cs);
	parse_format(format, &cs, arg);
	if (cs.type == 'f')
		return (process_float(arg, &cs, nbr));
	length(*format, arg, &print, cs);
	if (print == NULL && cs.type != 's')
		return (nbr);
	if (print == NULL && cs.type == 's')
		print = ft_strjoin("", "(null)");
	precision(&print, cs);
	if (cs.type != 'c' && cs.type != '%' && cs.type != 'Z')
		width(&print, cs);
	if (cs.type == 'c' || cs.type == '%' || cs.type == 'Z')
		nbr = character(print, fd, nbr, cs);
	else
		nbr = putout(print, fd, nbr, cs);
	free(print);
	print = NULL;
	return (nbr);
}

int		big_function(int fd, char *f, va_list arg, int nbr)
{
	char *format;

	format = f;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, fd);
			nbr++;
		}
		else if (*format == '%')
		{
			format++;
			nbr = funpart(fd, &format, arg, nbr);
		}
		if (*format)
			format++;
	}
	return (nbr);
}
