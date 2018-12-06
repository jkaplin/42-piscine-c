#include <unistd.h>

int	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int	num[2];

	num[0] = 0;
	while (num[0] < 99)
	{
		num[1] = num[0] + 1;
		while (num[1] <= 99)
		{
			ft_putchar(num[0] / 10 + '0');
			ft_putchar(num[0] % 10 + '0');
			ft_putchar(' ');
			ft_putchar(num[1] / 10 + '0');
			ft_putchar(num[1] % 10 + '0');
			if (num[0] != 98)
				write(1, ", ", 2);
			num[1]++;
		}
		num[0]++;
	}
}
