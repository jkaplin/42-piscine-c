/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 21:02:46 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/11 19:28:01 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	do_op(char **argv, int (*op_ptr)(int, int))
{
	if (ft_atoi(argv[3]) == 0)
	{
		if (argv[2][0] == '/')
		{
			write(1, "Stop : division by zero", 23);
			return ;
		}
		else if (argv[2][0] == '%')
		{
			write(1, "Stop : modulo by zero", 21);
			return ;
		}
	}
	putnbr(op_ptr(ft_atoi(argv[1]), ft_atoi(argv[3])), 1);
}

int		main(int argc, char **argv)
{
	int			(*op_ptr)(int, int);
	int			i;
	t_fun_op	ops[5];

	create_struct(ops);
	i = 0;
	if (argc == 4)
	{
		if (is_valid(argv[2]))
		{
			while (i <= 4)
			{
				if (ops[i].op_char == argv[2][0])
					op_ptr = ops[i].op_fun;
				i++;
			}
			do_op(argv, op_ptr);
		}
		else
			write(1, "0", 1);
		write(1, "\n", 1);
	}
	return (0);
}
