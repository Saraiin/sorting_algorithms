#include "sort.h"

/**
 * shell_sort - sorting an array by using shell sort
 * @array: the giving array
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t pas = 1, i, j;
	int tmp;

	while (pas < size)
	{
		pas = (pas * 3) + 1;
	}
	while ((pas = (pas - 1) / 3) > 0)
	{
		for (i = 0; i + pas < size; i++)
		{
			for (j = i + pas; (int)(j - pas) >= 0; j = j - pas)
			{
				if (array[j] < array[j -pas])
				{
					tmp = array[j];
					array[j] = array[j - pas];
					array[j - pas] = tmp;
				}
			}
		}
		print_array(array, size);
	}
}
