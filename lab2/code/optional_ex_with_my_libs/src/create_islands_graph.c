#include "islands.h"
#include "graphlib.h"
#include "libft.h"


const int c_algorithm_mark	= -42;


static t_bool	coords_are_valid(const t_matrix* islands, int x, int y)
{
	return !(
		x < 0 || x >= islands->width ||
		y < 0 || y >= islands->height
	);
}

static t_graph*	create_graph_nodes_for_islands(
					const t_matrix*	islands,
					t_graph**		nodes,
					int				x,
					int				y);

static void		explore_island(
					t_graph*		head,
					const t_matrix*	islands,
					t_graph**		nodes,
					int				x,
					int				y)
{
	t_graph*	node;
	int			island_value;	


	if (!coords_are_valid(islands, x, y))
		return;

	island_value = islands->tab[y][x];
	node = create_graph_nodes_for_islands(islands, nodes, x, y);

	if (node)
		graph_add(head, node, island_value);
}


static t_graph*	create_graph_nodes_for_islands(
					const t_matrix*	islands,
					t_graph**		nodes,
					int				x,
					int				y)
{
	int				id;
	t_graph*		node;
	e_island_type	island_type;


	if (!coords_are_valid(islands, x, y))
		return NULL;

	node = nodes[y * islands->width + x];
	if (node)
		return node;

	island_type = get_island_type(islands->tab[y][x]);
	if (island_type == c_obstacle)
		return NULL;

	id = y * islands->width + x;
	node = new_graph(new_island(x, y, island_type), id);
	nodes[y * islands->width + x] = node;

	explore_island(node, islands, nodes, x - 1, y);
	explore_island(node, islands, nodes, x + 1, y);
	explore_island(node, islands, nodes, x, y - 1);
	explore_island(node, islands, nodes, x, y + 1);
	return node;
}


t_graph*	create_islands_graph(
				const t_matrix* islands,
				const t_island* start,
				const t_island* end)
{
	t_graph*	head  = NULL;
	t_graph**	nodes;


	nodes = calloc(islands->width * islands->height, sizeof(*nodes));
	head = create_graph_nodes_for_islands(
		islands,
		nodes,
		start->coord_x, start->coord_y);
	if (nodes[end->coord_y * islands->width + end->coord_x] == NULL)
		critical_error("It's impossible to connect start with finish");
	free(nodes);

	return head;
}