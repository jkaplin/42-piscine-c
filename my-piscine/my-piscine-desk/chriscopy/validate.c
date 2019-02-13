/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:25:41 by chford            #+#    #+#             */
/*   Updated: 2018/11/12 21:49:33 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int		details_line(char *map_str, t_map *map, int *i)
{
	while (
	while (map_str[*i] != '\0')
	{
		if (map_str[*i] == '\n')
		{
			*i++;
			break;
		}
		map->height = ft_atoi(map_str);
	}
	if (map_str[*i] == '\0')
		return (0);
	return (1);
}


int		is_valid_map(char *map_str, t_map *map, int i)
{
	int		line_length;
	int		num_lines;

	line_length = 0;
	num_lines = 0;
	while (map_str[i] != '\0')
	{
		if (map_str[i] == '\n')
		{
			if (is_first_line)
			{
				map->width = i;
				is_first_line = 0;
			}
			else
				if (line_length != map->width)
					return (0);
		num_lines++;
		}
		if (map_str[i]---)
		line_length++;
	}
	if (num_lines != map->height)
		return (0);
	return (1);
}

int		is_valid(char *map_str, t_map *map)
{
	int		i;

	i = 0;
	if (details_line(map_str, map, &i) && is_valid_map(map_str, map, i))
		return (1);

}
