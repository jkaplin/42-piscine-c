/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:23:28 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/14 20:00:25 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_strcpy(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

t_list	*add_link(t_list *end_list, char *buf)
{
	t_list	*link;

	link = malloc(sizeof(t_list));
	if (link != NULL)
	{
		if (end_list != NULL)
		{
			ft_strcpy(link->str, buf);
			end_list->next = link;
			link->next = NULL;
		}
		else
		{
			ft_strcpy(link->str, buf);
			link->next = NULL;
		}
	}
	return (link);
}
