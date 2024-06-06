#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * enqueue - Adds a node to the end of the queue
 * @queue: Double pointer to the queue
 * @tail: Pointer to the end of the queue
 * @node: Node to be added
 */
void enqueue(binary_tree_t ***queue, size_t *tail, binary_tree_t *node)
{
	(*queue)[*tail] = node;
	(*tail)++;
}

/**
 * dequeue - Removes a node from the front of the queue
 * @queue: Double pointer to the queue
 * @head: Pointer to the front of the queue
 * Return: Node at the front of the queue
 */
binary_tree_t *dequeue(binary_tree_t ***queue, size_t *head)
{
	(*head)++;
	return ((*queue)[*head - 1]);
}

/**
 * binary_tree_levelorder - traverse binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_t **queue;
	size_t head = 0, tail = 0, queue_size = 1024;

	queue = malloc(queue_size * sizeof(binary_tree_t *));

	if (queue == NULL)
		return;

	enqueue(&queue, &tail, (binary_tree_t *)tree);

	while (head < tail)
	{
		binary_tree_t *node = dequeue(&queue, &head);

		func(node->n);

		if (node->left != NULL)
			enqueue(&queue, &tail, node->left);

		if (node->right != NULL)
			enqueue(&queue, &tail, node->right);
	}

	free(queue);
}

