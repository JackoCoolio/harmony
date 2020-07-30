
#include <malloc.h>
#include <stddef.h>
#include <stdio.h>

#include "harmony_linked_list.h"

void harmony_ll_append(harmony_ll_t *list, void *data)
{
	printf("%d", (list->data == NULL));
	if (list->data == NULL)
	{
		list->data = data;
		return;
	}
	
	printf("%p\n", list);
	while (list->next != NULL)
	{
		printf("%p\n", list->next);
		list = list->next;
	}
	
	list->next = malloc(sizeof(harmony_ll_t));
	list->next->data = data;
	list->next->next = NULL;
}

