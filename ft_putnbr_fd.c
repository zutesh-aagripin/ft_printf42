/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:54:09 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/17 17:39:28 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int nb, int fd)
{
	char n;

	if (nb == -2147483648)
	{
		nb = 147483648;
		write(fd, "-", 1);
		write(fd, "2", 1);
	}
	if (nb < 0)
	{
		nb = nb * (-1);
		write(fd, "-", 1);
	}
	if (nb / 10)
		ft_putnbr_fd(nb / 10, fd);
	n = '0' + nb % 10;
	write(fd, &n, 1);
}