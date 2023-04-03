#include "lists.h"

/**
 * free_listint - linked list will be freed
 * @head: listint_t list to be freed
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	for (temp = head; head != NULL; temp = head)
	{
		head = head->next;
		free(temp);
	}
}
