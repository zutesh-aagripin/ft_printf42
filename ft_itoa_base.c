/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:14:21 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/11 15:07:12 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		transform(int len, char *str, long long int nbr, int base)
{
	char c;

	if (nbr / base)
		transform(len - 1, str, nbr / base, base);
	c = nbr % base + 48;
	if (c > '9')
		c = c + 39;
	str[len] = c;
}

static char		*that_case(int len)
{
	char			*str;
	long long int	nb;

	nb = 8085774586302733229;
	if (!(str = (char*)malloc(sizeof(char) * (20 + 1))))
		return (NULL);
	str[0] = '-';
	while (nb / 10)
	{
		str[len] = nb % 10 + 48;
		nb = nb / 10;
		len++;
	}
	str[len] = '8';
	str[20] = '\0';
	return (str);
}

char			*normal(long long int nb, int base)
{
	char			*str;
	int				len;
	long long int	i;

	i = nb;
	len = 1;
	if (i < 0 && base == 10)
		len++;
	while (i / base)
	{
		i = i / base;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		if (base == 10)
			str[0] = '-';
		nb = -nb;
	}
	transform(len - 1, str, nb, base);
	return (str);
}

char			*ft_itoa_base(unsigned long long int nbr, int base)
{
	if ((nbr - 1) == 9223372036854775807)
		return (that_case(1));
	else
		return (normal((long long int)nbr, base));
}
