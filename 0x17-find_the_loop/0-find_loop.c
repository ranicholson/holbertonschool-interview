#include "lists.h"

/**
 * find_listint_loop - function to find a loop in a linked list
 * @head: Head of list to check for loops
 * Return: Adress where loop starts or NULL if no loop found
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *loopSlow = head, *loopFast = head;

	while (loopSlow && loopFast && loopFast->next)
	{
		loopSlow = loopSlow->next;
		loopFast = loopFast->next->next;

		if (loopFast == head || loopSlow == head)
			return (head);

		if (loopSlow == loopFast)
		{
			head = head->next;
			loopFast = head;
			loopSlow = head;
		}
	}
	return (NULL);
}
