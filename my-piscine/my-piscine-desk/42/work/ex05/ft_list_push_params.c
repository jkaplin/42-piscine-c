/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:40:17 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/07 23:41:39 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

ft_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	t_list	*node;
	int		i;

	list = NULL;
	node = NULL;
	i = 0;
	while (i < ac)
	{
		list = ft_create_elem(av[i]);
		list->next = node;
		node = list;
		i++;
	}
	return (list);
}
