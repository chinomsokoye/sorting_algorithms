#include "sort.h"

/**
 * list_len - Returns list length
 * @list: list
 * Return: length
 */
size_t list_len(listint_t *list)
{
	size_t leng = 0;

	while (list)
	{
		leng++;
		list = list->next;
	}
	return (leng);
}

/**
 * switch_nodes - Swap/Return node
 * @list: List node
 * @p: Pointer node
 */
void switch_nodes(listint_t **list, listint_t **p)
{
	listint_t *first, *second, *third, *fourth;

	first = (*p)->prev;
	second = *p;
	third = (*p)->next;
	fourth = (*p)->next->next;
	second->next = fourth;
	if (fourth)
		fourth->prev = second;
	third->next = second;
	third->prev = second->prev;
	if (first)
		first->prev = third;
	else
		*list = third;
	second->prev = third;
	*p = third;
}

/**
 * cocktail_sort_list - Sort a doubly linked list
 *
 * @list: The list pointer
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *p;
	int sorted = 0;

	if (!list || !*list || list_len(*list) < 2)
		return;
	p = *list;
	while (!sorted)
	{
		sorted = 1;
		while (p->next)
		{
			if (p->n > p->next->n)
			{
				sorted = 0;
				switch_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->next;
		}
		if (sorted)
			break;
		p = p->prev;
		while (p->prev)
		{
			if (p->n < p->prev->n)
			{
				sorted = 0;
				p = p->prev;
				switch_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->prev;
		}
	}
}
