# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 20:51:34 by isromero          #+#    #+#              #
#    Updated: 2023/07/31 21:32:36 by isromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =	so_long
CC          =	gcc
SRCS        =	src/check_chars.c src/check_path.c src/check_walls.c src/draw_objects.c \
				src/get_next_line_utils.c src/get_next_line.c src/handle_and_windows.c \
				src/init.c src/move_player.c src/movements.c src/read_map.c src/so_long.c \
				src/utils.c src/validating_map.c


LIBFT       =	./src/libft/libft.a
PRINTF      =	./src/ft_printf/libftprintf.a

CFLAGS      =	-Wall -Wextra -Werror
MLXFLAGS    =	-L ./mlx -lmlx -framework OpenGL -framework AppKit -lz
RM          =	rm -f

OBJ_DIR     =	obj
SRC_DIR     =	src

OBJS        =	$(addprefix $(OBJ_DIR)/, $(SRCS:$(SRC_DIR)/%.c=%.o))

ifeq ($(shell uname), Linux)
MLXFLAGS    = 	-lmlx -Ilmlx -lXext -lX11 -lbsd
endif

all: $(NAME)

$(NAME): $(OBJS)
	@make -C src/libft >/dev/null 2>&1
	@make -C src/ft_printf
	@make clean -C src/libft >/dev/null 2>&1
	@make clean -C src/ft_printf 
	$(CC) $(OBJS) $(LIBFT) $(PRINTF) $(MLXFLAGS) $(CFLAGS) -o $(NAME) >/dev/null 2>&1

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR) >/dev/null 2>&1

fclean: clean
	@$(RM) $(NAME) >/dev/null 2>&1
	@$(RM) *.out >/dev/null 2>&1
	@make fclean -C src/libft/ >/dev/null 2>&1
	@make fclean -C src/ft_printf/ >/dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re
