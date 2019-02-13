/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:35:53 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/11 19:28:29 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	putnbr(int n, int once)
{
	char	c;

	if (n < 0 && once)
	{
		write(1, "-", 1);
		once = 0;
	}
	if (n > 9 || n < -9)
		putnbr(n / 10, once);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

int		ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 12) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (sign * (int)num);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num = num * sign;
	return ((int)num);
}

int		is_valid(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i > 0 || (str[i] != '+' && str[i] != '-' && str[i] != '*' &&
			str[i] != '/' && str[i] != '%'))
			return (0);
		i++;
	}
	return (1);
}

void	create_struct(t_fun_op *ops)
{
	ops[0].op_fun = f_plus;
	ops[0].op_char = '+';
	ops[1].op_fun = f_minus;
	ops[1].op_char = '-';
	ops[2].op_fun = f_multiply;
	ops[2].op_char = '*';
	ops[3].op_fun = f_divide;
	ops[3].op_char = '/';
	ops[4].op_fun = f_mod;
	ops[4].op_char = '%';
}
