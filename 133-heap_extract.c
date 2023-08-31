#include "binary_trees.h"

void heapify_down(heap_t *root);

/**
 * heap_extract - Removes the root node of a max-heap and restores the
 *		max-heap property
 * @root: double pointer to the root node of the heap
 *
 * Return: Value of the extracted root node, or 0 if the heap is empty or
 *	 root is NULL
 */
int heap_extract(heap_t **root)
{
	heap_t *nd;
	int vl;

	if (!root || !*root)
	{
		return (0);
	}

	vl = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;

		return (vl);
	}

	nd = *root;
	while (nd->left || nd->right)
	{
		if (!nd->right || (nd->left && nd->left->n >= nd->right->n))
		{
			nd->n = nd->left->n;
			nd = nd->left;
		}
		else
		{
			nd->n = nd->right->n;
			nd = nd->right;
		}
	}

	if (nd->parent->left == nd)
		nd->parent->left = NULL;
	else
		nd->parent->right = NULL;

	free(nd);
	heapify_down(*root);

	return (vl);
}

/**
 * heapify_down - Restores the max-heap property in a heap starting from a
 *		given node
 * @root: pointer to the root node of the heap
 *
 * Return: void
 */
void heapify_down(heap_t *root)
{
	int vl;
	heap_t *biggest;

	while (1)
	{
		if (!root->left)
		{
			break;
		}

		if (!root->right || root->left->n > root->right->n)
			biggest = root->left;
		else
			biggest = root->right;

		if (root->n > biggest->n)
			break;

		vl = root->n;
		root->n = biggest->n;
		biggest->n = vl;

		root = biggest;
	}
}
