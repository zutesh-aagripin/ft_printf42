/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:29:29 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/05 18:10:25 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
//char lowalpha[17];
//char highalpha[17];

//lowalpha = "0123456789abcdef";
//highalpha = "0123456789ABCDEF";

int		ft_puthex_fd(unsigned int x, int fd)
{
	char n;
	char alpha[] = "0123456789abcdef";
	int len;
	
	len = 0;
	if (x / 16)
		len = ft_puthex_fd(x / 16, fd);
	n = alpha[(x % 16)];
	write(fd, &n, 1);
	return (len + 1);
}

int		ft_putlonghex_fd(unsigned long int x, int fd)
{
	char n;
	char alpha[] = "0123456789abcdef";
	int len;
	
	len = 0;
	if (x / 16)
		len = ft_putlonghex_fd(x / 16, fd);
	n = alpha[(x % 16)];
	write(fd, &n, 1);
	return (len + 1);
}

int		hex_low(unsigned int x, int fd, int nbr, t_conv_spec cs)
{
	int len;

	len = ft_puthex_fd(x, fd);
	return (nbr + len);
}

int		pointer(void *x, int fd, int nbr, t_conv_spec cs)
{
	int len;
	ft_putstr_fd("0x", fd);
	len = ft_putlonghex_fd((unsigned long int)x, fd);
	return (nbr + len + 2);
}
