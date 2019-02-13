/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 11:32:56 by jkaplin           #+#    #+#             */
/*   Updated: 2018/10/30 13:04:00 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2);

void	ft_putstr(char *str);

//int		ft_strcmp(char *s1, char *s2)
//{
//	int		i;
//
//	i = 0;
//	while (s1[i] != '\0' && s2 != '\0')
//	{
//		if(s1[i] != s2[i])
			

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		count;
	char	*copy;

	i = 1;
	count = 1;
	while (count < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) < 0 && i < j)
			{
				copy = argv[i];
				argv[i] = argv[j];
				argv[j] = copy;
				i = count;
			}
			j++;
		}
		count++;
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
