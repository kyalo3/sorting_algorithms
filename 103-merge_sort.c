#include "sort.h"


void merge(int *array, int *left, int *right, size_t leftSize, size_t rightSize)
{
    size_t i = 0, j = 0, k = 0;

    printf("Merging...\n");
    printf("[left]: ");
    for (i = 0; i < leftSize; i++)
    {
    	if (i < leftSize - 1)
		printf("%d, ", left[i]);
	else
		printf("%d\n", left[i]);
    }
    printf("[right]: ");
    for (i = 0; i < rightSize; i++)
    {
        if (i < rightSize - 1)
                printf("%d, ", right[i]);
        else
                printf("%d\n", right[i]);
    }
	i = 0;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            array[k++] = left[i++];
        } else {
            array[k++] = right[j++];
        }
    }

    // Copy the remaining elements from left and right back into array if any
    while (i < leftSize) {
        array[k++] = left[i++];
    }

    while (j < rightSize) {
        array[k++] = right[j++];
    }
    printf("[Done]: ");
    for (i = 0; i < rightSize + leftSize; i++)
    {
        if (i < rightSize + leftSize - 1)
                printf("%d, ", array[i]);
        else
                printf("%d\n", array[i]);
    }
}

void merge_sort_helper(int *array, int *temp, size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;

        merge_sort_helper(array, temp, left, mid);
        merge_sort_helper(array, temp, mid + 1, right);

       
        merge(temp + left, array + left, array + mid + 1, mid - left + 1, right - mid);

        for (size_t i = left; i <= right; i++) {
            array[i] = temp[i];
        }
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the arra to be sorted
 */
void merge_sort(int *array, size_t size)
{
	int *temp = malloc(size * sizeof(int));

	if (temp == NULL)
	{
		fprintf(stderr, "Memory allocation failed.\n");
        	exit(1);
	}

    merge_sort_helper(array, temp, 0, size - 1);
	free(temp);
}
