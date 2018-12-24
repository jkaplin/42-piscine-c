#include <unistd.h>
#include <limits.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 0 && nb < 10)
	{
		ft_putchar('0' + nb);
		return ;
	}
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar('0' + (nb % 10));
	}
}

void	iterative_putnbr(int nb)
{
	int		length;
	int		copy;
	char	*nb_str;
	int		i;
	
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -1 * nb;
	}
	copy = nb;
	length = 1;
	while (copy > 9)
	{
		length++;
		copy /= 10;
	}	
	nb_str = (char *)malloc(sizeof(char) * length);
	i = length - 1;
	while (i >= 0)
	{
		nb_str[i] = '0' + (nb % 10);
		nb /= 10;
		i--;
	}
	write(1, nb_str, length);
}
