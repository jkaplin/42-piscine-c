int	ft_iterative_factorial(int nb)
{
	int	factor;

	factor = 1;
	while (nb > 1)
	{
		factor *= nb;
		nb--;
	}
	return (factor);
}
