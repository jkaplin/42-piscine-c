/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubakir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:15:05 by aaubakir          #+#    #+#             */
/*   Updated: 2018/11/10 13:11:26 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	press(int i, char first, char second, char third)
{
	ft_putchar(first);
	while (i > 2)
	{
		ft_putchar(second);
		i--;
	}
	if (i > 1)
		ft_putchar(third);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		press(x, 'A', 'B', 'A');
		y--;
		while (y > 1)
		{
			press(x, 'B', ' ', 'B');
			y--;
		}
		if (y > 0)
			press(x, 'C', 'B', 'C');
	}
}
