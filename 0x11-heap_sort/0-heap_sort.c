#include "sort.h"


/**
 * swap - swaps elements
 *
 * @i: first element
 * @j: second element
 */
void swap(int *i, int *j)
{
		int temp = *i;
		*i = *j;
		*j = temp;
}

/**
 * build_heap - builds heap out of array
 *
 * @array: The array
 * @i: heap size
 * @j: root index
 * @size: Number of elements in @array
 */
void build_heap(int *array, int m, int i, size_t size)
{
		int max = i;
		int left = i * 2 + 1;
		int right = i * 2 + 2;

		if (left < m && array[left] > array[max])
			max = left;

		if (right < m && array[right] > array[max])
			max = right;

		if (max != i)
		{
			swap(&array[i], &array[max]);
			print_array(array, size);
			build_heap(array, m, max, size);
		}
}

/**
 * heap_sort - heap sort function
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
		int i;

		for (i = size / 2 - 1; i >= 0; i--)
			build_heap(array, size, i, size);

		for (i = size - 1; i >= 0; i--)
		{
			swap(&array[0], &array[i]);
			if (i != 0)
				print_array(array, size);
			build_heap(array, i, 0, size);
		}
}
