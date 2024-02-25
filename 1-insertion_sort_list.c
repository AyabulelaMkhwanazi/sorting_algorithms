#include "sort.h"

/**
 * insertion_sort_list - function sorts a doubly linked list of
 *                      integers in ascending
 *                      order using the 'Insertion sort' algorithm.
 *
 * @list: pointer to pointer to the doubly linked list.
 *
 * Return: void.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (!list || !*list)
	{
		return;
	}

	current = (*list)->next;
	while (current)
	{
		tmp = current;
		current = current->next;
		while (tmp->prev && tmp->prev->n > tmp->n)
		{
			swap_nodes(list, tmp->prev, tmp);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swap_nodes - helper function that swaps 2 nodes of a doubly
 *              linked list.
 *
 * @list: pointer to pointer to the doubly linked list.
 * @node1: pointer to the first node.
 * @node2: pointer to the second node.
 *
 * Return: void.
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
	{
		node1->prev->next = node2;
	}
	if  (node2->next)
	{
		node2->next->prev = node1;
	}

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (!node2->prev)
	{
		*list = node2;
	}
}
