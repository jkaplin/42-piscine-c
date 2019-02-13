/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:29:13 by chford            #+#    #+#             */
/*   Updated: 2018/11/14 11:43:49 by jkaplin          ###   ########.fr       */
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
					grid[box.h][box.w] = -1;
			}
			else
				grid[box.h][box.w] = 0;
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
			if (grid[h][w] == max && h != map->height - 1 && w != map->width - 1)
				if (grid[h][w + 1] == max && grid[h+1][w] == max && grid[h+1][w+1] == max)
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
