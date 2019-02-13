#include <stdio.h>
// this is already in stupidity.c
/*void ft_putchar(char c)
{
	c++;
	printf("ft_putchar\n");
}*/
void ft_putstr(char* str)
{
	str++;
	printf("ft_putstr\n");
}
int ft_strcmp(char* s1, char* s2)
{
	s1++;
	s2++;
	printf("ft_strcmp\n");
	return 0;
}
int ft_strlen(char* str)
{
	str++;
	printf("ft_strlen\n");
	return 0;
}
void ft_swap(int* a, int* b)
{
	a++;
	b++;
	printf("ft_swap\n");
}
