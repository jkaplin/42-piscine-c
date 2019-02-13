# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    where_am_i.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/02 11:00:09 by jkaplin           #+#    #+#              #
#    Updated: 2018/11/02 15:39:38 by jkaplin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
var=$(ifconfig | grep inet | grep broadcast | cut -d" " -f2)
if [ $var = '' ]
then
	echo "I am lost!\n"
else
	echo $var
fi
