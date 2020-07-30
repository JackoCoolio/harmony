#ifndef HARMONY_LINKED_LIST_H
#define HARMONY_LINKED_LIST_H

typedef struct harmony_ll_t
{
	void *data;
	struct harmony_ll_t *next;
} harmony_ll_t;

void harmony_ll_append(harmony_ll_t *list, void *data);

#endif
