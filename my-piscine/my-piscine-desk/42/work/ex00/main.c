


		#include <stdio.h>
		#include <stdlib.h>
		#include <string.h>

		#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
		#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

	#include "ft_list.h"
t_list *ft_create_elem(void *data);
int main()
{
	t_list* item = ft_create_elem("asdf");
	printf("%s\n", (char*)item->data);
	printf("%p\n", item->next);
}


