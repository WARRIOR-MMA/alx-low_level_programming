#include "lists.h"

/**
 * insert_nodeint_at_index - inserts node at given position in listint_t list
 * @head: pointer to a pointer to the head of the list
 * @idx: index of the node where the new node should be added
 * @n: value to be added to the new node
 *
 * Return: address of the new node, or NULL if it failed to add the node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current;
	unsigned int i;

	if (head == NULL)
	return (NULL);

	if (idx == 0)
	return (add_nodeint(head, n));

		current = *head;

	for (i = 0; current != NULL && i < idx - 1; i++)
		current = current->next;

	if (current == NULL || current->next == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}
