#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height = binary_tree_height(tree);
	int node_count = binary_tree_count_nodes(tree);

	if (tree == NULL)
		return (0);

	int last_level_nodes = 1 << height;

	return (node_count == last_level_nodes - 1);
}

