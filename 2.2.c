#include <stdio.h>
#include <stdlib.h>
#include "build_list.h"

void print(struct int_list *elm)
{
	printf("%d ", elm->elm);
}

void find_kth_last(struct int_list *head, int k)
{
	int ival;
	struct int_list *fir, *sec;

	fir = head;
	sec = head;
	/* first get interval k*/
	for(ival = 0; ival <= k;  ival++){
		if(sec->next == NULL){
			printf("not exist\n");
			return;
		}

		sec = sec->next;
	}

	for(;sec!= NULL; sec = sec->next, fir = fir->next);
	int_list_trav(fir, print);
	printf("\n");
	return;
}

int main(int argc, char *argv[])
{
	struct int_list head;

	if(argc != 2)
		return 0;

	

	build_list(int, &head, 6, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	int_list_trav(&head, print);
	printf("\n");
	find_kth_last(&head, atoi(argv[1]));

	return 1;
}
