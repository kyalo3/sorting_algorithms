#include "sort.h"
/**
 * swap_node_behind - Swaps a node with a node behind it
 * @list: Pointer to the head of the doubly linked list
 * @tail: Pointer to the tail of the double linked list
 * @shaker: Pointer to be swapped
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}
/**
 * swap_node_ahead- Swaps a node with a node ahead of it
 * @list: Pointer to the head of the doubly linked list
 * @tail: Pointer to the tail of the double linked list
 * @shaker: Pointer to be swapped
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}
/**
 * cocktail_sort_list -  a function that sorts a doubly linked list
 * of integers in ascending order using the Cocktail shaker sort algorithm
 * @list: Double linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;
	do {
		swapped = 0;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
		shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}
	} while (swapped);
}
