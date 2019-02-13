/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:31:43 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/14 21:38:37 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	full_str(char *input_str, t_map *map)
{
	int		h;
	int		w;
	int		min_size;
	int		i;

	i = map->details_len + 1;
	h = 0;
	if (map->height <= map->width)
		min_size = map->height;
	else
		min_size = map->width;
	while (h < min_size)
	{
		w = 0;
		while (w < min_size)
		{
			input_str[i] = map->full;
			w++;
			i++;
		}
		i += (map->width - min_size + 1);
		h++;
	}
}

void	fill_str(int max, char *input_str, t_map *map, t_position *center)
{
	int			i;
	int			w;
	t_position	start;
	t_position	last;

	start.h = center->h - (max - 1);
	start.w = center->w - (max - 1);
	i = map->details_len + 1 + start.h * (map->width + 1) + start.w;
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
