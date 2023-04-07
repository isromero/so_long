# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isromero <isromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 20:51:34 by isromero          #+#    #+#              #
#    Updated: 2023/04/07 18:28:40 by isromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	gcc
SRCS		=	so_long.c init.c validating_map.c movements.c handle_and_windows.c draw_objects.c get_next_line.c get_next_line_utils.c 

LIBFT		=	libft/libft.a
PRINTF		=	ft_printf/libftprintf.a

CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-L ./mlx -lmlx -framework OpenGL -framework AppKit -lz
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)

ifeq ($(shell uname), Linux)
MLXFLAGS	= -lmlx -Ilmlx -lXext -lX11 -lbsd
endif


all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C libft >/dev/null 2>&1
			@make -C ft_printf
			@make clean -C libft >/dev/null 2>&1
			@make clean -C ft_printf 
			$(CC) $(OBJS) $(LIBFT) $(PRINTF) $(MLXFLAGS) $(CFLAGS) -o $(NAME) >/dev/null 2>&1

%o:			%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
			@$(RM) $(OBJS) >/dev/null 2>&1

fclean:		clean
			@$(RM) $(NAME) >/dev/null 2>&1
			@$(RM) *.out >/dev/null 2>&1
			@make fclean -C libft/ >/dev/null 2>&1
			@make fclean -C ft_printf/ >/dev/null 2>&1

re:			fclean all

.PHONY:		all clean fclean re