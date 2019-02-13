/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 03:25:53 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/09 03:38:50 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*btree_search_item(t_btree *root, void *data_ref,
													int (*cmpf)(void *, void *))
{
	if (root == 0)
		return (0);
	if (root->item == data_ref)
		return (root->item);
	if (cmpf(root->item, data_ref) > 0)
		return (btree_search_item(root->left, data_ref, cmpf));
	return (btree_search_item(root->left, data_ref, cmpf));
}
