#include <stddef.h>
#include "lists.h"

/**
 * is_palindrome - checks if a linked list is a palindrome
 * @head: Head of list to check.
 * Return: 1 if it is a palindrome, otherwise 0.
 */

int is_palindrome(listint_t **head)
{
	listint_t *listCycler = *head;
	int listCount = 0;
	int listArray[1000];

	if (listCycler == NULL)
		return (1);

	while (listCycler)
	{
		listArray[listCount] = listCycler->n;
		listCycler = listCycler->next;
		listCount++;
	}

	listCycler = *head;

	while (listCycler)
	{
		if (listCycler->n != listArray[listCount - 1])
			return (0);

		listCount--;
		listCycler = listCycler->next;
	}

	return (1);
}
