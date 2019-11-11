#include "graphlib.h"


void	graph_add(t_graph* head, t_graph* node_to_add, int weight)
{
	t_edge*	edge;


	edge = new_graph_edge(head, node_to_add, weight);
	ft_lstadd(&head->edges, ft_lstnew_nocpy(edge, sizeof(*edge)));
}
