/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 23:34:37 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/07 23:41:49 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	ft_list		*head;

	clear(*begin_list);
	head = NULL;
}

void	clear(t_list *node)
{
	if (node->next == NULL)
	{
		free(node);
		return ;
	}
	clear(node->next);
	free(node);
}
