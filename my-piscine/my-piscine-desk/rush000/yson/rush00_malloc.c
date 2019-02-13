/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubakir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:15:05 by aaubakir          #+#    #+#             */
/*   Updated: 2018/11/10 21:09:45 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*press(int i, char first, char second, char third)
{
	int count;
	char *str;

	count = i;
	str = (char *)(malloc(sizeof(char) * (i + 2)));
	str[count - i] = first;
	//Not correctly printing row
	while (i > 2)
	{
		i--;
		str[count - i] = second;
	}
	//Most likely expression above
	if (i > 1)
		str[count - i] = third;
	str[count] = '\n';
	return (str);
}

char	**rush_store(int x, int y)
{
	int count;
	char **arr;

	count = y;
	//Memory Allocation Problem? 
	//Set to 100 until issue resolved
	arr = (char **)(malloc(sizeof(char) * 100 * (y * (x + 2))));
	if (x > 0 && y > 0)
	{
		arr[count - y] = press(x, 'o', '-', 'o');
		y--;
		while (y > 1)
		{
			arr[count - y] = press(x, '|', ' ', '|');
			y--;
		}
		if (y > 0)
			arr[count - y] = press(x, 'o', '-', 'o');
	}
	return (arr);
}

char	*rush(int x, int y)
{
	int 	i;
	int 	j;
	int 	count;
	char	*pat;
	char	**array;
	
	count = 0;
	//Memory Allocation Problem?
	pat = (char *)(malloc(sizeof(char) * 100 * (y * (x + 2))));
	array = rush_store(x, y);
	
	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			pat[count++] = array[i][j];
			j++;
		}
		i++;
	}
	pat[count] = '\0';
	return (pat);
}


int main(int argc, char **argv)
{
	int i;
	char *rushp = rush(atoi(argv[1]),atoi(argv[2]));

	i = 0;
	while (rushp[i])
		printf("%c", rushp[i++]);
	return (0);
}
