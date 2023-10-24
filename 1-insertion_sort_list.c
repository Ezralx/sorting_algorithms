#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm.
 * @list: double pointer to the head of the list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *key, *cur;

	if (list == NULL || *list == NULL)
		return;
	cur = (*list)->next;
	while (cur != NULL)
	{
		key = cur;
		cur = cur->next;
		while (key->prev != NULL && (key->prev)->n > key->n)
		{
			swap_nodes(list, key->prev, key);
			print_list(*list);
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
