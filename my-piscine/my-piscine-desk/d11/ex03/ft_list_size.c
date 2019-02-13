/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:48:09 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/07 23:26:22 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int		count;
	t_list	*list;

	count = 0;
	list = begin_list;
	if (list)
	{
		count = 1;
		while (list->next)
		{
			count++;
			list = list->next;
		}
	}
	return (count);
}
