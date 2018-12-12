/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 09:30:31 by schakor           #+#    #+#             */
/*   Updated: 2018/12/12 16:10:44 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_fun_ptr(t_pf *pf)
{
	pf->fun_ptr[c] = &conv_c;
	pf->fun_ptr[s] = &conv_s;
	pf->fun_ptr[p] = &conv_p;
	pf->fun_ptr[d] = &conv_d;
	pf->fun_ptr[i] = &conv_i;
	pf->fun_ptr[o] = &conv_o;
	pf->fun_ptr[u] = &conv_u;
	pf->fun_ptr[x] = &conv_x;
	pf->fun_ptr[mx] = &conv_mx;
	pf->fun_ptr[f] = &conv_f;
	pf->fun_ptr[perc] = &conv_perc;
}

void			init_pf(t_pf *pf, const char *format)
{
	pf->buf = NULL;
	pf->bufsize = 0;
	pf->bufalloc = 0;
	pf->fmt = (char *)format;
	pf->percent = (char *)format;
	init_fun_ptr(pf);
}

void			init_conv(t_conv *conv)
{
	conv->flag = 0;
	conv->width = 0;
	conv->prec = 0;
	conv->mod = 0;
	conv->iszero = 0;
	conv->index_conv = -1;
	conv->conv_buf = NULL;
	conv->convsize = 0;
}
