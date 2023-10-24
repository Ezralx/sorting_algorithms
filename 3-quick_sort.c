#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	if (a != NULL && b != NULL)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

/**
 * partition - sorts a portion of an array and divides it into partitions
 * @array: pointer to an array of integers
 * @start: start location of the next recursion
 * @end: end location of the next recursion
 *
 * Return: the pivot index
 */
int partition(int *array, int start, int end)
{
	int i = start - 1, j, pivot = array[end];

	for (j = start; j <= end; ++j)
		if (array[j] < pivot)
		{
			++i;
			swap(array + i, array + j);
		}
	++i;
	swap(array + i, array + end); /* put pivot on solid position */
	return (i);
}

/**
 * recursive_quick_sort - implement quick sort recursively by assigning
 *                        the last element as a pivot, as per the `Lomuto`
 *                        partition scheme.
 * @array: pointer to an array of integers
 * @size: size of the array
 * @start: start location of the next recursion
 * @end: end location of the next recursion
 *
 * Return: void
 */
void recursive_quick_sort(int *array, size_t size, int start, int end)
{
	int pivot;

	if (start >= end || start < 0)
		return;
	pivot = partition(array, start, end);
	print_array(array, size);
	recursive_quick_sort(array, size, start, pivot - 1);
	recursive_quick_sort(array, size, pivot + 1, end);
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 *              Quick sort algorithm.
 * @array: pointer to an array of integers
 * @size: size of the array
 *
 * Return: void
 * Description: The `Lomuto` partition scheme is implemented.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return;
	recursive_quick_sort(array, size, 0, size - 1);
}
