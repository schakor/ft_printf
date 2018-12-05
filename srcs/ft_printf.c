/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:12:31 by schakor           #+#    #+#             */
/*   Updated: 2018/12/05 20:10:19 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			do_printf(const char *format, va_list *ap)
{
	t_pf		pf;
	t_conv		conv;

	init_pf(&pf, format);
	while (*pf.fmt != '\0')
	{
		while (*pf.percent && *pf.percent != '%')
			pf.percent++;
		insert_buffer(&pf, pf.fmt, pf.percent - pf.fmt);
		pf.fmt = pf.percent;
		if (*pf.percent == '%')
		{
			init_conv(&pf, &conv);
			parser_percent(&pf, &conv);
			if (conv.i_conv != -1)
				pf.fun_ptr[conv.i_conv](&pf, &conv, ap);
			insert_buffer(&pf, pf.conv_buf, pf.convsize);
			ft_strdel(&pf.conv_buf);
		}
		else
			break ;
		pf.percent = pf.fmt;
	}
	write(1, pf.buf, pf.buf_i);
	destroy_pf(&pf);
	return (pf.buf_i);
}

int					ft_printf(const char *format, ...)
{
	int				ret;
	va_list			ap;

	va_start(ap, format);
	ret = do_printf(format, &ap);
	va_end(ap);
	return (ret);
}
