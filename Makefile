# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albrusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 04:53:41 by albrusso          #+#    #+#              #
#    Updated: 2023/05/17 15:39:50 by albrusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	clang
SRCS_DIR	=	src/
SRC		=	main.c check.c check_utils.c hook.c maps.c move.c sprite.c utils.c

LIBFT		=	libft/libft.a
MLXFLAGS	=	-L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

ifeq ($(shell uname), Linux)
MLXFLAGS	=	minilibx_linux/libmlx.a -lX11 -lXext -lm
endif

SRCS = $(addprefix $(SRCS_DIR), $(SRC))
OBJS = $(SRCS:.c=.o)
all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft	
			make clean -C libft
			$(CC) -g $(SRCS) $(LIBFT) $(MLXFLAGS) -o $(NAME)
			@echo "$(GREEN) so_long compiled!$(DEF_COLOR)"

%o:			%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
			$(RM) $(OBJS)
			@echo "$(BLUE)so_long object files cleaned!$(DEF_COLOR)"

fclean:		clean
			$(RM) $(NAME)
			$(RM) *.out
			make fclean -C libft/
			@echo "$(CYAN)so_long executable files cleaned!$(DEF_COLOR)"

re:			fclean all

git:
	@git add .
	@git commit -m "$m"
	@git push
	@echo "Commit sent to github"
	
.SILENT:
# To call: make git m="my commit"