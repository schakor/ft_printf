/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:17:34 by schakor           #+#    #+#             */
/*   Updated: 2018/12/05 20:23:23 by schakor          ###   ########.fr       */
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
		if ((conv->flag & FLAG_ZERO))
			ft_memset(tmp, '0', conv->width - 1);
		else
			ft_memset(tmp, ' ', conv->width - 1);
		if (conv->flag & FLAG_MINUS)
			pf->conv_buf = ft_strfjoin(pf->conv_buf, tmp, 2);
		else
			pf->conv_buf = ft_strfjoin(tmp, pf->conv_buf, 2);
		pf->convsize += conv->width - 1;
	}
}
