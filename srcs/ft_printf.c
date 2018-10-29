/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:12:31 by schakor           #+#    #+#             */
/*   Updated: 2018/10/29 22:04:18 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_pf	pf;
	char	*percent;

	init_pf(&pf, format);
	while (*(pf.fmt) != '\0')
	{
		if (*(pf.fmt) == '%')
		{
			;
		}
		else
			insert_buffer(&pf, pf.fmt, 1);
		(pf.fmt)++;
	}
	write(1, pf.buf, pf.ret);
	return (pf.ret);
}
