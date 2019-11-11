#include <stdlib.h>
#include "matrixlib.h"


t_matrix*	copy_matrix(const t_matrix* other)
{
	t_matrix*	matrix;


	matrix = new_matrix(other->width, other->height);
	for (int i = 0; i < matrix->height; i++)
		for (int j = 0; j < matrix->width; j++)
			matrix->tab[i][j] = other->tab[i][j];

	return matrix;
}