/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 09:57:23 by khsadira          #+#    #+#             */
/*   Updated: 2018/11/23 13:58:02 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_dlen_neg(double n)
{
	int	ret;

	ret = 0;
	if (n >= -1)
		return (1);
	while (n < -1)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

int			ft_dlen(double n)
{
	int	ret;

	ret = 0;
	printf("%f\n", n);
	if (n < 0)
		ret = ft_dlen_neg(n);
	else
	{
		if (n <= 1)
			return (1);
		while (n > 1)
		{
			n /= 10;
			ret++;
		}
	}
	return (ret);
}
