/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:18:23 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/05 14:31:19 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int *ft_map(int *tab, int length, int(*f)(int))
{
	int		*arr;
	int		i;

	arr = (int *)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		arr[i] = f(tab[i]);
		i++;
	}
	return (arr);
}
