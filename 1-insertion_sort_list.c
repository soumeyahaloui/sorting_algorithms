#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	/* Update n1's next and n2's next if n2 is not NULL */
	if ((*n1)->next != NULL)
		(*n1)->next->prev = n2;
	if (n2->next != NULL)
		n2->next->prev = *n1;

	/* Update n1's prev and n2's prev */
	n2->prev = (*n1)->prev;
	(*n1)->prev = n2;

	/* Update n1's next and n2's next */
	(*n1)->next = n2->next;
	n2->next = *n1;

	/* Update head if n1 was the head */
	if (n2->prev == NULL)
		*h = n2;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascend order
 *                        using Insertion sort algorithm
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *curr, *temp;

	curr = (*list)->next;
	while (curr != NULL)
	{
		temp = curr->prev;
		while (temp != NULL && temp->n > curr->n)
		{
			if (temp->prev != NULL)
				temp->prev->next = curr;
			else
				*list = curr;

			if (curr->next != NULL)
				curr->next->prev = temp;

			temp->next = curr->next;
			curr->prev = temp->prev;
			curr->next = temp;
			temp->prev = curr;

			print_list(*list);

			temp = curr->prev;
		}

		curr = curr->next;
	}
}
