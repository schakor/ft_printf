/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_perc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:50:38 by schakor           #+#    #+#             */
/*   Updated: 2018/11/19 20:55:02 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_perc(t_pf *pf, t_conv *conv, va_list *ap)
{
	(void)ap;
	(void)conv;
	pf->conv_buf = ft_strdup("%");
	pf->convsize = 1;
}
