#include "sort.h"

/**
 * bubble_sort - sort an array by using the Bubble algorithm
 * @array: the giving array to sorted
 * @size: the array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, bubble;

	if (array == NULL || size < 2)
		return;
	for (i = 0, bubble = 1; i < size && bubble; i++)
	{
		bubble = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
				bubble = 1;
			}
		}
	}

}
