#include "lists.h"

/**
 * insert_node - insert node into singly linked list
 * @head: Start of list to insert node into
 * @number: number to store in node of list
 * Return: address of new node or NULL upon failure
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *currentNode = *head;
	listint_t *nextNode = currentNode->next;
	listint_t *newNode;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);
	newNode->n = number;

	if (!*head)
	{
		newNode->next = NULL;
		*head = newNode;
		return (newNode);
	}

	if (currentNode->n > number)
	{
		*head = newNode;
		newNode->next = currentNode;
		return (newNode);
	}

	while (nextNode->next != NULL)
	{
		if (currentNode->next->n < number && nextNode->next != NULL)
		{
			currentNode = nextNode;
			nextNode = currentNode->next;
			continue;
		}
		newNode->next = nextNode;
		currentNode->next = newNode;
		break;
	}
	return (newNode);
}
