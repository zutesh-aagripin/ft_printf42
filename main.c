/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:36:38 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/03 15:59:46 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
	char c = 49;
	char string[] = "test string";
	char *ptr = &c;
	int	wchar[3];
	int  nbr = 15;
	short shrt = 28;
//	unsigned octal = 010;
	long lnbr = 123128390123;
	long long llnbr = 1231231231312313123;
	float fnbr = 123524;
	long double ld = (long double)fnbr;
	double d = (double)fnbr;
	
	wchar[0] = 1;
	wchar[1] = 2;
	wchar[2] = 3;
	printf("c conversions\n");
//	printf("% c\n", c);
//	printf("%+c\n", c);
	printf("%-5c\n", c);
	printf("%5c\n", c);
//	printf("%0c\n", c);
//	printf("%#c\n", c);
	printf("%lc\n", c);
//	printf("%Lc\n", c);
//	printf("%hhc\n", c);
//	printf("%hc\n", c);
//	printf("%llc\n", c);
	printf("s conversions\n");
//	printf("% s\n", string);
//	printf("%+s\n", string);
	printf("%-s\n", string);
//	printf("%0s\n", string);
//	printf("%#s\n", string);
	printf("%ls\n", wchar);
//	printf("%Ls\n", string);
//	printf("%hhs\n", string);
//	printf("%hs\n", string);
//	printf("%lls\n", string);
	printf("p conversions\n");
//	printf("% p\n", ptr);
//	printf("%+p\n", ptr);
	printf("%-p\n", ptr);
//	printf("%0p\n", ptr);
//	printf("%#p\n", ptr);
//	printf("%lp\n", ptr);
//	printf("%Lp\n", ptr);
//	printf("%hhp\n", ptr);
//	printf("%hp\n", ptr);
//	printf("%llp\n", ptr);
	printf("d conversions\n");
	printf("%+d\n", nbr);
	printf("% d\n", nbr);
	printf("%-5d\n", nbr);
	printf("%05d\n", nbr);
//	printf("%#d\n", nbr);
	printf("%ld\n", lnbr);
//	printf("%Ld\n", nbr);
	printf("%hhd\n", c);
	printf("%hd\n", shrt);
	printf("%lld\n", llnbr);
	printf("i conversions\n");
	printf("%+i\n", nbr);
	printf("% i\n", nbr);
	printf("%-i\n", nbr);
	printf("%0i\n", nbr);
//	printf("%#i\n", nbr);
	printf("%li\n", lnbr);
//	printf("%Li\n", nbr);
	printf("%hhi\n", c);
	printf("%hi\n", shrt);
	printf("%lli\n", llnbr);
	printf("o conversions\n");
//	printf("%+o\n", nbr);
//	printf("% o\n", nbr);
	printf("%-o\n", nbr);
	printf("%0o\n", nbr);
	printf("%#o\n", nbr);
	printf("%lo\n", lnbr);
//	printf("%Lo\n", nbr);
	printf("%hho\n", c);
	printf("%ho\n", shrt);
	printf("%llo\n", llnbr);
	printf("u conversions\n");
//	printf("%+u\n", nbr);
//	printf("% u\n", nbr);
	printf("%-u\n", nbr);
	printf("%0u\n", nbr);
//	printf("%#u\n", nbr);
	printf("%lu\n", lnbr);
//	printf("%Lu\n", nbr);
	printf("%hhu\n", c);
	printf("%hu\n", shrt);
	printf("%llu\n", llnbr);
	printf("x conversions\n");
//	printf("%+x\n", nbr);
//	printf("% x\n", nbr);
	printf("%-x\n", nbr);
	printf("%0x\n", nbr);
	printf("%#x\n", nbr);
	printf("%lx\n", lnbr);
//	printf("%Lx\n", nbr);
	printf("%hhx\n", c);
	printf("%hx\n", shrt);
	printf("%llx\n", llnbr);
	printf("X conversions\n");
//	printf("%+X\n", nbr);
//	printf("% X\n", nbr);
	printf("%-X\n", nbr);
	printf("%0X\n", nbr);
	printf("%#X\n", nbr);
	printf("%lX\n", lnbr);
//	printf("%LX\n", nbr);
	printf("%hhX\n", c);
	printf("%hX\n", shrt);
	printf("%llX\n", llnbr);
	printf("f conversions\n");
	printf("%+.3f\n", fnbr);
	printf("% .3f\n", fnbr);
	printf("%-f\n", fnbr);
	printf("%0f\n", fnbr);
	printf("%#f\n", fnbr);
	printf("%lf\n", d);
	printf("%Lf\n", ld);
//	printf("%hhf\n", fnbr);
//	printf("%hf\n", fnbr);
//	printf("%llf\n", llnbr);
	printf("percent %%");
	return (0);
}
