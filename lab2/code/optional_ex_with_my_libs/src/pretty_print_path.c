#include "islands.h"


void	pretty_print_path(t_list* path, const t_matrix* islands)
{
	t_island*	island;
	const char*	color;


	if (path == NULL)
		return;

	for (int i = 0; i < islands->height; i++)
	{
		for (int j = 0; j < islands->width; j++)
		{
			island = path->content;
			if (i == island->coord_y && j == island->coord_x)
				printf("%4s", "X");
			else
				printf("%4d", islands->tab[i][j]);

			
		}
		putchar('\n');
	}

	putchar('\n');
	pretty_print_path(LNEXT(path), islands);
}
