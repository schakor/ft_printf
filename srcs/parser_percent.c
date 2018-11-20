/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:46:01 by schakor           #+#    #+#             */
/*   Updated: 2018/11/20 14:12:50 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				parse_flags(t_pf *pf, t_conv *conv)
{
	while (*pf->fmt && ft_isflagpf(*pf->fmt))
	{
		if (*pf->fmt == '-')
		{
			conv->flag |= FLAG_MINUS;
			conv->flag &= ~FLAG_ZERO;
		}
		else if (*pf->fmt == '+')
			conv->flag |= FLAG_PLUS;
		else if (*pf->fmt == '0' && !(conv->flag & FLAG_MINUS))
			conv->flag |= FLAG_ZERO;
		else if (*pf->fmt == ' ')
			conv->flag |= FLAG_SPACE;
		else if (*pf->fmt == '#')
			conv->flag |= FLAG_HASH;
		pf->fmt++;
	}
}

static void				parse_width(t_pf *pf, t_conv *conv)
{
	if (*pf->fmt && *pf->fmt >= '0' && *pf->fmt <= '9')
	{
		while (*pf->fmt && *pf->fmt >= '0' && *pf->fmt <= '9')
			conv->width = (conv->width * 10) + (*pf->fmt++ - '0');
		conv->flag |= FLAG_WIDTH;
	}
}

static void				parse_prec(t_pf *pf, t_conv *conv)
{
	if (*pf->fmt && *pf->fmt == '.')
	{
		pf->fmt++;
		conv->flag |= FLAG_PREC;
		conv->flag &= ~FLAG_ZERO;
		while (*pf->fmt && *pf->fmt >= '0' && *pf->fmt <= '9')
			conv->prec = (conv->prec * 10) + (*pf->fmt++ - '0');
	}
}

static void				parse_mod(t_pf *pf, t_conv *conv)
{
	if (*pf->fmt && *(pf->fmt + 1) && *pf->fmt == 'h' && *(pf->fmt + 1) == 'h')
	{
		conv->mod |= MODIF_HH;
		(pf->fmt) += 2;
	}
	else if (*pf->fmt && *pf->fmt == 'h')
	{
		conv->mod |= MODIF_H;
		(pf->fmt)++;
	}
	else if (*pf->fmt && *(pf->fmt + 1) && *pf->fmt == 'l' && *(pf->fmt + 1) == 'l')
	{
		conv->mod |= MODIF_LL;
		(pf->fmt) += 2;
	}
	else if (*pf->fmt && *pf->fmt == 'l')
	{
		conv->mod |= MODIF_L;
		(pf->fmt)++;
	}
}

static void				parse_conv(t_pf *pf, t_conv *conv)
{
	static const char	*valid_conv = "cspdiouxXf%";
	t_uint8				i;

	i = 0;
	while (valid_conv[i])
	{
		if (valid_conv[i] == *pf->fmt)
		{
			if (i >= 3 && i <= 8 && (conv->flag & FLAG_PREC))
				conv->flag &= ~FLAG_ZERO;
			conv->i_conv = i;
			(pf->fmt)++;
			return ;
		}
		i++;
	}
}

void					parser_percent(t_pf *pf, t_conv *conv)
{
	pf->fmt++;
	//check_validity();
	parse_flags(pf, conv);
	parse_width(pf, conv);
	parse_prec(pf, conv);
	parse_mod(pf, conv);
	parse_conv(pf, conv);
}
