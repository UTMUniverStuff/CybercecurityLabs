#include <stdio.h>
#include <unistd.h>
#include "matrix.h"


static int	output_is_being_redirected()
{
	return !isatty(STDOUT_FILENO);
}

static void	read_matrix_tab(t_matrix matrix)
{
	for (int i = 0; i < matrix.height; i++)
		for (int j = 0; j < matrix.width; j++)
			scanf("%f", &matrix.tab[i][j]);
}

t_matrix	read_matrix()
{
	int width;
	int height;
	t_matrix matrix;

	
	if (!output_is_being_redirected())
		printf("Input the size of the matrix: Width x Height:\n");
	
	scanf("%d%d", &width, &height);

	matrix = init_matrix(width, height);
	read_matrix_tab(matrix);
	return matrix;
}