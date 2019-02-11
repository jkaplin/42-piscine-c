/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 22:23:39 by jkaplin           #+#    #+#             */
/*   Updated: 2018/10/28 22:42:58 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_print_comb(void)
{
	char d1;
	char d2;
	char d3;

	d1 = '0';
	d2 = '1';
	d3 = '2';
	while (d1++ <= '7')
	{
		while (d2++ <= '8')
		{
			while (d3++ <= '9')
			{
				ft_putchar(d1);
				ft_putchar(d2);
				ft_putchar(d3);
				if (d1 == '7' && d2 == '8' && d3 == '9')
					break ;
				ft_putchar(',');
				ft_putchar(' ');
			}
			d3 = d2 + 1;
		}
		d2 = d1 + 1;
	}
}
