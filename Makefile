# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/08 10:08:35 by dpoulter          #+#    #+#              #
#    Updated: 2018/07/20 13:00:47 by dpoulter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = resources/players/dpoulter.filler
FLAGS = -Wall -Werror -Wextra -I./includes

SRCS := src/filler.c \
		src/parsing.c \
		src/parsing_piece.c \
		src/solving.c \
		src/algo.c \
		src/vis.c \

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a
	@echo "Filler done"

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
