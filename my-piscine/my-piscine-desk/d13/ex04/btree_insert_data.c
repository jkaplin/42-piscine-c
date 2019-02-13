/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 03:10:20 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/09 03:24:20 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
													int (*cmpf)(void *, void *))
{
	t_btree		*element;

	if (root == 0)
		return ;
	element = *root;
	while (element != 0)
	{
		if (cmpf(item, element->item) < 0)
			element = element->left;
		else
			element = element->right;
	}
	element = btree_crete_node(item);
}
