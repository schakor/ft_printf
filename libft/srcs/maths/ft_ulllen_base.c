/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulllen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:20:01 by schakor           #+#    #+#             */
/*   Updated: 2018/11/19 15:21:47 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_ulllen_base(unsigned long long int n, int base)
{
	int		ret;

	ret = 1;
	while (n /= base)
		ret += 1;
	return (ret);
}
