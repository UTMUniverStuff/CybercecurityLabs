#include <stdio.h>
#include "matrix.h"


void print_matrix(const t_matrix* matrix)
{
	for (int i = 0; i < matrix->height; i++)
	{
		for (int j = 0; j < matrix->width; j++)
			printf("% 10.2f", matrix->tab[i][j]);

		putchar('\n');
	}
}