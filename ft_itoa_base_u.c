/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:14:21 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/11 14:46:37 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		transform(int l, char *s, unsigned long long int nbr, int base)
{
	char c;

	if (nbr / base)
		transform(l - 1, s, nbr / base, base);
	c = nbr % base + 48;
	if (c > '9')
		c = c + 39;
	s[l] = c;
}

char			*ft_itoa_base_u(unsigned long long int nbr, int base)
{
	char					*str;
	int						len;
	unsigned long long int	i;

	i = nbr;
	len = 1;
	while (i / base)
	{
		i = i / base;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	transform(len - 1, str, nbr, base);
	return (str);
}
