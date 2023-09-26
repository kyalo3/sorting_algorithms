#include "sort.h"


/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the doubly linked list
 * @node1: Pointer to the first node to be swapped
 * @node2: Pointer to the second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (!node1 || !node2)
        return;
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
/**
 * cocktail_sort_list -  a function that sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 * @list: Double linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left, *right;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		left = *list;
		right = NULL;

		while (left->next != right)
		{
			if (left->n > left->next->n)
			{
				swap_nodes(list, left, left->next);
				print_list(*list);
				swapped = 1;
			}
			left = left->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		right = left;
		left = left->prev;

		while (right->prev != left)
		{
			if (right->n < right->prev->n)
			{
				swap_nodes(list, right->prev, right);
				print_list(*list);
				swapped = 1;
			}
			right = right->prev;
		}
	} while (swapped);
}
