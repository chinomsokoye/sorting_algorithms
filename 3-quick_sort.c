#include "sort.h"

/**
 * quick_sort - Sort an array of integers using Quick sort
 *
 * @array: The array
 * @size: The number of size of @array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quick_recursion(array, 0, (int)size - 1, size);
}

/**
 * quick_recursion - Quick sort function
 *
 * @array: The array
 * @left: Left index element
 * @right: Right index element
 * @size: The size of @array
 */
void quick_recursion(int *array, int left, int right, size_t size)
{
	int qst;

	if (left < right)
	{
		qst = partition(array, left, right, size);
		quick_recursion(array, left, qst - 1, size);
		quick_recursion(array, qst + 1, right, size);
	}
}

/**
 * partition - Qst index for Quick sort
 *
 * @array: The array
 * @left: Left index element
 * @right: Right index element
 * @size: The size of @array
 * Return: index
 */
int partition(int *array, int left, int right, size_t size)
{
	int temp, x;
	int y;

	x = left - 1;

	for (y = left; y < right; y++)
	{
		if (array[y] < array[right])
		{
			x++;
			if (x != y)
			{
				temp = array[x];
				array[x] = array[y];
				array[y] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[right] < array[x + 1])
	{
		temp = array[x + 1];
		array[x + 1] = array[right];
		array[right] = temp;
		print_array(array, size);
	}
	return (x + 1);
}
