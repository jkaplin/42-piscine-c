int   ft_is_prime(int nb)
{
  int   i;

  if (nb == 0 || nb == 1)
		return (0);
  i = 2;
  while (i <= nb / 2)
  {
    if (nb % i == 0)
      return (0);
    i++;
  }
  return (1);
}

int recursive_is_prime(int nb, int div)
{
	if (nb == 0 || nb == 1)
		return (0);
	if (div > nb / 2)
		return (1);
	if (nb % div == 0)
		return (0);
	return (recursive_is_prime(nb, div + 1));
}
