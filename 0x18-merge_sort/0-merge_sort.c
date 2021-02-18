#include "sort.h"

/**
 * merge - merges the copied array into the original one
 * @array: array of integers to sort (the one being updated)
 * @subarray: copy of the array to sort
 * @left: left-most index indicating beginning of array;
 * @right: right-most index indication end of array;
 * @mid: half point between left and right indexes
 */
void merge(int *array, int *subarray, int left, int right, int mid)
{
	int start, end, i = left;

	start = left;
	end = mid;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(subarray + left, mid - left);
	printf("[right]: ");
	print_array(subarray + mid, right - mid);
	while (start < mid && end < right)
	{
		if (subarray[start] < subarray[end])
		{
			array[i] = subarray[start];
			start++;
		} else
		{
			array[i] = subarray[end];
			end++;
		}
		i++;
	}
	while (start < mid)
	{
		array[i] = subarray[start];
		i++;
		start++;
	}
	while (end <= right)
	{
		array[i] = subarray[end];
		i++;
		end++;
	}
	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_split - recursively splits an array in half and calls merge()
 * @array: array to sort
 * @subarray: copy of the array to sort
 * @left: left-most index indicating the beggining of the array
 * @right: right-most index indicating the end of the array
 */
void merge_split(int *array, int *subarray, int left, int right)
{
	int mid = left + (right - left) / 2;

	if (right - left <= 1)
		return;

	merge_split(subarray, array, left, mid);
	merge_split(subarray, array, mid, right);
	merge(array, subarray, left, right, mid);
}

/**
 * merge_sort - sorts an array by implementing top down merge sort.
 * @array: array of integers to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *subarray;
	size_t i = 0;

	if (!array || size < 2)
		return;

	subarray = malloc(size * sizeof(int));
	if (!subarray)
		return;
	for (; i < size; i++)
		subarray[i] = array[i];

	merge_split(array, subarray, 0, size);
	free(subarray);
}
