/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:00:36 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/14 22:19:37 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int argc, char **argv)
{
	int		i;
	t_input	file;
	t_map	map;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			file.name = argv[i];
			solve_file(&file, &map);
			if (i != argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	else
	{
		solve_stdi(&map);
	}
	return (0);
}
