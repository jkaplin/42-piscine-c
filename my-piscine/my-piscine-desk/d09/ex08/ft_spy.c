/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 09:40:34 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/02 15:34:01 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp_from_n(char *s1, char *s2, int n)
{
	int		i;
	int		j;
	int		k;

	i = n;
	j = 0;
	while (s1[i] == ' ')
		i++;
	while (s2[j + 1] != '\0' && (s1[i] == s2[j] || s1[i] - 'A' + 'a' == s2[j]))
	{
		i++;
		j++;
	}
	k = i + 1;
	while (s1[k] == ' ')
		k++;
	if (s1[k] == '\0')
		return (s1[i] - s2[j]);
	else
		return (1);
}

void	write_alert(char *s1, char *s2, int n)
{
	if (ft_strcmp_from_n(s1, s2, n) == ('A' - 'a') ||
		ft_strcmp_from_n(s1, s2, n) == 0)
		write(1, "Alert!!!\n", 9);
}

int		main(int argc, char **argv)
{
	int		i;
	int		n;

	i = 1;
	while (i < argc)
	{
		n = 0;
		while (argv[i][n] == ' ')
			n++;
		write_alert(argv[i], "president", n);
		write_alert(argv[i], "attack", n);
		write_alert(argv[i], "bauer", n);
		i++;
	}
	return (0);
}
