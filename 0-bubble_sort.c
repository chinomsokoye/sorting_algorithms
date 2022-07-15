#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted/printed
 * @size: Number of elements in the @array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int x, y;
	int temp;

	if (size < 2)
		return;
	x = 0;
	y = 0;
	while (x < size)
	{
		while (y < size - x - 1)
		{
			if (array[y] > array[y + 1])
			{
				temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
				print_array(array, size);
			}
			y++;
		}
		x++;
	}
}
