#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	better_putstr(char *str)
{
	int		length;

	length = 0;
	while (str[length])
	{
		length++;
	}
	write(1, str, length);
}
