/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 13:20:50 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/02 16:20:48 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_compact(char **tab, int length)
{
	int		i;
	int		j;

	i = 0;
	while (i < length)
	{
		while (tab[i] != 0)
			i++;
		length--;
		j = i;
		while (j < length)
		{
			tab[j] = tab[j + 1];
			j++;
		}
	}
	return (length);
}
