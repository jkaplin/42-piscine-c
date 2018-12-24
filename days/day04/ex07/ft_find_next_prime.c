int		ft_is_prime(int nb);

int 	ft_find_next_prime(int nb)
{
	while(ft_is_prime(nb) == 0)
	{
		nb++;
	}
	return (nb);
}

int		recursive_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	return (recursive_find_next_prime(nb + 1));
}
