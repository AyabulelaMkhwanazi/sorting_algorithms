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
