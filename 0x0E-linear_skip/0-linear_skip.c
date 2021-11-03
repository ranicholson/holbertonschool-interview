#include "search.h"

/**
 * linear_skip - function to search skip list
 * @list: list to search
 * @value: value to search for
 * Return: Pointer to node where value is located or NULL if something is off
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *sL = list;
	skiplist_t *eL = list->express;
	int foundFlag = 0, expressFlag = 0;

	if (!list)
		return (NULL);
	while (sL)
	{
		if (eL->n < value && expressFlag == 0)
		{
			printf("Value checked at index [%lu] = [%d]\n", eL->index, eL->n);
			if (eL->express == NULL)
			{
				sL = eL;
				while (eL->next != NULL)
					eL = eL->next;
				expressFlag = 1;
			}
			else
			{
				sL = eL;
				eL = eL->express;
				continue;
			}
		}
		if (foundFlag == 0)
		{
			if (expressFlag == 0)
				printf("Value checked at index [%lu] = [%d]\n", eL->index, eL->n);
			printf("Value found between indexes [%lu] and [%lu]\n",
			 sL->index, eL->index);
			foundFlag = 1;
		}
		printf("Value checked at index [%lu] = [%d]\n", sL->index, sL->n);
		if (value == sL->n)
			return (sL);
		sL = sL->next;
	}
	return (NULL);
}
