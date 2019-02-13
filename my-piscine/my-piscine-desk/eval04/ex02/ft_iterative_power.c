/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:33:55 by jkaplin           #+#    #+#             */
/*   Updated: 2018/10/26 15:14:33 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_iterative_power(int nb, int power)
{
	int total;

	total = 1;
	if (power < 0)
	{
		return (0);
	}
	while (power > 0)
	{
		total *= nb;
		power--;
	}
	return (total);
}
