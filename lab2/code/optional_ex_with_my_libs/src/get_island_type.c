#include "islands.h"


e_island_type	get_island_type(int island_value)
{
	switch (island_value)
	{
		case c_start_island:
			return c_start_island;

		case c_end_island:
			return c_end_island;

		case c_obstacle:
			return c_obstacle;
	}

	return c_normal_island;
}
