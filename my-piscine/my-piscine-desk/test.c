/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 23:24:10 by jkaplin           #+#    #+#             */
/*   Updated: 2018/10/30 23:25:34 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		main(void)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a <= b)
	{
		b += 10;
		a += 3;
		a++;
		b--;
	}
}
