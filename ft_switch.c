/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:20:13 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/15 20:53:13 by kbryce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_switchh(char *format, va_list arg, char **print)
{
	if (*format == 's')
		*print = ft_strjoin("", va_arg(arg, char*));
	else if (*format == '%')
		*print = ft_strjoin("", "%");
	else if (*format == 'Z')
		*print = ft_strjoin("", "Z");
	else if (*format == 'c')
	{
		if (!(*print = (char*)malloc(sizeof(char) * 2)))
			return ;
		print[0][0] = va_arg(arg, int);
		print[0][1] = '\0';
	}
	else if (*format == 'd' || *format == 'i')
		*print = ft_itoa_base((short)(va_arg(arg, long int)), 10);
	else if (*format == 'p')
		*print = ft_itoa_base_u((va_arg(arg, unsigned long int)), 16);
	else if (*format == 'o')
		*print = ft_itoa_base_u((unsigned short)(va_arg(arg, long int)), 8);
	else if (*format == 'x' || *format == 'X')
		*print = ft_itoa_base_u((unsigned short)(va_arg(arg, long int)), 16);
	else if (*format == 'u')
		*print = ft_itoa_base_u((unsigned short)(va_arg(arg, long int)), 10);
}

void	ft_switchhh(char *format, va_list arg, char **print)
{
	if (*format == 's')
		*print = ft_strjoin("", va_arg(arg, char*));
	else if (*format == '%')
		*print = ft_strjoin("", "%");
	else if (*format == 'Z')
		*print = ft_strjoin("", "Z");
	else if (*format == 'c')
	{
		if (!(*print = (char*)malloc(sizeof(char) * 2)))
			return ;
		print[0][0] = (char)va_arg(arg, int);
		print[0][1] = '\0';
	}
	else if (*format == 'd' || *format == 'i')
		*print = ft_itoa_base((char)(va_arg(arg, long int)), 10);
	else if (*format == 'p')
		*print = ft_itoa_base_u((va_arg(arg, unsigned long int)), 16);
	else if (*format == 'o')
		*print = ft_itoa_base_u((unsigned char)(va_arg(arg, long int)), 8);
	else if (*format == 'x' || *format == 'X')
		*print = ft_itoa_base_u((unsigned char)(va_arg(arg, long int)), 16);
	else if (*format == 'u')
		*print = ft_itoa_base_u((unsigned char)(va_arg(arg, long int)), 10);
}

void	ft_switchl(char *format, va_list arg, char **print)
{
	if (*format == 's')
		*print = ft_strjoin("", va_arg(arg, char*));
	else if (*format == '%')
		*print = ft_strjoin("", "%");
	else if (*format == 'Z')
		*print = ft_strjoin("", "Z");
	else if (*format == 'c')
	{
		if (!(*print = (char*)malloc(sizeof(char) * 2)))
			return ;
		print[0][0] = va_arg(arg, int);
		print[0][1] = '\0';
	}
	else if (*format == 'd' || *format == 'i')
		*print = ft_itoa_base((va_arg(arg, long int)), 10);
	else if (*format == 'p')
		*print = ft_itoa_base_u((va_arg(arg, unsigned long int)), 16);
	else if (*format == 'o')
		*print = ft_itoa_base_u((va_arg(arg, unsigned long int)), 8);
	else if (*format == 'x' || *format == 'X')
		*print = ft_itoa_base_u((va_arg(arg, unsigned long int)), 16);
	else if (*format == 'u')
		*print = ft_itoa_base_u((va_arg(arg, unsigned long int)), 10);
}

void	ft_switchll(char *format, va_list arg, char **print)
{
	if (*format == 's')
		*print = ft_strjoin("", va_arg(arg, char*));
	else if (*format == '%')
		*print = ft_strjoin("", "%");
	else if (*format == 'Z')
		*print = ft_strjoin("", "Z");
	else if (*format == 'c')
	{
		if (!(*print = (char*)malloc(sizeof(char) * 2)))
			return ;
		print[0][0] = va_arg(arg, int);
		print[0][1] = '\0';
	}
	else if (*format == 'd' || *format == 'i')
		*print = ft_itoa_base((va_arg(arg, long long int)), 10);
	else if (*format == 'p')
		*print = ft_itoa_base_u((va_arg(arg, unsigned long int)), 16);
	else if (*format == 'o')
		*print = ft_itoa_base_u((va_arg(arg, unsigned long long int)), 8);
	else if (*format == 'x' || *format == 'X')
		*print = ft_itoa_base_u((va_arg(arg, unsigned long long int)), 16);
	else if (*format == 'u')
		*print = ft_itoa_base_u((va_arg(arg, unsigned long long int)), 10);
}

void	ft_switch(char *format, va_list arg, char **print)
{
	if (*format == 's')
		*print = ft_strjoin("", va_arg(arg, char*));
	else if (*format == '%')
		*print = ft_strjoin("", "%");
	else if (*format == 'Z')
		*print = ft_strjoin("", "Z");
	else if (*format == 'c')
	{
		if (!(*print = (char*)malloc(sizeof(char) * 2)))
			return ;
		print[0][0] = va_arg(arg, int);
		print[0][1] = '\0';
	}
	else if (*format == 'd' || *format == 'i')
		*print = ft_itoa_base((va_arg(arg, int)), 10);
	else if (*format == 'p')
		*print = ft_itoa_base_u((va_arg(arg, unsigned long int)), 16);
	else if (*format == 'o')
		*print = ft_itoa_base_u((va_arg(arg, unsigned int)), 8);
	else if (*format == 'x' || *format == 'X')
		*print = ft_itoa_base_u((va_arg(arg, unsigned int)), 16);
	else if (*format == 'u')
		*print = ft_itoa_base_u((va_arg(arg, unsigned int)), 10);
}
