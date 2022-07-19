#include "sort.h"

/**
 * selection_sort - selection sort algorithm function
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int temp, swapped, min, index;
	unsigned long int i, j;

	if (size < 2 || array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		min = array[i];
		swapped = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				index = j;
				min = array[j];
				swapped = 1;
			}
		}
		if (swapped)
		{
			temp = array[i];
			array[i] = array[index];
			array[index] = temp;
			print_array(array, size);
		}
	}
}
