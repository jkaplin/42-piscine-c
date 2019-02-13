#include <unistd.h>
#include <stdlib.h>

char	**create_tab(int argc, char **argv);

int		get_nb(char **tab, int h, int w);

int		main(int argc, char **argv);

int		check_row(char **tab, int h, char nb);

int		check_col(char **tab, int w, char nb);

int		check_sq(char **tab, int h, int w, char nb);

int		check_nb(char **tab, int h, int w, char nb);

int		check_row(char **tab, int h, char nb)
{
	int		i;

	i = 0;
	while (i <= 8)
	{
		if(tab[h][i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int		check_col(char **tab, int w, char nb)
{
	int		j;

	j = 0;
	while (j <= 8)
	{
		if(tab[j][w] == nb)
			return (0);
		j++;
	}
	return (1);
}

int		check_sq(char **tab, int h, int w, char nb)
{
	int		j;
	int		i;
	int		start_h;
	int		start_w;

	start_h = (h / 3) * 3;
	start_w = (w / 3) * 3;
	j = start_h;
	while (j <= start_h + 2)
	{
		i = start_w;
		while(i <= start_w + 2)
		{
			if(tab[j][i] == nb)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int		check_nb(char **tab, int h, int w, char nb)
{
	if (check_row(tab, h, nb) && check_col(tab, w, nb) && check_sq(tab, h, w, nb))
		return (1);
	else
		return (0);
}

void	print_tab(char **tab)
{
	int		i;
	int		j;

	j = 0;
	while (j <= 8)
	{
		i = 0;
		while (tab[j][i] != '\0')
		{
			write(1, &tab[j][i], 1);
			if (tab[j][i + 1] != '\0')
				write(1, " ", 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

char	**create_tab(int argc, char **argv)
{
	char	**tab;
	int		i;
	int		j;

	tab = (char **)malloc(sizeof(char *) * 9);
	i = 1;
	j = 0;
	while (i < argc)
	{
		tab[j] = (char *)malloc(sizeof(char) * (9 + 1));
		tab[j] = argv[i];
		i++;
		j++;
	}
	return (tab);
}

int		skip_nb(char **tab, int h, int w)
{
	if (w <= 7)
	{
		if (get_nb(tab, h, w + 1) == 1)
			return (1);
	}
	else
	{
		w = 0;
		if(get_nb(tab, h + 1, w) == 1)
			return (1);
	}
	return (0);
}

int		get_nb(char **tab, int h, int w)
{
	int		last_check;

	if (h==9)
		return (1);
	if (tab[h][w] != '.')
		return skip_nb(tab, h, w);
	last_check = '1';
	while (last_check <= '9')
	{
		if (check_nb(tab, h, w, last_check) == 1)
		{
			tab[h][w] = last_check;
			if (w <= 7)
			{
				if (get_nb(tab, h, w + 1) == 1)
					return (1);;
			}
			else
			{
				w = 0;
				if(get_nb(tab, h + 1, w) == 1)
					return (1);
			}
		}
		last_check++;
	}
	tab[h][w] = '.';
	return (0);
}

int		main(int argc, char **argv)
{
	char	**tab;
	int		h;
	int		w;

	h = 0;
	w = 0;

	tab = create_tab(argc, argv);
	if (get_nb(tab, h, w))
		print_tab(tab);
	else
		write(1, "Error\n", 6);
	return (0);
}