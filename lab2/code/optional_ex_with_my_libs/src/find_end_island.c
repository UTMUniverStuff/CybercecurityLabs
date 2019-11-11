#include <unistd.h>
#include "islands.h"

t_island*	find_end_island(const t_matrix* islands)
{
	for (int i = 0; i < islands->height; i++)
		for (int j = 0; j < islands->width; j++)
			if (islands->tab[i][j] == c_end_island)
				return new_island(j, i, get_island_type(islands->tab[i][j]));

	return NULL;
}
