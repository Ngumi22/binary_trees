#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * is_perfect_rec - Recursive helper function to
 * check if a binary tree is perfect
 * @tree: Pointer to the root node of the current subtree
 * @size: Size of the entire tree
 *
 * Return: 1 if the subtree is perfect, 0 otherwise
 */
int is_perfect_rec(const binary_tree_t *tree, size_t size)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (size == 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_rec(tree->left, size / 2)
		&& is_perfect_rec(tree->right, size / 2));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t size = binary_tree_size(tree);

	if (tree == NULL)
		return (0);

	return (is_perfect_rec(tree, size));
}
