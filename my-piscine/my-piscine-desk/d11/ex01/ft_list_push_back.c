/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 20:40:45 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/07 23:22:30 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void		ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*list;

	list = *begin_list;
	if (list != NULL)
	{
		while (list->next != NULL)
		{
			list = list->next;
		}
		list->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
