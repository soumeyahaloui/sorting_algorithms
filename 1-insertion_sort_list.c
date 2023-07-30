#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascend order
 *                       using the Insertion sort algorithm.
 *
 * @list: A pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *curr = (*list)->next;

	while (curr != NULL)
	{
		listint_t *temp = curr;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			temp->next->prev = temp;
			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;
			print_list(*list);
		}
		curr = curr->next;
	}
}
