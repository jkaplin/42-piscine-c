/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:08:28 by chford            #+#    #+#             */
/*   Updated: 2018/11/14 22:20:05 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	stricpy(char *s1, char *s2, int *i)
{
	int		j;

	j = 0;
	while (s2[j] != '\0')
	{
		s1[*i] = s2[j];
		(*i)++;
		j++;
	}
}

t_list	*input_to_list(int *count_buf, t_input *input, t_list *link)
{
	int		buf_len;
	char	buf[BUF_SIZE + 1];
	int		is_begin;
	t_list	*begin_list;

	is_begin = 1;
	link = NULL;
	begin_list = NULL;
	while ((buf_len = read(input->descriptor, buf, BUF_SIZE)) > 0)
	{
		buf[buf_len] = '\0';
		link = add_link(link, buf);
		if (is_begin)
		{
			begin_list = link;
			is_begin = 0;
		}
		*count_buf += 1;
	}
	if (buf_len == -1)
		return (NULL);
	else
		return (begin_list);
}

void	list_to_str(t_list *begin_list, char *str)
{
	int		i;
	t_list	*link;
	t_list	*copy;

	link = begin_list;
	i = 0;
	while (link != NULL)
	{
		stricpy(str, link->str, &i);
		copy = link;
		link = link->next;
		free(copy);
	}
	str[i] = '\0';
}

char	*read_file(t_input *file)
{
	char	*str;
	int		count_buf;
	t_list	*begin_list;
	t_list	*last_link;

	file->descriptor = open(file->name, O_RDONLY);
	if (file->descriptor == -1)
		return (NULL);
	count_buf = 0;
	last_link = malloc(sizeof(t_list));
	begin_list = input_to_list(&count_buf, file, last_link);
	if (begin_list == NULL)
		return (NULL);
	str = (char *)malloc((sizeof(char) *
					((count_buf - 1) * BUF_SIZE + 1)) + sizeof(last_link->str));
	free(last_link);
	list_to_str(begin_list, str);
	return (str);
}

char	*read_stdi(t_input *stdi)
{
	char	*str;
	int		count_buf;
	t_list	*begin_list;
	t_list	*last_link;

	stdi->descriptor = 0;
	last_link = malloc(sizeof(t_list));
	count_buf = 0;
	begin_list = input_to_list(&count_buf, stdi, last_link);
	if (begin_list == NULL)
		return (NULL);
	str = (char *)malloc((sizeof(char) *
					((count_buf - 1) * BUF_SIZE + 1)) + sizeof(last_link->str));
	free(last_link);
	list_to_str(begin_list, str);
	return (str);
}
