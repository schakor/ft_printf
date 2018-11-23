/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:50:08 by schakor           #+#    #+#             */
/*   Updated: 2018/11/23 15:39:31 by khsadira         ###   ########.fr       */
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
static char		*convert_to_str(double n, int int_len, int float_len, char *tmp)
{
	int	i;

	(void)n;
	(void)int_len;
	(void)float_len;

	i = 0;
	if (tmp[i] == '-')
		i++;
	printf("%d | %d\n", int_len, float_len);
	ft_putendl(tmp);
	return (tmp);
}
static char		*from_d_to_str(double f, int int_len, int float_len, t_conv *conv)
{
	char		*tmp;
	int			i;
	int			neg;
	int			point;

	point = float_len > 0 ? 1 : 0;
	neg = f < 0 ? 1 : 0;
	i = float_len + neg + max_value(int_len + float_len, conv->width);
	printf("i = %d | %d | %d\n", i, int_len, float_len);
	if (!(tmp = ft_memalloc(i)))
		return (NULL);
	if ((conv->flag & FLAG_WIDTH) && conv->width > 1)
	{
		if (conv->flag & FLAG_ZERO)
			ft_memset(tmp, '0', i - 1);
		else
			ft_memset(tmp, ' ', i - 1);
		if (conv->flag & FLAG_MINUS || conv->flag & FLAG_ZERO)
		{
			if (neg)
				ft_memcpy(tmp, "-", 1);
		}
		else if (neg)
			ft_memcpy(tmp + (i - (float_len + int_len)), "-", 1);
		tmp = convert_to_str(f, int_len, float_len, tmp);
	}

	return (tmp);
}

void		conv_f(t_pf *pf, t_conv *conv, va_list *ap)
{
	double		f;
	int			int_len;
	int			float_len;

	/*(void)pf;
	(void)conv;
	(void)ap;*/
	f = (double)va_arg(*ap, double);	
	int_len = ft_dlen(f);
	float_len = 6;
	float_len = (conv->flag & FLAG_PREC) ? conv->prec : 6;
	if (conv->flag & FLAG_PREC)
		float_len = conv->prec;
	printf("%f\ni = %d | f = %d | conv = %d\n", f, int_len, float_len, conv->width);
	pf->conv_buf = from_d_to_str(f, int_len, float_len, conv);
	pf->convsize = max_value(int_len + float_len, conv->width);
}
