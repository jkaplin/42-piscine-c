/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 22:34:48 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/04 12:06:43 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

void	print_tab(char **tab)
{
	int		i;
	int		j;

	j = 0;
	while (j <= 8)
	{
		i = 0;
		while (tab[j][i] != '\0')
		{
			write(1, &tab[j][i], 1);
			if (tab[j][i + 1] != '\0')
				write(1, " ", 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

char	**create_tab(int argc, char **argv)
{
	char	**tab;
	int		i;
	int		j;

	tab = (char **)malloc(sizeof(char *) * 9);
	i = 1;
	j = 0;
	while (i < argc)
	{
		tab[j] = (char *)malloc(sizeof(char) * (9 + 1));
		tab[j] = argv[i];
		i++;
		j++;
	}
	return (tab);
}

int		skip_nb(char **tab, int h, int w)
{
	if (w <= 7)
	{
		if (get_nb(tab, h, w + 1) == 1)
			return (1);
	}
	else
	{
		if(get_nb(tab, h + 1, 0) == 1)
			return (1);
	}
	return (0);
}

int		get_nb(char **tab, int h, int w)
{
	int		last_check;

	if (h==9)
		return (1);
	if (tab[h][w] != '.')
		return (skip_nb(tab, h, w));
	last_check = '1';
	while (last_check <= '9')
	{
		return (check_and_insert_nb(tab, h, w, last_check));
		last_check++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char	**tab;
	int		h;
	int		w;

	h = 0;
	w = 0;

	tab = create_tab(argc, argv);
	if (get_nb(tab, h, w))
		print_tab(tab);
	else
		write(1, "Error\n", 6);
	return (0);
}
