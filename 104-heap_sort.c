#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t leftt, rightt, largee;

	leftt = 2 * root + 1;
	rightt = 2 * root + 2;
	largee = root;

	if (leftt < base && array[leftt] > array[largee])
		largee = leftt;
	if (rightt < base && array[rightt] > array[largee])
		largee = rightt;

	if (largee != root)
	{
		swap_ints(array + root, array + largee);
		print_array(array, size);
		max_heapify(array, size, base, largee);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int x;

	if (array == NULL || size < 2)
		return;

	for (x = (size / 2) - 1; x >= 0; x--)
		max_heapify(array, size, size, x);

	for (x = size - 1; x > 0; x--)
	{
		swap_ints(array, array + x);
		print_array(array, size);
		max_heapify(array, size, x, 0);
	}
}
