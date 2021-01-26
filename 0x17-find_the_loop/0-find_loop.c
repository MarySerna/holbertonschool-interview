#include "lists.h"

/**
* find_listint_loop - checks if a linked list has a cycle
* @head: pointer to a linked list
*
* Return: NULL if false or
* the pointer to the head of the loop
**/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *i = head;
	listint_t *j = head;

	if (!head)
		return (NULL);
	while (i->next && j->next->next)
	{
		i = i->next;
		j = j->next->next;
		if (i == j)
		{
			i = head;
			while (i != j)
			{
				i = i->next;
				j = j->next;
			}
			return (j);
		}
	}
	return (NULL);
}
