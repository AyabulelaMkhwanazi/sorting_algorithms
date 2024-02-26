#include "sort.h"

/**
 * shell_sort - function sorts an array of integers
 *				in ascending order
 *				using 'Shell sort' algorithm, using
 *				using the 'Knuth sequence'.
 *
 * @array: pointer to the array of integers to sort.
 * @size: the size of the array of integers to sort.
 *
 * Return: void.
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int tmp;

	/* Calculate the largest Knuth sequence samller than size */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		/**
		 * iterate over each element starting from the
		 * gap index
		 */
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			/**
			 * iterate over the array backwards starting
			 * from current index, decrementing by the gap size
			 */
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			/**
			 * insert the temporary variable into its correct
			 * position in the array
			 */
			if (j < size)  /* ensure j is not less than gap */
			{
				array[j] = tmp;
			}
		}
		/* print the array each time you decrease the interval */
		print_array(array, size);
		/* decrease the gap size by dividing it by 3 */
		gap /= 3;
	}
}
