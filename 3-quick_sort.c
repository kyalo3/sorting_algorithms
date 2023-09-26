#include "sort.h"
#include <stdbool.h>
#include <stdlib.h>

void swap(int *a, int *b);
int partition(int *array, int low, int high, size_t size);
void quicksort(int *array, int low, int high, size_t size);
bool array_changed(int *arr1, int *arr2, size_t size);

/**
 * array_changed - chexks whether swap happened
 * @tempArr: original version
 * @array: changed version
 * @size: size of the array
 * Return: true or false
*/
bool array_changed(int *tempArr, int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (tempArr[i] != array[i])
			return (true);
	}
	return (false);
}

/**
 * swap - swaps values in an array
 * @a: value 1 to be swapped
 * @b: value 2 to be swapped
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
/**
 * partition - partitions an array based on the pivot
 * @array: array or subarray to be partitioned
 * @low: index of the first element in the array or subarray
 * @high: index of the last element in the array or subarray
 * @size: size of the array
 * Return: Index of the new pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int j, pivot = array[high], lI = (low - 1);
	int *tempArr = malloc(size * sizeof(int));
	size_t i;
	bool arrayChanged;

	if (tempArr == NULL)
		return (high);
	for (i = 0; i < size; i++)
		tempArr[i] = array[i];

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			lI++;
			swap(&array[lI], &array[j]);
			arrayChanged = array_changed(tempArr, array, size);
			if (arrayChanged)
				print_array(array, size);
		}
	}
	swap(&array[lI + 1], &array[j]);
	arrayChanged = array_changed(tempArr, array, size);
	if (arrayChanged)
		print_array(array, size);
	free(tempArr);
	return (lI + 1);
}


/**
 * quicksort - Quick sort algorithm to sort array and subarrays
 * @array: array or subarray to be sorted
 * @low: index of the first element in the array or subarray
 * @high: index of the last element 0f the array or subarray
 * @size: size of array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivotIndex;

	if (low < high)
	{
		pivotIndex = partition(array, low, high, size);
		quicksort(array, low, pivotIndex - 1, size);
		quicksort(array, pivotIndex + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers using the quick sort algorithm
 * @array: array to be sorted
 * @size: size of array to be sorted
 */

void quick_sort(int *array, size_t size)
{
	int low = 0;
	int high = size - 1;

	if (array == NULL || size <= 1)
		return;
	quicksort(array, low, high, size);
}
