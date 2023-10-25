#include "sort.h"

/**
 * print_left_and_right - prints the left and right sub-arrays before merging.
 * @array: pointer to an array of integers
 * @left: left index
 * @mid: mid index
 * @right: right index
 *
 * Return: void
 */
void print_left_and_right(int *array, int left, int mid, int right)
{
	int i;

	printf("[left]: ");
	for (i = left; i <= mid; ++i)
	{
		printf("%d", array[i]);
		if (i < mid)
			printf(", ");
	}
	printf("\n[right]: ");
	for (i = mid + 1; i <= right; ++i)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * print_merged_array - prints the left and right sub-arrays after merging.
 * @array: pointer to an array of integers
 * @left: left index
 * @right: right index
 *
 * Return: void
 */
void print_merged_array(int *array, int left, int right)
{
	int i;

	printf("[Done]: ");
	for (i = left; i <= right; ++i)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * merge - merges two sorted sub-arrays in the ascending order
 * @array: pointer to an array of integers
 * @temp: pointer to a temporary memory allocation for merging
 * @left: left index
 * @mid: mid index
 * @right: right index
 *
 * Return: void
 */
void merge(int *array, int *temp, int left, int mid, int right)
{
	int i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right)
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	while (i <= mid)
		temp[k++] = array[i++];
	while (j <= right)
		temp[k++] = array[j++];
	for (i = left, k = 0; i <= right; ++i)
		array[i] = temp[k++];
}

/**
 * recursive_merge_sort - sorts the array using merge sort, recursively.
 * @array: pointer to an array of integers
 * @temp: pointer to a temporary memory allocation for merging
 * @left: left index
 * @right: right index
 *
 * Return: void
 * Description:
 *     - The left sub-array starts from left index to mid index
 *     - The right sub-array starts from mid + 1 index to right index
 */
void recursive_merge_sort(int *array, int *temp, int left, int right)
{
	int mid = (left + right) / 2;

	if (left >= right)
		return;
	/**
	 * Make sure the left sub-array is always smaller or equal
	 * than the right sub-array.
	 */
	if (mid - left + 1 > right - mid)
		--mid;

	recursive_merge_sort(array, temp, left, mid);
	recursive_merge_sort(array, temp, mid + 1, right);

	printf("Merging...\n");
	print_left_and_right(array, left, mid, right);
	merge(array, temp, left, mid, right);
	print_merged_array(array, left, right);

}

/**
 * merge_sort - Sort an array of integers in ascending order using the
 *              Merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	recursive_merge_sort(array, temp, 0, size - 1);
	free(temp);
}
