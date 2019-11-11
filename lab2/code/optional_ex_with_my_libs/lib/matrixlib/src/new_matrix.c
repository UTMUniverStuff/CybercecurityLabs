#include <stdlib.h>
#include "matrixlib.h"


t_matrix*		new_matrix(int width, int height)
{
	t_matrix*	matrix;


	matrix = malloc(sizeof(*matrix));
	matrix->width = width;
	matrix->height = height;

	matrix->tab = calloc(height, sizeof(matrix->tab));
	for (int i = 0; i < height; i++)
		matrix->tab[i] = calloc(width, sizeof(*matrix->tab));	

	return matrix;
}