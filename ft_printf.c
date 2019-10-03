/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:07:20 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/03 16:34:26 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	int		done;

	va_start (arg, format);
	done = big_function(stdout, format, arg, 0);
	va_end (arg);

	return (done);
}
