/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 13:02:04 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/02 16:57:05 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H

# include <string.h>
# define SAVE_THE_WORLD "42 Cadet Student"

typedef struct				s_perso
{
	char	*name;
	float	life;
	int		age;
	char	*profession;
}							t_perso;

#endif
