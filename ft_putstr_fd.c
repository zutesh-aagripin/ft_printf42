/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:55:51 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/08 16:52:56 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr_fd(char const *str, int fd)
{
	unsigned long i;

	i = 0;
	if (!str || !fd)
		return ;
	write(fd, str, ft_strlen(str));
}
