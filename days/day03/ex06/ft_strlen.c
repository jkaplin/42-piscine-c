int	ft_strlen(char *str)
{
	int	length;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}
