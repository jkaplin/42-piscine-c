/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 22:44:34 by jkaplin           #+#    #+#             */
/*   Updated: 2018/10/28 23:13:03 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_print_comb2(void)
{
	char digits[4];
	int i;

	digits = {'0', '0', '0', '1'};
	i = 0;
	while (digits[0]++ <= '8')
	{
		while (digits[1]++ <= '9')
		{
			while (digits[2]++ <= '9')
			{
				while (digits[3]++ <= '9')
				{
					ft_putchar(digits[0]);
					ft_putchar(digits[1]);
					ft_putchar(' ');
					ft_putchar(digits[2]);
					ft_putchar(digits[3]);
					if (digits[0] == '9' && digits[1] == '9' && digits[2] == '9' && digits[3] == '8')
						break ;
					ft_putchar(',');
					ft_putchar(' ');
				}
			
