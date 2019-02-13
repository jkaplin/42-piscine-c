/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:33:15 by jkaplin           #+#    #+#             */
/*   Updated: 2018/10/30 16:55:29 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		length;

	length = 0;
	while (to_find[length] != '\0')
		length++;
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] != '\0' && str[i] != '\0')
		{
			if (to_find[j++] != str[i++])
				break ;
		}
		if (j == length)
			return (&(str[i - j]));
	}
	return (0);
}
