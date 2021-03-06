/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:20:43 by schakor           #+#    #+#             */
/*   Updated: 2018/12/01 21:27:18 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		main(void)
{
	int		ret1;

	ret1 = ft_printf("first test pour voir");
	printf(" || return value ft_printf = %d\n", ret1);
	ret1 = printf("first test pour voir");
	printf(" || return value printf = %d\n", ret1);
	ret1 = ft_printf("4 arg different : %10.hhd | %+10lld | %10.3ld",  (char)13, (long long)20, (long)30);
	printf(" || return value ft_printf = %d\n", ret1);
	ret1 = printf("4 arg different : %10.hhd | %+10lld | %10.3ld",  (char)13, (long long)20, (long)30);
	printf(" || return value printf = %d\n", ret1);
	ret1 = ft_printf("%.s", "small test");
	printf(" || return value ft_printf = %d\n", ret1);
	ret1 = printf("%.s", "small test");
	printf(" || return value printf = %d\n", ret1);
	ret1 = ft_printf(" %10.10s", "la famille");
	printf(" || return value ft_printf = %d\n", ret1);
	ret1 = printf(" %10.10s", "la famille");
	printf(" || return value printf = %d\n", ret1);
	ft_printf("Argument hex : %x\n", 34);
	printf("Argument hex : %x\n", 34);
	ft_printf("Argument big hex : %X\n", 752424);
	printf("Argument big hex : %X\n", 752424);
	ft_printf("Argument octal : %o\n", 484823);
	printf("Argument octal : %o\n", 484823);
	ft_printf("Char : %-4c\n", 'U');
	printf("Char : %-4c\n", 'U');
	ft_printf("hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
	printf("hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
	ret1 = ft_printf("%-+10.12lld", (long long)30);
	printf(" || return value printf = %d\n", ret1);
	ret1 = printf("%-+10.12lld", (long long)30);
	printf(" || return value printf = %d\n", ret1);
	ret1 = ft_printf("%li", 0xff11ff11ff88);
	printf(" || return value printf = %d\n", ret1);
	ret1 = printf("%li", 0xff11ff11ff88);
	printf(" || return value printf = %d\n", ret1);
	ret1 = ft_printf("% 010d", 345);
	printf(" || return value printf = %d\n", ret1);
	ret1 = printf("% 010d", 345);
	printf(" || return value printf = %d\n", ret1);
	ret1 = ft_printf("%+d", -4440);
	printf(" || return value printf = %d\n", ret1);
	ret1 = printf("%+d", -4440);
	printf(" || return value printf = %d\n", ret1);
	ret1 = ft_printf("small to see if %c it works", '\0');
	printf(" || return value printf = %d\n", ret1);
	ret1 = printf("small to see if %c it works", '\0');
	printf(" || return value printf = %d\n", ret1);
	ret1 = ft_printf("%u", -0);
	printf(" || return value printf = %d\n", ret1);
	ret1 = printf("%u", -0);
	printf(" || return value printf = %d\n", ret1);
	ret1 = ft_printf("%5d", -741);
	printf(" || return value printf = %d\n", ret1);
	ret1 = printf("%5d", -741);
	printf(" || return value printf = %d\n", ret1);
	ret1 = ft_printf("%08i", -71);
	printf(" || return value printf = %d\n", ret1);
	ret1 = printf("%08i", -71);
	printf(" || return value printf = %d\n", ret1);
	//ret1 = ft_printf("test %-12i et %--2.4s %24s !\n", 0, NULL, "\"coco\"");
	//printf("ret = %d\n", ret1);
	//ret1 = printf("test %-12i et %--2.4s %24s !\n", 0, NULL, "\"coco\"");
	//printf("ret = %d\n", ret1);
	return (0);
}
