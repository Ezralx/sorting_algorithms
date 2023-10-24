#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 *                      ascending order using the Cocktail shaker
 *                      sort algorithm
 * @list: double pointer to the head of the list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *cur;
	bool swapped_values = true;

	if (list == NULL || *list == NULL)
		return;
	cur = *list;
	while (swapped_values)
	{
		swapped_values = false;
		while (cur->next != NULL)
		{
			if (cur->n > (cur->next)->n)
			{
				swap_nodes(list, cur, cur->next);
				swapped_values = true;
				print_list(*list);
				continue;
			}
			cur = cur->next;
		}
		if (!swapped_values)
			break;
		swapped_values = false;
		while (cur->prev != NULL)
		{
			if ((cur->prev)->n > cur->n)
			{
				swap_nodes(list, cur->prev, cur);
				swapped_values = true;
				print_list(*list);
				continue;
			}
			cur = cur->prev;
		}
	}
}


/**
 * swap_nodes - swaps two nodes
 * @list: double pointer to the head of the list
 * @a: first node
 * @b: second node
 *
 * Return: void
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a == NULL || b == NULL)
		return;
	if (a->prev != NULL)
		(a->prev)->next = b;
	if (b->next != NULL)
		(b->next)->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
	if (list != NULL && *list == a)
		*list = b;
}
