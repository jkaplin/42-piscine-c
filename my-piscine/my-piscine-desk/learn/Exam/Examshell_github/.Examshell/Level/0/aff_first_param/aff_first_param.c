/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_first_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 08:23:44 by jkaplin           #+#    #+#             */
/*   Updated: 2018/10/30 08:28:53 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc > 1)
	{
		while (argv[1][i] != '\0')
		{
			write(1, &(argv[1][i]), 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
