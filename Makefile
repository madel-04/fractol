# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madel-va <madel-va@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 16:19:57 by madel-va          #+#    #+#              #
#    Updated: 2024/09/23 16:19:57 by madel-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB			= ar rcs
RM			= rm -f
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= fractol 
LIB_NAME	= fractol.a

MLX 		= -L minilibx-linux -lmlx_Linux -lX11 -lXext -lm

SRC			= handeler.c \
			  init.c \
			  main.c \
			  math_utils.c \
			  render.c \
			  string_utils.c \

OBJ			= $(SRC:%.c=%.o)

INCLUDE		= fractol.h -I minilibx-linux

all: $(NAME)

minilibx-linux/libmlx.a:
	@echo "$(YELLOW)Compiling MinilibX library$(CLEAR)"
	@make -sC minilibx-linux

$(NAME): minilibx-linux/libmlx.a $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(MLX) -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(LIB_NAME)

re: fclean all
