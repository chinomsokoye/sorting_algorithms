#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers
 *
 * @array: The array
 * @size: The size of the @array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size > 2)
		return;
	quick_recursion(array, 0, (int)size - 1, size);
}

/**
 * quick_recursion - Function for quick sort
 *
 * @array: The array
 * @left: Left index
 * @right: Right index
 * @size: The @array size
 */
void quick_recursion(int *array, int left, int right, size_t size)
{
	int civ;

	if (left < right)
	{
		civ = partition(array, left, right, size);
		quick_recursion(array, left, civ - 1, size);
		quick_recursion(array, civ, right, size);
	}
}

/**
 * partition - Function for quick sort
 *
 * @array: The array
 * @left: Left index
 * @right: Right index
 * @size: The @array size
 * Return: index civ
 */
int partition(int *array, int left, int right, size_t size)
{
	int temp, civot = array[right];
	size_t a, b;

	a = left - 1;
	b = right + 1;
	while (1)
	{
		do {
			a++;
		} while (array[a] < civot);
		do {
			b--;
		} while (array[b] > civot);
		if (a >= b)
			return (a);
		if (a != b)
		{
			temp = array[a];
			array[a] = array[b];
			array[b] = temp;
			print_array(array, size);
		}
	}
	return (0);
}
