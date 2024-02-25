#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
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
