/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:08:28 by chford            #+#    #+#             */
/*   Updated: 2018/11/12 20:14:03 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_list	**iterate_files(int argc, char **argv)
{
	int		i;
	char	**input;

	if (argc > 1)
	{
		i = 1;
		input = (char *)malloc(sizeof(char *) * argc);
		while (i < argc)
		{
			input[i - 1] = read_file(argv[i], input);
			i++;
		}
	}
	else
	{
	//read stdin
	}
}

char	**read_file(char *filename, char **input)
{
	int		fd;
	int		ret;
	t_list	*begin;
	t_list	*element;
	char	buffer[BUF_SIZE + 1];

	begin = (t_list *)malloc(sizeof(t_list));
	begin = 0;
	fd = open(filename, O_RDWR);
	if (fd == -1)
		//Error - Cannot open file
		1 = 1;
	while ((ret = read(fd, buffer, BUFSIZE)) > 0)
	{
		buffer[ret] = '\0';
		element = create_element(buffer);
	}
		if (ret == -1)
			1 = 1;
	//Error reading from file
}
