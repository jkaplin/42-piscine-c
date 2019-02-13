/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 22:30:00 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/07 23:36:55 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list	*list;

	list = begin_list;
	while (nbr > 0)
	{
		if (list == NULL || list->next == NULL)
		{
			list = NULL;
			break ;
		}
		list = list->next;
		nbr--;
	}
	return (list);
}
