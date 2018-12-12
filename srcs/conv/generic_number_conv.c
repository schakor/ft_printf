/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_number_conv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:44:37 by schakor           #+#    #+#             */
/*   Updated: 2018/12/12 16:06:48 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			generic_number_conv(t_conv *conv, int isneg)
{
	fill_prec(conv);
	fill_zero(conv, isneg);
	fill_sign(conv, isneg);
	fill_prefix(conv);
	fill_space(conv);
}
