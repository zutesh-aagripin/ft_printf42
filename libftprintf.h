/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:15:28 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/04 21:06:09 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

typedef enum	{ LEN_NONE, LEN_HH, LEN_H, LEN_LL, LEN_L, LEN_BIG_L } t_length;

typedef struct	s_conv_spec
{
char		flag_sharp;
char        flag_zero;                                                      
char        flag_minus;                                                     
char        flag_plus;                                                      
char        flag_space;                                                     
char        flags_set;                                                      
long int    width;                                                          
char        width_set;                                                      
char        has_dot;                                                        
long int    precision;                                                      
char        precision_set;                                                  
t_length    length;                                                         
char        length_set;                                                     
char        type;                                                           
char        type_set;
}				t_conv_spec;

int				ft_printf(const char *format, ...);
int				big_function(int fd, char *format, va_list arg, int nbr);
int				number(int d, int fd, int nbr);
int				string(char *s, int fd, int nbr, t_conv_spec cs);
int				character(int d, int fd, int nbr);
int				parse_format(char *format, t_conv_spec *main_cs);

#endif
