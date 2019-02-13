/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:51:28 by chford            #+#    #+#             */
/*   Updated: 2018/11/14 00:03:07 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <stdio.h>

int		ft_atoi_n(char *str, int n)
{
	int		num;
	int		i;

	num = 0;
	i = 0;
	while (i < n)
	{
		if (str[i] < '0' || str[i] < '9')
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

int		valid_details_line(char *file_str, t_map *map, int i)
{
	if (file_str[0] < '0' || file_str[0] > '9' || i < 3)
		return (0);
	map->height = ft_atoi_n(file_str, i - 2);
	if (map->height == 0)
		return (0);
	map->full = file_str[i];
	map->obstacle = file_str[i - 1];
	map->empty = file_str[i - 2];
	return (1);
}

int		is_not_valid_char(char c, t_map *map)
{
	if (c == map->empty || c == map->obstacle || c == '\n')
		return (0);
	return (1);
}

int		is_valid_map(char *file_str, t_map *map, int i,
		int line_length, int num_lines)
{
	int		is_first_line;

	is_first_line = 1;
	while (file_str[i] != '\0')
	{
		if (file_str[i] == '\n')
		{
			if (is_first_line)
			{
				map->width = line_length;
				is_first_line = 0;
			}
			else
				if (line_length != map->width)
					return (0);
			line_length = 0;
			num_lines++;
		}
		else
			line_length++;
		if (is_not_valid_char(file_str[i++], map))
			return (0);
	}
	if (num_lines != map->height)
		return (0);
	return (1);
}

int		is_valid(char *file_str, t_map *map)
{
	int		details_len;

	details_len = 0;
	while (file_str[details_len] != '\0' && file_str[details_len] != '\n')
		details_len++;
	map->details_len = details_len;
	if (file_str[details_len] == '\0')
		return (0);
	if (valid_details_line(file_str, map, details_len - 1) &&
		is_valid_map(file_str, map, details_len + 1, 0 ,0))
		return (1);
	return (0);
}
