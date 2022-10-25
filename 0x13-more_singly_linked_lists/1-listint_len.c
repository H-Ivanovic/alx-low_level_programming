#include "lists.h"

/**
 * listint_len-returns the number of elements
 * @h:pointer
 *
 * Return:number of elememts
 */
size_t listint_len(const listint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		nodes++;
		h = h->next;
	}

	return (nodes);
}

