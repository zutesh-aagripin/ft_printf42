/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:35:10 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/05 17:11:24 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main()
{
	char c;
	char b;
	
	b = 2;
	c = 1;
//	ft_putnbr(ft_printf("%s\n", "this"));
//	ft_putnbr(ft_printf("\n%9s\n", "this"));
//	ft_putnbr(ft_printf("\n%-9s\n", "this"));
	ft_putnbr(ft_printf("%x\n", 424242424));
	ft_putnbr(printf("\n%x\n", 424242424));
	ft_putnbr(ft_printf("\n%p\n", &c));
	ft_putnbr(printf("\n%p\n", &c));
//	ft_putnbr(ft_printf("\n%-09i\n", 42));
//	ft_putnbr(ft_printf("\n%+09i\n", 42));
//	ft_putnbr(ft_printf("\n%+-9d\n", 42));
//	ft_putnbr(ft_printf("\n%9c\n", 'a'));
	return (0);
}
