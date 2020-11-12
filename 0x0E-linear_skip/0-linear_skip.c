#include "search.h"


/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the list
 * @value: the value to search for
 *
 * Return: NULL or a pointer to the node with the value
 **/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
		skiplist_t *skip;

		if (!list)
			return (NULL);
		skip = list;
		while (skip->express)
		{
			printf("Value checked at index [%lu] = [%d]\n",
				skip->express->index, skip->express->n);
			if (skip->express->n >= value)
			{
				printf("Value found between indexes [%lu] and [%lu]\n",
					skip->index, skip->express->index);
				break;
			}
			skip = skip->express;
		}
		if (!skip->express)
		{
			list = skip;
			while (list->next)
				list = list->next;
			printf("Value found between indexes [%lu] and [%lu]\n",
				skip->index, list->index);
		}
		list = skip;
		while (list != skip->express)
		{
			printf("Value checked at index [%lu] = [%d]\n",
				list->index, list->n);
			if (list->n == value)
				break;
			list = list->next;
		}
		if (list != skip->express)
			return (list);
		return (NULL);
}
