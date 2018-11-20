/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:18:00 by schakor           #+#    #+#             */
/*   Updated: 2018/11/20 15:41:46 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strfjoin(char *s1, char *s2, int opt)
{
	char	*ret;

	if (!(ret = ft_strjoin(s1, s2)))
		return (NULL);
	if (opt == 0)
		ft_strdel(&s1);
	else if (opt == 1)
		ft_strdel(&s2);
	else if (opt == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (ret);
}
