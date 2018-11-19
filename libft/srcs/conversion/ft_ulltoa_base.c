/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:01:42 by schakor           #+#    #+#             */
/*   Updated: 2018/11/19 20:25:44 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_ulltoa_base(unsigned long long n, int base, int maj)
{
	char				*ret;
	int					len;
	static const char	*str1 = "0123456789ABCDEF";
	static const char	*str2 = "o123456789abcdef";

	len = ft_ulllen_base(n, base);
	if (!(ret = (char *)ft_memalloc(len + 1)))
		return (NULL);
	while (n)
	{
		if (maj == 0)
			ret[len-- - 1] = str2[n % base];
		else
			ret[len-- - 1] = str1[n % base];
		n /= base;
	}
	return (ret);
}
