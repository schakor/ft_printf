/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:17:34 by schakor           #+#    #+#             */
/*   Updated: 2018/11/19 21:16:58 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_c(t_pf *pf, t_conv *conv, va_list *ap)
{
	char	c;
	char	*tmp;

	c = (char)va_arg(*ap, int);
	pf->conv_buf = ft_memalloc(2);
	pf->conv_buf[0] = c;
	pf->convsize = 1;
	if ((conv->flag & FLAG_WIDTH) && conv->width > 1)
	{
		if (!(tmp = ft_memalloc(conv->width)))
			return ;
		ft_memset(tmp, ' ', conv->width - 1);
		if (conv->flag & FLAG_MINUS)
			pf->conv_buf = ft_strjoin(pf->conv_buf, tmp);
		else
			pf->conv_buf = ft_strjoin(tmp, pf->conv_buf);
		pf->convsize += conv->width - 1;
	}
}
