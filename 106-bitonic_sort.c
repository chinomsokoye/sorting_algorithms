#include "sort.h"

/**
 * bitonic_sort - Sorts an array of integers
 *
 * @array: The array
 * @size: The size of the @array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	bitonic_recursion(array, 0, size - 1, 1, size);
}

/**
 * bitonic_recursion - Function for bitonic sort
 *
 * @array: The array
 * @l: The left index
 * @r: The right index
 * @direction: Either asc or desc
 * @size: The size of the @array
 */
void bitonic_recursion(int *array, int l, int r, int direction, size_t size)
{
	int step;

	if (r - l >= 1)
	{
		step = (r + l) / 2;
		printf("Mergin [%d/%lu] ", r - l + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
		bitonic_recursion(array, l, step, 1, size);
		bitonic_recursion(array, step + 1, r, 0, size);
		bitonic_merge(array, l, r, direction);
		printf("Result [%d%lu] ", r - l + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
	}
}

/**
 * bitonic_merge - Function for bitonic sort
 *
 * @array: The array
 * @l: The index left
 * @r: The right index
 * @direction: Either asc or desc
 */
void bitonic_merge(int *array, int l, int r, int direction)
{
	int temp, x, step = (l + r) / 2, mid = (r - l + 1) / 2;

	if (r - l >= 1)
	{
		for (x = l; x < l + mid; x++)
		{
			if (direction == (array[x] > array[x + mid]))
			{
				temp = array[x + mid];
				array[x + mid] = array[x];
				array[x] = temp;
			}
		}
		bitonic_merge(array, l, step, direction);
		bitonic_merge(array, step + 1, r, direction);
	}
}
