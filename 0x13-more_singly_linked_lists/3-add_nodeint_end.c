#include "lists.h"

/**
 * add_nodeint_end - node added at the end of a linked list
 * @head: pointer to the first element
 * @n: data to insert in the new element
 * Return: pointer to new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new = malloc(sizeof(listint_t));

	if (new == NULL)

	return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	listint_t *temp;

	for (temp = *head; temp->next != NULL; temp = temp->next)
	{
		/* Unused Loop Body */
	}

	temp->next = new;

	return (new);
}
