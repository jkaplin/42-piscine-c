/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:59:36 by chford            #+#    #+#             */
/*   Updated: 2018/11/14 22:11:12 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		find_big_center(t_position *center, int **grid, t_map *map, int max)
{
	int		h;
	int		w;

	h = 0;
	while (h < map->height)
	{
		w = 0;
		while (w < map->width)
		{
			if (grid[h][w] == max && h != map->height - 1 &&
				w != map->width - 1)
				if (grid[h][w + 1] == max && grid[h + 1][w] == max &&
					grid[h + 1][w + 1] == max)
				{
					center->h = h;
					center->w = w;
					center->is_small = 0;
					return (1);
				}
			w++;
		}
		h++;
	}
	return (0);
}

int		find_small_center(t_position *center, int **grid, t_map *map, int max)
{
	int		h;
	int		w;

	h = 0;
	while (h < map->height)
	{
		w = 0;
		while (w < map->width)
		{
			if (grid[h][w] == max)
			{
				center->h = h;
				center->w = w;
				center->is_small = 1;
				return (1);
			}
			w++;
		}
		h++;
	}
	return (0);
}

void	solve_map(char *input_str, t_map *map)
{
	int			**grid;
	int			i;
	int			max;
	t_position	box;
	t_position	center;

	box.h = 0;
	box.w = 0;
	grid = allocate_grid(map);
	initialize_grid(grid, input_str, map, box);
	max = 0;
	fill_grid(grid, map, &max, box);
	max--;
	if (find_big_center(&center, grid, map, max) ||
				find_small_center(&center, grid, map, max))
		fill_str(max, input_str, map, &center);
	i = 0;
	while (i < map->height)
		free(grid[i++]);
	free(grid);
}

void	solve_file(t_input *file, t_map *map)
{
	int		bombs;

	bombs = 0;
	file->str = read_file(file);
	if (file->str == NULL || is_valid(file->str, map, &bombs) == 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	if (bombs == 0)
		full_str(file->str, map);
	else
		solve_map(file->str, map);
	print(file->str, map);
}

void	solve_stdi(t_map *map)
{
	int		bombs;
	t_input stdi;

	bombs = 0;
	stdi.str = read_stdi(&stdi);
	if (stdi.str == NULL || is_valid(stdi.str, map, &bombs) == 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	if (bombs == 0)
		full_str(stdi.str, map);
	else
		solve_map(stdi.str, map);
	print(stdi.str, map);
}
