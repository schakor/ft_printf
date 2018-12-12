/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:13:19 by schakor           #+#    #+#             */
/*   Updated: 2018/12/12 16:10:34 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <locale.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/includes/libft.h"
# include <stdio.h>

/*
**	TYPES
*/

typedef signed char			t_int8;
typedef signed short		t_int16;
typedef signed int			t_int32;
typedef signed long long	t_int64;
typedef unsigned char		t_uint8;
typedef unsigned short		t_uint16;
typedef unsigned int		t_uint32;
typedef unsigned long long	t_uint64;
typedef unsigned char		t_bool;

/*
**	BIT FLAGS : '-' | '+' | '0' | ' ' | '#'
*/

# define FLAG_MINUS			0x1
# define FLAG_PLUS			0x2
# define FLAG_ZERO			0x4
# define FLAG_SPACE			0x8
# define FLAG_HASH			0x10
# define FLAG_WIDTH			0x20
# define FLAG_PREC			0x40

# define TRUE				1
# define FALSE				0

/*
**	BIT FLAGS MODIFIER : 'hh' | 'h' | 'll' | 'l'
*/

# define MODIF_HH			0x1
# define MODIF_H			0x2
# define MODIF_LL			0x4
# define MODIF_L			0x8
# define MODIF_J			0x10
# define MODIF_Z			0x20

# define BUFFSIZE			2048
# define STOP				-2
# define ERROR				-1

enum
{
	c = 0,
	s,
	p,
	d,
	i,
	o,
	u,
	x,
	mx,
	f,
	perc,
	end_fun,
};

typedef struct	s_conv
{
	t_uint8		flag;
	t_uint8		width;
	t_uint8		prec;
	t_uint8		mod;
	t_int8		index_conv;
	int			iszero;
	char		*conv_buf;
	int			convsize;
}				t_conv;

typedef struct	s_pf
{
	char		*buf;
	int			bufsize;
	int			bufalloc;
	char		*fmt;
	char		*percent;
	void		(*fun_ptr[end_fun])(t_conv *, va_list *);
}				t_pf;

int				ft_printf(const char *format, ...);
int				main_loop(const char *format, va_list *ap);
void			init_pf(t_pf *pf, const char *format);
void			init_conv(t_conv *conv);
void			insert_buffer(t_pf *pf, char *ins, int size);
void			increase_buffer(t_pf *pf);
void			destroy_pf(t_pf *pf);
void			parser_percent(t_pf *pf, t_conv *conv);
void			conv_c(t_conv *conv, va_list *ap);
void			conv_s(t_conv *conv, va_list *ap);
void			conv_p(t_conv *conv, va_list *ap);
void			conv_d(t_conv *conv, va_list *ap);
void			conv_i(t_conv *conv, va_list *ap);
void			conv_o(t_conv *conv, va_list *ap);
void			conv_u(t_conv *conv, va_list *ap);
void			conv_x(t_conv *conv, va_list *ap);
void			conv_mx(t_conv *conv, va_list *ap);
void			conv_f(t_conv *conv, va_list *ap);
void			conv_perc(t_conv *conv, va_list *ap);
void			generic_number_conv(t_conv *conv, int isneg);
void			fill_prec(t_conv  *conv);
void			fill_zero(t_conv *conv, int isneg);
void			fill_sign(t_conv *conv, int isneg);
void			fill_space(t_conv *conv);
void			fill_prefix(t_conv *conv);

#endif
