#include <unistd.h>
#include "sort.h"

/**
 * insertion_sort_list - bubble sort algorithm function
 * @list: list to be sorted
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *bf, *curr;

	if (list == NULL)
		return;
	curr = (*list)->next;
	while (curr)
	{
		while (curr->n < curr->prev->n && curr->prev)
		{
			bf = curr->prev;

			curr->prev = bf->prev;
			bf->next = curr->next;
			if (bf->prev)
			{
				bf->prev->next = curr;
			}
			if (curr->next)
			{
				curr->next->prev = bf;
			}
			curr->next = bf;
			bf->prev = curr;
			bf = curr->prev;
			if (curr->prev == NULL)
			{
				(*list) = curr;
				print_list(*list);
				break;
			}
			print_list(*list);
		}
		curr = curr->next;
	}
}
