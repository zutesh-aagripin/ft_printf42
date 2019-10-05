/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:20:13 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/05 17:12:01 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_switch(int fd, char *format, va_list arg, int nbr, t_conv_spec cs)
{
	switch(*format)
	{
		case 's':	
			nbr = string((va_arg(arg, char*)), fd, nbr, cs);
			break ;
		case 'c':
			nbr = character((va_arg(arg, int)), fd, nbr, cs);
			break ;
		case 'd':
			nbr = number((va_arg(arg, int)), fd, nbr, cs);
			break ;
		case 'p':
			nbr = pointer((va_arg(arg, void *)), fd, nbr, cs);
			break ; 
		case 'i':
			nbr = number((va_arg(arg, int)), fd, nbr, cs);
			break ;
	/*	case 'o':
	 *		nbr = octal((va_arg(arg, int)), fd, nbr);
	 *		break;
	 */	case 'x':
			nbr = hex_low((va_arg(arg, unsigned int)), fd, nbr, cs);
			break ; /*
		case 'X':
			nbr = hex_high((va_arg(arg, int)), fd, nbr);
			break ;
		case 'f':
			nbr = ft_float((va_arg(arg, float)), fd, nbr);
			break ; */
	//commented functions not ready yet, but need to be done
	}
	return (nbr);
}		

int		funpart(int fd, char *format, va_list arg, int nbr, int *offset)
{
	t_conv_spec cs;
 	
	*offset = parse_format(format, &cs);
	if (*offset > 1)
		format = format + *offset - 1;
	nbr = ft_switch(fd, format, arg, nbr, cs);
	return (nbr); 
}

int		big_function(int fd, char *format, va_list arg, int nbr)
{
	int offset;

	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, fd);
			nbr++;
			offset = 1;
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			ft_putchar_fd(*format, fd);
			offset = 2;
			nbr++;
		}
		else if (*format == '%')
		{
			format++;
			nbr = funpart(fd, format, arg, nbr, &offset);
		}
		format = format + offset;
	}
	return (nbr);
}
