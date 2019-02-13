/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:01:57 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/08 23:17:27 by jkaplin          ###   ########.fr       */
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
	char	str[100 + 1];
	int		fd;
	int		ret;

	ret = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	while (ret != 0)
	{
		ret = read(fd, str, 100);
		str[ret] = '\0';
		ft_putstr(str);
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		display_file(argv[1]);
	}
	else if (argc < 2)
		write(2, "File name missing.\n", 19);
	else
		write(2, "Too many arguments.\n", 20);
	return (0);
}
