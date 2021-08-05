#include "binary_trees.h"

heap_t *heapMaxifier(heap_t *newNode);

/**
 * heap_insert - function to insert value into max binary heap
 * @root: double popinter to root node of heap
 * @value: Value to be stored in the node
 * Return: Pointer to inserted node or null upon failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *currentNode;

	if (*root == NULL)
		return (binary_tree_node(*root, value));

	currentNode = *root;

	while (!currentNode)
	{
		if (currentNode->n == value)
			return (heapMaxifier(currentNode));

		if (currentNode->n < value)
		{
			currentNode = currentNode->left;
			continue;
		}
		currentNode = currentNode->right;
	}

	return (binary_tree_node(currentNode, value));
}


/**
 * heapMaxifier - moves new node to correct position in max heap
 * @newNode: node to move to correct place
 * Return: newnode
 */

heap_t *heapMaxifier(heap_t *newNode)
{
	heap_t *temp;
	int tempNum = 0;

	while (newNode && newNode->parent)
	{
		while (newNode->n > newNode->parent->n)
		{
			temp = newNode;
			tempNum = newNode->n;
			newNode = newNode->parent;
			temp->n = newNode->n;
			newNode->n = tempNum;
		}
	}
	return (newNode);
}
