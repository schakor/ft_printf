/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:07:48 by schakor           #+#    #+#             */
/*   Updated: 2018/12/12 16:03:56 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_int64	cast_va_arg(t_conv *conv, va_list *ap)
{
	t_int64		d;

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
	else if (conv->mod & MODIF_Z)
		d = (size_t)va_arg(*ap, size_t);
	else
		d = (int)va_arg(*ap, int);
	return (d);
}

void			conv_d(t_conv *conv, va_list *ap)
{
	t_int64		d;
	t_uint64	ret;
	int			isneg;

	d = cast_va_arg(conv, ap);
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
	conv->conv_buf = ft_ulltoa(ret);
	generic_number_conv(conv, isneg);
	conv->convsize = ft_strlen(conv->conv_buf);
}
