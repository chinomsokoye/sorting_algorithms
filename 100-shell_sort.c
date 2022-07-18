#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in asc using shell sort
 *
 * @array: The array
 * @size: Number of the size of the @array
 * Return: sorted array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 0, b, a;
	int temp;

	if (size < 2)
		return;
	while ((gap = gap * 3 + 1) < size)
		;
	gap = (gap - 1) / 3;
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (a = gap; a < size; a++)
		{
			temp = array[a];
			for (b = a; b >= gap && temp <=
				     array[b - gap]; b -= gap)
				array[b] = array[b - gap];
			array[b] = temp;
		}
		print_array(array, size);
	}
}
