/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:44:34 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/20 18:42:37 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_rewrite(const char *s1, const char *s2, char *string)
{
	unsigned long	j;
	unsigned long	i;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		string[i + j] = s2[j];
		j++;
	}
	string[i + j] = '\0';
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long	j;
	unsigned long	i;
	char			*string;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	if (!(string = (char*)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	ft_rewrite(s1, s2, string);
	return (string);
}
