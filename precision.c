/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:20:13 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/11 14:53:56 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	precision2(char **print, t_conv_spec cs, int minus, int len)
{
	char *string;

	if (cs.type == 'i' || cs.type == 'd' || cs.type == 'o' || cs.type == 'x' ||
			cs.type == 'X' || cs.type == 'u' || cs.type == 'p')
		if ((len = cs.precision - len) > 0)
		{
			string = (char*)malloc(sizeof(char) * (len + 1));
			if (string == NULL)
				return ;
			string[len] = '\0';
			while (--len >= 0)
				string[len] = '0';
			if (minus)
			{
				string[0] = '-';
				**print = '0';
			}
			ptrswap(print, ft_strjoin(string, *print));
			free(string);
			string = NULL;
		}
	if (cs.type == 'i' || cs.type == 'd' || cs.type == 'o' || cs.type == 'x' ||
			cs.type == 'X' || cs.type == 'u' || cs.type == 'p')
		if (cs.precision == 0 && **print == '0')
			**print = '\0';
}

void	precision(char **print, t_conv_spec cs)
{
	int len;
	int minus;

	if (!cs.has_dot || !print)
		return ;
	minus = 0;
	len = ft_strlen(*print);
	if (**print == '-')
	{
		minus = 1;
		len--;
	}
	if (cs.type == 's')
	{
		print[0][cs.precision] = '\0';
		return ;
	}
	precision2(print, cs, minus, len);
}
