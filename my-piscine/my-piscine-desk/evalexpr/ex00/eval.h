/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 00:48:26 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/11 23:29:16 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_H
# define EVAL_H

# include <unistd.h>
# include <stdlib.h>

typedef	struct s_list	t_list;

struct	s_list
{
	int		n;
	char	op;
	t_list	*next;
	t_list	*prev;
};

prototypes;

#endif
