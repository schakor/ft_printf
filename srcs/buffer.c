/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:25:12 by schakor           #+#    #+#             */
/*   Updated: 2018/12/12 15:44:22 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		increase_buffer(t_pf *pf)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(*ret) * (pf->bufalloc + BUFFSIZE))))
	{
		destroy_pf(pf);
		exit(EXIT_FAILURE);
	}
	ft_memset(ret, '\0', pf->bufalloc + BUFFSIZE);
	if (pf->buf)
		ft_memcpy(ret, pf->buf, pf->bufsize);
	ft_strdel(&(pf->buf));
	pf->buf = ret;
	pf->bufalloc += BUFFSIZE;
}

void		insert_buffer(t_pf *pf, char *ins, int size)
{
	if (ins == NULL || size == 0)
		return ;
	if (pf->bufsize + size >= pf->bufalloc)
		increase_buffer(pf);
	ft_memcpy(pf->buf + pf->bufsize, ins, size);
	pf->bufsize += size;
}
