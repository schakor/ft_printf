/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:25:12 by schakor           #+#    #+#             */
/*   Updated: 2018/10/29 18:33:32 by schakor          ###   ########.fr       */
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
	ft_memcpy(ret, pf->buf, pf->ret);
	ft_strdel(&(pf->buf));
	pf->buf = ret;
	pf->bufsztot += BUFFSIZE;
}

void		insert_buffer(t_pf *pf, char *add, int size)
{
	if (pf->ret + size >= pf->bufsztot)
		increase_buffer(pf);
	ft_memcpy(pf->buf + pf->ret, add, size);
	pf->ret += size;
}
