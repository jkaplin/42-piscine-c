/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 07:58:21 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/11 23:20:11 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rush00.h"
#include "../headers/rush02.h"

void	put_nbr(int nb)
{
	char	digit[11];
	int		i;

	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write(1, "2", 1);
			nb = -147483648;
		}
		nb *= -1;
	}
	else if (nb == 0)
		write(1, "0", 1);
	i = 0;
	while (nb > 0)
	{
		digit[i++] = '0' + (nb % 10);
		nb /= 10;
	}
	i--;
	while (i >= 0)
		write(1, &digit[i--], 1);
}

void	assign_funs(t_rush *f_ptr)
{
	f_ptr[0].rush = &rush00;
	f_ptr[1].rush = &rush01;
	f_ptr[2].rush = &rush02;
	f_ptr[3].rush = &rush03;
	f_ptr[4].rush = &rush04;
}

void	ft_write(int i, int width, int height, int count)
{
	if (count == 0 || count > 2)
	{
		write(1, "[colle-0", 8);
		put_nbr(i);
		write(1, "] [", 3);
		put_nbr(width);
		write(1, "] [", 3);
		put_nbr(height);
		write(1, "]", 1);
	}
	else
	{
		write(1, "[rush-0", 7);
		put_nbr(i);
		write(1, "] [", 3);
		put_nbr(width);
		write(1, "] [", 3);
		put_nbr(height);
		write(1, "]", 1);
	}
}

int		str_match(char *input_str, void (*f_ptr)(int, int, char*, int*),
		int input_width, int input_height)
{
	char	*rush_str;
	int		i;

	rush_str = rush_to_str(input_width, input_height, f_ptr);
	i = 0;
	while (rush_str[i] != '\0')
	{
		if (input_str[i] != rush_str[i])
			return (0);
		i++;
	}
	free(rush_str);
	if (input_str[i] == '\0')
		return (1);
	else
		return (0);
}

void	print(char *input_str, int input_width, int input_height)
{
	int		i;
	int		is_not_valid;
	t_rush	f_ptr[NUM_RUSHES];

	i = 0;
	is_not_valid = 1;
	assign_funs(f_ptr);
	while (i < NUM_RUSHES)
		if (str_match(input_str, f_ptr[i++].rush, input_width, input_height))
			is_not_valid++;
	i = 0;
	while (i < NUM_RUSHES)
	{
		if (str_match(input_str, f_ptr[i].rush, input_width, input_height))
		{
			ft_write(i, input_width, input_height, is_not_valid);
			is_not_valid = 0;
			if (i < (NUM_RUSHES - 1) && str_match(input_str, f_ptr[i + 1].rush,
				input_width, input_height))
				write(1, " || ", 4);
		}
		i++;
	}
	if (is_not_valid)
		write(1, "aucune", 6);
}
