/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 01:03:55 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/09 01:51:34 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree		*btree_create_node(void *item)
{
	t_btree		*new;

	new = (t_btree *)malloc(sizeof(t_btree));
	if (new == 0)
		return (0);
	new->left = 0;
	new->right = 0;
	new->item = item;
	return (new);
}
