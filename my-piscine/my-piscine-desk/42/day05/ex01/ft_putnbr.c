/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 08:55:42 by jkaplin           #+#    #+#             */
/*   Updated: 2018/10/29 23:03:36 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	char	digit[11];
	int		i;

	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb = -147483648;
		}
		nb *= -1;
	}
	else if (nb == 0)
		ft_putchar('0');
	i = 0;
	while (nb > 0)
	{
		digit[i++] = '0' + (nb % 10);
		nb /= 10;
	}
	i--;
	while (i >= 0)
		ft_putchar(digit[i--]);
}
