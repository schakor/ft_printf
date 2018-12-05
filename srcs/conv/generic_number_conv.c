/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_number_conv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:44:37 by schakor           #+#    #+#             */
/*   Updated: 2018/11/30 16:58:54 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			generic_number_conv(t_pf *pf, t_conv *conv, int isneg)
{
	fill_prec(pf, conv);
	fill_zero(pf, conv, isneg);
	fill_sign(pf, conv, isneg);
	fill_prefix(pf, conv);
	fill_space(pf, conv);
}
