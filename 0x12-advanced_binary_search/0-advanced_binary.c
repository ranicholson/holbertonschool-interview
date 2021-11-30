#include "search_algos.h"

/**
 * advanced_binary - funciton to perform an advanced binary search
 * @array: pointer to first element of array to be searching on
 * @size: number of elements in array
 * @value: value to search for
 * Return: index where value is located
 */

int advanced_binary(int *array, size_t size, int value)
{
	int retInd = 0, middle = (size - 1) / 2;
	size_t x = 0;

	if (array == NULL)
		return (-1);

	printf("Searching in array: ");
	for (x = 0; x < size; x++)
	{
		printf("%d", array[x]);

		if (x != (size - 1))
			printf(", ");
		else
			printf("\n");
	}

	if (array[middle] == value && middle == 0)
		return (middle);

	if (size == 1)
		return (-1);

	if (array[middle] >= value)
		return (advanced_binary(array, middle + 1, value));

	middle++;
	retInd = advanced_binary(&array[middle], size - middle, value);

	if (retInd == -1)
		return (-1);

	return (middle + retInd);
}
