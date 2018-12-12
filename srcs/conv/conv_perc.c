/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_perc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:50:38 by schakor           #+#    #+#             */
/*   Updated: 2018/12/12 16:06:05 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_perc(t_conv *conv, va_list *ap)
{
	(void)ap;
	conv->conv_buf = ft_strdup("%");
	fill_prec(conv);
	fill_zero(conv, 0);
	fill_space(conv);
	conv->convsize = ft_strlen(conv->conv_buf);
}
