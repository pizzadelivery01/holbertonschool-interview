#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * is_palindrome - checks if a linked list is a palindrome
 *
 * @head: head
 *
 * Return: 1 if palindrome, 0 otherwise
 */

int is_palindrome(listint_t **head)
{
	listint_t **top = NULL;
	listint_t *bot = NULL;
	int result = 0;

	if (!head)
                return (0);
        if (!*head)
                return (1);
	top = head;
	bot = *head;
	result = mover(top, bot);
	return (result);
}

/**
 * mover - Recursive function to check a linked list for palindromeness
 *
 * @top: top value to check
 * @bot: bottom value to check
 *
 * Return: 1 or 0;
 */

int mover(listint_t **top, listint_t *bot)
{
	int result = -1;
	int output = -1;

	if (bot == NULL)
		return (1);
	result = mover(top, bot->next);
	if (result == 0)
		return (0);
	if ((*top)->n == bot->n)
		output = 1;
	else
		output = 0;
	*top = (*top)->next;
	return (output);

}