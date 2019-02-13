/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 10:33:18 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/01 15:07:19 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int		count_words(char *str)
{
	int		words;
	int		i;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_is_whitespace(str[i]))
			if (ft_is_whitespace(str[i + 1]) || str[i + 1] == '\0')
				words++;
		i++;
	}
	return (words);
}

void	allocate_strings(char **str_array, char *str)
{
	int		words;
	int		letters;
	int		i;

	word = 0;
	letters = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_is_whitespace(str[i]))
		{
			letters++;
			if (ft_is_whitespace(str[i + 1]) || str[i + 1] == '\0')
			{
				str_array[word] = (char *)malloc(sizeof(char) * (letters + 1));
				word++;
				letters = 0;
			}
		}
		i++;
	}
	str_array[word] = (char *)malloc(sizeof(char) * 1);
}

char	**ft_split_whitespace(char *str)
{
	char	**str_array;
	int		i;
	int		j;
	int		word;

	str_array = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	allocate_strings(str_array, str);
	i = 0;
	j = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (!ft_is_whitespace(str[i]))
		{
			str_array[word][j] = str[i];
			j++;
			if (ft_is_whitespace(str[i + 1]) || str[i + 1] == '\0')
			{
				word++;
				j = 0;
			}
		}
		i++;
	}
	str_array[word] = 0;
}
