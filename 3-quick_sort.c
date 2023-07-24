#include "sort.h"
/**
 * swap_it - Swap two integers in an array.
 * @x: first integer to swap.
 * @y: second integer to swap.
 */
void swap_it(int x, int y)
{
	int tmp;

	tmp = x;
	x = y;
	y = tmp;
}
/**
 * lomutoPartition - sorts pivot
 * @array: The array to sort
 * @start: The start index
 * @end: The end index
 * @size: The array size
 * Return: The index of the pivot
 */
size_t lomutoPartition(int *array, size_t start, size_t end, size_t size)
{
	int pivot = array[end], tmp;
	size_t i = start - 1, j;

	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;

			if (i != j)
			{
				/* swap */
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;

				print_array(array, size);
			}
		}
	}

	i++;
	if (array[i] > pivot)
	{
		tmp = array[i];
		array[i] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}

	return (i);
}
/**
 * sortLomuto - sorts an array using the quick sort algorithm
 * @array: The array to sort
 * @start: The start index
 * @end: The end index
 * @size: The array size
 */
void sortLomuto(int *array, int start, int end, size_t size)
{
	size_t pivot_index;

	/* base */
	if (end < start)
		return;

	pivot_index = lomutoPartition(array, start, end, size);
	
	sortLomuto(array, start, pivot_index - 1, size);
	sortLomuto(array, pivot_index + 1, end, size);
}
/**
 * quick_sort - sorts a list using the quick sort algotithm
 * @array: The array to  sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sortLomuto(array, 0, size - 1, size);
}
