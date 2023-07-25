#include "sort.h"

/**
 * swap_node - swaps two nodes in a douibly linked list
 * @nd1: the first node to swap
 * @nd2: the second node to swap
 * @l: the linked list
 * @tail: the tail
 */
void swap_node(listint_t *nd1, listint_t *nd2, listint_t **l, listint_t **tail)
{
	listint_t *prev, *curr, *next;

	prev = nd1->prev;
	curr = nd1;
	next = nd2;

	curr->next = next->next;
	next->prev = prev;

	if (prev)
		prev->next = next;

	if (next->next)
		next->next->prev = curr;

	curr->prev = next;
	next->next = curr;

	if (!(next->prev))
		*l = next;

	if (!(curr->next))
		*tail = curr;

	print_list(*l);
}

/**
 * cocktail_sort_list - sort a list using the cocktail shaker sort algorithm
 * @list: The doubly linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *ptr;
	int swapped;

	if (!list)
		return;

	tail = *list;
	while (tail->next)
		tail = tail->next;

	do {
		swapped = 0;
		ptr = *list;
		while (ptr)
		{
			while (ptr->next && ptr->n > ptr->next->n)
			{
				swap_node(ptr, ptr->next, list, &tail);
				swapped = 1;
				ptr = ptr->prev;
			}
			ptr = ptr->next;
		}
		if (!swapped)
			break;

		swapped = 0;
		ptr = tail;
		while (ptr)
		{
			while (ptr->prev && ptr->n < ptr->prev->n)
			{
				swap_node(ptr->prev, ptr, list, &tail);
				swapped = 1;
				ptr = ptr->next;
			}
			ptr = ptr->prev;
		}
	} while (swapped);
}
