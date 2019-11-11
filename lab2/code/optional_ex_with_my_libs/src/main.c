#include <float.h>
#include "matrixlib.h"
#include "graphlib.h"
#include "islands.h"
#include "ft_colors.h"


typedef struct	s_djikstra
{
	int			shortest_dist;
	t_graph*	previous_node;
}				t_djikstra;


t_djikstra*		new_djikstra()
{
	t_djikstra*	result;


	result = malloc(sizeof(*result));
	result->shortest_dist = INT_MAX;
	result->previous_node = NULL;
	return result;
}


t_djikstra*	get_djikstra(t_djikstra** djikstras, int index)
{
	t_djikstra*	result;

	
	result = djikstras[index];
	if (result == NULL)
	{
		result = new_djikstra();
		djikstras[index] = result;
	}
	return result;
}

t_bool	array_is_empty(t_graph** nodes, int size)
{
	for (int i = 0; i < size; i++)
		if (nodes[i])
			return FALSE;
	return TRUE;
}

int		get_shortest_index(
			t_graph**		nodes,
			t_djikstra**	djikstras,
			int				size)
{
	int			dist;
	int			smallest_index;
	t_djikstra*	djikstra;


	dist = INT_MAX;
	smallest_index = 0;

	for (int i = 0; i < size; i++)
	{
		if (nodes[i] == NULL)
			continue;

		djikstra = get_djikstra(djikstras, i);
		if (dist > djikstras[i]->shortest_dist)
		{
			dist = djikstras[i]->shortest_dist;
			smallest_index = i;
		}
	}

	if (dist == INT_MAX)
		critical_error("Viteook loh");

	return smallest_index;
}

void		do_djikstra_magic2(
				t_graph*		start,
				t_graph**		nodes,
				int				nodes_count,
				t_djikstra**	djikstras)
{
	t_lst_edge*	edge;
	t_graph*	node;
	t_graph*	end_node;
	int			index;
	int			dist;


	while (!array_is_empty(nodes, nodes_count))
	{
		index = get_shortest_index(nodes, djikstras, nodes_count);
		node = nodes[index];
		nodes[index] = NULL;

		for (edge = node->edges; edge; LTONEXT(edge))
		{
			t_djikstra*	other;

			other = djikstras[LEDGE(edge)->end->id];

			dist = djikstras[index]->shortest_dist + LEDGE(edge)->weight;
			if (dist < other->shortest_dist)
			{
				other->shortest_dist = dist;
				other->previous_node = node;
			}
		}
	}
}

t_list*		create_island_path(
				t_djikstra**	djikstras,
				t_graph*		start_node,
				t_graph*		end_node)
{
	t_list*		path;
	t_graph* 	node;
	t_djikstra*	djikstra;


	path = NULL;
	node = end_node;

	while (TRUE)
	{
		if (node == NULL)
			break;

		djikstra = djikstras[node->id];
		ft_lstadd(&path, ft_lstnew_nocpy(node->content, sizeof(node->content)));

		if (node == start_node)
			break;

		node = djikstra->previous_node;
	}

	return path;
}


void	get_all_nodes(t_graph* head, t_graph** nodes)
{
	t_lst_edge*	edge;


	if (head == NULL || head->visited)
		return;

	head->visited = TRUE;
	nodes[head->id] = head;
	for (edge = head->edges; edge; LTONEXT(edge))
		get_all_nodes(LEDGE(edge)->end, nodes);
}

t_list*	find_shortest_path(
			t_graph*	start,
			t_graph*	end,
			int			total_nb_of_nodes)
{
	t_djikstra**	djikstras;
	t_djikstra*		djikstra;
	t_graph**		nodes;


	djikstras = calloc(total_nb_of_nodes, sizeof(*djikstras));
	nodes = calloc(total_nb_of_nodes, sizeof(*nodes));
	get_all_nodes(start, nodes);
	graph_reset_visited_flag(start);

	djikstra = get_djikstra(djikstras, start->id);
	djikstra->shortest_dist = 0;

	do_djikstra_magic2(start, nodes, total_nb_of_nodes, djikstras);
	return create_island_path(djikstras, start, end);
}

void	find_shortest_path_between_islands(const t_matrix* islands)
{
	t_island*	start_island;
	t_island*	end_island;
	t_graph*	islands_graph;
	t_graph*	end_node;
	t_list*		path;


	start_island = find_start_island(islands);
	end_island = find_end_island(islands);

	if (start_island == NULL)
		critical_error("Couldn't find start island");

	if (end_island == NULL)
		critical_error("Couldn't find end island");

	islands_graph = create_islands_graph(islands, start_island, end_island);

	end_node = find_end_node(islands_graph, end_island);
	graph_reset_visited_flag(islands_graph);
	if (end_node == NULL)
		critical_error("Couldn't find end node");
	
	int total_nb_of_nodes = islands->width * islands->height;
	path = find_shortest_path(islands_graph, end_node, total_nb_of_nodes);
	
	print_path(path);
	pretty_print_path(path, islands);
}


int main(const int argc, const char** argv)
{
	t_matrix*	islands_matrix;


	islands_matrix = read_matrix();
	print_matrix(islands_matrix);
	find_shortest_path_between_islands(islands_matrix);
	free_matrix(&islands_matrix);
	return 0;
}

