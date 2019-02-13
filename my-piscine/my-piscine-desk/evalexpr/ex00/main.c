/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 23:36:54 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/10 16:19:58 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

int		strlen(char *str)
{
	int		length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

void	split(char **arr, char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		k = 0;
		if (str[i] == ' ')
			i++;
		if (str[i] == '\0')
			break;
		if (str[i] >= '0' && str[i] <= '9')
			while (str[i] >= '0' && str[i] <= '9')
				arr[j][k++] = str[i++];
		arr[j++][k] = '\0';
		if (str[i] == '\0')
			break;
		if (str[i] == ' ')
			i++;
		arr[j][0] = str[i++];
		arr[j++][1] = '\0';
	}
	arr[j] = 0;
}

int eval_expr(char *str)
{
	int		num_expr;
	char	**arr;
	int		i;

	num_expr = num_expr(str);
	arr = (char **)malloc(sizeof(char *) * (num_expr + 1));
	i = 0;
	while (i <= num_expr)
	{
		arr[i] = (char *)malloc(sizeof(char) * (strlen(str) + 1));
		i++;
	}
	split(arr, str);
	i = 0;
	while (i <= num_expr)
	{

	return (evaluate(arr));
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar(’\n’);
	}
	return (0);
}
