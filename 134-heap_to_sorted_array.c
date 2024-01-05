#include "binary_trees.h"
/**
 * binary_tree_size - function that return the size of a tree
 * @tree: tree to check
 * Return: size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0, r = 0, l = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		l = binary_tree_size(tree->left);
		r = binary_tree_size(tree->right);
		size = r + l + 1;
	}
	return (size);
}
/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array of integers
 *
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * Return: array sorted
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	if (heap == NULL || size == NULL)
		return (NULL);

	size_t heap_size = binary_tree_size(heap);

	int *sorted_array = malloc(sizeof(int) * heap_size);
	if (sorted_array == NULL)
		return (NULL);

	for (size_t i = 0; i < heap_size; i++)
	{
		sorted_array[i] = heap->n;
		heap_extract(&heap);
	}

	*size = heap_size;

	return (sorted_array);
}