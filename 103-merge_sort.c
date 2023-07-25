#include "sort.h"
#include <stdio.h>

/**
 * merge - merge two sorted array
 * @array: array of integer.
 * @tmp: temporary array.
 * @left: start idx of subarray.
 * @mid: middle idx of array.
 * @right: end idx of subarray.
 */
void merge(int *array, int *tmp, int left, int mid, int right)
{
	int i, j, k = left;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left + 1);
	printf("[right]: ");
	print_array(array + mid + 1, right - mid);

	for (i = left, j = mid + 1; i <= mid && j <= right; k++)
	{
		if (array[i] <= array[j])
			tmp[k] = array[i++];
		else
			tmp[k] = array[j++];
	}
	while (j <= right)
		tmp[k++] = array[j++];
	while (i <= mid)
		tmp[k++] = array[i++];

	for (i = left; i <= right; i++)
		array[i] = tmp[i];

	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}

/**
 * merge_sort_recursive - separate array in one element
 * @array: array of integer.
 * @tmp: temporary array.
 * @left: start of subarray.
 * @right: end of subarray.
 */
void merge_sort_recursive(int *array, int *tmp, int left, int right)
{
	int mid;

	if (left >= right)
		return;
	mid = left + (right - left) / 2;
	if ((left + right) % 2 == 0)
		mid--;
	merge_sort_recursive(array, tmp, left, mid);
	merge_sort_recursive(array, tmp, mid + 1, right);
	merge(array, tmp, left, mid, right);
}
/**
 * merge_sort - sor array of integer in merge alogorithm.
 * @array: array of integer.
 * @size: size of array.
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;
	tmp = malloc(size * sizeof(int));
	if (!tmp)
		return;
	merge_sort_recursive(array, tmp, 0, size - 1);
	free(tmp);
}
