#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Insert node into sorted linked list
 *
 * @head: head of sorted linked list
 * @number: where to insert
 *
 * Return: Address of new node or NULL on failure
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *pointer;

	if (!head)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if (!*head)
	{
		*head = new;
		return (new);
	}
	pointer = *head;
	if (number < pointer->n)
	{
		new->next = pointer;
		*head = new;
		return (new);
	}
	while (pointer->next && number > pointer->next->n)
	{
		pointer = pointer->next;
	}
	new->next = pointer->next;
	pointer->next = new;
	return (new);
}
