/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 13:57:31 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/04 21:46:12 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		skip_nb(char **tab, int h, int w)
{
	if (w <= 7)
	{
		if (solve(tab, h, w + 1) == 1)
			return (1);
	}
	else
	{
		if (solve(tab, h + 1, 0) == 1)
			return (1);
	}
	return (0);
}

int		skip_nb_again(char **tab, int h, int w)
{
	if (w <= 7)
	{
		if (solve_again(tab, h, w + 1) == 1)
			return (1);
	}
	else
	{
		if (solve_again(tab, h + 1, 0) == 1)
			return (1);
	}
	return (0);
}

void	change_w_and_h(int w, int h, int *change_width, int *change_height)
{
	if (w <= 7)
	{
		*change_width = w + 1;
		*change_height = h;
	}
	else
	{
		*change_width = 0;
		*change_height = h + 1;
	}
}

int		solve(char **tab, int h, int w)
{
	int		last_check;
	int		change_width;
	int		change_height;

	if (h == 9)
		return (1);
	if (tab[h][w] != '.')
		return (skip_nb_again(tab, h, w));
	last_check = '1';
	while (last_check <= '9')
	{
		if (check_nb(tab, h, w, last_check) == 1 && tab[h][w] == '.')
		{
			tab[h][w] = last_check;
			change_w_and_h(w, h, &change_width, &change_height);
			if (solve(tab, change_height, change_width) == 1)
				return (1);
			else
				tab[h][w] = '.';
		}
		last_check++;
	}
	return (0);
}

int		solve_again(char **tab, int h, int w)
{
	int		last_check;
	int		change_width;
	int		change_height;

	if (h == 9)
		return (1);
	if (tab[h][w] != '.')
		return (skip_nb(tab, h, w));
	last_check = '9';
	while (last_check >= '1')
	{
		if (check_nb(tab, h, w, last_check) == 1 && tab[h][w] == '.')
		{
			tab[h][w] = last_check;
			change_w_and_h(w, h, &change_width, &change_height);
			if (solve_again(tab, change_height, change_width) == 1)
				return (1);
			else
				tab[h][w] = '.';
		}
		last_check--;
	}
	return (0);
}
