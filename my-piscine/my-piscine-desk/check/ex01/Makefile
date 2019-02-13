# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 21:28:37 by jkaplin           #+#    #+#              #
#    Updated: 2018/11/08 21:40:47 by jkaplin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat
SRCS = ft_cat.c
OBJ = ft_cat.o

all: $(NAME)

$(NAME): 
	gcc -Wall -Werror -Wextra $(SRCS) -o $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
