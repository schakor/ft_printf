/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_perc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:50:38 by schakor           #+#    #+#             */
/*   Updated: 2018/11/30 15:49:33 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_perc(t_pf *pf, t_conv *conv, va_list *ap)
{
	(void)ap;
	pf->conv_buf = ft_strdup("%");
	fill_prec(pf, conv);
	fill_zero(pf, conv, 0);
	fill_space(pf, conv);
	pf->convsize = ft_strlen(pf->conv_buf);
}
