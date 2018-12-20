int	ft_iterative_power(int nb, int power)
{
	int	factor;

	factor = 1;
	while (power > 0)
	{
		factor *= nb;
		power--;
	}
}
