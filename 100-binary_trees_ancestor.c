#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes
 *         NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *first_ancestor, *second_ancestor;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	first_ancestor = (binary_tree_t *)first;
	second_ancestor = (binary_tree_t *)second;

	while (first_ancestor != NULL)
	{
		second_ancestor = (binary_tree_t *)second;
		while (second_ancestor != NULL)
		{
			if (first_ancestor == second_ancestor)
				return (first_ancestor);
			second_ancestor = second_ancestor->parent;
		}
		first_ancestor = first_ancestor->parent;
	}

	return (NULL);
}

