
#include "sort.h"

void bubble_sort(int *array, size_t size)
{
    int swapped;
	/*size_t i, j; // Declare loop variables here*/

    for (size_t i = 0; i < size - 1; i++)
	{
        swapped = 0;

        for (size_t j = 0; j < size - 1 - i; j++)
		{
            if (array[j] > array[j + 1])
				{
                /* Swap array[j] and array[j + 1] */
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                swapped = 1; /* Set swapped flag */
				for (size_t k = 0; k < size; k++)
				{
					if (k == size -1)
					{
						printf("%d", array[k]);
					}
					else {
						printf("%d, ", array[k]);
					}
				}
				printf("\n");
            }

		}
		/*printf("%d, ", array[i], array[j]);*/
        /* If no swaps were made in this pass, the array is sorted */
        if (!swapped)
		{
            break;
        }
    }
}
