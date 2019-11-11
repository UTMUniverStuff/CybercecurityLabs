#include "islands.h"


void	print_path(t_list* path)
{
	t_island*	island;


	for (; path; LTONEXT(path))
	{
		island = path->content;
		printf("-> %d\t %d\n", island->coord_x, island->coord_y);
	}
}
