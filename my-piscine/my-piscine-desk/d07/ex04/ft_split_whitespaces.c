/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:59:30 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/01 14:46:30 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		words_in_str(char *str)
{
	int		i;
	int		words_count;

	i = 0;
	words_count = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != ' ' && str[i] != '\t' && str[i] != '\n') &&
			(str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n' ||
			str[i + 1] == '\0'))
			words_count++;
		i++;
	}
	return (words_count);
}

void	create_boxes(char *str, char **str_arr)
{
	int		i;
	int		letters;
	int		box_position;

	i = 0;
	letters = 0;
	box_position = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			letters++;
			if (str[i + 1] == ' ' || str[i + 1] == '\t'
					|| str[i + 1] == '\n' || str[i + 1] == '\0')
			{
				str_arr[box_position] = (char *)malloc(sizeof(char) *
														(letters + 1));
				letters = 0;
				box_position++;
			}
		}
		i++;
	}
	str_arr[box_position] = (char *)malloc(sizeof(char) * 1);
}

void	insert_words(char *str, char **str_arr)
{
	int		i;
	int		j;
	int		word;

	i = 0;
	j = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			str_arr[word][j] = str[i];
			j++;
			if (str[i + 1] == ' ' || str[i + 1] == '\t'
					|| str[i + 1] == '\n' || str[i + 1] == '\0')
			{
				str_arr[word][j] = '\0';
				j = 0;
				word++;
			}
		}
		i++;
	}
	str_arr[word] = 0;
}

char	**ft_split_whitespaces(char *str)
{
	char	**str_arr;
	int		words;

	words = words_in_str(str);
	str_arr = (char **)malloc(sizeof(char*) * (words + 1));
	create_boxes(str, str_arr);
	insert_words(str, str_arr);
	return (str_arr);
}
