/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:21:23 by schakor           #+#    #+#             */
/*   Updated: 2018/11/30 16:28:29 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		ret;

	ret = ft_printf("% 10.5d", 4242);
	printf(" || %d\n", ret);
	ret = printf("% 10.5d", 4242);
	printf(" || %d\n", ret);
	ret = ft_printf("%#.x %#.0x", 0, 0);
	printf(" || %d\n", ret);
	ret = printf("%#.x %#.0x", 0, 0);
	printf(" || %d\n", ret);
	ret = ft_printf("%#.o %#.0o", 0, 0);
	printf(" || %d\n", ret);
	ret = printf("%#.o %#.0o", 0, 0);
	printf(" || %d\n", ret);
}
