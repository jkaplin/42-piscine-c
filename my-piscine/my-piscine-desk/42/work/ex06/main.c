


		#include <stdio.h>
		#include <stdlib.h>
		#include <string.h>

		#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
		#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

	#include "ft_list.h"
void ft_list_clear(t_list **begin_list);
t_list* ft_create_elem(void* data)
{
	t_list* item = malloc(sizeof(t_list));
	item->next = NULL;
	item->data = data;
	return (item);
}
#define CE(data) ft_create_elem(data)
#define CL(list) crap_a_list(list)
void crap_a_list(t_list* list)
{
	for (; list != 0; list = list->next)
		printf("%s,", (char*)list->data);
	printf("\n");
}
int compare_ints(const int* v1, const int* v2)
{
	return *v1 - *v2;
}
int main()
{
	t_list* l = CE("asdf");
	l->next = CE("qwer");
	l->next->next = CE("zxcv");
	t_list* addresses[] = {l, l->next, l->next->next};
	qsort(addresses, 3, sizeof(t_list*), (int(*)(const void*, const void*))compare_ints);
	ft_list_clear(&l);
	// verify that this is set to a null pointer now
	printf("is null? %p\n", l);
	// verify that you freed the addresses by checking with malloc
	// if you freed them correctly, malloc will reuse them for this second batch
	l = CE("asdf");
	l->next = CE("qwer");
	l->next->next = CE("zxcv");
	t_list* addresses2[] = {l, l->next, l->next->next};
	qsort(addresses2, 3, sizeof(t_list*), (int(*)(const void*, const void*))compare_ints);
	printf("address good? %d,%d,%d\n", addresses[0] == addresses[0], addresses[1] == addresses[1], addresses[2] == addresses[2]);
}


