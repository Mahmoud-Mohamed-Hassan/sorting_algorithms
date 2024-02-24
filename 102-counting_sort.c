#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int maxx, i;

	for (maxx = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maxx)
			maxx = array[i];
	}

	return (maxx);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *countt, *sortedd, max, i;

	if (array == NULL || size < 2)
		return;

	sortedd = malloc(sizeof(int) * size);
	if (sortedd == NULL)
		return;
	max = get_max(array, size);
	countt = malloc(sizeof(int) * (max + 1));
	if (countt == NULL)
	{
		free(sortedd);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		countt[i] = 0;
	for (i = 0; i < (int)size; i++)
		countt[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		countt[i] += countt[i - 1];
	print_array(countt, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sortedd[countt[array[i]] - 1] = array[i];
		countt[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sortedd[i];

	free(sortedd);
	free(countt);
}
