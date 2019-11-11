#include <stdlib.h>
#include "matrixlib.h"


static void	free_tab(t_matrix* matrix)
{
	if (matrix->tab == NULL)
		return;

	for (int i = 0; i < matrix->height; i++)
		if (matrix->tab[i])
		{
			free(matrix->tab[i]);
			matrix->tab[i] = NULL;
		}

	free(matrix->tab);
	matrix->tab = NULL;
}


void free_matrix(t_matrix** matrix)
{
	if (*matrix == NULL)
		return;

	free_tab(*matrix);
	free(*matrix);

	*matrix = NULL;
}