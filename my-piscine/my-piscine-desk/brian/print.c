/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:32:12 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/14 20:39:57 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print(char *str, t_map *map)
{
	int		i;

	i = map->details_len + 1;
	write(1, str + i, map->width * map->height + map->height);
	free(str);
}
