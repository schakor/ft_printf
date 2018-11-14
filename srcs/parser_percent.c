/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:46:01 by schakor           #+#    #+#             */
/*   Updated: 2018/11/14 11:32:25 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		parse_flags(t_pf *pf, t_conv *conv)
{
	while (*pf->fmt && ft_isflagpf(*pf->fmt))
	{
		if (*pf->fmt == '-')
			conv->flag_mod |= FLAG_MINUS;
		else if (*pf->fmt == '+')
			conv->flag_mod |= FLAG_PLUS;
		else if (*pf->fmt == '0')
			conv->flag_mod |= FLAG_ZERO;
		else if (*pf->fmt == ' ')
			conv->flag_mod |= FLAG_SPACE;
		else if (*pf->fmt == '#')
			conv->flag_mod |= FLAG_HASH;
		pf->fmt++;
	}
}

static void		parse_width(t_pf *pf, t_conv *conv)
{
	while (*pf->fmt && *pf->fmt >= '0' && *pf->fmt <= '9')
		conv->width = (conv->width * 10) + (*pf->fmt++ - '0');
}

static void		parse_prec(t_pf *pf, t_conv *conv)
{
	if (*pf->fmt && *pf->fmt == '.')
	{
		pf->fmt++;
		conv->flag_mod &= FLAG_PLUS;
		while (*pf->fmt && *pf->fmt >= '0' && *pf->fmt < '9')
			conv->prec = (conv->prec * 10) + (*pf->fmt++ - '0');
	}
}

static void		parse_conv(t_pf *pf, t_conv *conv)
{
		
}

void			parser_percent(t_pf *pf, t_conv *conv)
{
	pf->fmt++;
	//check_validity();
	parse_flags(pf, conv);
	parse_width(pf, conv);
	parse_prec(pf, conv);
	parse_conv(pf, conv);
}
