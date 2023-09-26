#include "sort.h"
/**
 * swap_nodes - swaps nodes in a doubly linked list
 * @list: the double linked list
 * @node1: node to be swapped
 * @node2: node to be swapped
*/

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
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
 * insertion_sort_list - sorts a doubly linked list of integers in an
 * ascending order
 * @list: list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current->prev;
		while (temp && temp->n > current->n)
		{
			swap_nodes(list, temp, current);
			print_list(*list);
			temp = current->prev;
		}
		current = current->next;
	}
}
