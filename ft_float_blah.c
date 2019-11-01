/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_blah.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbryce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:01:40 by kbryce            #+#    #+#             */
/*   Updated: 2019/10/15 18:43:52 by kbryce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_float.h"

void		normalize_str(char *s)
{
	char	*p;
	char	*end;

	p = s;
	while (*p)
		p++;
	end = --p;
	while (*end == '0')
	{
		*end = '\0';
		end--;
	}
}

void		reverse_str(char *s)
{
	char	*beg;
	char	*end;
	char	tmp;

	beg = s;
	end = s;
	while (*end)
		end++;
	end--;
	while (beg < end)
	{
		tmp = *beg;
		*beg = *end;
		*end = tmp;
		beg++;
		end--;
	}
}

char		*add_leading_zeroes_and_dot(char *s, size_t add_size)
{
	char	*res;
	char	*tmp;
	size_t	i;

	tmp = ft_strnew(add_size);
	if (!tmp)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (i < add_size)
		tmp[i++] = '0';
	tmp[1] = '.';
	res = ft_strjoin(tmp, s);
	free(tmp);
	free(s);
	return (res);
}

char		*insert_comma(char *s, int shift)
{
	char	*res;
	char	*end;
	int		idx;

	res = s;
	idx = (int)ft_strlen(s);
	end = s + idx;
	*(end + 1) = '\0';
	if (shift < idx)
	{
		while (shift)
		{
			*end = *(end - 1);
			end--;
			shift--;
		}
		*end = '.';
	}
	else
		res = add_leading_zeroes_and_dot(s, shift - idx + 1 + 1);
	return (res);
}

void		pad(char c, int n)
{
	while (n > 0)
	{
		ft_putchar(c);
		n--;
	}
}
