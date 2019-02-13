/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:15:10 by jkaplin           #+#    #+#             */
/*   Updated: 2018/10/27 21:49:39 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power < 0 || power >= 31 || nb == 0)
	{
		return (0);
	}
	if (power == 0 || nb == 1)
	{
		return (1);
	}
	return (nb * ft_recursive_power(nb, power - 1));
}
