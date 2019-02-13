


		#include <stdio.h>
		#include <stdlib.h>
		#include <string.h>

		#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
		#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

	#include "ft_list.h"
int ft_list_size(t_list *begin_list);
t_list* ft_create_elem(void* data)
{
	t_list* item = malloc(sizeof(t_list));
	item->next = NULL;
	item->data = data;
	return (item);
}
#define CE(data) ft_create_elem(data)
void crap_a_list(t_list* list)
{
	for (; list != 0; list = list->next)
		printf("%s,", (char*)list->data);
	printf("\n");
}
int main()
{
	t_list* list = 0;
	printf("%d\n", ft_list_size(list));
	list = CE("asdf");
	printf("%d\n", ft_list_size(list));
	list->next = CE("qwer");
	list->next->next = CE("zxcv");
	printf("%d\n", ft_list_size(list));
	list = CE("asdf");
	list->next = CE("asdf");
	list->next->next = CE("asdf");
	list->next->next->next = CE("asdf");
	printf("%d\n", ft_list_size(list));
	list->next->next->next->next = CE("asdf");
	printf("%d\n", ft_list_size(list));
}


