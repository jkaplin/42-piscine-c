# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 21:34:00 by jkaplin           #+#    #+#              #
#    Updated: 2018/11/11 10:32:19 by jkaplin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op
SRCS = main.c ops.c fun.c
HDR = do_op.h
OBJ = main.o ops.o fun.o

all: $(NAME)

$(NAME):
	gcc --silent -Wall -Werror -Wextra $(SRCS) -I $(HDR) -o $(NAME)
clean:
	/bin/rm --silent -f $(OBJ)
fclean: clean
	/bin/rm --silent -f $(NAME)
re: fclean all
