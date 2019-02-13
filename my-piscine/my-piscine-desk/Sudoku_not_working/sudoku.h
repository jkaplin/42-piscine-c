/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 22:33:59 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/04 12:03:26 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

char	**create_tab(int argc, char **argv);

int		get_nb(char **tab, int h, int w);

int		main(int argc, char **argv);

int		check_row(char **tab, int h, char nb);

int		check_col(char **tab, int w, char nb);

int		check_sq(char **tab, int h, int w, char nb);

int		check_and_insert_nb(char **tab, int h, int w, char last_check);

#endif
