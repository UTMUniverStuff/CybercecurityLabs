#include "graphlib.h"
#include <stdlib.h>


static void del_edge(t_edge** edge)
{
	if (edge == NULL)
		return;

	free(*edge);
	*edge = NULL;
}


static void	del_edges(t_lst_edge* edges, t_graphdel_func* del_f)
{
	while (edges)
	{
		free_graph(&LEDGE(edges)->start, del_f);
		free_graph(&LEDGE(edges)->end, del_f);
		
		edges = LNEXT(edges);
	}
}


void		free_graph(t_graph** graph, t_graphdel_func* del_f)
{
	if (*graph == NULL)
		return;


	del_f((*graph)->content, 0);
	del_edges((*graph)->edges, del_f);

	ft_lstdel(&(*graph)->edges, (t_ldel_func*)&del_edge);
	
	free(*graph);
	*graph = NULL;
}
