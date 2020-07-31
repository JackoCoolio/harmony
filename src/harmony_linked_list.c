
#include <malloc.h>
#include <stddef.h>
#include <stdio.h>

#include "harmony_linked_list.h"

void harmony_ll_append(harmony_ll_t *list, void *data)
{
	printf("Beginning append %p to LL %p\n", data, list);
	if (list->data == NULL)
	{
		list->data = data;
		printf("Starting LL with pointer %p\n", data);
		return;
	}
	
	printf("Appending %p to LL %p\n", data, list);
	while (list->next != NULL)
	{
		printf("Traversing LL @ %p\n", list->next);
		list = list->next;
	}
	
	list->next = malloc(sizeof(harmony_ll_t));
	list->next->data = data;
	list->next->next = NULL;
}

