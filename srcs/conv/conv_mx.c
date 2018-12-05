/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_mx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:49:29 by schakor           #+#    #+#             */
/*   Updated: 2018/12/05 18:51:48 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void						conv_mx(t_pf *pf, t_conv *conv, va_list *ap)
{
	unsigned long long		d;

	if (conv->mod & MODIF_HH)
		d = (unsigned char)va_arg(*ap, unsigned int);
	else if (conv->mod & MODIF_H)
		d = (unsigned short)va_arg(*ap, unsigned int);
	else if (conv->mod & MODIF_L)
		d = (unsigned long)va_arg(*ap, unsigned long);
	else if (conv->mod & MODIF_LL)
		d = (unsigned long long)va_arg(*ap, unsigned long long);
	else if (conv->mod & MODIF_J)
		d = (uintmax_t)va_arg(*ap, uintmax_t);
	else
		d = (unsigned int)va_arg(*ap, unsigned int);
	if (d == 0)
		conv->iszero = 0;
	pf->conv_buf = ft_ulltoa_base(d, 16, 1);
	generic_number_conv(pf, conv, 0);
	pf->convsize = ft_strlen(pf->conv_buf);
}
