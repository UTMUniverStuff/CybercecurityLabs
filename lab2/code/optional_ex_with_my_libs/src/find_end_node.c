#include "islands.h"


t_graph*	find_end_node(t_graph* head, const t_island* end_island)
{
	t_lst_edge*	edge;
	t_graph*	result;
	t_island*	island;


	if (head == NULL || head->visited)
		return NULL;

	island = head->content;
	if (island->coord_x == end_island->coord_x &&
		island->coord_y == end_island->coord_y)
	{
		return head;
	}

	head->visited = TRUE;
	for (edge = head->edges; edge; LTONEXT(edge))
	{
		result = find_end_node(LEDGE(edge)->end, end_island);
		if (result)
			return result;
	}

	return NULL;
}
