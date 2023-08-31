#include "binary_trees.h"

int btih_helper(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);
int btic_helper(const binary_tree_t *tree, size_t index, size_t size);
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - checks if a binary tree is a max heap
 * @tree: pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is a max heap, 0 otherwise or if the tree is NULL
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	return (btih_helper(tree));
}

/**
 * btic_helper - helper function to check if a binary tree is complete
 * @tree: pointer to the node being checked during recursion
 * @index: current index of the node being checked
 * @size: total size of the binary tree
 *
 * Return: 1 if the subtree is complete, 0 otherwise
 */
int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
	{
		return (1);
	}

	if (index >= size)
	{
		return (0);
	}

	return (btic_helper(tree->left, 2 * index + 1, size) &&
		btic_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - calculates the size of a binary tree
 * @tree: pointer to the root node of the binary tree
 *
 * Return: size of the binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}

/**
 * btih_helper - helper function to check if a binary tree is a max heap
 * @tree: pointer to the node being checked during recursion
 *
 * Return: 1 if the subtree is a max heap, 0 otherwise
 */
int btih_helper(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (1);
	}

	if (!binary_tree_is_complete(tree))
	{
		return (0);
	}

	if (tree->left)
		if (tree->left->n > tree->n)
		{
			return (0);
		}
	if (tree->right)
		if (tree->right->n > tree->n)
		{
			return (0);
		}

	return (btih_helper(tree->left) &&
		btih_helper(tree->right));
}

/**
 * binary_tree_is_complete - checks if a binary tree is a complete binary tree
 * @tree: pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is complete, 0 otherwise or if the tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
	{
		return (0);
	}
	size = binary_tree_size(tree);

	return (btic_helper(tree, 0, size));
#include "binary_trees.h"

int btih_helper(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);
int btic_helper(const binary_tree_t *tree, size_t index, size_t size);
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - checks if a binary tree is a max heap
 * @tree: pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is a max heap, 0 otherwise or if the tree is NULL
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	return (btih_helper(tree));
}

/**
 * btic_helper - helper function to check if a binary tree is complete
 * @tree: pointer to the node being checked during recursion
 * @index: current index of the node being checked
 * @size: total size of the binary tree
 *
 * Return: 1 if the subtree is complete, 0 otherwise
 */
int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
	{
		return (1);
	}

	if (index >= size)
	{
		return (0);
	}

	return (btic_helper(tree->left, 2 * index + 1, size) &&
		btic_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - calculates the size of a binary tree
 * @tree: pointer to the root node of the binary tree
 *
 * Return: size of the binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}

/**
 * btih_helper - helper function to check if a binary tree is a max heap
 * @tree: pointer to the node being checked during recursion
 *
 * Return: 1 if the subtree is a max heap, 0 otherwise
 */
int btih_helper(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (1);
	}

	if (!binary_tree_is_complete(tree))
	{
		return (0);
	}

	if (tree->left)
		if (tree->left->n > tree->n)
		{
			return (0);
		}
	if (tree->right)
		if (tree->right->n > tree->n)
		{
		return (0);
		}

	return (btih_helper(tree->left) &&
		btih_helper(tree->right));
}

/**
 * binary_tree_is_complete - checks if a binary tree is a complete binary tree
 * @tree: pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is complete, 0 otherwise or if the tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
	{
		return (0);
	}
	size = binary_tree_size(tree);

	return (btic_helper(tree, 0, size));
}}
