/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbryce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:50:03 by kbryce            #+#    #+#             */
/*   Updated: 2019/10/16 17:56:28 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_float.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	char	*n;

	size++;
	new = (char *)malloc(size);
	if (!new)
		return (NULL);
	n = new;
	while (size)
	{
		*n = 0;
		n++;
		size--;
	}
	return (new);
}
