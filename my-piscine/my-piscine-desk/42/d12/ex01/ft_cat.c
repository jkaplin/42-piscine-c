/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:36:19 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/08 23:29:32 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	display_file(char *file)
{
	char	str[28 + 1];
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		return ;
	}
	ret = read(fd, str, 28);
	while (ret != 0)
	{
		ret = read(fd, str, 28);
		str[ret] = '\0';
		ft_putstr(str);
	}
}

int		valid(int argc, char **argv)
{
	if (argc < 2 || !argv[0][0])
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (valid(argc, argv))
	{
		while (i < argc)
		{
			display_file(argv[i]);
			i++;
		}
	}
	return (0);
}
