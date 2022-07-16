#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in asc using Selection sort
 *
 * @array: The array
 * @size: The size
 */
void selection_sort(int *array, size_t size)
{
	unsigned int x, y, min;

	register int temp;

	if (size < 2)
		return;
	for (x = 0; x < size; x++)
	{
		min = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[min])
				min = y;
		}
		temp = array[x];
		array[x] = array[min];
		array[min] = temp;
		if (x != min)
			print_array(array, size);
	}
}
