/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:12:31 by schakor           #+#    #+#             */
/*   Updated: 2018/11/19 12:22:43 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			init_conv(t_conv *cv)
{
	cv->flag = 0;
	cv->width = 0;
	cv->prec = 0;
	cv->mod = 0;
	cv->i_conv = -1;
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
	static void		(*fcn_ptr[])(t_pf *, t_conv *conv, va_list *ap) = {conv_c, conv_s, conv_p, conv_d};
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
			init_conv(&conv);
			parser_percent(&pf, &conv);
			static int i = 0;
			printf("%d : - = %d | + = %d | 0 = %d | ' ' = %d | # = %d | wid = %llu | pre = %llu | hh = %d | h = %d | ll = %d | l = %d | i_conv = %d\n", i++, (conv.flag & FLAG_MINUS), ((conv.flag & FLAG_PLUS) >> 1), ((conv.flag & FLAG_ZERO) >> 2), ((conv.flag & FLAG_SPACE) >> 3), ((conv.flag & FLAG_HASH) >> 4), conv.width, conv.prec,(conv.mod & MODIF_HH), ((conv.mod & MODIF_H) >> 1), ((conv.mod & MODIF_LL) >> 2), ((conv.mod & MODIF_L) >> 3), conv.i_conv);
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
