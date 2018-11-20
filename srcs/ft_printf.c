/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:12:31 by schakor           #+#    #+#             */
/*   Updated: 2018/11/20 11:57:12 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			init_conv_pf(t_pf *pf, t_conv *cv)
{
	cv->flag = 0;
	cv->width = 0;
	cv->prec = 0;
	cv->mod = 0;
	cv->i_conv = -1;
	pf->conv_buf = NULL;
	pf->convsize = 0;
}

static void			init_pf(t_pf *pf, const char *format)
{
	pf->buf = NULL;
	pf->conv_buf = NULL;
	pf->buf_i = 0;
	pf->bufsztot = 0;
	pf->convsize = 0;
	pf->fmt = (char *)format;
	pf->percent = (char *)format;
}

int					ft_printf(const char *format, ...)
{
	t_pf			pf;
	t_conv			conv;
	static void		(*fcn_ptr[])(t_pf *, t_conv *conv, va_list *ap) = {conv_c, \
		conv_s, conv_p, conv_d, conv_i, conv_o, conv_u, conv_x, conv_mx, conv_f, \
	conv_perc};
	va_list			ap;

	init_pf(&pf, format);
	va_start(ap, format);
	while (*pf.fmt != '\0')
	{
		while (*pf.percent && *pf.percent != '%')
			pf.percent++;
		insert_buffer(&pf, pf.fmt, pf.percent - pf.fmt);
		pf.fmt = pf.percent;
		if (*pf.percent == '%')
		{
			init_conv_pf(&pf, &conv);
			parser_percent(&pf, &conv);
			/*static int i = 0;
			printf("%d : - = %d | + = %d | 0 = %d | ' ' = %d | # = %d | w = %d | w = %d | p = %d | p = %d | hh = %d | h = %d | ll = %d | l = %d | indc = %d\n", i++, (conv.flag & FLAG_MINUS), ((conv.flag & FLAG_PLUS) >> 1), ((conv.flag & FLAG_ZERO) >> 2), ((conv.flag & FLAG_SPACE) >> 3), ((conv.flag & FLAG_HASH) >> 4), ((conv.flag & FLAG_WIDTH) >> 5), conv.width, ((conv.flag & FLAG_PREC) >> 6), conv.prec, (conv.mod & MODIF_HH), ((conv.mod & MODIF_H) >> 1), ((conv.mod & MODIF_LL) >> 2), ((conv.mod & MODIF_L) >> 3), conv.i_conv);
			*/
			if (conv.i_conv != -1)
				fcn_ptr[conv.i_conv](&pf, &conv, &ap);
			insert_buffer(&pf, pf.conv_buf, pf.convsize);
		}
		else
			break ;
		pf.percent = pf.fmt;
	}
	va_end(ap);
	write(1, pf.buf, pf.buf_i);
	return (pf.buf_i);
}
