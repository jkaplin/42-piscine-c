# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 14:34:22 by jkaplin           #+#    #+#              #
#    Updated: 2018/11/13 20:27:15 by chford           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRC = list.c read.c valid.c grid.c solve.c print.c main.c border.c
OBJ = object.o
all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra $(SRC) -o $(NAME)
clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
