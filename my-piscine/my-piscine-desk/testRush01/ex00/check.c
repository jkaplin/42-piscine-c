/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 22:37:02 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/04 21:45:57 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		check_row(char **tab, int h, char nb)
{
	int		i;

	i = 0;
	while (i <= 8)
	{
		if (tab[h][i] == nb)
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
		if (tab[j][w] == nb)
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
		while (i <= start_w + 2)
		{
			if (tab[j][i] == nb)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int		check_nb(char **tab, int h, int w, char nb)
{
	if (check_row(tab, h, nb) && check_col(tab, w, nb) &&
		check_sq(tab, h, w, nb))
		return (1);
	else
		return (0);
}

int		is_same_solution(char **tab1, char **tab2)
{
	int		h;
	int		w;

	h = 0;
	while (h <= 8)
	{
		w = 0;
		while (w <= 8)
		{
			if (tab1[h][w] != tab2[h][w])
				return (0);
			w++;
		}
		h++;
	}
	return (1);
}
