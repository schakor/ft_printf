/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:20:32 by schakor           #+#    #+#             */
/*   Updated: 2018/11/20 16:49:35 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	max_value(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void		conv_p(t_pf *pf, t_conv *conv, va_list *ap)
{
	(void)pf;
	(void)conv;
	(void)ap;
	int		i;
	char	*tmp;
	char	*s;
	void	*pointer;

	
	pointer = (void *)va_arg(*ap, void *);
	s = ft_strdup("0x");
	s = ft_strfjoin(s, ft_ulltoa_base((unsigned long long)pointer, 16, 0), 0);
	i = max_value(ft_strlen(s), conv->width);
	if ((conv->flag & FLAG_WIDTH) && conv->width > 1)
	{
		if (!(tmp = ft_memalloc(i)))
			return ;
		if (conv->flag & FLAG_ZERO)
			ft_memset(tmp, '0', i - 1);
		else
			ft_memset(tmp, ' ', i - 1);
		if (conv->flag & FLAG_MINUS)
			ft_memcpy(tmp, s, ft_strlen(s));
		else
			ft_memcpy(tmp + (i - ft_strlen(s)), s, i);
	}
	else
		tmp = ft_strdup(s);
	if (s)
		ft_strdel(&s);
	pf->conv_buf = tmp;
	pf->convsize += i;
}
