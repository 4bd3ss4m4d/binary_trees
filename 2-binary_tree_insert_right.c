#include "binary_trees.h"


binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_binary_tree = malloc(sizeof(binary_tree_t));

	if (!parent)
	{
        return (NULL);
    }

	if (!new_binary_tree)
	{
        return (NULL);
    }

	new_binary_tree->n = value;
	new_binary_tree->parent = parent;
	new_binary_tree->left = NULL;
	new_binary_tree->right = parent->right;

	parent->right = new_binary_tree;

	if (new_binary_tree->right)
	{
        new_binary_tree->right->parent = new_binary_tree;
    }

	return (new_binary_tree);
}
