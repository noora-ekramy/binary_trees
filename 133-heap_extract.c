#include "binary_trees.h"

/**
 * heapify_down - Helper function to perform heapify down operation
 *
 * @heap: Pointer to the heap
 */
void heapify_down(heap_t *heap)
{
    heap_t *largest = NULL;
    int temp;

    if (heap == NULL)
        return;

    while (1)
    {
        if (heap->left && heap->left->n > heap->n)
            largest = heap->left;
        else
            largest = heap;

        if (heap->right && heap->right->n > largest->n)
            largest = heap->right;

        if (largest == heap)
            break;

        temp = heap->n;
        heap->n = largest->n;
        largest->n = temp;

        heap = largest;
    }
}

/**
 * heap_extract - Extracts the root value from a binary max heap
 *
 * @heap: Pointer to the heap
 *
 * Return: Value stored in the root node, 0 if the heap is empty
 */
int heap_extract(heap_t **heap)
{
    int root_value;

    if (heap == NULL || *heap == NULL)
        return (0);

    root_value = (*heap)->n;

    if ((*heap)->left == NULL && (*heap)->right == NULL)
    {
        free(*heap);
        *heap = NULL;
        return (root_value);
    }

    (*heap)->n = (*heap)->right ? (*heap)->right->n : (*heap)->left->n;

    if ((*heap)->right)
    {
        free((*heap)->right);
        (*heap)->right = NULL;
    }
    else
    {
        free((*heap)->left);
        (*heap)->left = NULL;
    }

    heapify_down(*heap);

    return (root_value);
}
