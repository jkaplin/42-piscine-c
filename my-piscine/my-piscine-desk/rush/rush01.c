/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:54:25 by jkaplin           #+#    #+#             */
/*   Updated: 2018/10/27 21:16:02 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	rush(int x, int y)
{
	int width;
	int height;

	width = x;
	height = y;
	while (y > 0)
	{
		x = width;
		while (x > 0)
		{
			if ((x == width && y == height) || (x == 1 && y == 1 && height != 1 && width != 1))
				ft_putchar('/');
			else if ((x == width && y == 1) || (x == 1 && y == height))
				ft_putchar('\\');
			else if (x == width || x == 1 || y == height || y == 1)
				ft_putchar('*');
			else
				ft_putchar(' ');	
			x--;
		}
		if (width == 0 || height == 0)
			ft_putchar('\n');
		y--;
	}
}

int		main(void)
{
	printf("5, 1\n");
	rush(5, 1);
	printf("1, 1\n");
	rush(1, 1);
	printf("1, 5\n");
	rush(1, 5);
	printf("142, 42");
	rush(142, 42);
	printf("1, 0\n");
	rush(1, 0);
	printf("0, 1\n");
	rush(0, 1);
	printf("0, 0\n");
	rush(0, 0);
	printf("gre");
	return (0);
}
