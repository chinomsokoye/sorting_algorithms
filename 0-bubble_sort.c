#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted/printed
 * @size: Number of elements in the @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, new_size = size;
	int temp, swap;

	if (array == NULL || size < 2)
		return;
	while (new_size)
	{
		swap = 0;
		for (x = 0; x < new_size - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				temp = array[x + 1];
				array[x + 1] = array[x];
				array[x] = temp;
				print_array(array, size);
				swap = 1;
			}
		}
		new_size--;
		if (!swap)
			break;
	}
}
