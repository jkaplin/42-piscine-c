#include <unistd.h>

int	ft_putchar(char c);

void	ft_print_comb(void)
{
	char	digit[3];

	digit[0] = '0' - 1;
	digit[1] = '1' - 1;
	digit[2] = '2' - 1;
	while (digit[0] < digit[1] && digit[0] <= '7')
	{
		digit[1] = ++digit[0] + 1;
		while ((digit[1] < digit[2] && digit[1] <= '8') || (digit[2] == '1'))
		{
			digit[2] = digit[1] + 1;
			while (digit[2] <= '9')
			{
				ft_putchar(digit[0]);
				ft_putchar(digit[1]);
				ft_putchar(digit[2]);
				if (digit[0] != '7')
					write(1, ", ", 2);
				digit[2]++;
			}
			digit[1]++;
		}
	}
}
