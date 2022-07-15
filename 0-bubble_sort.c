#include "sort.h"

/**
 * bubble_sort - bubble sort algorithm function
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int temp, swapped;
	unsigned long int i;

	if (size < 2)
		return;
	do {
		swapped = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
	} while (swapped);
}
