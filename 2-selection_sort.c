#include "sort.h"

/**
* selection_sort - Sorts an array of integers in ascending order
* using the Selection Sort algorithm.
* @array: A pointer to the first element of the array to be sorted.
* @size: The number of elements in the array.
* Return: No return value.
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;
	/*size = n;*/

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;

			print_array(array, size);
		}
	}
}
