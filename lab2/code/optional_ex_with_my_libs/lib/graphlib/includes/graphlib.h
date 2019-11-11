#ifndef GRAPH_LIB_H
# define GRAPH_LIB_H

# include "listlib.h"

# define LEDGE(list_cell)	LCONT(list_cell, t_edge*)


typedef void	(t_graphdel_func)(void*, size_t);

/*
** Forward declarations
*/

typedef struct s_edge	t_edge;
typedef struct s_graph	t_graph;

/*
** Aliases
*/

typedef t_list			t_lst_edge;


struct					s_edge
{
	int					weight;

	t_graph*			start;
	t_graph*			end;
};

struct					s_graph
{
	void*				content;
	t_lst_edge*			edges;
	int					visited;
	int					id;
};


void		free_graph(t_graph** graph, t_graphdel_func* content_del_func);
t_edge*		new_graph_edge(t_graph* start, t_graph* end, int weight);
t_graph*	new_graph(void* content, int id);
void		graph_reset_visited_flag(t_graph* head);

void		graph_add(t_graph* head, t_graph* node_to_add, int weight);

#endif
