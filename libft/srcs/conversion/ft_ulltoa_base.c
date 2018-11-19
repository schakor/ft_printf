/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:01:42 by schakor           #+#    #+#             */
/*   Updated: 2018/11/19 15:26:26 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_ulltoa_base(unsigned long long int n, int base)
{
	char				*ret;
	int					len;
	static const char	*str = "0123456789ABCDEF";

	len = ft_ulllen_base(n, base);
	if (!(ret = (char *)ft_memalloc(len + 1)))
		return (NULL);
	while (n)
	{
		ret[len-- - 1] = str[n % base];
		n /= base;
	}
	return (ret);
}
