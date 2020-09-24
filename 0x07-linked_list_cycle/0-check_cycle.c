#include "lists.h"

/**
 * check_cycle - checks for a loop in linked list
 * @list: pointer to the head of the list
 * Return: 1 if loop found, else false
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = list, *fast = list;

	if (!list)
		return (0);
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}
