#include "sort.h"

/**
 * counting_sort - Sorts an integers of array
 *
 * @array: The array
 * @size: The size of the @array
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *out_array, max, numb, b, d;
	size_t a, c, e, f;

	if (size < 2)
		return;
	max = array[0];
	for (a = 1; a < size; a++)
		if (array[a] > max)
			max = array[a];
	count_array = malloc(sizeof(size_t) * (max + 1));
	out_array = malloc(sizeof(int) * size);
	for (b = 0; b <= max; b++)
		count_array[b] = 0;
	for (c = 0; c < size; c++)
	{
		numb = array[c];
		count_array[numb] += 1;
	}
	for (d = 1; d <= max; d++)
		count_array[d] += count_array[d - 1];
	print_array(count_array, max + 1);
	for (e = 0; e < size; e++)
	{
		out_array[count_array[array[e]] - 1] = array[e];
		count_array[array[e]]--;
	}
	for (f = 0; f < size; f++)
		array[f] = out_array[f];
	free(count_array);
	free(out_array);
}
