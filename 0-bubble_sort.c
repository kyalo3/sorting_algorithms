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
	/*size_t i, j; // Declare loop variables here*/
	
    if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
				{
				/* Swap array[j] and array[j + 1] */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				swapped = 1; /* Set swapped flag */
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
		/* If no swaps were made in this pass, the array is sorted */
		if (!swapped)
		{
			break;
		}
	}
}
