#include <stdlib.h>
#include "islands.h"


t_island*	new_island(int x, int y, e_island_type island_type)
{
	t_island*	island;


	island = malloc(sizeof(*island));
	island->coord_x = x;
	island->coord_y = y;
	island->island_type = island_type;

	return island;
}