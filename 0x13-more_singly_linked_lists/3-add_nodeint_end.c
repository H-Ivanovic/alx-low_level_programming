#include "lists.h"

/**
 * add_nodeint_end- adds a new node at the end
 * @head:pointer
 * @n:integer
 *
 * Return:the address of the new element
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;

	*head = new;

	return (new);
}
