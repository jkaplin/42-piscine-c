/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 23:56:21 by jkaplin           #+#    #+#             */
/*   Updated: 2018/10/29 00:49:40 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrev(char *str)
{
	char	*res;
	char	*beg;
	char	*end;
	char	buf;

	res = str;
	beg = str;
	end = str;
	while (*end != '\0')
		end++;
	end--;
	while (beg < end)
	{
		buf = *beg;
		*beg = *end;
		*end = buf;
		beg++;
		end--;
	}
	return (res);
}

int		main(void)
{
	char string[] = "check";
	*string = *ft_strrev(string);
	int i = 0;
	while (string[i] != '\0')
	{
		write(1, &(string[i]), 1);
		i++;
	}
}
