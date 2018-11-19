/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:17:34 by schakor           #+#    #+#             */
/*   Updated: 2018/11/19 16:01:06 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_c(t_pf *pf, t_conv *conv, va_list *ap)
{
	char	c;

	(void)conv;
	c = (char)va_arg(*ap, int);
	pf->conv_buf = &c;
	pf->convsize = 1;
}
