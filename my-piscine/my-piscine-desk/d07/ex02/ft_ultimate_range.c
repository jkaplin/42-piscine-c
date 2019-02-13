/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 09:48:07 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/01 15:11:34 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		diff;

	diff = max - min;
	i = 0;
	if (min >= max)
	{
		*range = (void *)0;
		return (0);
	}
	range[0] = (int *)malloc(sizeof(int) * (diff));
	while (i < diff)
	{
		range[0][i] = min;
		min++;
		i++;
	}
	return (diff);
}
