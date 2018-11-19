/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:32:33 by schakor           #+#    #+#             */
/*   Updated: 2018/11/19 15:41:21 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_lltoa(long long int n)
{
	char				*ret;
	int					len;
	unsigned long long	tmp;

	len = ft_lllen(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (!(ret = (char *)ft_memalloc(len + 1)))
		return (NULL);
	if (n < 0)
	{
		ret[0] = '-';
		tmp = -n;
	}
	else
		tmp = n;
	while (tmp)
	{
		ret[len-- - 1] = tmp % 10 + '0';
		tmp /= 10;
	}
	return (ret);
}
