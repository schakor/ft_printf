/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lllen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:08:13 by schakor           #+#    #+#             */
/*   Updated: 2018/11/19 14:40:13 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_lllen(signed long long nb)
{
	int					ret;
	unsigned long long	tmp;

	ret = 1;
	if (nb < 0)
	{
		tmp = -nb;
		ret += 1;
	}
	else
		tmp = nb;
	while (tmp /= 10)
		ret += 1;
	return (ret);
}
