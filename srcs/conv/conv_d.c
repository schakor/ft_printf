/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:07:48 by schakor           #+#    #+#             */
/*   Updated: 2018/11/19 18:41:18 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			conv_d(t_pf *pf, t_conv *conv, va_list *ap)
{
	long long 	d;
	int			len;

	if (conv->mod & MODIF_HH)
		d = (signed char)va_arg(*ap, int);
	else if (conv->mod & MODIF_H)
		d = (short)va_arg(*ap, int);
	else if (conv->mod & MODIF_L)
		d = (long)va_arg(*ap, long);
	else if (conv->mod & MODIF_LL)
		d = (long long)va_arg(*ap, long long);
	else
		d = (int)va_arg(*ap, int);
	len = ft_lllen(d);
	if ((conv->flag & FLAG_WIDTH) && len < conv->width)
	{
		pf->conv_buf = (char *)ft_memalloc((conv->width - len) + 1);
		ft_memset(pf->conv_buf, ' ', conv->width - len);
	}
	if (pf->conv_buf != NULL)
		pf->conv_buf = ft_strjoin(pf->conv_buf, ft_lltoa(d));
	else
		pf->conv_buf = ft_lltoa(d);
	pf->convsize = ft_strlen(pf->conv_buf);
}
