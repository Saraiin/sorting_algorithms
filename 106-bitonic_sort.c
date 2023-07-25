#include "sort.h"


/**
 * upSort - sorts up an array
 * @array:  giving array
 * @start:  start index of the array
 * @end:  end index of the array
 */
void upSort(int *array, int start, int end)
{
	int low, tmp, i, j;

	for (i = start; i < end - 1; i++)
	{
		low = i;
		for (j = i + 1; j < end; j++)
			if (array[low] >  array[j])
				low = j;
		if (low != i)
		{
			tmp = array[i];
			array[i] = array[low];
			array[low] = tmp;
		}
	}
}
/**
 * downSort - sorts down an array
 * @array:  giving array
 * @start:  start index of the array
 * @end: end index of the array
 */
void downSort(int *array, int start, int end)
{
	int max, tmp, i, j;

	for (i = start; i < end - 1; i++)
	{
		max = i;
		for (j = i + 1; j < end; j++)
			if (array[max] <  array[j])
				max = j;
		if (max != i)
		{
			tmp = array[i];
			array[i] = array[max];
			array[max] = tmp;
		}
	}
}
/**
 * arrayInterval - prints array interval
 * @array: giving array
 * @start:  start index of the array
 * @end:  end index of the array
 */
void arrayInterval(int *array, int start, int end)
{
        int i;

        for (i = start; i < end; i++)
        {
                if (i != start)
                        printf(", ");
                printf("%d", array[i]);
        }
        printf("\n");
}

/**
 * bitonic_recursion - bitonic sort recursion
 * @array: the giving array
 * @start: the start index of the array
 * @end:  end index of the array
 * @dir:  sort direction
 * @size: size of the array
 */
void bitonic_recursion(int *array, int start, int end, char dir, size_t size)
{
	char *direction;

	if (end - start < 2)
		return;

	direction = (dir == 'U') ? "UP" : "DOWN";

	printf("Merging [%d/%ld] (%s):\n", end - start, size, direction);
	arrayInterval(array, start, end);

	if (end - start == 2)
		return;

	bitonic_recursion(array, start, (start + end) / 2, 'U', size);
	upSort(array, start, (start + end) / 2);
	printf("Result [%d/%ld] (%s):\n", (((end + start) / 2) - start), size, "UP");
	arrayInterval(array, start, (start + end) / 2);


	bitonic_recursion(array, (start + end) / 2, end, 'D', size);
	downSort(array, (start + end) / 2, end);
	printf("Result [%d/%ld] (%s):\n", (end - (end + start) / 2), size, "DOWN");
	arrayInterval(array, (start + end) / 2, end);
}

/**
 * bitonic_sort - sorts an array by using bitonic sort algorithm
 * @array: the giving array
 * @size: the size of the array
 */
void bitonic_sort(int *array, size_t size)
{

	if (size < 2 || !array)
		return;

	bitonic_recursion(array, 0, size, 'U', size);
	upSort(array, 0, size);
	printf("Result [%ld/%ld] (%s):\n", size, size, "UP");
	print_array(array, size);
}
