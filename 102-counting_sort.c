#include "sort.h"

/**
 * find_max - finds the maximum integers from the array
 * @array: pointer to an array of integers
 * @size: size of the array
 *
 * Return: maximum integer
 */
int find_max(int *array, size_t size)
{
	int i = 0, max_num = 0;

	for (i = 0; (size_t)i < size; ++i)
		if (array[i] > max_num)
			max_num = array[i];
	return (max_num);
}

/**
 * counting_sort - sorts an array of integers in ascending order using
 *                 the Counting sort algorithm
 * @array: pointer to an array of integers
 * @size: size of the array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int i, k, *counts, *sorted_array;

	if (array == NULL || size < 2)
		return;
	k = find_max(array, size);
	counts = malloc(sizeof(int) * (k + 1));
	if (counts == NULL)
		return;
	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
		return;
	/* Initialize to zero */
	for (i = 0; i < k + 1; ++i)
		counts[i] = 0;
	/* Get the counts */
	for (i = 0; (size_t)i < size; ++i)
		++counts[array[i]];
	/* Get the positions */
	for (i = 1; i <= k; ++i)
		counts[i] += counts[i - 1];
	/* Print the prepared counts */
	print_array(counts, k + 1);
	/* Sort the array based on the counts */
	for (i = size - 1; i >= 0; --i)
		sorted_array[--counts[array[i]]] = array[i];
	/* Copy sorted array to original array */
	for (i = 0; (size_t)i < size; ++i)
		array[i] = sorted_array[i];
	/* Free memory */
	free(counts);
	free(sorted_array);
}
