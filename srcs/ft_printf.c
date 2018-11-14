/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:12:31 by schakor           #+#    #+#             */
/*   Updated: 2018/11/14 11:32:27 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			init_conv(t_conv *cv)
{
	cv->flags = 0;
	cv->width = 0;
	cv->prec = 0;
	cv->conv = 0;
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
	//static void		(*fcn_ptr[])(t_pf *, t_conv *conv) = {conv_c, conv_s, \
	//conv_p, conv_d, conv_i, conv_o, conv_u, conv_x, conv_X};
	//va_list			ap;

	init_pf(&pf, format);
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
			printf("arg %d : minus = %d | plus = %d | zero = %d | space = %d | hash = %d | width = %llu | prec = %llu | conv = %c\n", i++, (conv.flags & FLAG_MINUS), ((conv.flags & FLAG_PLUS) >> 1), ((conv.flags & FLAG_ZERO) >> 2), ((conv.flags & FLAG_SPACE) >> 3), ((conv.flags & FLAG_HASH) >> 4), conv.width, conv.prec, conv.conv);
			//if ()
			//	fcn_ptr[](&pf, &conv);
			//insert_buffer(&pf, pf.conv_buf, pf.convsize);
		}
		else
			break ;
		//pf.fmt = ++pf.percent;
		pf.percent = ++pf.fmt;
	}
	write(1, pf.buf, pf.buf_i);
	return (pf.buf_i);
}
