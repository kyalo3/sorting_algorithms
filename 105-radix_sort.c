#include "sort.h"

/**
 * findMax - finds the maximum number in an array
 * @arr: The array with numbers
 * @size: size of the array
 * Return: The largest int
 */
int findMax(int *arr, size_t size)
{
	int max = arr[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return (max);
}

/**
 * countingSort - perform counting sort based on the digit represented by exp
 * @arr: array to be sorted
 * @size: size of array
 * @exp: exponent of the radix base
 */
void countingSort(int *arr, int size, int exp)
{
	int *output;
	int i;
	int count[10] = {0};

	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		exit(1);
	}

	for (i = 0; i < size; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = (size - 1); i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		arr[i] = output[i];
}
/**
 * radix_sort -  a function that sorts an array of integers in
 * ascending order using the Radix sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;
	size_t i;

	max = findMax(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
		for (i = 0; i < size; i++)
		{
			printf("%d", array[i]);
			if (i < (size - 1))
				printf(" ,");
		}
		printf("\n");
	}
}
