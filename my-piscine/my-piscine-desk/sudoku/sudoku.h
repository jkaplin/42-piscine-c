/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 22:33:59 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/04 14:14:22 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <unistd.h>
# include <stdlib.h>

int		check_row(char **tab, int h, char nb);

int		check_col(char **tab, int w, char nb);

int		check_sq(char **tab, int h, int w, char nb);

int		check_nb(char **tab, int h, int w, char nb);

void	print_tab(char **tab);

char	**create_tab(int argc, char **argv);

int		skip_nb(char **tab, int h, int w);

void	change_w_and_h(int w, int h, int *change_width, int *change_height);

int		solve(char **tab, int h, int w);

#endif
