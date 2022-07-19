#include "sort.h"

/**
 * insertion_sort - bubble sort algorithm function
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *af, *curr, *temp;

	curr = *list;
	while (curr->next)
	{
		af = (*list)->next;
		while ((*list)->n > af->n && af->prev != NULL)
		{
			if ((*list)->prev == NULL)
			{
				(*list)->next = af->next;
				af->next->prev = (*list);
				(*list)->prev = af;

				af->next = (*list);
				af->prev = NULL;
			}
			else if (af->next == NULL)
			{
				af->next = (*list);
                                af->prev = (*list)->prev;

				(*list)->next = NULL;
				(*list)->prev= af;
				(*list)->prev->next = af;
			}
			else
			{
				(*list)->prev->next = af;
				af->prev = (*list)->prev;

				(*list)->next = af->next;
				af->next->prev = (*list);

				af->next = (*list);
				(*list)->prev = af;
			}
			temp = (*list);
			*list = af;
			af = temp;
			af = af->prev;
		}
		(*list) = (*list)->next;
	}
}
