#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Double linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current = (*list)->next;

	while (current)
	{
		while (current->prev && current->prev->n > current->n)
		{
			current = swap_node(current->prev, list);
			print_list(*list);
		}
		current = current->next;
	}
}

/**
 * swap_node - Swaps a node with its previous node in a doubly linked list
 * @node: Node to be swapped
 * @list: Pointer to the head of the doubly linked list
 * Return: Pointer to the node which was swapped
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;

	return (current);
}
