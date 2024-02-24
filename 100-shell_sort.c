#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gapp, x, j;

	if (array == NULL || size < 2)
		return;

	for (gapp = 1; gapp < (size / 3);)
		gapp = gapp * 3 + 1;

	for (; gapp >= 1; gapp /= 3)
	{
		for (x = gapp; x < size; x++)
		{
			j = x;
			while (j >= gapp && array[j - gapp] > array[j])
			{
				swap_ints(array + j, array + (j - gapp));
				j -= gapp;
			}
		}
		print_array(array, size);
	}
}
