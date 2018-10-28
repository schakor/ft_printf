# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: famillechakor <marvin@42.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 18:18:41 by famillech         #+#    #+#              #
#    Updated: 2018/10/28 14:32:10 by famillech        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		libftprintf.a

CC			=		gcc

CFLAGS		=		-Wall -Wextra -Werror

CPPFLAGS	=		-I includes

LIBS		=		./libft/libft.a

SRC_PATH	=		./srcs/

OBJ_PATH	=		./objs/

SRC_FILES	=		ft_printf.c

OBJ_FILES	=		$(SRC_FILES:.c=.o)

SRCS		=		$(addprefix $(SRC_PATH), $(SRC_FILES))

OBJS		=		$(addprefix $(OBJ_PATH), $(OBJ_FILES))

all : $(NAME)

$(NAME) : $(OBJS) | $(OBJ_PATH)

