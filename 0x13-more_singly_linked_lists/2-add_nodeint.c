#include "lists.h"

/**
 * add_nodeint - new node will be added beginning of a linked list
 * @head: pointer to the first node
 * @n: data to insert in new node
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
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
