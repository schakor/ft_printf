/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_number_conv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:44:37 by schakor           #+#    #+#             */
/*   Updated: 2018/11/20 14:26:30 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		generic_number_conv(t_pf *pf, t_conv *conv)
{
	char 	*tmp;
	int		len;
	int		ok;

	ok = pf->conv_buf[0] == '-' ? 0 : 1;
	len = ft_strlen(pf->conv_buf);
	if (conv->flag != 0)
	{
		if ((conv->flag & FLAG_PREC) && len < conv->prec)
		{
			tmp = (char *)ft_memalloc(conv->prec - len + 1);
			ft_memset(tmp, '0', conv->prec - len);
			pf->conv_buf = ft_strjoin(tmp, pf->conv_buf);
			len = conv->prec;
		}
		if ((conv->flag & FLAG_PLUS) && ok)
		{
			pf->conv_buf = ft_strjoin("+", pf->conv_buf);
			len += 1;
		}
		if ((conv->flag & FLAG_WIDTH) && len < conv->width)
		{
			if ((conv->flag & FLAG_ZERO) && (conv->flag & FLAG_SPACE))
			{
				tmp = (char *)ft_memalloc(conv->width - len);
				if (conv->flag & FLAG_ZERO)
					ft_memset(tmp, '0', conv->width - len - 1);
				else
					ft_memset(tmp, ' ', conv->width - len - 1);
			}
			else
			{
				tmp = (char *)ft_memalloc(conv->width - len + 1);
				if (conv->flag & FLAG_ZERO)
					ft_memset(tmp, '0', conv->width - len);
				else
					ft_memset(tmp, ' ', conv->width - len);
			}
			if (conv->flag & FLAG_MINUS)
				pf->conv_buf = ft_strjoin(pf->conv_buf, tmp);
			else
				pf->conv_buf = ft_strjoin(tmp, pf->conv_buf);
		}
		if ((conv->flag & FLAG_SPACE) && !(conv->flag & FLAG_PLUS))
			pf->conv_buf = ft_strjoin(" ", pf->conv_buf);
	}
}
