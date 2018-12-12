/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:41:08 by schakor           #+#    #+#             */
/*   Updated: 2018/12/12 16:00:48 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fill_prec(t_conv *conv)
{
	char		*tmp;

	conv->convsize = ft_strlen(conv->conv_buf);
	if ((conv->flag & FLAG_PREC) && conv->prec == 0 && conv->convsize == 1\
			&& conv->conv_buf[0] == '0')
	{
		if (conv->index_conv == o && (conv->flag & FLAG_HASH))
			return ;
		ft_strdel(&conv->conv_buf);
		conv->conv_buf = ft_strnew(1);
		conv->convsize = 0;
	}
	else if ((conv->flag & FLAG_PREC) && conv->convsize < conv->prec)
	{
		if (!(tmp = ft_strnewchar('0', conv->prec - conv->convsize)))
			exit(EXIT_FAILURE);
		conv->conv_buf = ft_strfjoin(tmp, conv->conv_buf, 2);
		conv->convsize = conv->prec;
	}
}

void		fill_zero(t_conv *conv, int isneg)
{
	char		*tmp;

	if (!(conv->iszero))
	{
		if ((conv->flag & FLAG_HASH) && conv->index_conv == o)
			conv->convsize += 1;
		if ((conv->flag & FLAG_HASH) && conv->index_conv == x)
			conv->convsize += 2;
		if ((conv->flag & FLAG_HASH) && conv->index_conv == mx)
			conv->convsize += 2;
	}
	if ((conv->flag & FLAG_WIDTH) && (conv->flag & FLAG_ZERO) \
			&& conv->convsize < conv->width)
	{
		if (((conv->flag & FLAG_PLUS) && !isneg) || isneg)
			conv->convsize += 1;
		tmp = ft_strnewchar('0', conv->width - conv->convsize);
		conv->conv_buf = ft_strfjoin(tmp, conv->conv_buf, 2);
	}
}

void		fill_sign(t_conv *conv, int isneg)
{
	if (conv->index_conv != d && conv->index_conv != i)
		return ;
	if ((conv->flag & FLAG_PLUS) && !isneg)
	{
		conv->conv_buf = ft_strfjoin("+", conv->conv_buf, 1);
		conv->convsize += 1;
	}
	else if (isneg)
	{
		conv->conv_buf = ft_strfjoin("-", conv->conv_buf, 1);
		conv->convsize += 1;
	}
	else if ((conv->flag & FLAG_SPACE) && !(conv->flag & FLAG_PLUS))
		conv->conv_buf = ft_strfjoin(" ", conv->conv_buf, 1);
}

void		fill_space(t_conv *conv)
{
	char		*tmp;

	if ((conv->flag & FLAG_WIDTH) && !(conv->flag & FLAG_ZERO) \
			&& conv->convsize < conv->width)
	{
		if (conv->flag & FLAG_SPACE)
			tmp = ft_strnewchar(' ', conv->width - conv->convsize - 1);
		else
			tmp = ft_strnewchar(' ', conv->width - conv->convsize);
		if (conv->flag & FLAG_MINUS)
			conv->conv_buf = ft_strfjoin(conv->conv_buf, tmp, 2);
		else
			conv->conv_buf = ft_strfjoin(tmp, conv->conv_buf, 2);
	}
}

void		fill_prefix(t_conv *conv)
{
	if (!(conv->iszero))
	{
		if ((conv->flag & FLAG_HASH) && conv->index_conv == o)
			conv->conv_buf = ft_strfjoin("0", conv->conv_buf, 1);
		if ((conv->flag & FLAG_HASH) && conv->index_conv == x)
			conv->conv_buf = ft_strfjoin("0x", conv->conv_buf, 1);
		if ((conv->flag & FLAG_HASH) && conv->index_conv == mx)
			conv->conv_buf = ft_strfjoin("0X", conv->conv_buf, 1);
	}
}
