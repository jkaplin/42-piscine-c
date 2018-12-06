#include <unistd.h>

int	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	if (nb == 0)
		return;
	if (nb / 10 == 0 && nb < 0)
		ft_putchar('-');
	ft_putnbr(nb / 10);
	ft_putchar('0' + (nb % 10);
}

void	ft_print_combn(int n)
{
	int	num;
	int	power10;

	power10 = 1;
	while (n > 0)
	{
		power10 *= 10;
		n--;
	}
	num = 0;
	while (num < power10)
	{
		ft_putnbr(num);
		num++;
		if (num != power10 - 1)
			write(1, ", ", 2);
	}
}
