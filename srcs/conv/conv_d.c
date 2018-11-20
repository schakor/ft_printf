/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:07:48 by schakor           #+#    #+#             */
/*   Updated: 2018/11/20 13:26:16 by schakor          ###   ########.fr       */
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
			if ((conv->flag & FLAG_ZERO) && (conv->flag & FLAG_SPACE))
			{
				printf("ok\n");
				tmp = (char *)ft_memalloc(conv->width - len);
				ft_memset(tmp, '0', conv->width - len - 1);
			}
			else if (conv->flag & FLAG_ZERO)
			{
				tmp = (char *)ft_memalloc(conv->width - len + 1);
				ft_memset(tmp, '0', conv->width - len);
			}
			else
			{
				tmp = (char *)ft_memalloc(conv->width - len + 1);
				ft_memset(tmp, ' ', conv->width - len);
			}
			if (conv->flag & FLAG_MINUS)
				pf->conv_buf = ft_strjoin(pf->conv_buf, tmp);
			else
				pf->conv_buf = ft_strjoin(tmp, pf->conv_buf);
		}
		if (conv->flag & FLAG_SPACE)
			pf->conv_buf = ft_strjoin(" ", pf->conv_buf);
	}
	pf->convsize = ft_strlen(pf->conv_buf);
}
