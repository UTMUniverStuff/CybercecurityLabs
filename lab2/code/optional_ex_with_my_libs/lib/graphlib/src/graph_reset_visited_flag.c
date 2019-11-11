#include "graphlib.h"


void	graph_reset_visited_flag(t_graph* head)
{
	t_lst_edge*	edge;


	if (head == NULL || !head->visited)
		return;

	head->visited = 0;
	for (edge = head->edges; edge; LTONEXT(edge))
		graph_reset_visited_flag(LEDGE(edge)->end);
}
