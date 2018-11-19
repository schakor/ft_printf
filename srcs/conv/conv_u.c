/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:47:52 by schakor           #+#    #+#             */
/*   Updated: 2018/11/19 20:38:26 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void						conv_u(t_pf *pf, t_conv *conv, va_list *ap)
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
	else
		d = (unsigned int)va_arg(*ap, unsigned int);
	pf->conv_buf = ft_ulltoa_base(d, 10, 0);
	pf->convsize = ft_strlen(pf->conv_buf);
}
