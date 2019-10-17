#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


typedef struct	s_matrix
{
	float**		tab;
	size_t		width;
	size_t		height;
}				t_matrix;

typedef float (*t_matrix_operation)(float, float);


int output_is_being_redirected()
{
	return isatty(STDOUT_FILENO) == 0;
}

void handle_critical_errno(const char* reason)
{
	if (!errno)
		return;

	perror(reason);
	exit(1);
}

t_matrix init_matrix(const size_t width, const size_t height)
{
	t_matrix	matrix;


	matrix.width = width;
	matrix.height = height;

	matrix.tab = calloc(height, sizeof(matrix.tab));
	handle_critical_errno("calloc");

	for (size_t i = 0; i < height; i++)
	{
		matrix.tab[i] = calloc(width, sizeof(*matrix.tab));
		handle_critical_errno("calloc");
	}

	return matrix;
}

void free_matrix(t_matrix* matrix)
{
	if (matrix->tab == NULL)
		return;

	for (size_t i = 0; i < matrix->height; i++)
	{
		if (matrix->tab[i])
		{
			free(matrix->tab[i]);
			matrix->tab[i] = NULL;
		}
	}

	free(matrix->tab);
	matrix->tab = NULL;
}

void read_matrix_tab(t_matrix matrix)
{
	for (size_t i = 0; i < matrix.height; i++)
		for (size_t j = 0; j < matrix.width; j++)
			scanf("%f", &matrix.tab[i][j]);
}

t_matrix read_matrix()
{
	size_t width;
	size_t height;
	t_matrix matrix;

	
	if (!output_is_being_redirected())
		printf("Input the size of the matrix: Width x Height:\n");

	scanf("%u%u", &width, &height);

	matrix = init_matrix(width, height);
	read_matrix_tab(matrix);
	return matrix;
}

void print_matrix(const t_matrix* const matrix)
{
	for (size_t i = 0; i < matrix->height; i++)
	{
		for (size_t j = 0; j < matrix->width; j++)
			printf("% 10.2f", matrix->tab[i][j]);

		putchar('\n');
	}
}

t_matrix apply_operation(
	const t_matrix* const matrix1,
	const t_matrix* const matrix2,
	const t_matrix_operation op)
{
	t_matrix result;

	if (matrix1->width != matrix2->width || matrix1->height != matrix2->height)
	{
		fprintf(stderr, "Invalid matrix sizes to apply operation\n");
		exit(1);
	}

	result = init_matrix(matrix1->width, matrix1->height);
	for (size_t i = 0; i < matrix1->height; i++)
		for (size_t j = 0; j < matrix1->width; j++)
			result.tab[i][j] = op(matrix1->tab[i][j], matrix2->tab[i][j]);

	return result;
}

float add(const float a, const float b) { return a + b; }
float sub(const float a, const float b) { return a - b; }
float mul(const float a, const float b) { return a * b; }
float divide(const float a, const float b) { return a / b; }


t_matrix_operation extract_operation(const int argc, const char** argv)
{
	if (argc <= 1)
	{
		fprintf(stderr, "Operation not provided\n");
		exit(1);
	}

	switch (argv[1][0])
	{
		case '+': return add;
		case '-': return sub;
		case '*': return mul;
		case '/': return divide;
	}

	fprintf(stderr, "Invalid operation\n");
	exit(1);
}

int main(const int argc, const char** argv)
{
	t_matrix			matrix1;
	t_matrix			matrix2;
	t_matrix			result;
	t_matrix_operation	op;


	op = extract_operation(argc, argv);

	matrix1 = read_matrix();
	matrix2 = read_matrix();

	result = apply_operation(&matrix1, &matrix2, op);
	print_matrix(&result);

	free_matrix(&matrix1);
	free_matrix(&matrix2);
	free_matrix(&result);

	return 0;
}
