# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albrusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 04:53:41 by albrusso          #+#    #+#              #
#    Updated: 2023/05/16 01:18:14 by albrusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = clang
SRC = main.c utils.c check.c start.c hook.c
LIBFT = libft/libft.a
MLX = minilibx_linux/libmlx.a -lX11 -lXext -lm
OBJ = $(SRC:%.c=.o)
all:
	make -C libft
	make clean -C libft
	$(CC) -g $(SRC) $(MLX) $(LIBFT) -o $(NAME)
clean:
	rm -rf $(OBJ)
fclean:
	clean
	rm -rf $(NAME)
re:
	fclean all