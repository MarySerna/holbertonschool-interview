#include "search_algos.h"


/**
 * print_array - prints an array
 * @left: first el of the array
 * @right: last el of the array
 **/
void print_array(int *array, size_t left, size_t right)
{
		printf("Searching in array: ");
		while (left < right)
		{
			printf("%i, ", array[left]);
			left++;
		}
		printf("%i\n", array[left]);
}

/**
 * recursive_bsearch - recursively searches for a value
 * in a sorted array of integers
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 *
 * Return:	the index or -1
 **/
int recursive_bsearch(int *array, int left, int right, int value)
{
		int mid;

		print_array(array, left, right);
		mid = (right - left) / 2 + left;
		if (left == right)
			return (-1);
		if (array[mid] == value && array[mid - 1] != value)
			return (mid);
		if (array[mid] >= value)
			return (recursive_bsearch(array, left, mid, value));
		if (array[mid] <= value)
			return (recursive_bsearch(array, mid + 1, right, value));
		return (-1);
}

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 *
 * Return:	the index or -1
 **/
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (recursive_bsearch(array, 0, size - 1, value));
}
