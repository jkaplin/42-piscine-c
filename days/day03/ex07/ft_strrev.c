void	ft_swap_char(char *a, char *b)
{
	char	copy;

	copy = *a;
	*a = *b;
	*b = copy;
}

char	*ft_strrev(char *str)
{
	int	left;
	int	right;

	left = 0;
	right = 0;
	while (str[right + 1] != '\0')
	{
		right++;
	}
	while(left < right)
	{
		ft_swap_char(&str[left], &str[right]);
		left++;
		right--;
	}
	return (str);
}
