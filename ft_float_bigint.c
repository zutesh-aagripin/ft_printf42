/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_bigint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbryce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:21:39 by kbryce            #+#    #+#             */
/*   Updated: 2019/10/15 18:43:28 by kbryce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_float.h"

#define BINT_BASE 1000000000U

static t_bigint		*pre_init_bigint(int size)
{
	t_bigint		*b;

	b = (t_bigint *)malloc(sizeof(t_bigint));
	if (!b)
		return (NULL);
	b->array = (int *)malloc(sizeof(int) * size);
	if (!b->array)
	{
		free(b);
		return (NULL);
	}
	return (b);
}

t_bigint			*init_bigint(int size, unsigned long num)
{
	t_bigint		*b;
	int				i;
	unsigned long	rem;

	b = pre_init_bigint(size);
	if (!b)
		return (NULL);
	b->size = size;
	i = 0;
	while (i < b->size)
	{
		if (num)
		{
			rem = num % BINT_BASE;
			num /= BINT_BASE;
			b->array[i] = rem;
		}
		else
			b->array[i] = 0;
		i++;
	}
	b->res = NULL;
	return (b);
}

int					calc_buf_size(int power, int mode)
{
	int		res;
	double	add_places;

	res = 3 + 3;
	if (mode == 2)
	{
		add_places = ((1.0 + power) * 0.31) / 9.0;
	}
	else if (mode == 5)
	{
		add_places = ((1.0 + power) * 0.70) / 9.0;
	}
	else
		add_places = 0.0;
	res += (int)add_places;
	return (res);
}

void				bigint_times_short(t_bigint *b, int num)
{
	int			i;
	int			carry;
	long long	curr;

	i = 0;
	carry = 0;
	while (i < b->size || carry)
	{
		curr = carry + b->array[i] * 1ll * num;
		b->array[i] = (int)(curr % BINT_BASE);
		carry = (int)(curr / BINT_BASE);
		i++;
	}
}
