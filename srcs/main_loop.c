/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:59:17 by schakor           #+#    #+#             */
/*   Updated: 2018/12/12 16:10:28 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				main_loop(const char *format, va_list *ap)
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
			init_conv(&conv);
			parser_percent(&pf, &conv);
			if (conv.index_conv != -1)
				pf.fun_ptr[conv.index_conv](&conv, ap);
			insert_buffer(&pf, conv.conv_buf, conv.convsize);
			ft_strdel(&conv.conv_buf);
		}
		else
			break ;
		pf.percent = pf.fmt;
	}
	write(1, pf.buf, pf.bufsize);
	destroy_pf(&pf);
	return (pf.bufsize);
}
