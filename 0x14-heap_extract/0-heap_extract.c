#include "binary_trees.h"

/**
 * heap_extract - function to extract root node of a heap
 * @root: Double pointer to root node of the heap
 * Return: value stored in root node
 */

int heap_extract(heap_t **root)
{
	int extractedRoot, heapHeight;
	heap_t *lastNode;

	if (*root == NULL || root == NULL)
		return (0);

	extractedRoot = (*root)->n;
	heapHeight = binary_tree_height(*root) + 1;
	lastNode = getLastNode(*root, heapHeight);

	if (heapHeight == 1)
	{
		free(lastNode);
		*root = NULL;
		return (extractedRoot);
	}

	(*root)->n = lastNode->n;

	if (lastNode->parent->right == lastNode)
		lastNode->parent->right = NULL;
	else
		lastNode->parent->left = NULL;

	free(lastNode);
	heapSorter(*root);
	return (extractedRoot);
}

/**
 * getLastNode - Function to return last node in a heap
 * @root: pointer to heap
 * @height: heaight of heap
 * Return: heap_t* pointer to last node
 */

heap_t *getLastNode(heap_t *root, int height)
{
	heap_t *leftSide, *rightSide;

	if (root == NULL)
		return (NULL);

	if (height == 1)
		return (root);

	leftSide = getLastNode(root->left, height - 1);
	rightSide = getLastNode(root->right, height - 1);

	return (rightSide == NULL ? leftSide : rightSide);
}


/**
 * binary_tree_height - Function to measure height of binary tree
 * @tree: Tree to measure height of
 * Return: Height or 0 if tree is null
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (right_height > left_height)
		return (right_height + 1);
	else
		return (left_height + 1);
}

/**
 * heapSorter - function to sort heap by max value
 * @root: pointer to heap that needs a good sorting
 */

void heapSorter(heap_t *root)
{
	int numberHolder;
	heap_t *biggerNode = root;

	if (root->left != NULL && root->left->n >= biggerNode->n)
		biggerNode = root->left;

	if (root->right != NULL)
	{
		if (biggerNode == root->left && root->right->n > biggerNode->n)
			biggerNode = root->right;

		else if (root->right->n >= biggerNode->n)
			biggerNode = root->right;
	}

	if (biggerNode != root)
	{
		numberHolder = root->n;
		root->n = biggerNode->n;
		biggerNode->n = numberHolder;
		heapSorter(biggerNode);
	}
}
