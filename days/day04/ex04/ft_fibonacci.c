int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int	ft_fibonacci(int index)
{
	int	sum;
	int	a;
	int	b;

	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	a = 0;
	b = 1;
	while (index > 1)
	{
		sum = a + b;
		a = b;
		b = sum;
		index--;
	}
	return (sum);
}
