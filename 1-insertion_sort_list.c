#include "sort.h"

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
