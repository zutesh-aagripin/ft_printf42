/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:20:13 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/03 20:51:14 by kbryce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

typedef	enum	{ LEN_NONE, LEN_HH, LEN_H, LEN_LL, LEN_L, LEN_BIG_L } t_length;

typedef	struct	s_conv_spec
{
	char		flag_sharp;
	char		flag_zero;
	char		flag_minus;
	char		flag_plus;
	char		flag_space;
	char		flags_set;
	long int	width;
	char		width_set;
	char		has_dot;
	long int	precision;
	char		precision_set;
	t_length	length;
	char		length_set;
	char		type;
	char		type_set;
}				t_conv_spec;

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
			c == 'o' || c == 'u' || c == 'x' || c = 'X');
}

int		funpart(int fd, char *format, va_list arg, int nbr, int *offset)
{
	int d;
	int i;
	char c;
	char *s;
	char		*f;
	t_conv_spec	cs;
	
	*offset = 0;
	f = format + 1;
	while (*f)
	{
		if (!cs.flags_set && is_flag(*f))
		{
			set_flag(*f, &cs);
			f++;
		}
		else if (!cs.width_set && is_digit(*f))
		{
			cs.flags_set = 1;
			while (*f && is_digit(*f))
			{
				cs.width = cs.width * 10 + (*f - '0');
				f++;
			}
		}
		else if (!cs.precision_set && *f == '.')
		{
			cs.flags_set = 1;
			cs.width_set = 1;
			cs.has_dot = 1;
			f++;
		}
		else if (cs.has_dot && !cs.precision_set && is_digit(*f)))
		{
			while (*f && is_digit(*f))
			{
				cs.precision = cs.precision * 10 + (*f - '0');
				f++;
			}
			cs.precision_set = 1;
		}
		else if (!cs.length_set && is_length(*f))
		{
			cs.flags_set = 1;
			cs.width_set = 1;
			cs.precision_set = 1;
			if (*f == 'h')
				cs.length = (*(f + 1) == 'h') ? LEN_HH : LEN_H;
			else if (*f == 'l')
				cs.length = (*(f + 1) == 'l') ? LEN_LL : LEN_L;
			ele if (*f == 'L')
				cs.length == LEN_BIG_L;
			f++;
			if (cs.length == LEN_HH || cs.length == LEN_LL)
				f++;
			cs.length_set = 1;
		}
		else if (!type_set)
		{
			if (is_type(*f))
			{
				cs.type = *f;
				type_set = 1;
				f++;
				*offset = (f - format);
				// PUT SWITCH HERE
			}
			else
				// ERROR
		}
		else
			// ???
	}

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
	return (f-format);
}		

int		big_function(int fd, char *format, va_list arg, int nbr)
{
	int	offset;

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
			nbr++;
			offset = 2;
		}
		else if (*format == '%')
			nbr = funpart(fd, format, arg, nbr, &offset);
		format += offset;
	}
	return (nbr);
}
