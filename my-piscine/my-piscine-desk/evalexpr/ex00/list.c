/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:51:27 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/11 23:29:36 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

t_list	*add_link(t_list *list, char *str, char c)
{
	t_list	*link;
	
	link = malloc(sizeof(t_list));
	if (link != NULL && list != NULL)
	{
		link->n = atoi(str);
		link->op = c;
		list->next = link;
		link->next = NULL;
		link->prev = list;
	}
	if (link != NULL && list == NULL)
	{
		link->n = atoi(str);
		link->op = c;
		link->next = NULL;
		link->prev = NULL;
	}
	return (link);
}
