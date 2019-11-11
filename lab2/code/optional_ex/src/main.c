#include <stdlib.h>
#include <stdio.h>


typedef struct s_graph_node t_graph_node;
typedef struct s_graph_edge t_graph_edge;

struct s_graph_edge
{
	float weight;

	t_graph_node* start;
	t_graph_node* end;
};

struct	s_graph_node
{
	t_graph_edge** edges;
};

int main(const int argc, const char** argv)
{
	return 0;
}