#include "sort.h"

/**
 * radix_sort - Sorts an array of integers
 *
 * @array: The array
 * @size: The size of the @array
 */
void radix_sort(int *array, size_t size)
{
	int max;
	size_t x, lsd;

	if (!array || size < 2)
		return;
	max = 0;
	for (x = 0; x < size; x++)
		if (array[x] > max)
			max = array[x];
	for (lsd = 1; max / lsd > 0; lsd *= 10)
	{
		count_sort_LSD(array, size, lsd);
		print_array(array, size);
	}
}

/**
 * count_sort_LSD - Function for sorting LSD
 *
 * @array: The array to be sorted
 * @size: The size of the @array
 * @lsd: The lsd
 */
void count_sort_LSD(int *array, size_t size, size_t lsd)
{
	int count_array[10] = {0}, *out_array, b, c;
	size_t a, d;

	out_array = malloc(sizeof(int) * size);

	for (a = 0; a < size; a++)
		count_array[(array[a] / lsd) % 10]++;
	for (b = 1; b < 10; b++)
		count_array[b] +=  count_array[b - 1];
	for (c = size - 1; c >= 0; c--)
	{
		out_array[count_array[(array[c] / lsd) % 10] - 1] = array[c];
		count_array[(array[c] / lsd) % 10]--;
	}
	for (d = 0; d < size; d++)
		array[d] = out_array[d];
	free(out_array);
}
