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

MLX 		= -Lminilibx-linux -lmlx_Linux -lX11 -lXext

SRC			= handeler.c \
			  init.c \
			  main.c \
			  math_utils.c \
			  render.c \
			  string_utils.c \

OBJ			= $(SRC:%.c=%.o)
#Para generar los archivos objetos de una lista fuente SRCS

INCLUDE		= fractol.h

all: $(NAME)
#Define el target/objetivo y especifica que depende de NAME
#Si el archivo no existe o no está actualizado se ejecutan las reglas para obtenerlo

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)
# gcc $(FLAGS) -c $(SRCS) -I ./ 
#Para compilar con las flags en el directorio actual, la I (Include directory) busca archivos de cabecera
#en el directorio indicado. Los archivos fuentes .c con la cabecera propia (libft.h), si el .h está en el
#directorio actual, se necesita el flag para que el compilador realice su función
#Fuerza a buscar en mi directorio sobre los del sistema si hubiera coincidencias

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@
#El archivo .o depende del respectivo .c y la cabecera includeç
#la -c $< se refiere a la primera dependencia de la regla, siendo .c en este caso
# -o $@ indica el nombre del archivo de salida y el $@ se refiere al nombre del objetivo de la regla (.o)

.PHONY: clean fclean re 
#Objetivos declarados ficticios para que se ejecuten siempre que se invoquen sin importar
#que haya archivos con los mismos nombres.

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(LIB_NAME)

#Ejecuta primero el clean para eliminar los archivos objetos y luego la libreria .a y
# y vuelve a compilar los archivos generales 

re: fclean all
#re for rebuilt
#Aegurarse de que se construya desde un estado limpio
#eliminando cualquier problema o residuo de compilaciones anteriores
