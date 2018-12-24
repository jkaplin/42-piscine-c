#include <stdlib.h>

#include "ft_putnbr.c"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_putnbr(atoi(argv[1]));
		ft_putchar('\n');
		iterative_putnbr(atoi(argv[1]));
		ft_putchar('\n');
	}
	return (0);
}
