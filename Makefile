# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 12:18:07 by amirfatt          #+#    #+#              #
#    Updated: 2024/01/29 20:50:39 by amirfatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
CC = cc
FLAGS= -g -Werror -Wall -Wextra
INCLUDES= -I includes

LIBFT= cd includes/libft && make
FT_PRINTF= cd includes/ft_printf && make 

FILES= push_swap.c validate_input.c validate_input_checker.c small_sort.c big_sort.c push.c reverse.c rotate.c swap.c free_error.c lst_utils.c stack_utils.c
	
SRC_PATH= $(addprefix source/, $(FILES))

OBJECT= $(SRC_PATH:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	$(LIBFT)
	$(FT_PRINTF)
	$(CC) $(OBJECT) -o $(NAME) $(FLAGS) includes/libft/libft.a includes/ft_printf/libftprintf.a
	@echo "<><><><><><><><><>Successfully created executable<><><><><><><><><>"

%.o: %.c
	$(CC) $(INCLUDES) $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJECT)
	cd includes/libft && make clean
	cd includes/ft_printf && make clean
	@echo "<><><><><><><><><><><><Object files deleted><><><><><><><><><><><>"

fclean: clean
	rm -f $(NAME)
	cd includes/libft && make fclean
	cd includes/ft_printf && make fclean
	@echo "<><><><><><><><><><><><Executable deleted><><><><><><><><><><><>"

re: fclean all
	
.PHONY: all clean fclean
