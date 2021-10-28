#include "binary_trees.h"


/**
 * sorted_array_to_avl - Builds AVL tree from array
 * @array: Pointer to first element of an array
 * @size: Number of elements in array
 * Return: Pointer to root node of tree or NULL upon failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	int middle = (size - 1) / 2;

	if (array == NULL || size < 1)
		return (NULL);

	root = malloc(sizeof(avl_t));

	if (!root)
		return (NULL);

	root->parent = NULL;
	root->left = recursionAssistant(array, 0, middle - 1, root);
	root->right = recursionAssistant(array, middle + 1, size - 1, root);
	root->n = array[middle];

	return (root);
}


/**
 * recursionAssistant - Function to add nodes to tree recursivly
 * @array: Array to convert to nodes
 * @begin: Location to start creating node
 * @finish: Location to stop creating node
 * @tree: Tree to add nodes to
 * Return: Completed tree
 */

avl_t *recursionAssistant(int *array, int begin, int finish, avl_t *tree)
{
	avl_t *newNode = NULL;
	int middle = (begin + finish) / 2;

	if (begin > finish)
		return (NULL);

	newNode = malloc(sizeof(avl_t));

	newNode->parent = tree;
	newNode->left = recursionAssistant(array, begin, middle - 1, newNode);
	newNode->right = recursionAssistant(array, middle + 1, finish, newNode);
	newNode->n = array[middle];

	return (newNode);
}
