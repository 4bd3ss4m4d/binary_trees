#include "binary_trees.h"

int binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: balance factor of the tree, or 0 if the tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_node, right_node;

	if (tree == NULL)
	{
		return (0);
	}

	left_node = binary_tree_height(tree->left);
	right_node = binary_tree_height(tree->right);

	return (left_node - right_node);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree, or 0 if the tree is NULL
 */
int binary_tree_height(const binary_tree_t *tree)
{
	int h_left_node, h_right_node;

	if (tree == NULL)
	{
		return (0);
	}

	h_left_node = binary_tree_height(tree->left);
	h_right_node = binary_tree_height(tree->right);

	if (h_left_node >= h_right_node)
	{
		return (h_left_node + 1);
	}

	return (h_right_node + 1);

}
