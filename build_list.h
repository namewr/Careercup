#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#define list(type)\
	struct type##_list{\
		type elm;\
		struct type##_list *next;\
	};

#define list_func(type)\
struct type##_list* build_list_##type(struct type##_list *head,\
					int num, ...)

#define alloc_list(type)\
	(struct type##_list*)malloc(sizeof(struct type##_list))

list(int);

list_func(int)
{
	struct int_list *new;	
	int i;
	
	head->next = NULL;
	va_list l_elm;
	va_start(l_elm, num);

	for(i = 0; i < num; i++){
		new = alloc_list(int);
		new->elm = va_arg(l_elm, int);
		new->next = head->next;
		head->next = new;
	}
	va_end(l_elm);
	
	return head;
}

#define build_list(type, head, num, args...)\
		build_list_##type(head, num, ##args)

void int_list_trav(struct int_list* head, void func(struct int_list*))
{
	struct int_list *next;

	for(next = head->next; next != NULL; next = next->next){
		func(next);
	}	
} 
