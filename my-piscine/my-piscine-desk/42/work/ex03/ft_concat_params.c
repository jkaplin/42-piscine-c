/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:52:53 by jkaplin           #+#    #+#             */
/*   Updated: 2018/10/31 19:22:06 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_size_of_string(char *str)
{
	int		length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (sizeof(char) * (length + 1));
}

int		ft_total_size(int argc, char **strings)
{
	int		total_size;
	int		i;

	total_size = 0;
	i = 1;
	while (i < argc)
	{
		total_size += ft_size_of_string(strings[i]);
		i++;
	}
	return (total_size);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	str = (char *)malloc(ft_total_size(argc, argv));
	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			str[k] = argv[i][j];
			j++;
			k++;
		}
		i++;
		if (i == argc)
			str[k] = '\0';
		else
			str[k] = '\n';
		k++;
	}
	return (str);
}
