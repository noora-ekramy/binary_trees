#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 * Return: The balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int height_left = 0, height_right = 0;
	if (tree->left)
	{
		height_left++;
		height_left += binary_tree_balance(tree->left);
	}
	if (tree->right)
	{
		height_right++;
		height_right += binary_tree_balance(tree->right);
	}
	if (!tree->left && !tree->right)
	{
		height_left = -1;
		height_right = -1;
	}
	return (height_left - height_right);
}
