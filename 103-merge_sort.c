#include "sort.h"

/**
 * merge - Merges two sorted sub-arrays into a single sorted array.
 * @array: The integer array containing the merged result.
 * @left: The left sub-array to be merged.
 * @right: The right sub-array to be merged.
 * @leftSize: The size of the left sub-array.
 * @rightSize: The size of the right sub-array.
 *
 * This function takes two sorted sub-arrays
 * (left and right) and merges them
 */
void merge(int *array, int *left, int *right,
size_t leftSize, size_t rightSize)
{
	size_t i = 0, j = 0, k = 0;

	while (i < leftSize && j < rightSize)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < leftSize)
		array[k++] = left[i++];
	while (j < rightSize)
		array[k++] = right[j++];
}

/**
 * merge_sort_helper - Recursively sorts a portion of an integer
 * array using the merge sort algorithm.
 * @array: The integer array to be sorted.
 * @temp: A temporary integer array for merging sub-arrays.
 * @left: The starting index of the portion to be sorted.
 * @right: The ending index of the portion to be sorted.
 *
 * This function sorts a portion of the given array
 * using the merge sort algorithm.
 */
void merge_sort_helper(int *array, int *temp, size_t left, size_t right)
{
	size_t mid, i;

	if (left < right)
	{
		mid = left + (right - left) / 2;

		merge_sort_helper(array, temp, left, mid);
		merge_sort_helper(array, temp, mid + 1, right);
		merge(temp + left, array + left, array + mid + 1,
				mid - left + 1, right - mid);
		for (i = left; i <= right; i++)
			array[i] = temp[i];

		printf("Merging...\n");
		printf("[left]: ");
		for (i = left; i <= mid; i++)
		{
			printf("%d", array[i]);
			if (i < mid)
				printf(", ");
		}
		printf("\n[right]: ");
		for (i = mid + 1; i <= right; i++)
		{
			printf("%d", array[i]);
			if (i < right)
				printf(", ");
		}
		printf("\n[Done]: ");
		for (i = left; i <= right; i++)
		{
			printf("%d", array[i]);
			if (i < right)
				printf(", ");
		}
		printf("\n");
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
