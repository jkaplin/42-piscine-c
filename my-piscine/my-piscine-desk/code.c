/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:50:45 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/09 13:02:08 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    hecks(char *str)
{
    int i;

	i = -1;
    while (str[++i])
		write(1, str, i);
	write(1, "\n", 1);
}

void ft_one(char **what, char *the)
{
    char    *heck;
    int     i;
    int     j;

    i = 0;
	j = 0;
    while (what[i][j] && the[j])
	{
        if (the[j] && what[i][j] ? the[j] : heck[j])
        {
            if (what[i][j++] && what[i][j] ? the[i][j] : heck[j])
                hecks(*what);
            hecks(the);
        }
	}
}

int main(void)
{
    char *string;
    char *other;

    string = "GOOD LUCK PISCINERS!!!";
    other = "May the code be with you!";
    ft_one(&string, &other);
    write(1, "\n", 1);
    return (0);
}
