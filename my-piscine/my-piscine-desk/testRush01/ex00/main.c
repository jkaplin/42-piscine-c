/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 13:58:25 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/04 21:52:27 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	**copy_tab(char **tab)
{
	char	**tab_copy;
	int		h;
	int		w;

	tab_copy = (char **)malloc(sizeof(char *) * 9);
	h = 0;
	while (h <= 8)
	{
		tab_copy[h] = (char *)malloc(sizeof(char) * (9 + 1));
		w = 0;
		while (w <= 9)
		{
			tab_copy[h][w] = tab[h][w];
			w++;
		}
		h++;
	}
	return (tab_copy);
}

int		main(int argc, char **argv)
{
	char	**tab1;
	char	**tab2;
	int		h;
	int		w;

	h = 0;
	w = 0;
	tab1 = create_tab(argc, argv);
	tab2 = copy_tab(tab1);
	if (argc == 10 && is_valid(tab1) && solve(tab1, h, w) &&
					solve_again(tab2, h, w) && is_same_solution(tab1, tab2))
		print_tab(tab1);
	else
		write(1, "Error\n", 6);
	return (0);
}
