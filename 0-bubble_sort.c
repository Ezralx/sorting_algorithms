#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using the modified
 *               bubble sort algorithm
 * @array: pointer to an array of integers
 * @size: size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	if (array == NULL || size == 0)
		return;
	for (i = 0; i < size; ++i)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; ++j)
			if (array[j] > array[j + 1])
			{
				swap(array + j, array + j + 1);
				swapped = true;
				print_array(array, size);
			}
		if (swapped == false)
			return;
	}
}

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
