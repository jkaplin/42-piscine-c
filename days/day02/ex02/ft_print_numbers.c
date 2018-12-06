int	ft_putchar(char c);

void	ft_print_numbers(void)
{
	char digit = '0';

	while (digit <= '9')
	{
		ft_putchar(digit);
		digit++;
	}
}
