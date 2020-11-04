#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * bisearch - recursive function to build a tree
 * @array: pointer to array
 * @start: pointer to start
 * @end: pointer to end
 * @parent: parent node
 *
 * Return: pointer to header node
 **/
avl_t *bisearch(int *array, int start, int end, avl_t *parent)
{
		int mid;
		avl_t *node;

	    if (start > end)
		    return (NULL);
	
        mid = (start + end) / 2;
	    node = malloc(sizeof(avl_t));

        if (!node)
			return (NULL);
		node->n = array[mid];
		node->parent = parent;
		node->left = bisearch(array, start, mid - 1, node);
		node->right = bisearch(array, mid + 1, end, node);
		return (node);
}


/**
 * sorted_array_to_avl - builds a tree out of sorted array
 * @array: pointer to array
 * @size: size of the array
 *
 * Return: calls helper function
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
		if (!array)
			return (NULL);
		return (bisearch(array, 0, size - 1, NULL));
}