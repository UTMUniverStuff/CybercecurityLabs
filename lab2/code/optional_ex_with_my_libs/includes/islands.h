#ifndef ISLANDS_H
# define ISLANDS_H

# include "matrixlib.h"
# include "graphlib.h"

typedef enum		e_island_type
{
	c_obstacle		= 0,
	c_normal_island	= 1042,
	c_start_island	= 42,
	c_end_island	= 142,
}					e_island_type;


typedef struct		s_island
{
	int				coord_x;
	int				coord_y;
	e_island_type	island_type;
}					t_island;


void			critical_error(const char* msg);

t_island*		new_island(int x, int y, e_island_type island_type);
t_island*		find_start_island(const t_matrix* islands);
t_island*		find_end_island(const t_matrix* islands);
e_island_type	get_island_type(int island_value);
t_graph*		create_islands_graph(
					const t_matrix* islands,
					const t_island* start,
					const t_island* end);

t_graph*		find_end_node(t_graph* head, const t_island* end_island);

void			print_path(t_list* path);
void			pretty_print_path(t_list* path, const t_matrix* islands);

#endif