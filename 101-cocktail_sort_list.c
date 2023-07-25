#include "sort.h"
#include <stdio.h>
/**
 *swap_node - swap a nd
 *@nd: nd
 *@list: nd list
 *Return: return a pointer to a nd which was enter it
 */
listint_t *swap_node(listint_t *nd, listint_t **list)
{
	listint_t *back = nd->prev, *cur = nd;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = cur->next;
	if (cur->next)
		cur->next->prev = back;
	cur->next = back;
	cur->prev = back->prev;
	back->prev = cur;
	if (cur->prev)
		cur->prev->next = cur;
	else
		*list = cur;
	return (cur);
}
/**
 *cocktail_sort_list - this is a cocktail
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *nd;
	int swap_finish = 1;

	if (list == '\0' || (*list) == '\0' || (*list)->next == '\0')
		return;
	nd = *list;
	while (swap_finish == 1)
	{
		swap_finish = 0;
		while (nd->next)
		{
			if (nd->n > nd->next->n)
			{
				nd = swap_node(nd->next, list);
				swap_finish = 1;
				print_list(*list);
			}
			nd = nd->next;
		}
		if (swap_finish == 0)
			break;
		swap_finish = 0;
		while (nd->prev)
		{
			if (nd->n < nd->prev->n)
			{
				nd = swap_node(nd, list);
				swap_finish = 1;
				print_list(*list);
			}
			else
				nd = nd->prev;
		}
	}
}
