/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:01:15 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/02 16:25:34 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		str_len(char *str)
{
	int		length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

int		count_letters(char **tab, char *sep)
{
	int		letters;
	int		i;

	letters = 0;
	i = 0;
	while (tab[i] != 0)
	{
		letters += str_len(tab[i]);
		if (tab[i + 1] != 0)
			letters += str_len(sep);
		i++;
	}
	return (letters);
}

char	*ft_join(char **tab, char *sep)
{
	char	*merge;
	int		i;
	int		j;
	int		k;

	merge = (char *)malloc(sizeof(char) * (count_letters(tab, sep) + 1));
	i = 0;
	k = 0;
	while (tab[i] != 0)
	{
		j = 0;
		while (tab[i][j] != '\0')
			merge[k++] = tab[i][j++];
		j = 0;
		while (sep[j] != '\0')
			merge[k++] = sep[j++];
		i++;
	}
	merge[k] = '\0';
	return (merge);
}
