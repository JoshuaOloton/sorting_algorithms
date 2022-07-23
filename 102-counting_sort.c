#include "sort.h"

/**
 * counting_sort - counting sort algorithm
 * @array: array to be sorted
 * @size: array size
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j, k, l, m, n;
	int max, *count, *sorted;

	if (size < 2)
		return;
	max = 0;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * max + 1);
	if (count == NULL)
		return;
	for (j = 0; (int)j <= max; j++)
		count[j] = 0;
	for (k = 0; k < size; k++)
	{
		count[array[k]]++;
	}
	for (l = 1; (int)l <= max; l++)
		count[l] = count[l - 1] + count[l];
	print_array(count, max + 1);
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
	{
		free(count);
		return;
	}
	for (m = 0; m < size ; m++)
	{
		sorted[count[array[m]] - 1] = array[m];
		count[array[m]]--;
	}
	for (n = 0; n < size; n++)
	{
		array[n] = sorted[n];
	}
	free(count);
	free(sorted);
}
