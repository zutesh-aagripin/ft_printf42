/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:15:28 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/16 17:58:19 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum
{
	LEN_NONE,
	LEN_HH,
	LEN_H,
	LEN_LL,
	LEN_L,
	LEN_BIG_L
}	t_length;

typedef struct	s_conv_spec
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

int				ft_printf(const char *format, ...);
int				big_function(int fd, char *format, va_list arg, int nbr);
int				putout(char *print, int fd, int nbr, t_conv_spec cs);
int				character(char *print, int fd, int nbr, t_conv_spec cs);
void			precision(char **print, t_conv_spec cs);
void			width(char **print, t_conv_spec cs);
void			parse_format(char **format, t_conv_spec *main_cs, va_list arg);
void			ft_switch(char *format, va_list arg, char **print);
void			ft_switchl(char *format, va_list arg, char **print);
void			ft_switchll(char *format, va_list arg, char **print);
void			ft_switchh(char *format, va_list arg, char **print);
void			ft_switchhh(char *format, va_list arg, char **print);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *str, int fd);
void			ft_putnbr_fd(int nb, int fd);
void			ptrswap(char **print, char *ptr);
void			set_to_null(t_conv_spec *cs);
int				ft_strlen(char const *str);
char			*ft_itoa_base(unsigned long long int nbr, int base);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa_base_u(unsigned long long int nbr, int base);
char			*ft_strupcase(char *str);
int				set_flag(char c, t_conv_spec *cs);
char			is_flag(char c);
int				is_digit(char c);
int				is_length(char c);
int				is_type(char c);
int				process_float(va_list arg, t_conv_spec *cs, int nbr);
#endif
