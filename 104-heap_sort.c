#include "sort.h"
/**
 * get_largest - gets the largest node index
 * @array: the giving array
 * @i: giving parent node index
 * @max:  max size of the tree
 * Return: largest node index
 */
int get_largest(int *array, int i, int max)
{
	int largest = i, left, right;

	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < max && array[left] > array[largest])
		largest = left;
	if (right < max && array[right] > array[largest])
		largest = right;
	return (largest);
}
/**
 * heapify - To heapify a subtree rooted with node i
 * @array: the giving array
 * @size: the array size
 * @i: the node i
 * @max: max tree length
 */
void heapify(int *array, size_t size, int i, int max)
{
	int largest, tmp;

	largest = get_largest(array, i, max);

	if (i != largest)
	{
		tmp = array[i];
		array[i] = array[largest];
		array[largest] = tmp;

		print_array(array, size);
		heapify(array, size, largest, max);
	}
}
/**
 * heap_sort - sorts an array by using heap sort
 * @array: the giving array
 * @size: the array size
 */
void heap_sort(int *array, size_t size)
{
	int k, tmp;

	if (size < 2 || !array)
		return;

	for (k = (size / 2) - 1; k >= 0; k--)
	{
		heapify(array, size, k, size);
	}
	for (k = size - 1; k > 0; k--)
	{
		/* Swap */
		tmp = array[k];
		array[k] = array[0];
		array[0] = tmp;

		print_array(array, size);
		heapify(array, size, 0, k);
	}
}
