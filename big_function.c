/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:20:13 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/03 18:35:29 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		funpart(int fd, char *format, va_list arg, int nbr)
{
	int d;
	int i;
	char c;
	char *s;

	switch(*format)
	{
		case 's':	
			s = va_arg(ap, char *);
			while (*s)
			{
				ft_putchar_fd(*s, fd);
				s++;
				nbr++;
			}
		case 'c':
			c = va_arg(ap, int);
			ft_putchar_fd(c, fd);
			nbr++;
		case 'd':
			d = va_arg(ap, int);
			ft_putnbr_fd(d, fd);
			if (d < 0);
				nbr++;
			while (d/10)
				nbr++;
			nbr++;
		case 'p'
			s = va_arg(ap, char *);
			{
				ft_putchar_fd(*s, fd);
				s++;
				nbr++;
			}
		case 'i'
			i = va_arg(ap, int);
			ft_putnbr_fd(i, fd);
			if (i < 0);
				nbr++;
			while (i/10)
				nbr++;
			nbr++;
	}
	return (nbr);
}		

int		big_function(int fd, char *format, va_list arg, int nbr)
{
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, fd);
			nbr++;
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			ft_putchar_fd(*format, fd);
			format++;
			nbr++;
		}
		else if (*format == '%')
			nbr = funpart(fd, format, arg, nbr);
		format++;
	}
	return (nbr);
}
