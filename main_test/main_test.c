/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:20:43 by schakor           #+#    #+#             */
/*   Updated: 2018/11/16 17:45:39 by schakor          ###   ########.fr       */
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
	ret1 = ft_printf("3 arg different : %+-0 #hhd | %+10lld | %10.4ld\n", 13, 20, 30);
	printf("  || return value ft_printf = %d\n", ret1);
	ret2 = printf("3 arg different : %10hhd | %+10lld | %10.4ld\n", (char)13, (long long)20, (long)30);
	printf("  || return value printf = %d\n", ret2);
	return (0);
}
