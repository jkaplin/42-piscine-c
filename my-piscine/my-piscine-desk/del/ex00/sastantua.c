/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 00:11:26 by jkaplin           #+#    #+#             */
/*   Updated: 2018/10/29 08:08:18 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		calculate_base(int size)
{
	int base;
	int base_transition;
	int i;
	int levels;

	base = -1;
	base_transition = 2;
	i = 1;
	while (i <= size)
	{
		levels = i + 2;
		if (i % 2 == 0)
			base_transition += 2;
		base += (base_transition + (2 * levels));
		i++;
	}
	return (base);
}

void	print_line(int *spaces, int *stars, char door, int door_transition, int section)
{
	int i;
	int middle;

	middle = 0;
	if (door == '$')
	{
		middle = 1;
	}
	i = 1;
	while (i <= *spaces)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar('/');
	i = 1;
	while (i <= *stars)
	{
		if ((door == '|' || door == '$') && (i >= (*stars / 2) + 1 - (door_transition / 2)) && (i <= ((*stars / 2) + 1 + (door_transition / 2))))
		{
			if ((middle == 1) && section >= 5 && (i == ((*stars / 2) + (door_transition / 2))))
				door = '$';
			else
				door = '|';
			ft_putchar(door);
		}
		else
			ft_putchar('*');
		i++;
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

void	print_section(int *spaces, int *stars, int section, int door_transition, int size)
{
	int levels;
	int base_transition;
	int i;
	char door;
	int door_top;

	base_transition = 2;
	door = '*';
	levels = section + 2;
	i = 1;
	door_top = levels - door_transition + 1;
	while (i <= levels)
	{
		if (section == size && i >= door_top)
		{
			if (i == (door_top + levels) / 2 )
				door = '$';
			else
				door = '|';
		}
		print_line(spaces, stars, door, door_transition, section);
		*spaces = *spaces - 1;
		*stars += 2;
		i++;
	}
}

void	sastantua(int size)
{
	int spaces;
	int stars;
	int section;
	int base_transition;
	int door_transition;

	base_transition = 2;
	door_transition = 1;
	spaces = calculate_base(size) / 2 - 1;
	stars = 1;
	section = 1;
	while (section <= size)
	{
		print_section(&spaces, &stars, section, door_transition, size);
		section++;
		if (section % 2 == 0)
			base_transition += 2;
		else
			door_transition += 2;
		spaces -= (base_transition / 2);
		stars += base_transition;
	}
}

int		main(void)
{
	sastantua(1);
	sastantua(2);
	sastantua(3);
	sastantua(4);
	sastantua(5);
	sastantua(6);
	sastantua(7);
	return (0);
}
