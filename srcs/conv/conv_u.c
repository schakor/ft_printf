/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:47:52 by schakor           #+#    #+#             */
/*   Updated: 2018/12/12 16:04:50 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void						conv_u(t_conv *conv, va_list *ap)
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
	else if (conv->mod & MODIF_Z)
		d = (size_t)va_arg(*ap, size_t);
	else
		d = (unsigned int)va_arg(*ap, unsigned int);
	conv->conv_buf = ft_ulltoa_base(d, 10, 0);
	generic_number_conv(conv, 0);
	conv->convsize = ft_strlen(conv->conv_buf);
}
