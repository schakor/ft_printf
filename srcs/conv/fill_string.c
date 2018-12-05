/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:41:08 by schakor           #+#    #+#             */
/*   Updated: 2018/12/05 19:06:33 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fill_prec(t_pf *pf, t_conv *conv)
{
	char		*tmp;

	pf->convsize = ft_strlen(pf->conv_buf);
	if ((conv->flag & FLAG_PREC) && conv->prec == 0 && pf->convsize == 1\
			&& pf->conv_buf[0] == '0')
	{
		if (conv->i_conv == o && (conv->flag & FLAG_HASH))
			return ;
		ft_strdel(&pf->conv_buf);
		pf->conv_buf = ft_strnew(1);
		pf->convsize = 0;
	}
	else if ((conv->flag & FLAG_PREC) && pf->convsize < conv->prec)
	{
		if (!(tmp = ft_strnewchar('0', conv->prec - pf->convsize)))
			exit(EXIT_FAILURE);
		pf->conv_buf = ft_strfjoin(tmp, pf->conv_buf, 2);
		pf->convsize = conv->prec;
	}
}

void		fill_zero(t_pf *pf, t_conv *conv, int isneg)
{
	char		*tmp;

	if (!(conv->iszero))
	{
		if ((conv->flag & FLAG_HASH) && conv->i_conv == o)
			pf->convsize += 1;
		if ((conv->flag & FLAG_HASH) && conv->i_conv == x)
			pf->convsize += 2;
		if ((conv->flag & FLAG_HASH) && conv->i_conv == mx)
			pf->convsize += 2;
	}
	if ((conv->flag & FLAG_WIDTH) && (conv->flag & FLAG_ZERO) \
			&& pf->convsize < conv->width)
	{
		if (((conv->flag & FLAG_PLUS) && !isneg) || isneg)
			pf->convsize += 1;
		//if (conv->flag & FLAG_SPACE || isneg)
		//	tmp = ft_strnewchar('0', conv->width - pf->convsize - 1);
		//else
			tmp = ft_strnewchar('0', conv->width - pf->convsize);
		pf->conv_buf = ft_strfjoin(tmp, pf->conv_buf, 2);
	}
}

void		fill_sign(t_pf *pf, t_conv *conv, int isneg)
{
	if ((conv->flag & FLAG_PLUS) && !isneg)
	{
		pf->conv_buf = ft_strfjoin("+", pf->conv_buf, 1);
		pf->convsize += 1;
	}
	else if (isneg)
	{
		pf->conv_buf = ft_strfjoin("-", pf->conv_buf, 1);
		pf->convsize += 1;
	}
	else if ((conv->flag & FLAG_SPACE) && !(conv->flag & FLAG_PLUS))
		pf->conv_buf = ft_strfjoin(" ", pf->conv_buf, 1);
}

void		fill_space(t_pf *pf, t_conv *conv)
{
	char		*tmp;

	if ((conv->flag & FLAG_WIDTH) && !(conv->flag & FLAG_ZERO) \
			&& pf->convsize < conv->width)
	{
		if (conv->flag & FLAG_SPACE)
			tmp = ft_strnewchar(' ', conv->width - pf->convsize - 1);
		else
			tmp = ft_strnewchar(' ', conv->width - pf->convsize);
		if (conv->flag & FLAG_MINUS)
			pf->conv_buf = ft_strfjoin(pf->conv_buf, tmp, 2);
		else
			pf->conv_buf = ft_strfjoin(tmp, pf->conv_buf, 2);
	}
}

void		fill_prefix(t_pf *pf, t_conv *conv)
{
	if (!(conv->iszero))
	{
		if ((conv->flag & FLAG_HASH) && conv->i_conv == o)
			pf->conv_buf = ft_strfjoin("0", pf->conv_buf, 1);
		if ((conv->flag & FLAG_HASH) && conv->i_conv == x)
			pf->conv_buf = ft_strfjoin("0x", pf->conv_buf, 1);
		if ((conv->flag & FLAG_HASH) && conv->i_conv == mx)
			pf->conv_buf = ft_strfjoin("0X", pf->conv_buf, 1);
	}
}
