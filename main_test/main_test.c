/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:20:43 by schakor           #+#    #+#             */
/*   Updated: 2018/11/13 15:57:03 by schakor          ###   ########.fr       */
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
	ft_printf("3 arg different : %+-0 #d | %+10d | %10.4d\n", 13, 20, 30);
	printf("3 arg different : %10d | %+10d | %10.4d\n", 13, 20, 30);
	return (0);
}
