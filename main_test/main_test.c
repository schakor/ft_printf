/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:20:43 by schakor           #+#    #+#             */
/*   Updated: 2018/11/19 18:38:08 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		main(void)
{
	int		ret1;
	int		ret2;

	ret1 = ft_printf("first test pour voir");
	printf("  || return value ft_printf = %d\n", ret1);
	ret2 = printf("first test pour voir");
	printf("  || return value printf = %d\n", ret2);
	ret1 = ft_printf("4 arg different : %10.hhd | %+10lld | %10.4ld\n",  (char)13, (long long)20, (long)30);
	printf("  || return value ft_printf = %d\n", ret1);
	ret2 = printf("4 arg different : %10.hhd | %+10lld | %10.4ld\n",  (char)13, (long long)20, (long)30);
	printf("  || return value printf = %d\n", ret2);
	ret1 = ft_printf("%.s\n", "small test");
	printf(" || return value ft_printf = %d\n", ret1);
	ret2 = printf("%.s\n", "small test");
	printf(" || return value printf = %d\n", ret2);
	ret1 = ft_printf(" %.1010s\n", "la famille");
	printf(" || return value ft_printf = %d\n", ret1);
	ret2 = printf(" %10.10s\n", "la famille");
	printf(" || return value printf = %d\n", ret2);
	return (0);
}
