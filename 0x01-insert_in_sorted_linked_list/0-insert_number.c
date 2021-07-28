#include "lists.h"

/**
 * insert_node - insert node into singly linked list
 * @head: Start of list to insert node into
 * @number: number to store in node of list
 * Return: address of new node or NULL upon failure
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *currentNode, *newNode;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);
	newNode->n = number;
	newNode->next = NULL;

	if (*head == NULL)
	{
		newNode->next = NULL;
		*head = newNode;
		return (newNode);
	}
	currentNode = *head;
	if (currentNode->n > number)
	{
		*head = newNode;
		newNode->next = currentNode;
		return (newNode);
	}

	while (currentNode->next != NULL)
	{
		if (currentNode->next->n > number)
		{
			newNode->next = currentNode->next;
			currentNode->next = newNode;
			return (newNode);
		}
		currentNode = currentNode->next;
	}
	currentNode->next = newNode;
	return (newNode);
}
