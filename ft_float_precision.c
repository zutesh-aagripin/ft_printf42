/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbryce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:56:57 by kbryce            #+#    #+#             */
/*   Updated: 2019/10/15 18:44:05 by kbryce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_float.h"

void			clear_tail_zeroes(char *str)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(str);
	tmp = str + len - 1;
	while (*tmp == '0')
	{
		*tmp = '\0';
		tmp--;
	}
	if (*tmp == '.')
		*tmp = '\0';
}

static char		*append_zeroes(char **s, int num, int add_dot)
{
	char	*tail;
	size_t	len;
	size_t	i;

	len = add_dot ? 1 : 0;
	len += num;
	tail = ft_strnew(len);
	if (!tail)
		exit(1);
	i = 0;
	while (i < len)
	{
		tail[i] = '0';
		i++;
	}
	if (add_dot)
		tail[0] = '.';
	*s = ft_strjoin(*s, tail);
	return (*s);
}

static void		propagate_trailing_zero(char **s, char *curr)
{
	int		carry;
	char	*first;
	char	*second;

	carry = 1;
	while (curr >= *s)
	{
		if (*curr == '9')
			*curr = '0';
		else if (*curr == '.')
			;
		else
		{
			++*curr;
			carry = 0;
			break ;
		}
		curr--;
	}
	if (carry)
	{
		first = "1";
		second = *s;
		*s = ft_strjoin(first, second);
	}
}

static void		handle_prec_switch(char **s, char *curr, char *next)
{
	if (*next - '0' < 5)
		*next = '\0';
	else if (*next - '0' >= 5 && *curr != '9')
	{
		*next = '\0';
		if (*curr == '.')
			propagate_trailing_zero(s, curr - 1);
		else
			++*curr;
	}
	else if (*next - '0' >= 5 && *curr == '9')
	{
		*curr = '0';
		*next = '\0';
		propagate_trailing_zero(s, curr - 1);
	}
}

char			*handle_precision(char **s, int prec)
{
	char	*dot;
	size_t	tail_len;
	char	*curr;
	char	*next;

	dot = ft_strchr(*s, '.');
	if (!dot)
		return (append_zeroes(s, prec, 1));
	tail_len = ft_strlen(dot) - 1;
	if (tail_len <= (size_t)prec)
		return (append_zeroes(s, prec - tail_len, 0));
	else
	{
		curr = dot + prec;
		next = dot + prec + 1;
		handle_prec_switch(s, curr, next);
	}
	return (*s);
}
