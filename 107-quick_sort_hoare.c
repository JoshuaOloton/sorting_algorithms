#include "sort.h"

/**
* swap - the positions of two elements into an array
* @array: array to be sorted
* @item1: array element
* @item2: array element
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int temp;

	temp = array[item1];
	array[item1] = array[item2];
	array[item2] = temp;
}

/**
 * hoare_partition - hoare partition sorting scheme implementation
 * @array: array
 * @first: first array element
 * @last: last array element
 * @size: size array
 * Return: return the position of the last element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int pivot = array[last];

	while (1)
	{

		do {
			current++;
		} while (array[current] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current >= finder)
			return (current);
		swap(array, current, finder);
		print_array(array, size);
	}
}

/**
 * quicksort - qucksort algorithm implementation
 * @array: array to be sorted
 * @first: first element
 * @last: last element
 * @size: array size
 */
void quicksort(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t pos = 0;

	if (first < last)
	{
		pos = hoare_partition(array, first, last, size);
		quicksort(array, first, pos - 1, size);
		quicksort(array, pos, last, size);
	}
}

/**
 * quick_sort_hoare - prepare the terrain to quicksort algorithm
 * @array: array to be sorted
 * @size: size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
