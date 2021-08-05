#include "binary_trees.h"

/**
 * binary_tree_node - function to create binary tree node
 * @parent: pointer to parent node of node that needs to be created
 * @value: value to store in the node
 * Return: pointer to new node or NULL upon failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	newNode = malloc(sizeof(binary_tree_t));

	if (!newNode)
		return (NULL);

	newNode->n = value;
	newNode->parent = parent;
	newNode->left = NULL;
	newNode->right = NULL;

	return (newNode);
}
