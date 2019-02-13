/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:59:36 by chford            #+#    #+#             */
/*   Updated: 2018/11/13 22:43:33 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

void	fill_grid(int **grid, t_map *map, int *max, t_position start)
{
	t_position	box;
	t_position change;

	change.h = 0;
	change.w = 0;
	change.is_small = 1;
	while (change.is_small)
	{
		change.is_small = 0;
		*max += 1;
		box.h = start.h + change.h ;
		box.w = start.w + change.w ;
		while (box.h < map->height - change.h)
		{
			while(box.w < map->width - change.w)
			{
				if (grid[box.h][box.w] == EMPTY && !is_on_border(box.h, box.w, map))
					change.is_small += check_surrounding_spaces(grid, box, *max);
				box.w++;
			}
			box.h++;
			box.w = 0;
		}
		start.h + change.h  <= map->height - change.h  ? change.h++ : 1;
		start.w + change.w  <= map->width - change.w  ? change.w++ : 1;
	}
}

void	fill_str(int max, char *input_str, t_map *map, t_position *center)
{
	int			i;
	t_position	start;
	int			w;

	t_position	last;
	start.h = center->h - (max - 1);
	start.w = center->w - (max - 1);
	i = map->details_len + 1 + start.h * map->width + start.w;
	last.h = center->h + (max - center->is_small);
	last.w = center->w + (max - center->is_small);
	while (start.h <= last.h)
	{
		w = start.w;
		while (w <= last.w)
		{
			input_str[i] = map->full;
			w++;
			i++;
		}
		i += (map->width - (last.w - start.w));
		start.h++;
	}
}
//DELeTE at the end of the world

void	fun(int **grid, t_map map)
{
	int h;
	int w;

	h = 0;
	while (h < map.height)
	{
		w = 0;
		while (w < map.width)
		{
			printf("%d", grid[h][w++]);
		}
		printf("\n");
		h++;
	}
}

void	solve_map(char *input_str, t_map *map)
{
	int		**grid;
	int		i;
	int		max;
	t_position	box;
	t_position	center;

	box.h = 0;
	box.w = 0;
	grid = allocate_grid(map);
	initialize_grid(grid, input_str, map, box);
	max = 0;
	fill_grid(grid, map, &max, box);
	fun(grid, *map);
	max--;
	printf("MAX = %d", max);
	if (find_big_center(&center, grid, map, max) ||
				find_small_center(&center, grid, map, max))
		fill_str(max, input_str, map, &center);
	i = 0;
	while (i < map->height)
		free(grid[i++]);
}



int		solve_file(t_input *file, t_map *map)
{
	file->str = read_file(file);
	if (file->str == NULL || is_valid(file->str, map) == 0)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	solve_map(file->str, map);
	print(file->str);
	return (1);
}

int		solve_stdi(t_map *map)
{
	t_input stdi;

	stdi.str = read_stdi(&stdi);
	if (stdi.str == NULL || is_valid(stdi.str, map) == 0)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	solve_map(stdi.str, map);
	print(stdi.str);
	return (1);
}
