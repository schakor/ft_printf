/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:25:12 by schakor           #+#    #+#             */
/*   Updated: 2018/11/30 16:01:14 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		increase_buffer(t_pf *pf)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(*ret) * (pf->bufsztot + BUFFSIZE))))
	{
		destroy_pf(pf);
		exit(EXIT_FAILURE);
	}
	ft_memset(ret, '\0', pf->bufsztot + BUFFSIZE);
	if (pf->buf)
		ft_memcpy(ret, pf->buf, pf->buf_i);
	ft_strdel(&(pf->buf));
	pf->buf = ret;
	pf->bufsztot += BUFFSIZE;
}

void		insert_buffer(t_pf *pf, char *ins, int size)
{
	if (ins == NULL || size == 0)
		return ;
	if (pf->buf_i + size >= pf->bufsztot)
		increase_buffer(pf);
	ft_memcpy(pf->buf + pf->buf_i, ins, size);
	pf->buf_i += size;
}
