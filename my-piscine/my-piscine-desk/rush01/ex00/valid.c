/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:35:05 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/04 21:53:09 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		str_len(char *str)
{
	int		length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

int		valid_str(char **tab)
{
	int		i;

	i = 0;
	while (i <= 8)
	{
		if (str_len(tab[i]) != 9)
			return (0);
		i++;
	}
	return (1);
}

int		valid_char(char **tab)
{
	int		h;
	int		w;

	h = 0;
	while (h <= 8)
	{
		w = 0;
		while (tab[h][w] != '\0')
		{
			if (!((tab[h][w] >= '1' && tab[h][w] <= '9') || tab[h][w] == '.'))
				return (0);
			w++;
		}
		h++;
	}
	return (1);
}

int		is_valid(char **tab)
{
	if (valid_str(tab) == 1 && valid_char(tab) == 1)
		return (1);
	return (0);
}
