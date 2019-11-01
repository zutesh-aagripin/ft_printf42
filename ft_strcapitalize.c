/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 23:18:46 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/20 20:22:32 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isletter(char s)
{
	if ('A' <= s && s <= 'Z')
		return (1);
	else if ('a' <= s && s <= 'z')
		return (1);
	else if ('0' <= s && s <= '9')
		return (1);
	else
		return (0);
}

static char	*ft_uppercase(char *s)
{
	if ('a' <= *s && *s <= 'z')
		*s = *s - 32;
	return (s);
}

static char	*ft_lowercase(char *s)
{
	if ('A' <= *s && *s <= 'Z')
		*s = *s + 32;
	return (s);
}

char		*ft_strcapitalize(char *str)
{
	int i;
	int letter;

	i = 0;
	letter = 0;
	while (*str != '\0')
	{
		if (ft_isletter(*str))
		{
			if (letter == 0)
				ft_uppercase(str);
			else if (letter == 1)
				ft_lowercase(str);
			letter = 1;
		}
		else
			letter = 0;
		i++;
		str++;
	}
	str = str - i;
	return (str);
}
