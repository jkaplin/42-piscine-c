/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 22:37:02 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/04 12:05:30 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		check_row(char **tab, int h, char nb)
{
	int		i;

	i = 0;
	while (i <= 8)
	{
		if(tab[h][i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int		check_col(char **tab, int w, char nb)
{
	int		j;

	j = 0;
	while (j <= 8)
	{
		if(tab[j][w] == nb)
			return (0);
		j++;
	}
	return (1);
}

int		check_sq(char **tab, int h, int w, char nb)
{
	int		j;
	int		i;
	int		start_h;
	int		start_w;

	start_h = (h / 3) * 3;
	start_w = (w / 3) * 3;
	j = start_h;
	while (j <= start_h + 2)
	{
		i = start_w;
		while(i <= start_w + 2)
		{
			if(tab[j][i] == nb)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int		check_and_insert_nb(char **tab, int h, int w, char last_check)
{
	if (check_row(tab, h, last_check) && check_col(tab, w, last_check) && check_sq(tab, h, w, last_check))
	{
		tab[h][w] = last_check;
		if (w <= 7)
		{
			if (get_nb(tab, h, w + 1) == 1)
				return (1);
			else
				tab[h][w] = '.';
		}
		else
		{
			if(get_nb(tab, h + 1, 0) == 1)
				return (1);
			else
				tab[h][w] = '.';
		}
	}
	return (0);
}
