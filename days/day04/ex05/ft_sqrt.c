int	recursive(int nb, int i)
{
	if (i * i > nb)
		return (0);
	if (i * i == nb)
		return (i);
	return (recursive(nb, i + 1));
}

int	ft_sqrt(int nb)
{
	return (recursive(nb, 1));
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
