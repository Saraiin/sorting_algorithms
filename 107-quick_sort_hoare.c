#include "sort.h"


/**
 * hoare_devide - sorts pivot
 * @array: array to sort
 * @start: start index
 * @end: end index
 * @size: size of array
 * Return: index of pivot
 */
size_t hoare_devide(int *array, size_t start, size_t end, size_t size)
{
	int pivot = array[end], tmp;
	size_t i = end + 1, j = start - 1;

	while (1)
	{
		do {
			i--;
		} while (array[i] > pivot);

		do {
			j++;
		} while (array[j] < pivot);

		if (i <= j)
			return (j);

		tmp = array[j];
		array[j] = array[i];
		array[i] = tmp;
		print_array(array, size);
	}
}
/**
 * sortHoare - sorts an array using the quick sort algorithm
 * @array: The array to sort
 * @start: The start index
 * @end: The end index
 * @size: The array size
 */
void sortHoare(int *array, int start, int end, size_t size)
{
	size_t pivot_index;

	if (start >= end)
		return;

	pivot_index = hoare_devide(array, start, end, size);
	sortHoare(array, start, pivot_index - 1, size);
	sortHoare(array, pivot_index, end, size);
}

/**
 * quick_sort_hoare - sorts a list using the quick sort algotithm
 * @array: The array to  sort
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2 || !array)
		return;

	sortHoare(array, 0, size - 1, size);
}
