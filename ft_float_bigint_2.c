/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_bigint_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbryce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:04:47 by kbryce            #+#    #+#             */
/*   Updated: 2019/10/15 18:43:42 by kbryce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_float.h"

static int			g_pows5[] = { 1, 5, 25, 125, 625, 3125, 15625, 78125,
	390625, 1953125, 9765625, 48828125, 244140625 };

static int			g_pows2[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024,
	2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576,
	2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728,
	268435456, 536870912 };

static void			do_multiplications(t_bigint *bbb, int digit, int pow)
{
	int		*pp;
	int		max_pow;

	pp = (digit == 2) ? g_pows2 : g_pows5;
	max_pow = (digit == 2) ? 29 : 12;
	while (pow > 0)
	{
		if (pow > max_pow)
		{
			bigint_times_short(bbb, pp[max_pow]);
			pow -= max_pow;
		}
		else
		{
			bigint_times_short(bbb, pp[pow]);
			pow = 0;
		}
	}
}

static int			length_of_big_digit(int n)
{
	int res;

	if (n >= 0 && n < 10)
		res = 1;
	else if (n >= 10 && n < 100)
		res = 2;
	else if (n >= 100 && n < 1000)
		res = 3;
	else if (n >= 1000 && n < 10000)
		res = 4;
	else if (n >= 10000 && n < 100000)
		res = 5;
	else if (n >= 100000 && n < 1000000)
		res = 6;
	else if (n >= 1000000 && n < 10000000)
		res = 7;
	else if (n >= 10000000 && n < 100000000)
		res = 8;
	else
		res = 9;
	return (res);
}

static char			*put_big_digit_to_str(char *str, int num)
{
	int		zeroes;
	char	*s;

	s = str;
	if (!num)
	{
		zeroes = 9 + 1;
		while (--zeroes)
			*s++ = '0';
	}
	else
	{
		zeroes = 9 + 1 - length_of_big_digit(num);
		while (num)
		{
			*s++ = num % 10 + '0';
			num /= 10;
		}
		while (--zeroes)
			*s++ = '0';
	}
	return (s);
}

static char			*process_bigint(t_bigint *b)
{
	char	*res;
	char	*r;
	int		size;
	int		i;

	i = 0;
	size = b->size * 9 + 10;
	res = (char *)malloc(size);
	if (!res)
		return (NULL);
	res[size - 1] = '\0';
	r = res;
	while (i < b->size)
	{
		r = put_big_digit_to_str(r, b->array[i]);
		i++;
	}
	*r = '\0';
	return (res);
}

char				*get_full_string(t_float *fff)
{
	t_bigint	*bbb;
	int			mode;
	int			power;
	char		*res;

	mode = (fff->power_of_2 >= 0) ? 2 : 5;
	power = (mode == 2) ? fff->power_of_2 : -1 * fff->power_of_2;
	bbb = init_bigint(calc_buf_size(power, mode), fff->m);
	if (!bbb)
		return (NULL);
	do_multiplications(bbb, mode, power);
	res = process_bigint(bbb);
	free(bbb->array);
	free(bbb);
	return (res);
}
