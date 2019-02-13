/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 03:39:44 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/09 03:58:13 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	recursive(t_btree *element, int count, int *max)
{
	if (element == 0)
	{
		if (*max < count)
			*max = count;
		return ;
	}
	recursive(elment->left, ++count, max);
	count--;
	recursive(element->right, ++count, max);
	count--;
}

int		btree_level_count(t_btree *root)
{
	int		max;

	max = 0;
	recursive(root, 0, &max);
	return (max);
}
