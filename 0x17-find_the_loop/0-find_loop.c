#include "lists.h"

/**
 * find_listint_loop - function to find a loop in a linked list
 * @head: Head of list to check for loops
 * Return: Adress where loop starts or NULL if no loop found
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *loopStart = head, *loopCheck = NULL;

	while (!loopStart)
	{
		loopCheck = loopStart;
		loopStart = loopCheck->next;

		while (!loopStart)
		{
			if (loopCheck == loopStart)
				return (loopCheck);

			loopStart = loopStart->next;
		}

		loopStart = loopCheck->next;
	}

	return (NULL);
}
