#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in asc using Selection sort
 *
 * @array: The array
 * @size: The size
 */
void selection_sort(int *array, size_t size)
{
	int idx = 0, minn, temp;
	size_t x, y;

	if (array == NULL || size < 2)
		return;
	for (x = 0; x < size - 1; x++)
	{
		minn = array[x];
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < minn)
			{
				minn = array[y];
				idx = y;
			}
			if (minn != array[x])
			{
				temp = array[x];
				array[x] = array[idx];
				array[idx] = temp;
				print_array(array, size);
			}
		}
	}
}
