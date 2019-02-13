/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:32:59 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/06 20:17:37 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

typedef struct	s_fun_op
{
	int		(*op_fun)(int a, int b);
	char	op_char;
}				t_fun_op;

int				f_plus(int a, int b);

int				f_minus(int a, int b);

int				f_multiply(int a, int b);

int				f_divide(int a, int b);

int				f_mod(int a, int b);

void			putnbr(int n, int once);

int				ft_atoi(char *str);

int				is_valid(char *str);

void			create_struct(t_fun_op *ops);

#endif
