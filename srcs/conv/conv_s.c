/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:19:54 by schakor           #+#    #+#             */
/*   Updated: 2018/11/19 16:22:41 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_s(t_pf *pf, t_conv *conv, va_list *ap)
{
	char	*s;
	int		i;

	s = (char *)va_arg(*ap, int *);
	i = ft_strlen(s);
	if (i > (int)conv->prec)
		pf->convsize = (int)conv->prec;
	else
		pf->convsize = ft_strlen(s);
	pf->conv_buf = s;
}
