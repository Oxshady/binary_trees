#include<stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_delete - delete all the nodes of the tree and tree itself
 * @tree: pointer to the root node of the tree to delete
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}

