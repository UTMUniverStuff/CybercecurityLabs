#include <stdlib.h>
#include "graphlib.h"


t_edge*	new_graph_edge(t_graph* start, t_graph* end, int weight)
{
	t_edge* result;


	result = malloc(sizeof(*result));
	result->start = start;
	result->end = end;
	result->weight = weight;

	return result;
}
