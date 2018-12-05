/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:07:48 by schakor           #+#    #+#             */
/*   Updated: 2018/12/05 19:13:40 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			conv_d(t_pf *pf, t_conv *conv, va_list *ap)
{
	long long	d;
	t_uint64	ret;
	int			isneg;

	if (conv->mod & MODIF_HH)
		d = (signed char)va_arg(*ap, int);
	else if (conv->mod & MODIF_H)
		d = (short)va_arg(*ap, int);
	else if (conv->mod & MODIF_L)
		d = (long)va_arg(*ap, long);
	else if (conv->mod & MODIF_LL)
		d = (long long)va_arg(*ap, long long);
	else if (conv->mod & MODIF_J)
		d = (intmax_t)va_arg(*ap, intmax_t);
	else
		d = (int)va_arg(*ap, int);
	if (d < 0)
	{
		ret = -d;
		isneg = 1;
	}
	else
	{
		ret = d;
		isneg = 0;
	}
	pf->conv_buf = ft_ulltoa(ret);
	generic_number_conv(pf, conv, isneg);
	pf->convsize = ft_strlen(pf->conv_buf);
}
