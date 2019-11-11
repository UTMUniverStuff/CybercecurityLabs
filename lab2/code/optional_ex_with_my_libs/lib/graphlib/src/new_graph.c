#include <stdlib.h>
#include "graphlib.h"


t_graph*	new_graph(void* content, int id)
{
	t_graph* result;


	result = malloc(sizeof(*result));
	result->content = content;
	result->edges = NULL;
	result->visited = 0;
	result->id = id;

	return result;
}
