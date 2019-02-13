/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 13:58:25 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/04 15:39:23 by jkaplin          ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	char	**tab;
	char	**tab_copy;
	int		h;
	int		w;

	h = 0;
	w = 0;
	tab = create_tab(argc, argv);
	tab_copy = create_tab(argc, argv);
	if (solve(tab, h, w) == 1 && other_solutions(tab, tab_copy, h, w) == 0)
		print_tab(tab);
	else
		write(1, "Error\n", 6);
	return (0);
}
