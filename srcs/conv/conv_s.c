/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:19:54 by schakor           #+#    #+#             */
/*   Updated: 2018/12/12 16:03:16 by schakor          ###   ########.fr       */
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

void		conv_s(t_conv *conv, va_list *ap)
{
	char	*s;
	char	*tmp;
	int		i;

	s = (char *)va_arg(*ap, char *);
	if (!s)
		s = ft_strdup("(null)");
	if (conv->flag & FLAG_PREC)
		s = ft_strsub(s, 0, conv->prec);
	i = max_value(ft_strlen(s), conv->width);
	if ((conv->flag & FLAG_WIDTH) && conv->width > 1)
	{
		if (!(tmp = ft_memalloc(i + 1)))
			return ;
		if (conv->flag & FLAG_ZERO)
			ft_memset(tmp, '0', i);
		else
			ft_memset(tmp, ' ', i);
		if (conv->flag & FLAG_MINUS)
			ft_memcpy(tmp, s, ft_strlen(s));
		else
			ft_memcpy(tmp + (i - ft_strlen(s)), s, i);
	}
	else
		tmp = ft_strdup(s);
	if (conv->flag & FLAG_PREC && s)
		ft_strdel(&s);
	conv->conv_buf = tmp;
	conv->convsize += i;
}
