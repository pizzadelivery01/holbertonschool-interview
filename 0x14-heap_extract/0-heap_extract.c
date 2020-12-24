#include "binary_trees.h"

/**
 * get_tree_size - gets the size of the tree
 * @root: first node of the tree
 * Return: the size of the tree
 */
int get_tree_size(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + get_tree_size(root->left) + get_tree_size(root->right));
}

/**
 * swap - swaps the values of two nodes
 * @first_node: node to swap value of
 * @second_node: node to swap value of
 * Return: the first given node
 */
heap_t *swap(heap_t *first_node, heap_t *second_node)
{
	first_node->n = first_node->n * second_node->n;
	second_node->n = first_node->n / second_node->n;
	first_node->n = first_node->n / second_node->n;

	return (first_node);
}

/**
 * get_node - Gets the last node of a binary tree
 * @root: pointer to the root of the tree
 * @size: size of the tree
 *
 * Return: the found node ptr
 */
heap_t *get_node(heap_t *root, int size)
{
	int index, mk  = 0;

	for (; 1 << (index + 1) <= size; index++)
		;

	for (index--; index >= 0; index--)
	{
		mk = 1 << index;
		if (size & mk)
			root = root->right;
		else
			root = root->left;
	}
	return (root);
}

/**
 * heapify - Turns a binary tree into a valid max heap tree
 * @root: root node of the binary tree to heapify
 */
void heapify(heap_t *root)
{
	heap_t *max;
	int first = 0;

	if (!root)
		return;
	while (max || !first)
	{
		max = NULL;
		first = 1;
		if (root->left && root->left->n > root->n)
			max = root->left;
		if (root->right && root->right->n > root->n &&
				(max && root->right->n > max->n))
			max = root->right;
		if (max)
			root = swap(max, root);
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root of the heap
 * Return: the value stored in the root node, or 0.
 */
int heap_extract(heap_t **root)
{
	int max;
	int size;
	heap_t *last_node;

	if (!root || !*root)
		return (0);
	max = (*root)->n;
	size = get_tree_size(*root);
	last_node = get_node(*root, size);

	if (last_node->parent)
	{
		swap(last_node, *root);
		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;
	}
	else
	{
		*root = NULL;
	}
	free(last_node);
	heapify(*root);
	return (max);
}
