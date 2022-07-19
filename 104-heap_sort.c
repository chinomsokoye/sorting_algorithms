#include "sort.h"

/**
 * heap_sort - Sort an array of integers
 *
 * @array: The array
 * @size: The size of the @array
 */
void heap_sort(int *array, size_t size)
{
	int x;
	int temp;

	if (size < 2)
		return;
	for (x = size / 2 - 1; x >= 0; x--)
		heapify(array, size, (size_t)x, size);
	for (x = size - 1; x >= 0; x--)
	{
		temp = array[x];
		array[x] = array[0];
		array[0] = temp;
		if (x != 0)
			print_array(array, size);
		heapify(array, (size_t)x, 0, size);
	}
}

/**
 * heapify - Function for array heap tree
 *
 * @array: The array
 * @s: The size
 * @root: The index of subtree
 * @size: The size
 */
void heapify(int *array, size_t s, size_t root, size_t size)
{
	size_t max, left, right;
	int temp;

	max = root;
	left = (root * 2) + 1;
	right = (root * 2) + 2;

	if (left  < s && array[left] > array[max])
		max = left;
	if (right < s && array[right] > array[max])
		max = right;
	if (max != root)
	{
		temp = array[root];
		array[root] = array[max];
		array[max] = temp;
		print_array(array, size);
		heapify(array, s, max, size);
	}
}
