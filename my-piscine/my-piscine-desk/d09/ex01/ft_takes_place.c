/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 19:01:22 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/02 15:10:55 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	allocate_time(int hour, char *time_x, char *time_y)
{
	if ((hour >= 0 && hour <= 10) || hour == 24)
	{
		*time_x = 'A';
		*time_y = 'A';
	}
	else if (hour == 11)
	{
		*time_x = 'A';
		*time_y = 'P';
	}
	else if (hour == 23)
	{
		*time_x = 'P';
		*time_y = 'A';
	}
	else
	{
		*time_x = 'P';
		*time_y = 'P';
	}
}

void	ft_takes_place(int hour)
{
	int		x;
	int		y;
	char	time_x;
	char	time_y;

	if (hour >= 0 && hour <= 24)
	{
		x = hour % 12;
		y = x + 1;
		if (x == 0)
			x = 12;
		allocate_time(hour, &time_x, &time_y);
		printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 %c.M. ", x, time_x);
		printf("AND %d.00 %c.M.\n", y, time_y);
	}
}
