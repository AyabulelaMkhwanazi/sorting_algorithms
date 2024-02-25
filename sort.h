#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* print_array.c */
void print_array(const int *array, size_t size);
void swap(int *ptr1, int *ptr2);

/* print_list.c */
void print_list(const listint_t *list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

/* 0-bubble_sort.c */
void bubble_sort(int *array, size_t size);

listint_t *create_listint(const int *array, size_t size);

/* 1-insertion_sort_list.c */
void insertion_sort_list(listint_t **list);

/* 2-selection_sort.c */
void selection_sort(int *array, size_t size);

/* 3-quick_sort.c */
void quick_sort(int *array, size_t size);
void quick_sort_helper(int *array, int start_idx, int end_idx);
int partition(int array[], int start_idx, int end_idx);
void swap(int *a, int *b);


#endif
