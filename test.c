#include "build_list.h"

void print(struct int_list *p)
{
	printf("%d ", p->elm);
}

int main()
{
	struct int_list head;

	build_list_int(&head, 6, 1, 2, 3, 4, 5, 6);
	int_list_trav(&head, print);
	printf("\n");

}
