#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *nd;

	if (list == NULL || (*list)->next == NULL)
		return;
	nd = (*list)->next;
	while (nd)
	{
		while ((nd->prev) && (nd->prev->n > nd->n))
		{
			nd = swap_node(nd, list);
			print_list(*list);
		}
		nd = nd->next;
	}
}
/**
 *swap_node - swap a node
 *@node: node
 *@list: node list
 *Return: return a pointer to a node
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *previeu = node->prev, *current = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	previeu->next = current->next;
	if (current->next)
		current->next->prev = previeu;
	current->next = previeu;
	current->prev = previeu->prev;
	previeu->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
