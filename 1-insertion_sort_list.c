#include "sort.h"

/**
 * len_list - Returns length of linked list
 *
 * @h: Pointer to header
 * Return: Length of list
 */
int len_list(listint_t *h)
{
	int len = 0;

	while (h)
	{
		len++;
		h = h->next;
	}
	return (len);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integer
 *
 * @list: The list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *one = NULL;
	listint_t *two = NULL, *three = NULL, *four = NULL;

	if (!list || !(*list) || len_list(*list) < 2)
		return;

	current = *list;
	while (current)
	{
		if (current->prev && current->n < current->prev->n)
		{
			one = current->prev->prev;
			two = current->prev;
			three = current;
			four = current->next;

			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;
			if (one)
				one->next = three;
			else
				*list = three;
			two->prev = three;
			current = *list;
			print_list(*list);
			continue;
		}
		else
			current = current->next;
	}
}
