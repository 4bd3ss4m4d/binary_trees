#include "binary_trees.h"

/**
 * binary_tree_height_aux - measures the height of a binary tree (auxiliary function)
 * @tree: root of the tree to measure
 * Return: height of the tree, 0 if the tree is NULL
 */
size_t	binary_tree_height_aux(const binary_tree_t *tree)
{
	size_t hleft = 0, hright = 0;

	if (!tree)
		return (0);
	if (tree->left)
		hleft = 1 + binary_tree_height_aux(tree->left);
	if (tree->right)
		hright = 1 + binary_tree_height_aux(tree->right);

	if (hleft > hright)
		return (hleft);
	return (hright);
}
/**
 * print_level_order - prints the nodes of a binary tree at a specific level
 * @tree: root of the tree to print from
 * @level: the level at which to print nodes
 * @func: pointer to a function to call for each node's value
 */
void print_level_order(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level_order(tree->left, level - 1, func);
		print_level_order(tree->right, level - 1, func);
	}
}
/**
 * binary_tree_levelorder - performs level-order traversal on a binary tree
 * @tree: root of the tree to traverse
 * @func: pointer to a function to call for each node's value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = 0;
	int len = 1;

	if (!tree || !func)
		return;

	height = binary_tree_height_aux(tree) + 1;

	while (len <= height)
	{
		print_level_order(tree, len, func);
		len++;
	}
}
