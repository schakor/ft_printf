/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lllen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:08:13 by schakor           #+#    #+#             */
/*   Updated: 2018/11/19 15:31:40 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_lllen(long long int n)
{
	int					ret;
	unsigned long long	tmp;

	ret = 1;
	if (n < 0)
	{
		tmp = -n;
		ret += 1;
	}
	else
		tmp = n;
	while (tmp /= 10)
		ret += 1;
	return (ret);
}
