void	ft_swap(int *a, int *b)
{
	int	copy;

	copy = *a;
	*a = *b;
	*b = copy;
}

void	ft_sort_integer_table(int *tab, int size)
{
	int	i;
	int	swapped;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				swapped = 1;
			}
			i++;
		}
	}
}
