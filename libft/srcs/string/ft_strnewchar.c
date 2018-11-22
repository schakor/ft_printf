/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:23:05 by schakor           #+#    #+#             */
/*   Updated: 2018/11/22 15:25:34 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnewchar(int c, size_t n)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(*ret) * (n + 1))))
		return (NULL);
	ret[n] = '\0';
	ft_memset(ret, c, n);
	return (ret);
}
