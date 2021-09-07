#include "lists.h"


/**
 * check_cycle - checks if linked list contains a cycle.
 * @list: linked list to check
 * Return: 0 if there is no cycle or 1 if there is.
*/

int check_cycle(listint_t *list)
{
	listint_t *steadyChecker = list;
	listint_t *speedyChecker = list->next;

	if (list == NULL || list->next == NULL)
		return (0);

	while (speedyChecker->next != NULL)
	{
		speedyChecker = speedyChecker->next;

		if (speedyChecker->next != NULL)
			speedyChecker = speedyChecker->next;

		steadyChecker = steadyChecker->next;

		if (steadyChecker == speedyChecker)
			return (1);
	}

	return (0);
}
