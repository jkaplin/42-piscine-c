/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:21:57 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/13 20:56:36 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		is_on_border(int h, int w, t_map *map)
{
	if (h == 0 || w == 0 || h == map->height - 1 || w == map->width - 1)
		return 1;
	return (0);
}
