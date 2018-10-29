/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:51:03 by schakor           #+#    #+#             */
/*   Updated: 2018/10/29 18:20:48 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_pf(t_pf *pf, const char *format)
{
	pf->flags = 0;
	pf->ret = 0;
	pf->fmt = (char *)format;
	pf->buf = NULL;
	pf->bufsztot = BUFFSIZE;
}
