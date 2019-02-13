/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:55:01 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/03 23:13:17 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int root;
	int max;
	int min;

	if (nb == 1)
		return (1);
	max = nb;
	min = 0;
	root = nb;
	while (min + 1 < max)
	{
		if (root * root == nb)
			return (root);
		else if (root * root > nb)
			max = root;
		else
			min = root;
		root = (min + max) / 2;
	}
	return (0);
}
