/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:07:48 by schakor           #+#    #+#             */
/*   Updated: 2018/11/16 17:40:04 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_d(t_pf *pf, t_conv *conv, va_list *ap)
{
	int		d;
	
	if (conv->flag)
		;
	d = va_arg(*ap, int);
	pf->conv_buf = ft_itoa(d);
	pf->convsize = ft_strlen(pf->conv_buf);
}
