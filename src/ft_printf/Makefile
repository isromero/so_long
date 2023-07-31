# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 12:42:25 by isromero          #+#    #+#              #
#    Updated: 2022/10/20 12:19:27 by isromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.

SRCS = ft_printf.c ft_print_int.c ft_print_char.c ft_print_unsigned.c ft_print_hex.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		  ar rcs $(NAME) $(OBJS)

clean :
		$(RM) $(OBJS)   

fclean : clean
		 $(RM) $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re