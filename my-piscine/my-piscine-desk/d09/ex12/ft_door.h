/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 13:11:48 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/02 16:07:48 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H

# include <stdlib.h>
# include <unistd.h>

# define OPEN 1
# define CLOSE 0

typedef enum	e_bool
{
	TRUE = 1,
	FALSE = 0
}				t_bool;

typedef struct		s_door
{
	int		state;
}					t_door;

#endif
