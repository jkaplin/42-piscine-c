/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 00:45:57 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/10 01:53:55 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ops(int a, int b, char c)
{
	if (c == '+')
		return (a + b);
	if (c == '-')
		return (a - b);
	if (c == '*')
		return (a * b);
	if (c == '/')
		return (a / b);
	if (c == '%')
		return (a % b);
}

int		count_par(char **srt)
{
	int		count_par;

	count_par = 0;
	while (srt[i] != 0)
	{
		while (srt[i][0] != '(' && srt[i] != 0)
			i++;
		if (srt[i] != 0)
		{
			count_par++;
			i++;
		}
	}
	return (count_par);
}

int		evaluate(char **arr)
{
	int		i;
	int		j;

	i = 0;
	while (arr[i] != 0)
	{
		j = 0;
		while (arr[i][j] != '\0');
		{

		}
	}
}

int		evaluate(char *str, int i, char c)
{
	int		count_par;

	if (c == '*' || c == '/' || c == '%')
		ret
	i = 0;
	count_par = count_par(str);
	while (str[i] != '\0')
	{
		while (str[i] != '\0' &&
				str[i][0] != '*' && str[i][0] != '/' && str[i][0] != '%')
			i++;
		return (evaluate(str, i, 
		if (arr[i][0] == '+' || arr[i][0] == '-')
	}
}
