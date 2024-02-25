#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}

/**
 * swap - helper function swaps 2 integers.
 *
 * @ptr1: pointer to the first number
 * @ptr2: pointer to the second number
 *
 * Return: void
*/
void swap(int *ptr1, int *ptr2)
{
	int tmp = *ptr1;

	*ptr1 = *ptr2;
	*ptr2 = tmp;
}
