#include "sort.h"

/**
 * merge_sort - Sort an array of integers
 *
 * @array: The array
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *arr;

	if (!array || size < 2)
		return;
	arr = malloc(sizeof(int) * size);
	merge_recursion(arr, array, 0, size);
	free(arr);
}

/**
 * merge_recursion - Merge array function
 * @arr: array
 * @array: The array
 * @left: The left index
 * @right: The right index
 */
void merge_recursion(int *arr, int *array, size_t left, size_t right)
{
	size_t middle;

	if (right - left > 1)
	{
		middle = (right - left) / 2 + left;
		merge_recursion(arr, array, left, middle);
		merge_recursion(arr, array, middle, right);
		merge_subarray(arr, array, left, middle, right);
	}
}

/**
 * merge_subarray - Function to merge subarray
 *
 * @arr: array
 * @array: The array
 * @left: The left index
 * @middle: The middle index
 * @right: The right index
 */
void merge_subarray(int *arr, int *array, size_t left,
		    size_t middle, size_t right)
{
	size_t a, b, c = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, middle - left);
	printf("[right]: ");
	print_array(array + middle, right - middle);
	for (a = left, b = middle; a < middle && b < right; c++)
	{
		if (array[a] < array[b])
			arr[c] = array[a++];
		else
			arr[c] = array[b++];
	}
	while (a < middle)
		arr[c++] = array[a++];
	while (b < right)
		arr[c++] = array[b++];
	for (c = left, a = 0; c < right; c++)
		array[c] = arr[a++];
	printf("[Done]: ");
	print_array(array + left, right - left);
}
