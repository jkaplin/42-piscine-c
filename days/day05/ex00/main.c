#include "ft_putstr.c"

int		main(int argc, char **argv)
{
	int		i;
	
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (0);
}
