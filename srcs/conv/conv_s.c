/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:19:54 by schakor           #+#    #+#             */
/*   Updated: 2018/11/20 15:02:07 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	max_value(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void		conv_s(t_pf *pf, t_conv *conv, va_list *ap)
{
	char	*s;
	char	*tmp;
	int		i;

	s = (char *)va_arg(*ap, char *);
	if (conv->flag & FLAG_PREC)
		s = ft_strsub(s, 0, conv->prec);
	i = max_value(ft_strlen(s), conv->width);
	if ((conv->flag & FLAG_WIDTH) && conv->width > 1)
	{
		if (!(tmp = ft_memalloc(i)))
			return ;
		if ((conv->flag & FLAG_ZERO))
			ft_memset(tmp, '0', conv->width - 1);
		else
			ft_memset(tmp, ' ', conv->width - 1);
		if (conv->flag & FLAG_MINUS)
			ft_memcpy(tmp, s, i);
		else
			ft_memcpy(tmp + (i - ft_strlen(s)), s, i);
	}
	else
		tmp = ft_strdup(s);
	pf->conv_buf = tmp;
	pf->convsize += i;
}
