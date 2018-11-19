/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:07:48 by schakor           #+#    #+#             */
/*   Updated: 2018/11/19 20:48:31 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			conv_d(t_pf *pf, t_conv *conv, va_list *ap)
{
	char		*tmp;
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
	/*
	if ((conv->flag & FLAG_WIDTH) && len < conv->width)
	{
		if (len < conv->prec)
		{
			pf->conv_buf = (char *)ft_memalloc(conv->width - conv->prec + 1);
			ft_memset(pf->conv_buf, ' ', conv->width - conv->prec);
		}
		else
		{
			pf->conv_buf = (char *)ft_memalloc(conv->width - len + 1);
			ft_memset(pf->conv_buf, ' ', conv->width - len);
		}
	}
	*/
	pf->conv_buf = ft_lltoa(d);
	if (conv->flag != 0)
	{
		if ((conv->flag & FLAG_PREC) && len < conv->prec)
		{
			tmp = (char *)ft_memalloc(conv->prec - len + 1);
			ft_memset(tmp, '0', conv->prec - len);
			pf->conv_buf = ft_strjoin(tmp, pf->conv_buf);
			len = conv->prec;
		}
		if ((conv->flag & FLAG_PLUS))
		{
			pf->conv_buf = ft_strjoin("+", pf->conv_buf);
			len += 1;
		}
		if ((conv->flag & FLAG_WIDTH) && len < conv->width)
		{
			tmp = (char *)ft_memalloc(conv->width - len + 1);
			ft_memset(tmp, ' ', conv->width - len);
			if (pf->conv_buf)
				pf->conv_buf = ft_strjoin(tmp, pf->conv_buf);
			else
				pf->conv_buf = tmp;
		}
	}
	else
		pf->conv_buf = ft_lltoa(d);
	pf->convsize = ft_strlen(pf->conv_buf);
}
