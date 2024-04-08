# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 13:50:16 by amirfatt          #+#    #+#              #
#    Updated: 2024/01/23 11:48:31 by amirfatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 

CC = cc

CFLAGS = -g -Wall -Wextra -Werror 

SRC = ft_printf.c ft_print_utils.c ft_print_ptr.c\
	ft_print_nbr.c ft_print_hex.c

OBJ = $(SRC:.c=.o)

$(NAME):
	$(CC) -c $(CFLAGS) $(SRC)
	ar crs $(NAME) $(OBJ)

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(OBJ)
	
re: fclean all