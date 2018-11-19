# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: famillechakor <marvin@42.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 18:18:41 by famillech         #+#    #+#              #
#    Updated: 2018/11/19 12:23:20 by schakor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=		libftprintf.a

CC					=		gcc

CFLAGS				=		-Wall -Wextra -Werror

CPPFLAGS			=		-I includes

SRC_PATH			=		./srcs/

OBJ_PATH			=		./objs/

SRC_FILES			=		ft_printf.c\
							buffer.c\
							destroy_pf.c\
							parser_percent.c\
							conv/conv_d.c\
							conv/conv_c.c\
							conv/conv_s.c\
							conv/conv_p.c

OBJ_PATH_LIBFT		=		./libft/objs/

OBJ_FILES_LIBFT		=		memory/ft_memset.o\
							conversion/ft_itoa.o\
							string/ft_strlen.o\
							string/ft_strdel.o\
							string/ft_strdup.o\
							string/ft_strcpy.o\
							memory/ft_memcpy.o\
							memory/ft_memdel.o\
							type/ft_isflagpf.o

OBJS_LIBFT			=		$(addprefix $(OBJ_PATH_LIBFT), $(OBJ_FILES_LIBFT))

OBJ_FILES			=		$(SRC_FILES:.c=.o)

SRCS				=		$(addprefix $(SRC_PATH), $(SRC_FILES))

OBJS				=		$(addprefix $(OBJ_PATH), $(OBJ_FILES))


all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	ar rc $@ $^ $(LIBS) $(OBJS_LIBFT)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH) :
	mkdir -p $@
	mkdir -p $(dir $(OBJS))

clean :
	make -C libft clean
	rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean : clean
	make -C libft fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
