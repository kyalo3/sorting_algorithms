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
	size_t i, j, k;

	if (array == NULL) /*to check if array is null*/
		return;

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

				swapped = 1;
				for (k = 0; k < size; k++)
				{
					if (k == size - 1)
					{
						printf("%d", array[k]);
					}
					else
					{
						printf("%d, ", array[k]);
					}
				}
				printf("\n");
			}

		}
		if (swapped == 0)
		{
			break;
		}
	}
}
