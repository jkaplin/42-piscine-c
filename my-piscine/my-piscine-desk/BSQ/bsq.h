/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:06:12 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/13 22:40:45 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define BUF_SIZE 4096
# define EMPTY -1

typedef struct s_input		t_input;
typedef struct s_map		t_map;
typedef	struct s_list		t_list;
typedef struct s_position	t_position;

struct	s_input
{
	char	*name;
	int		descriptor;
	char	*str;
};

struct	s_map
{
	int		details_len;
	int		height;
	int		width;
	char	empty;
	char	obstacle;
	char	full;
};

struct	s_list
{
	char	str[BUF_SIZE + 1];
	t_list	*next;
};

struct	s_position
{
	int		h;
	int		w;
	int		is_small;
};

void	ft_strcpy(char *s1, char *s2);
t_list	*add_link(t_list *end_list, char *buf);
void	stricpy(char *s1, char *s2, int *i);
t_list	*input_to_list(int *count_buf, t_input *file, t_list *link);
void	list_to_str(t_list *begin_list, char *str);
char	*read_file(t_input *file);
char	*read_stdi(t_input *stdi);
int		ft_atoi_n(char *str, int n);
int		valid_details_line(char *file_str, t_map *map, int i);
int		is_not_valid_char(char c, t_map *map);
int		is_valid_map(char *file_str, t_map *map, int i, int line_length, int num_lines);
int		is_valid(char *file_str, t_map *map);
void	print(char *str);
int		**allocate_grid(t_map *map);
void	initialize_grid(int **grid, char *input_str, t_map *map, t_position box);
int		check_surrounding_spaces(int **grid, t_position box, int max);
int		find_big_center(t_position *center, int **grid, t_map *map, int max);
int		find_small_center(t_position *center, int **grid, t_map *map, int max);
void	fill_grid(int **grid, t_map *map, int *max, t_position start);
void	fill_str(int max, char *input_str, t_map *map, t_position *center);
void	solve_map(char *input_str, t_map *map);
int		solve_file(t_input *file, t_map *map);
int		solve_stdi(t_map *map);
int		is_on_border(int h, int w, t_map *map);

#endif
