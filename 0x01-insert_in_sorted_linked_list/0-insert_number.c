#include<stdio.h>
#include<stdlib.h>
#include"lists.h"


/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to the linked list
 * @number: the value at the new node
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current;
	listint_t *new;

	if (!head)
		return (NULL);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);

	current = *head;
	new->n = number;
	new->next = NULL;

	if (!*head)
	{
		*head = new;
		return (new);
	}
	if (current->n > new->n)
	{
		new->next = *head;
		*head = new;
			return (new);
	}
	while (current)
	{
		if (current->next == NULL)
		{
		current->next = new;
			return (new);
		}
		if (current->next->n > new->n)
		{
			new->next = current->next;
			current->next = new;
				return (new);
		}
		current = current->next;
	}
	return (new);
}
