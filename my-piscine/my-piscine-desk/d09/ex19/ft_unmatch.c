/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:37:56 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/02 16:26:06 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unmatch(int *tab, int length)
{
	int		i;
	int		j;

	i = 0;
	while (i < length)
	{
		j = i;
		while (j < length)
		{
			if (tab[i] == tab[j])
				break ;
			j++;
		}
		if (j == length)
			return (tab[i]);
		i++;
	}
	return (0);
}
