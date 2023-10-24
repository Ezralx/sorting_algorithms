#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 *              Shell sort algorithm, using the Knuth sequence.
 * @array: pointer to an array of integers
 * @size: size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t j, gap;
	int i, temp;

	if (array == NULL || size < 2)
		return;
	/* Find initial gap, using Knuth sequence */
	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;
	/* Sort the array, using the initial gap */
	while (gap > 0)
	{
		for (j = gap; j < size; ++j)
		{
			temp = array[j];
			for (i = j; i >= (int)gap && array[i - gap] > temp; i -= gap)
				array[i] = array[i - gap];
			array[i] = temp;
		}
		gap /= 3;
		print_array(array, size);
	}
}
