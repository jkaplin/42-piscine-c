/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 00:50:01 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/02 15:31:32 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ultimator.h"

void	ft_destroy(char ***factory)
{
	int		i;
	int		j;

	i = 0;
	while (factory[i] != 0)
	{
		j = 0;
		while (factory[i][j] != 0)
		{
			free(factory[i][j]);
			j++;
		}
		free(factory[i][j]);
		free(factory[i]);
		i++;
	}
	free(factory[i]);
	free(factory);
}
