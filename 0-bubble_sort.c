#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The number of elements in the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int swapped, temp;
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{

				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swapped = 1;
				printf("\n");
			}

		}

		if (!swapped)
		{
			break;
		}
	}
}
