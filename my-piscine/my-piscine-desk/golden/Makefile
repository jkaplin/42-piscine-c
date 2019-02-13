# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 14:34:22 by jkaplin           #+#    #+#              #
#    Updated: 2018/11/14 22:47:45 by jkaplin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRC = list.c read.c valid.c grid.c solve.c string.c print.c main.c
all: $(NAME)

$(NAME):
	gcc -O3 -Wall -Werror -Wextra $(SRC) -o $(NAME)
clean:
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
