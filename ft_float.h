/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbryce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:16:18 by kbryce            #+#    #+#             */
/*   Updated: 2019/10/15 20:13:03 by kbryce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLOAT_H
# define FT_FLOAT_H
# include "libftprintf.h"

typedef	struct	s_float
{
	long double			num;
	char				sign;
	unsigned long		m;
	int					power_of_2;
	int					is_inf;
	int					is_nan;
	int					is_zero;
}				t_float;

typedef	struct	s_bigint
{
	int		*array;
	int		size;
	char	*res;
}				t_bigint;

typedef	struct	s_fbits
{
	unsigned short	*pe;
	unsigned long	*pm;
}				t_fbits;

char			*get_full_string(t_float *fff);
void			normalize_str(char *s);
void			reverse_str(char *s);
char			*insert_comma(char *s, int shift);
void			clear_tail_zeroes(char *str);
char			*handle_precision(char **s, int prec);
int				real_print_float(char *res, int w, t_float *fff,
	t_conv_spec *cs);
void			bigint_times_short(t_bigint *b, int num);
t_bigint		*init_bigint(int size, unsigned long num);
int				calc_buf_size(int power, int mode);
void			pad(char c, int n);
char			*process_special(t_float *f);
int				print_float(long double f, t_conv_spec *cs);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strnew(size_t size);
#endif
