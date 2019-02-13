/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:29:13 by chford            #+#    #+#             */
/*   Updated: 2018/11/14 22:21:07 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		**allocate_grid(t_map *map)
{
	int		**grid;
	int		i;

	grid = (int **)malloc(sizeof(int *) * map->height);
	i = 0;
	while (i < map->height)
	{
		grid[i] = (int *)malloc(sizeof(int) * map->width);
		i++;
	}
	return (grid);
}

void	initialize_grid(int **grid, char *input_str, t_map *map, t_position box)
{
	int		i;

	i = map->details_len + 1;
	while (box.h < map->height)
	{
		box.w = 0;
		while (box.w < map->width)
		{
			if (input_str[i] == map->empty)
			{
				if (box.h == 0 || box.h == map->height - 1 ||
					box.w == 0 || box.w == map->width - 1)
					grid[box.h][box.w] = 1;
				else
					grid[box.h][box.w] = EMPTY;
			}
			else
				grid[box.h][box.w] = OBSTACLE;
			i++;
			box.w++;
		}
		i++;
		box.h++;
	}
}

int		check_surrounding_spaces(int **grid, t_position box, int max)
{
	int		i;
	int		j;

	i = -1;
	while (i <= 1)
	{
		j = -1;
		while (j <= 1)
		{
			if (grid[box.h + i][box.w + j] == max - 1)
			{
				grid[box.h][box.w] = max;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	fill_grid(int **grid, t_map *map, int *max, t_position start)
{
	t_position	box;
	t_position	change;

	change.h = 0;
	change.w = 0;
	change.is_small = 1;
	while (change.is_small)
	{
		*max += 1;
		change.is_small = 0;
		box.h = start.h + change.h - 1;
		box.w = start.w + change.w - 1;
		while (++box.h < map->height - change.h)
		{
			while (++box.w < map->width - change.w)
				if (grid[box.h][box.w] == EMPTY && !(box.h == 0 || box.w == 0 ||
					box.h == map->height - 1 || box.w == map->width - 1))
					change.is_small +=
									check_surrounding_spaces(grid, box, *max);
			box.w = 0;
		}
		start.h + change.h <= map->height - change.h ? change.h++ : 1;
		start.w + change.w <= map->width - change.w ? change.w++ : 1;
		(*max == 1 && change.is_small == 0) ? change.is_small = 1 : 1;
	}
}
