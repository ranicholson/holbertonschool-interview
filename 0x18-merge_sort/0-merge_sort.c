#include "sort.h"

/**
 * merge_sort - funciton to sort an array using merge sort
 * @array: Array to sort
 * @size:size of array
 */

void merge_sort(int *array, size_t size)
{
	int *newArray = NULL, x = 0;

	newArray = malloc(sizeof(int) * size);

	for (x = 0; x < (int)size; x++)
		newArray[x] = array[x];

	splitMerge(array, newArray, size);
	free(newArray);
}


/**
 * splitMerge - splitting array to sort and merge
 * @newArray: Array to help merge process
 * @array: array to sort
 * @size: size of array to sort
 */

void splitMerge(int *array, int *newArray, size_t size)
{
	int arrayMiddle = (int)size / 2;

	if (size < 2)
		return;

	splitMerge(array, newArray, arrayMiddle);
	splitMerge(array + arrayMiddle, newArray, size - arrayMiddle);
	mergeMerge(array, newArray, size);
}


/**
 * mergeMerge - merging sorted array and printing out
 * @array:array to merge
 * @newArray: array to merge
 * @size: array size
 */

void mergeMerge(int *array, int *newArray, size_t size)
{
	int arrayMiddle = (int)size / 2, x = 0, y = 0, z = 0;

	z = arrayMiddle;

	printf("Merging...\n[left]: ");
	print_array(array, arrayMiddle);
	printf("[right]: ");
	print_array(array + arrayMiddle, size - arrayMiddle);

	for (x = 0; y < (int)size; y++)
	{
		if (x < arrayMiddle && (z == (int)size || array[x] <= array[z]))
		{
			newArray[y] = array[x];
			x++;
		}
		else
		{
			newArray[y] = array[z];
			z++;
		}
	}

	for (x = 0; x < (int)size; x++)
		array[x] = newArray[x];

	printf("[Done]: ");
	print_array(newArray, size);
}
