/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:13:19 by schakor           #+#    #+#             */
/*   Updated: 2018/10/29 18:39:18 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <locale.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/includes/libft.h"

typedef signed char			t_int8;
typedef signed short		t_int16;
typedef signed int			t_int32;
typedef signed long long	t_int64;
typedef unsigned char		t_uint8;
typedef unsigned short		t_uint16;
typedef unsigned int		t_uint32;
typedef unsigned long long	t_uint64;

# define FLAG_MINUS			0x1
# define FLAG_PLUS			0x2
# define FLAG_ZERO			0x4
# define FLAG_SPACE			0x8
# define FLAG_HASH			0x10
# define BUFFSIZE			2048

typedef struct	s_pf
{
	t_uint8		flags;
	int			ret;
	char		*fmt;
	char		*buf;
	int			bufsztot;
}				t_pf;

int				ft_printf(const char *format, ...);
void			init_pf(t_pf *pf, const char *format);
void			insert_buffer(t_pf *pf, char *add, int size);
void			increase_buffer(t_pf *pf);
void			destroy_pf(t_pf *pf);
#endif
