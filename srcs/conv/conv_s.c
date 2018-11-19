/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:19:54 by schakor           #+#    #+#             */
/*   Updated: 2018/11/19 16:46:36 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_s(t_pf *pf, t_conv *conv, va_list *ap)
{
	char	*s;
	int		i;

	s = (char *)va_arg(*ap, char *);
	i = ft_strlen(s);
	if ((conv->flag & FLAG_PREC) && i > (int)conv->prec)
		pf->convsize = (int)conv->prec;
	else
		pf->convsize = i;
	pf->conv_buf = s;
}