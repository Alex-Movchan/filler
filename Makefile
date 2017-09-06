#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amovchan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 19:31:33 by amovchan          #+#    #+#              #
#    Updated: 2017/06/23 21:02:43 by amovchan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME_P = filler
NAME_C = visu-hex

G = gcc
FLAGS = -Wall -Wextra -Werror
GFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

SRC_PATH_P = ./src/
SRC_NAME_P =   main.c \
				ft_put_pieca.c \
				manheten_distanc.c \
				read_params.c

OBJ_PATH_P = ./src/
OBJ_NAME_P = $(SRC_NAME_P:.c=.o)
SRC_P = $(addprefix $(SRC_PATH_P), $(SRC_NAME_P))
OBJ_P = $(addprefix $(OBJ_PATH_P), $(OBJ_NAME_P))
GCFLAGS_P = -I./src/ -I./libft/
SRC_PATH_C = ./src_grafik/
SRC_NAME_C =	main.c \
				ft_read_params.c \
				write_pleyer.c

OBJ_PATH_C = ./src_grafik/
OBJ_NAME_C = $(SRC_NAME_C:.c=.o)
SRC_C = $(addprefix $(SRC_PATH_C), $(SRC_NAME_C))
OBJ_C = $(addprefix $(OBJ_PATH_C), $(OBJ_NAME_C))
GCFLAGS_C = -I./src_grafik/ -I./libft/
LIBFT = libft/libft.a
all: $(NAME_P) $(NAME_C)
$(NAME_P): $(OBJ_P)
	@make -C libft/
	@$(G) $(FLAGS) $(GCFLAGS_P) -o $@ $(OBJ_P) $(LIBFT)

$(NAME_C): $(OBJ_C)
	@$(G) $(GFLAGS) $(GCFLAGS_C) -o $@ $(OBJ_C) $(LIBFT)

$(OBJ_PATH_P)%.o: $(SRC_PATH_P)%.c
	@$(G) $(FLAGS) $(GCFLAGS_P) -o $@ -c $<

$(OBJ_PATH_C)%.o: $(SRC_PATH_C)%.c
	@$(G) $(FLAGS) $(GCFLAGS_C) -o $@ -c $<

%.o: %.c
	$(G) $(FLAGS) -c $< -o $@

clean:
	@make -C libft/ clean
	@rm -f $(OBJ_P)
	@rm -f $(OBJ_C)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME_P) $(NAME_C)

re: fclean all
	@make -C libft/ re
