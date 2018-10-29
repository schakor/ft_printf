/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:33:45 by schakor           #+#    #+#             */
/*   Updated: 2018/10/29 18:34:29 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		destroy_pf(t_pf *pf)
{
	ft_strdel(&(pf->buf));
	free(pf);
	pf = NULL;
}
