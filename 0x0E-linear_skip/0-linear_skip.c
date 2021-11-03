#include "search.h"

/**
 * linear_skip - function to search skip list
 * @list: list to search
 * @value: value to search for
 * Return: Pointer to node where value is located or NULL if something is off
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *slowLane = list;
	skiplist_t *expressLane = list->express;
	int foundFlag = 0, expressFlag = 0;

	if (!list)
		return (NULL);
	while (slowLane)
	{
		if (expressLane->n < value && expressFlag == 0)
		{
			printf("Value checked at index [%lu] = [%d]\n",
			 expressLane->index, expressLane->n);
			if (expressLane->express == NULL)
			{
				slowLane = expressLane;
				while (expressLane->next != NULL)
					expressLane = expressLane->next;
				expressFlag = 1;
			}
			else
			{
				slowLane = expressLane;
				expressLane = expressLane->express;
				continue;
			}
		}
		if (foundFlag == 0)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
			 slowLane->index, expressLane->index);
			foundFlag = 1;
		}
		printf("Value checked at index [%lu] = [%d]\n",
		 slowLane->index, slowLane->n);

		if (value == slowLane->n)
			return (slowLane);
		slowLane = slowLane->next;
	}
	return (NULL);
}
