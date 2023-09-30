#include "sort.h"

void merge(int *array, int *left, int *right, size_t size);

/**
 * merge_sort - a function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid = size / 2, i;
	int *left = array;
	int *right = array + mid;

	if (size <= 1)
		return;

	merge_sort(left, mid);
	merge_sort(right, size - mid);

	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < mid; i++)
	{
		printf("%d", left[i]);
		if (i < mid - 1)
			printf(", ");
	}
	printf("\n");
	printf("[right]: ");
	for (i = 0; i < size - mid; i++)
	{
		printf("%d", right[i]);
		if (i < size - mid - 1)
			printf(", ");
	}
	printf("\n");

	merge(array, left, right, size);
}

/**
 * merge - merges two arrays together
 * @array: Destination of the merged arrays
 * @left: array to be merged
 * @right: array to be merged
 * @size: size of the final merged array
 */

void merge(int *array, int *left, int *right, size_t size)
{
	size_t left_size = size / 2;
	size_t right_size = size - left_size;
	size_t i = 0, j = 0, k = 0, m;
	int *temp = malloc(size * sizeof(int));

	if (temp == NULL)
	{
		return;
	}

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			temp[k] = left[i];
			i++;
		}
		else
		{
			temp[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		temp[k] = left[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		temp[k] = right[j];
		j++;
		k++;
	}

	for (k = 0; k < size; k++)
		array[k] = temp[k];

	printf("[Done]: ");
	for (m = 0; m < size; m++)
	{
		printf("%d", array[m]);
		if (m < size - 1)
			printf(", ");
	}
	printf("\n");
	free(temp);
}
