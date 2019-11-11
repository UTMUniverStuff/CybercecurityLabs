#include <stdlib.h>
#include "matrix.h"


t_matrix init_matrix(const int width, const int height)
{
	t_matrix	matrix;


	matrix.width = width;
	matrix.height = height;

	matrix.tab = calloc(height, sizeof(matrix.tab));
	for (int i = 0; i < height; i++)
		matrix.tab[i] = calloc(width, sizeof(*matrix.tab));

	return matrix;
}
