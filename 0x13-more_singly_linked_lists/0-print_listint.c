#include "lists.h"

/**
 * print_listint - all elements of a linked list will be printed
 * @h: linked list of type listint_t to print
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	for (; h != NULL; h = h->next)
	{
		printf("%d\n", h->n);
		num++;
	}

	return (num);
}
