* **************************************************************************  */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:43:55 by jkaplin           #+#    #+#             */
/*   Updated: 2018/10/27 13:12:54 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int length;
	int i;
	char swap;

	length = 0;
	i = 0;
	while (str[length])
	{
		length++;
	}
	length--;
	while (i < length)
	{
		swap = str[i];
		str[i] = str[length];
		str[length] = swap;
		i++;
		length--;
	}
	return (str);
}
