# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: famillechakor <marvin@42.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 18:18:41 by famillech         #+#    #+#              #
#    Updated: 2018/10/29 22:05:17 by schakor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		libftprintf.a

CC			=		gcc

CFLAGS		=		-Wall -Wextra -Werror

CPPFLAGS	=		-I includes

LIBS		=		./libft/libft.a

SRC_PATH	=		./srcs/

OBJ_PATH	=		./objs/

SRC_FILES	=		ft_printf.c\
					init_pf.c\
					buffer.c\
					destroy_pf.c\

OBJ_FILES	=		$(SRC_FILES:.c=.o)

SRCS		=		$(addprefix $(SRC_PATH), $(SRC_FILES))

OBJS		=		$(addprefix $(OBJ_PATH), $(OBJ_FILES))

all : $(NAME)

$(NAME) : $(OBJS) | $(OBJ_PATH)
	ar rc $@ $^ $(LIBS)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c | $(OBJ_PATH)
	make -C libft
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH) :
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(dir $(OBJS))

clean :
	make -C libft clean
	rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean : clean
	make -C libft fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
