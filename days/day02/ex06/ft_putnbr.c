int	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	int	copy;
	int	length;
	int	i;

	if (nb == 0)
		ft_putchar('0');
	if (nb < 0)
		ft_putchar('-');
	copy = nb;
	length = 0;
	while (copy > 0)
	{
		length++;
		copy /= 10;
	}
	while (length > 0)
	{
		i = 1;
		copy = num;
		while (i++ < length)
			copy /= 10;
		ft_putchar(copy % 10 + '0');
		length--;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		return;
	if (nb / 10 == 0 && nb < 0)
		ft_putchar('-');
	ft_putnbr(nb / 10);
	ft_putchar('0' + (nb % 10);
}
